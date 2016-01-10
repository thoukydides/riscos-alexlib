/*
    File        : button_c.c++
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a button toolbox gadget.

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
#include "button_c.h"

/*
    Parameters  : value     - The text string to set.
    Returns     : button_c  - This object.
    Description : Set the value of this gadget. To reduce flicker the value
                  is not updated unless it has changed.
*/
button_c &button_c::operator=(const char *value)
{
    button_b::operator=(value);
    return *this;
}

/*
    Parameters  : value     - The text string to set.
    Returns     : button_c  - This object.
    Description : Set the value of this gadget. To reduce flicker the value
                  is not updated unless it has changed.
*/
button_c &button_c::operator=(const string &value)
{
    button_b::operator=(value);
    return *this;
}

/*
    Parameters  : clear - Icon flags to clear.
                  eor   - Icon flags to toggle.
    Returns     : void
    Description : Representation specific function to set the icon flags
                  for this button.
*/
void button_c::_set_icon_flags(wimp_icon_flags clear, wimp_icon_flags eor)
{
    button_set_flags(0, object, component, clear, eor);
}

/*
    Parameters  : void
    Returns     : wimp_icon_flags   - The current icon flags.
    Description : Representation specific function to get the icon flags
                  for this button.
*/
wimp_icon_flags button_c::_get_icon_flags() const
{
    return button_get_flags(0, object, component);
}

/*
    Parameters  : validation    - The text string to set.
    Returns     : void
    Description : Representation specific function to set the validation
                  string.
*/
void button_c::_set_validation(const char *validation)
{
    button_set_validation(0, object, component, validation);
}

/*
    Parameters  : validation    - Pointer to buffer to hold the validation
                                  string, or NULL to read the size of
                                  buffer required.
                  size          - The size of the buffer.
    Returns     : size_t        - Number of bytes written to the buffer, or
                                  the buffer size required if NULL passed.
    Description : Representation specific function to get the validation
                  string or the buffer size required.
*/
size_t button_c::_get_validation(char *validation, size_t size) const
{
    return button_get_validation(0, object, component, validation, size);
}

/*
    Parameters  : value - The text string to set.
    Returns     : void
    Description : Gadget specific function to set the value.
*/
void button_c::_set_value(const char *value)
{
    button_set_value(0, object, component, value);
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
size_t button_c::_get_value(char *value, size_t size) const
{
    return button_get_value(0, object, component, value, size);
}

/*
    Parameters  : font  - The name of the font to use, or NULL to use the
                          system font.
                  xsize - The width in 16ths of a point.
                  ysize - The height in 16ths of a point.
    Returns     : void
    Description : Gadget specific function to set the font.
*/
void button_c::_set_font(const char *font, int xsize, int ysize)
{
    button_set_font(0, object, component, font, xsize, ysize);
}
