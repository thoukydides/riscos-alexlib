/*
    File        : displayfield_c.c++
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a display field toolbox gadget.

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
#include "displayfield_c.h"

/*
    Parameters  : value             - The text string to set.
    Returns     : displayfield_c    - This object.
    Description : Set the value of this gadget. To reduce flicker the value
                  is not updated unless it has changed.
*/
displayfield_c &displayfield_c::operator=(const char *value)
{
    displayfield_b::operator=(value);
    return *this;
}

/*
    Parameters  : value             - The text string to set.
    Returns     : displayfield_b    - This object.
    Description : Set the value of this gadget. To reduce flicker the value
                  is not updated unless it has changed.
*/
displayfield_c &displayfield_c::operator=(const string &value)
{
    displayfield_b::operator=(value);
    return *this;
}

/*
    Parameters  : value - The text string to set.
    Returns     : void
    Description : Gadget specific function to set the value.
*/
void displayfield_c::_set_value(const char *value)
{
    displayfield_set_value(0, object, component, value);
}

/*
    Parameters  : value     - Pointer to buffer to hold the value, or NULL
                              to read the size of buffer required.
                  size      - The size of the buffer.
    Returns     : size_t    - Number of bytes written to the buffer, or
                              the buffer size required if NULL passed.
    Description : Gadget specific function to get the value or the buffer
                  size required.
*/
size_t displayfield_c::_get_value(char *value, size_t size) const
{
    return displayfield_get_value(0, object, component, value, size);
}

/*
    Parameters  : font  - The name of the font to use, or NULL to use the
                          system font.
                  xsize - The width in 16ths of a point.
                  ysize - The height in 16ths of a point.
    Returns     : void
    Description : Gadget specific function to set the font.
*/
void displayfield_c::_set_font(const char *font, int xsize, int ysize)
{
    displayfield_set_font(0, object, component, font, xsize, ysize);
}
