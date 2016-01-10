/*
    File        : slider_c.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a slider toolbox gadget.

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
#ifndef slider_c_h
#define slider_c_h

// Include alexlib header files
#ifndef gadget_c_h
#include "gadget_c.h"
#endif
#ifndef slider_b_h
#include "slider_b.h"
#endif

// A class to represent a slider gadget
class slider_c : public virtual gadget_b,
                 public gadget_c,
                 public slider_b
{
public:

    /*
        Parameters  : component - The component ID of this slider.
                      object    - The object ID of this slider's parent
                                  window.
        Returns     : -
        Description : Constructor function. This does not create a slider;
                      it merely creates an object to represent the slider.
    */
    slider_c(toolbox_c component = toolbox_NULL_COMPONENT,
             toolbox_o object = toolbox_NULL_OBJECT);

    /*
        Parameters  : value     - The number to set.
        Returns     : slider_c  - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    slider_c &operator=(int value);

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

    /*
        Parameters  : value - The number to set.
        Returns     : void
        Description : Gadget specific function to set the value.
    */
    virtual void _set_value(int value);

    /*
        Parameters  : void
        Returns     : int   - The value
        Description : Gadget specific function to get the value.
    */
    virtual int _get_value() const;

    /*
        Parameters  : lower - The lower bound.
        Returns     : void
        Description : Gadget specific function to set the lower bound.
    */
    virtual void _set_lower_bound(int lower);

    /*
        Parameters  : void
        Returns     : int   - The lower bound.
        Description : Gadget specific function to get the lower bound.
    */
    virtual int _get_lower_bound() const;

    /*
        Parameters  : upper - The upper bound.
        Returns     : void
        Description : Gadget specific function to set the upper bound.
    */
    virtual void _set_upper_bound(int upper);

    /*
        Parameters  : void
        Returns     : int   - The upper bound.
        Description : Gadget specific function to get the upper bound.
    */
    virtual int _get_upper_bound() const;

    /*
        Parameters  : step  - The step size.
        Returns     : void
        Description : Gadget specific function to set the step size.
    */
    virtual void _set_step_size(int step);

    /*
        Parameters  : void
        Returns     : int   - The step size.
        Description : Gadget specific function to get the step size.
    */
    virtual int _get_step_size() const;
};

/*
    Parameters  : component - The component ID of this slider.
                  object    - The object ID of this slider's parent
                              window.
    Returns     : -
    Description : Constructor function. This does not create a slider;
                  it merely creates an object to represent the slider.
*/
inline slider_c::slider_c(toolbox_c component, toolbox_o object)
: gadget_c(component, object) {}

#endif
