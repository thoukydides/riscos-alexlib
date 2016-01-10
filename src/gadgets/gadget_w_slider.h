/*
    File        : gadget_w_slider.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a toolbox gadget that has a slider.

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
#ifndef gadget_w_slider_h
#define gadget_w_slider_h

// Include oslib header files
#include "oslib/wimp.h"

// Include alexlib header files
#ifndef gadget_w_number_h
#include "gadget_w_number.h"
#endif

// A class to represent a gadget with a slider
class gadget_w_slider : public gadget_w_number
{
public:

    /*
        Parameters  : colour    - The slider colour.
        Returns     : void
        Description : Set the colour of the slider.
    */
    void set_slider_colour(wimp_colour colour = wimp_COLOUR_MID_DARK_GREY);

    /*
        Parameters  : void
        Returns     : wimp_colour   - The slider colour.
        Description : Get the colour of the slider.
    */
    wimp_colour get_slider_colour() const;

    /*
        Parameters  : colour    - The well colour.
        Returns     : void
        Description : Set the colour of the well.
    */
    void set_well_colour(wimp_colour colour = wimp_COLOUR_WHITE);

    /*
        Parameters  : void
        Returns     : wimp_colour   - The well colour.
        Description : Get the colour of the well.
    */
    wimp_colour get_well_colour() const;

    /*
        Parameters  : lower - The lower bound.
        Returns     : void
        Description : Set the lower bound.
    */
    void set_lower_bound(int lower);

    /*
        Parameters  : void
        Returns     : int   - The lower bound.
        Description : Get the lower bound.
    */
    int get_lower_bound() const;

    /*
        Parameters  : upper - The upper bound.
        Returns     : void
        Description : Set the upper bound.
    */
    void set_upper_bound(int upper);

    /*
        Parameters  : void
        Returns     : int   - The upper bound.
        Description : Get the upper bound.
    */
    int get_upper_bound() const;

    /*
        Parameters  : step  - The step size.
        Returns     : void
        Description : Set the step size.
    */
    void set_step_size(int step);

    /*
        Parameters  : void
        Returns     : int   - The step size.
        Description : Get the step size.
    */
    int get_step_size() const;

    /*
        Parameters  : value             - The number to set.
        Returns     : gadget_w_slider   - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    gadget_w_slider &operator=(int value);

protected:

    /*
        Parameters  : colour    - The slider colour.
        Returns     : void
        Description : Gadget specific function to set the colour of the slider.
    */
    virtual void _set_slider_colour(wimp_colour colour) = 0;

    /*
        Parameters  : void
        Returns     : wimp_colour   - The slider colour.
        Description : Gadget specific function to get the colour of the slider.
    */
    virtual wimp_colour _get_slider_colour() const = 0;

    /*
        Parameters  : colour    - The well colour.
        Returns     : void
        Description : Gadget specific function to set the colour of the well.
    */
    virtual void _set_well_colour(wimp_colour colour) = 0;

    /*
        Parameters  : void
        Returns     : wimp_colour   - The well colour.
        Description : Gadget specific function to get the colour of the well.
    */
    virtual wimp_colour _get_well_colour() const = 0;

    /*
        Parameters  : lower - The lower bound.
        Returns     : void
        Description : Gadget specific function to set the lower bound.
    */
    virtual void _set_lower_bound(int lower) = 0;

    /*
        Parameters  : void
        Returns     : int   - The lower bound.
        Description : Gadget specific function to get the lower bound.
    */
    virtual int _get_lower_bound() const = 0;

    /*
        Parameters  : upper - The upper bound.
        Returns     : void
        Description : Gadget specific function to set the upper bound.
    */
    virtual void _set_upper_bound(int upper) = 0;

    /*
        Parameters  : void
        Returns     : int   - The upper bound.
        Description : Gadget specific function to get the upper bound.
    */
    virtual int _get_upper_bound() const = 0;

    /*
        Parameters  : step  - The step size.
        Returns     : void
        Description : Gadget specific function to set the step size.
    */
    virtual void _set_step_size(int step) = 0;

    /*
        Parameters  : void
        Returns     : int   - The step size.
        Description : Gadget specific function to get the step size.
    */
    virtual int _get_step_size() const = 0;
};

/*
    Parameters  : colour    - The slider colour.
    Returns     : void
    Description : Set the colour of the slider.
*/
inline void gadget_w_slider::set_slider_colour(wimp_colour colour)
{
    _set_slider_colour(colour);
}

/*
    Parameters  : void
    Returns     : wimp_colour   - The slider colour.
    Description : Get the colour of the slider.
*/
inline wimp_colour gadget_w_slider::get_slider_colour() const
{
    return _get_slider_colour();
}

/*
    Parameters  : colour    - The well colour.
    Returns     : void
    Description : Set the colour of the well.
*/
inline void gadget_w_slider::set_well_colour(wimp_colour colour)
{
    _set_well_colour(colour);
}

/*
    Parameters  : void
    Returns     : wimp_colour   - The well colour.
    Description : Get the colour of the well.
*/
inline wimp_colour gadget_w_slider::get_well_colour() const
{
    return _get_well_colour();
}

/*
    Parameters  : lower - The lower bound.
    Returns     : void
    Description : Set the lower bound.
*/
inline void gadget_w_slider::set_lower_bound(int lower)
{
    _set_lower_bound(lower);
}

/*
    Parameters  : void
    Returns     : int   - The lower bound.
    Description : Get the lower bound.
*/
inline int gadget_w_slider::get_lower_bound() const
{
    return _get_lower_bound();
}

/*
    Parameters  : upper - The upper bound.
    Returns     : void
    Description : Set the upper bound.
*/
inline void gadget_w_slider::set_upper_bound(int upper)
{
    _set_upper_bound(upper);
}

/*
    Parameters  : void
    Returns     : int   - The upper bound.
    Description : Get the upper bound.
*/
inline int gadget_w_slider::get_upper_bound() const
{
    return _get_upper_bound();
}

/*
    Parameters  : step  - The step size.
    Returns     : void
    Description : Set the step size.
*/
inline void gadget_w_slider::set_step_size(int step)
{
    _set_step_size(step);
}

/*
    Parameters  : void
    Returns     : int   - The step size.
    Description : Get the step size.
*/
inline int gadget_w_slider::get_step_size() const
{
    return _get_step_size();
}

#endif
