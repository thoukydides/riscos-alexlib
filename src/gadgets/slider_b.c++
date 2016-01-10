/*
    File        : slider_b.c++
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

// Include header file for this module
#include "slider_b.h"

/*
    Parameters  : value     - The number to set.
    Returns     : slider_b  - This object.
    Description : Set the value of this gadget. To reduce flicker the value
                  is not updated unless it has changed.
*/
slider_b &slider_b::operator=(int value)
{
    gadget_w_slider::operator=(value);
    return *this;
}

/*
    Parameters  : colour    - The slider colour.
    Returns     : void
    Description : Gadget specific function to set the colour of the slider.
*/
void slider_b::_set_slider_colour(wimp_colour colour)
{
    _set_flags((_get_flags() & ~slider_KNOB_COLOUR)
               | (colour << slider_KNOB_COLOUR_SHIFT));
}

/*
    Parameters  : void
    Returns     : wimp_colour   - The slider colour.
    Description : Gadget specific function to get the colour of the slider.
*/
wimp_colour slider_b::_get_slider_colour() const
{
    return (_get_flags() & slider_KNOB_COLOUR)
           >> slider_KNOB_COLOUR_SHIFT;
}

/*
    Parameters  : colour    - The well colour.
    Returns     : void
    Description : Gadget specific function to set the colour of the well.
*/
void slider_b::_set_well_colour(wimp_colour colour)
{
    _set_flags((_get_flags() & ~slider_WELL_COLOUR)
               | (colour << slider_WELL_COLOUR_SHIFT));
}

/*
    Parameters  : void
    Returns     : wimp_colour   - The well colour.
    Description : Gadget specific function to get the colour of the well.
*/
wimp_colour slider_b::_get_well_colour() const
{
    return (_get_flags() & slider_WELL_COLOUR)
           >> slider_WELL_COLOUR_SHIFT;
}
