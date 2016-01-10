/*
    File        : numberrange_c.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a number range toolbox gadget.

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
#ifndef numberrange_c_h
#define numberrange_c_h

// Include alexlib header files
#ifndef gadget_c_h
#include "gadget_c.h"
#endif
#ifndef numberrange_b_h
#include "numberrange_b.h"
#endif

// A class to represent a number range gadget
class numberrange_c : public virtual gadget_b,
                      public gadget_c,
                      public numberrange_b
{
public:

    /*
        Parameters  : component - The component ID of this number range.
                      object    - The object ID of this number range's parent
                                  window.
        Returns     : -
        Description : Constructor function. This does not create a number
                      range; it merely creates an object to represent the number
                      range.
    */
    numberrange_c(toolbox_c component = toolbox_NULL_COMPONENT,
                  toolbox_o object = toolbox_NULL_OBJECT);

    /*
        Parameters  : void
        Returns     : toolbox_c - The component ID.
        Description : Get the component ID of the numerical component.
    */
    toolbox_c get_numerical_component() const;

    /*
        Parameters  : void
        Returns     : toolbox_c - The component ID.
        Description : Get the component ID of the left adjuster component.
    */
    toolbox_c get_left_adjuster_component() const;

    /*
        Parameters  : void
        Returns     : toolbox_c - The component ID.
        Description : Get the component ID of the right adjuster component.
    */
    toolbox_c get_right_adjuster_component() const;

    /*
        Parameters  : void
        Returns     : toolbox_c - The component ID.
        Description : Get the component ID of the slider component.
    */
    toolbox_c get_slider_component() const;

    /*
        Parameters  : value         - The number to set.
        Returns     : numberrange_c - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    numberrange_c &operator=(int value);

protected:

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

    /*
        Parameters  : precision - The precision.
        Returns     : void
        Description : Set the precision.
    */
    virtual void _set_precision(int precision);

    /*
        Parameters  : void
        Returns     : int   - The precision.
        Description : Get the precision.
    */
    virtual int _get_precision() const;
};

/*
    Parameters  : component - The component ID of this number range.
                  object    - The object ID of this number range's parent
                              window.
    Returns     : -
    Description : Constructor function. This does not create a number
                  range; it merely creates an object to represent the number
                  range.
*/
inline numberrange_c::numberrange_c(toolbox_c component, toolbox_o object)
: gadget_c(component, object) {}

/*
    Parameters  : void
    Returns     : toolbox_c - The component ID.
    Description : Get the component ID of the numerical component.
*/
inline toolbox_c numberrange_c::get_numerical_component() const
{
    toolbox_c numerical;
    numberrange_get_components(numberrange_GET_NUMERICAL_FIELD,
                               object, component,
                               &numerical, NULL, NULL, NULL);
    return numerical;
}

/*
    Parameters  : void
    Returns     : toolbox_c - The component ID.
    Description : Get the component ID of the left adjuster component.
*/
inline toolbox_c numberrange_c::get_left_adjuster_component() const
{
    toolbox_c left_adjuster;
    numberrange_get_components(numberrange_GET_LEFT_ADJUSTER, object, component,
                               NULL, &left_adjuster, NULL, NULL);
    return left_adjuster;
}

/*
    Parameters  : void
    Returns     : toolbox_c - The component ID.
    Description : Get the component ID of the right adjuster component.
*/
inline toolbox_c numberrange_c::get_right_adjuster_component() const
{
    toolbox_c right_adjuster;
    numberrange_get_components(numberrange_GET_RIGHT_ADJUSTER,
                               object, component,
                               NULL, NULL, &right_adjuster, NULL);
    return right_adjuster;
}

/*
    Parameters  : void
    Returns     : toolbox_c - The component ID.
    Description : Get the component ID of the slider component.
*/
inline toolbox_c numberrange_c::get_slider_component() const
{
    toolbox_c slider;
    numberrange_get_components(numberrange_GET_SLIDER, object, component,
                               NULL, NULL, NULL, &slider);
    return slider;
}

#endif
