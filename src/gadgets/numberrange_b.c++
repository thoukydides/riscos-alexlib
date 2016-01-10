/*
    File        : numberrange_b.c++
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Base class to represent a number range toolbox gadget.

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
#include "numberrange_b.h"

// Include clib header files
#include <math.h>

/*
    Parameters  : value         - The number to set.
    Returns     : numberrange_b - This object.
    Description : Set the value of this gadget. To reduce flicker the value
                  is not updated unless it has changed.
*/
numberrange_b &numberrange_b::operator=(int value)
{
    gadget_w_slider::operator=(value);
    return *this;
}

/*
    Parameters  : position  - The field justification.
    Returns     : void
    Description : Gadget specific function to set the justification.
*/
void numberrange_b::_set_justification(justification position)
{
    gadget_flags flags = _get_flags()
                         & ~(numberrange_RJUSTIFIED | numberrange_HCENTRED);
    if (position == right) flags |= numberrange_RJUSTIFIED;
    else if (position == centre) flags |= numberrange_HCENTRED;
    _set_flags(flags);
}

/*
    Parameters  : void
    Returns     : bool  - The field justification.
    Description : Gadget specific function to Get the justification.
*/
numberrange_b::justification numberrange_b::_get_justification() const
{
    gadget_flags flags = _get_flags();
    return  flags & numberrange_RJUSTIFIED
            ? right
            : (flags & numberrange_HCENTRED ? centre : left);
}

/*
    Parameters  : colour    - The slider colour.
    Returns     : void
    Description : Gadget specific function to set the colour of the slider.
*/
void numberrange_b::_set_slider_colour(wimp_colour colour)
{
    _set_flags((_get_flags() & ~numberrange_KNOB_COLOUR)
               | (colour << numberrange_KNOB_COLOUR_SHIFT));
}

/*
    Parameters  : void
    Returns     : wimp_colour   - The slider colour.
    Description : Gadget specific function to get the colour of the slider.
*/
wimp_colour numberrange_b::_get_slider_colour() const
{
    return (_get_flags() & numberrange_KNOB_COLOUR)
           >> numberrange_KNOB_COLOUR_SHIFT;
}

/*
    Parameters  : colour    - The well colour.
    Returns     : void
    Description : Gadget specific function to set the colour of the well.
*/
void numberrange_b::_set_well_colour(wimp_colour colour)
{
    _set_flags((_get_flags() & ~numberrange_WELL_COLOUR)
               | (colour << numberrange_WELL_COLOUR_SHIFT));
}

/*
    Parameters  : void
    Returns     : wimp_colour   - The well colour.
    Description : Gadget specific function to get the colour of the well.
*/
wimp_colour numberrange_b::_get_well_colour() const
{
    return (_get_flags() & numberrange_WELL_COLOUR)
           >> numberrange_WELL_COLOUR_SHIFT;
}

/*
    Parameters  : value     - The floating point value to scale.
                  rounding  - The required rounding mode.
    Returns     : int       - The scaled and rounded value.
    Description : Scale the specified value according to the current
                  precision and round to an integer.
*/
int numberrange_b::scale(double value, rounding_mode rounding) const
{
    int precision = _get_precision();
    int scaled;
    while (precision--) value *= 10.0;
    switch (rounding)
    {
        case positive:
            // Round to +infinity
            scaled = (int) ceil(value);
            break;

        case negative:
            // Round to -infinity
            scaled = (int) floor(value);
            break;

        case zero:
            // Round to zero
            scaled = value < 0.0 ? (int) ceil(value) : (int) floor(value);
            break;

        default:
            // Round to nearest for all other cases
            scaled = (int) floor(value + 0.5);
            break;
    }
    return scaled;
}

/*
    Parameters  : value     - The integer value to scale.
    Returns     : double    - The scaled.
    Description : Scale the specified value according to the current
                  precision.
*/
double numberrange_b::scale(int value) const
{
    int precision = _get_precision();
    double scaled = value;
    while (precision--) scaled /= 10.0;
    return scaled;
}
