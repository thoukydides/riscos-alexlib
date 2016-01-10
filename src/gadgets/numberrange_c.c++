/*
    File        : numberrange_c.c++
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

// Include header file for this module
#include "numberrange_c.h"

/*
    Parameters  : value         - The number to set.
    Returns     : numberrange_c - This object.
    Description : Set the value of this gadget. To reduce flicker the value
                  is not updated unless it has changed.
*/
numberrange_c &numberrange_c::operator=(int value)
{
    numberrange_b::operator=(value);
    return *this;
}

/*
    Parameters  : value - The number to set.
    Returns     : void
    Description : Gadget specific function to set the value.
*/
void numberrange_c::_set_value(int value)
{
    numberrange_set_value(0, object, component, value);
}

/*
    Parameters  : void
    Returns     : int   - The value
    Description : Gadget specific function to get the value.
*/
int numberrange_c::_get_value() const
{
    return numberrange_get_value(0, object, component);
}

/*
    Parameters  : lower - The lower bound.
    Returns     : void
    Description : Gadget specific function to set the lower bound.
*/
void numberrange_c::_set_lower_bound(int lower)
{
    numberrange_set_bounds(numberrange_BOUND_LOWER, object, component,
                           lower, 0, 0, 0);
}

/*
    Parameters  : void
    Returns     : int   - The lower bound.
    Description : Gadget specific function to get the lower bound.
*/
int numberrange_c::_get_lower_bound() const
{
    int lower;
    numberrange_get_bounds(numberrange_BOUND_LOWER, object, component,
                           &lower, 0, 0, 0);
    return lower;
}

/*
    Parameters  : upper - The upper bound.
    Returns     : void
    Description : Gadget specific function to set the upper bound.
*/
void numberrange_c::_set_upper_bound(int upper)
{
    numberrange_set_bounds(numberrange_BOUND_UPPER, object, component,
                           0, upper, 0, 0);
}

/*
    Parameters  : void
    Returns     : int   - The upper bound.
    Description : Gadget specific function to get the upper bound.
*/
int numberrange_c::_get_upper_bound() const
{
    int upper;
    numberrange_get_bounds(numberrange_BOUND_UPPER, object, component,
                           0, &upper, 0, 0);
    return upper;
}

/*
    Parameters  : step  - The step size.
    Returns     : void
    Description : Gadget specific function to set the step size.
*/
void numberrange_c::_set_step_size(int step)
{
    numberrange_set_bounds(numberrange_BOUND_STEP, object, component,
                           0, 0, step, 0);
}

/*
    Parameters  : void
    Returns     : int   - The step size.
    Description : Gadget specific function to get the step size.
*/
int numberrange_c::_get_step_size() const
{
    int step;
    numberrange_get_bounds(numberrange_BOUND_STEP, object, component,
                           0, 0, &step, 0);
    return step;
}

/*
    Parameters  : precision - The precision.
    Returns     : void
    Description : Set the precision.
*/
void numberrange_c::_set_precision(int precision)
{
    numberrange_set_bounds(numberrange_BOUND_PRECISION, object, component,
                           0, 0, 0, precision);
}

/*
    Parameters  : void
    Returns     : int   - The precision.
    Description : Get the precision.
*/
int numberrange_c::_get_precision() const
{
    int precision;
    numberrange_get_bounds(numberrange_BOUND_PRECISION, object, component,
                           0, 0, 0, &precision);
    return precision;
}
