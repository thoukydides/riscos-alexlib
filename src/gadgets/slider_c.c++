/*
    File        : slider_c.c++
    Date        : 19-Sep-02
    Author      : � A.Thoukydides, 1995-2002, 2016
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

// Include header file for this module
#include "slider_c.h"

/*
    Parameters  : value     - The number to set.
    Returns     : slider_c  - This object.
    Description : Set the value of this gadget. To reduce flicker the value
                  is not updated unless it has changed.
*/
slider_c &slider_c::operator=(int value)
{
    slider_b::operator=(value);
    return *this;
}

/*
    Parameters  : colour    - The slider colour.
    Returns     : void
    Description : Gadget specific function to set the colour of the slider.
*/
void slider_c::_set_slider_colour(wimp_colour colour)
{
    slider_set_colour(0, object, component, colour, _get_well_colour());
}

/*
    Parameters  : void
    Returns     : wimp_colour   - The slider colour.
    Description : Gadget specific function to get the colour of the slider.
*/
wimp_colour slider_c::_get_slider_colour() const
{
    wimp_colour colour;
    slider_get_colour(0, object, component, &colour, NULL);
    return colour;
}

/*
    Parameters  : colour    - The well colour.
    Returns     : void
    Description : Gadget specific function to set the colour of the well.
*/
void slider_c::_set_well_colour(wimp_colour colour)
{
    slider_set_colour(0, object, component, _get_slider_colour(), colour);
}

/*
    Parameters  : void
    Returns     : wimp_colour   - The well colour.
    Description : Gadget specific function to get the colour of the well.
*/
wimp_colour slider_c::_get_well_colour() const
{
    wimp_colour colour;
    slider_get_colour(0, object, component, NULL, &colour);
    return colour;
}

/*
    Parameters  : value - The number to set.
    Returns     : void
    Description : Gadget specific function to set the value.
*/
void slider_c::_set_value(int value)
{
    slider_set_value(0, object, component, value);
}

/*
    Parameters  : void
    Returns     : int   - The value
    Description : Gadget specific function to get the value.
*/
int slider_c::_get_value() const
{
    return slider_get_value(0, object, component);
}

/*
    Parameters  : lower - The lower bound.
    Returns     : void
    Description : Gadget specific function to set the lower bound.
*/
void slider_c::_set_lower_bound(int lower)
{
    slider_set_bounds(slider_BOUND_LOWER, object, component, lower, 0, 0);
}

/*
    Parameters  : void
    Returns     : int   - The lower bound.
    Description : Gadget specific function to get the lower bound.
*/
int slider_c::_get_lower_bound() const
{
    int lower;
    slider_get_bounds(slider_BOUND_LOWER, object, component, &lower, 0, 0);
    return lower;
}

/*
    Parameters  : upper - The upper bound.
    Returns     : void
    Description : Gadget specific function to set the upper bound.
*/
void slider_c::_set_upper_bound(int upper)
{
    slider_set_bounds(slider_BOUND_UPPER, object, component, 0, upper, 0);
}

/*
    Parameters  : void
    Returns     : int   - The upper bound.
    Description : Gadget specific function to get the upper bound.
*/
int slider_c::_get_upper_bound() const
{
    int upper;
    slider_get_bounds(slider_BOUND_UPPER, object, component, 0, &upper, 0);
    return upper;
}

/*
    Parameters  : step  - The step size.
    Returns     : void
    Description : Gadget specific function to set the step size.
*/
void slider_c::_set_step_size(int step)
{
    slider_set_bounds(slider_BOUND_STEP, object, component, 0, 0, step);
}

/*
    Parameters  : void
    Returns     : int   - The step size.
    Description : Gadget specific function to get the step size.
*/
int slider_c::_get_step_size() const
{
    int step;
    slider_get_bounds(slider_BOUND_STEP, object, component, 0, 0, &step);
    return step;
}

