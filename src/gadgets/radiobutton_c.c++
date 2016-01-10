/*
    File        : radiobutton_c.c++
    Date        : 19-Sep-02
    Author      : � A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a radio button toolbox gadget.

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
#include "radiobutton_c.h"

/*
    Parameters  : value         - The value to set.
    Returns     : radiobutton_c - This object.
    Description : Set the value of this gadget. To reduce flicker the value
                  is not updated unless it has changed.
*/
radiobutton_c &radiobutton_c::operator=(bool value)
{
    radiobutton_b::operator=(value);
    return *this;
}

/*
    Parameters  : value - The value to set.
    Returns     : void
    Description : Gadget specific function to set the value.
*/
void radiobutton_c::_set_value(bool value)
{
    radiobutton_set_state(0, object, component, value);
}

/*
    Parameters  : void
    Returns     : bool  - The value
    Description : Gadget specific function to get the value.
*/
bool radiobutton_c::_get_value() const
{
    return radiobutton_get_state(0, object, component, NULL);
}

/*
    Parameters  : event      - The toolbox event code.
    Returns     : void
    Description : Gadget specific function to set the toolbox event code
                  which will be raised for this gadget.
*/
void radiobutton_c::_set_event(bits event)
{
    radiobutton_set_action(0, object, component, event);
}

/*
    Parameters  : void
    Returns     : bits  - The toolbox event code.
    Description : Gadget specific function to get the toolbox event code
                  which will be raised for this gadget.
*/
bits radiobutton_c::_get_event() const
{
    return radiobutton_get_action(0, object, component);
}

/*
    Parameters  : text  - The text string to set.
    Returns     : void
    Description : Gadget specific function to set the text.
*/
void radiobutton_c::_set_text(const char *text)
{
    radiobutton_set_label(0, object, component, text);
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
size_t radiobutton_c::_get_text(char *text, size_t size) const
{
    return radiobutton_get_label(0, object, component, text, size);
}
