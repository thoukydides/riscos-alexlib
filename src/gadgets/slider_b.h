/*
    File        : slider_b.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Base class to represent a slider toolbox gadget.

    License     : AlexLib is free software: you can redistribute it and/or
                  modify it under the terms of the GNU General Public License
                  as published by the Free Software Foundation, either
                  version 3 of the License, or (at your option) any later
                  version.

                  AlexLib is distributed in the hope that it will be useful,
                  but WITHOUT ANY WARRANTY; without even the implied warranty
                  of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See
                  the GNU General Public License for more details.

                  You should have received a copy of the GNU General Public
                  License along with AlexLib. If not, see
                  <http://www.gnu.org/licenses/>.
*/

// Only include header file once
#ifndef slider_b_h
#define slider_b_h

// Include oslib header files
#include "oslib/slider.h"

// Include alexlib header files
#ifndef gadget_b_h
#include "gadget_b.h"
#endif
#ifndef gadget_w_slider_h
#include "gadget_w_slider.h"
#endif

// A base class to represent a slider gadget
class slider_b : public virtual gadget_b,
                 public gadget_w_slider
{
public:

    /*
        Parameters  : generate  - The generate event status.
        Returns     : void
        Description : Set the Slider_ValueChanged event status.
    */
    void set_generate_value_changed(bool generate = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - The generate event status.
        Description : Get the Slider_ValueChanged event status.
    */
    bool get_generate_value_changed() const;

    /*
        Parameters  : generate  - The generate event status.
        Returns     : void
        Description : Set the Slider_ValueChanged event while dragging status.
    */
    void set_generate_value_changed_by_dragging(bool generate = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - The generate event status.
        Description : Get the Slider_ValueChanged event while dragging status.
    */
    bool get_generate_value_changed_by_dragging() const;

    /*
        Parameters  : vertical  - The vertical status.
        Returns     : void
        Description : Set the vertical/horizontal status for this slider.
    */
    void set_vertical(bool vertical = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - The vertical status.
        Description : Get the vertical/horizontal status for this slider.
    */
    bool get_vertical() const;

    /*
        Parameters  : draggable - The draggable status.
        Returns     : void
        Description : Set the draggable status for this slider.
    */
    void set_draggable(bool draggable = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - The draggable status.
        Description : Get the draggable status for this slider.
    */
    bool get_draggable() const;

    /*
        Parameters  : value     - The number to set.
        Returns     : slider_b  - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    slider_b &operator=(int value);

protected:

    /*
        Parameters  : colour    - The slider colour.
        Returns     : void
        Description : Gadget specific function to set the colour of the slider.
    */
    virtual void _set_slider_colour(wimp_colour colour);

    /*
        Parameters  : void
        Returns     : wimp_colour   - The slider colour.
        Description : Gadget specific function to get the colour of the slider.
    */
    virtual wimp_colour _get_slider_colour() const;

    /*
        Parameters  : colour    - The well colour.
        Returns     : void
        Description : Gadget specific function to set the colour of the well.
    */
    virtual void _set_well_colour(wimp_colour colour);

    /*
        Parameters  : void
        Returns     : wimp_colour   - The well colour.
        Description : Gadget specific function to get the colour of the well.
    */
    virtual wimp_colour _get_well_colour() const;
};

/*
    Parameters  : generate  - The generate event status.
    Returns     : void
    Description : Set the Slider_ValueChanged event status.
*/
inline void slider_b::set_generate_value_changed(bool generate)
{
    gadget_flags flags = _get_flags();
    _set_flags(generate
               ? flags | slider_GENERATE_VALUE_CHANGED
               : flags & ~slider_GENERATE_VALUE_CHANGED);
}

/*
    Parameters  : void
    Returns     : bool  - The generate event status.
    Description : Get the Slider_ValueChanged event status.
*/
inline bool slider_b::get_generate_value_changed() const
{
    return BOOL(_get_flags() & slider_GENERATE_VALUE_CHANGED);
}

/*
    Parameters  : generate  - The generate event status.
    Returns     : void
    Description : Set the Slider_ValueChanged event while dragging status.
*/
inline void slider_b::set_generate_value_changed_by_dragging(bool generate)
{
    gadget_flags flags = _get_flags();
    _set_flags(generate
               ? flags | slider_GENERATE_VALUE_CHANGED_BY_DRAGGING
               : flags & ~slider_GENERATE_VALUE_CHANGED_BY_DRAGGING);
}

/*
    Parameters  : void
    Returns     : bool  - The generate event status.
    Description : Get the Slider_ValueChanged event while dragging status.
*/
inline bool slider_b::get_generate_value_changed_by_dragging() const
{
    return BOOL(_get_flags() & slider_GENERATE_VALUE_CHANGED_BY_DRAGGING);
}

/*
    Parameters  : vertical  - The vertical status.
    Returns     : void
    Description : Set the vertical/horizontal status for this slider.
*/
inline void slider_b::set_vertical(bool vertical)
{
    gadget_flags flags = _get_flags();
    _set_flags(vertical
               ? flags | slider_VERTICAL
               : flags & ~slider_VERTICAL);
}

/*
    Parameters  : void
    Returns     : bool  - The vertical status.
    Description : Get the vertical/horizontal status for this slider.
*/
inline bool slider_b::get_vertical() const
{
    return BOOL(_get_flags() & slider_VERTICAL);
}

/*
    Parameters  : draggable - The draggable status.
    Returns     : void
    Description : Set the draggable status for this slider.
*/
inline void slider_b::set_draggable(bool draggable)
{
    gadget_flags flags = _get_flags();
    _set_flags(draggable
               ? flags | slider_DRAGGABLE
               : flags & ~slider_DRAGGABLE);
}

/*
    Parameters  : void
    Returns     : bool  - The draggable status.
    Description : Get the draggable status for this slider.
*/
inline bool slider_b::get_draggable() const
{
    return BOOL(_get_flags() & slider_DRAGGABLE);
}

#endif
