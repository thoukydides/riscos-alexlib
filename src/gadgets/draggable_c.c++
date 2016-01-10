/*
    File        : draggable_c.c++
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a draggable toolbox gadget.

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
#include "draggable_c.h"

/*
    Parameters  : value         - The value to set.
    Returns     : draggable_c   - This object.
    Description : Set the value of this gadget. To reduce flicker the value
                  is not updated unless it has changed.
*/
draggable_c &draggable_c::operator=(bool value)
{
    gadget_w_boolean::operator=(value);
    return *this;
}

/*
    Parameters  : value - The value to set.
    Returns     : void
    Description : Gadget specific function to set the value.
*/
void draggable_c::_set_value(bool value)
{
    draggable_set_state(0, object, component, value);
}

/*
    Parameters  : void
    Returns     : bool  - The value
    Description : Gadget specific function to get the value.
*/
bool draggable_c::_get_value() const
{
    return draggable_get_state(0, object, component);
}

/*
    Parameters  : text  - The text string to set.
    Returns     : void
    Description : Gadget specific function to set the text.
*/
void draggable_c::_set_text(const char *text)
{
    draggable_set_text(0, object, component, text);
}

/*
    Parameters  : text      - Pointer to buffer to hold the text, or NULL
                              to read the size of buffer required.
                  size      - The size of the buffer.
    Returns     : size_t    - Number of bytes written to the buffer, or
                              the buffer size required if NULL passed.
    Description : Gadget specific function to get the text or the buffer
                  size required.
*/
size_t draggable_c::_get_text(char *text, size_t size) const
{
    return draggable_get_text(0, object, component, text, size);
}

/*
    Parameters  : sprite    - The sprite name.
    Returns     : void
    Description : Representation specific function to set the sprite name.
*/
void draggable_c::_set_sprite(const char *sprite)
{
    draggable_set_sprite(0, object, component, sprite);
}

/*
    Parameters  : sprite    - Pointer to buffer to hold the sprite name,
                              or NULL to read the size of buffer required.
                  size      - The size of the buffer.
    Returns     : size_t    - Number of bytes written to the buffer, or
                              the buffer size required if NULL passed.
    Description : Representation specific function to get the sprite name
                  or the buffer size required.
*/
size_t draggable_c::_get_sprite(char *sprite, size_t size) const
{
    return draggable_get_sprite(0, object, component, sprite, size);
}
