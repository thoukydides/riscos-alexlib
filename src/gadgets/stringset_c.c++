/*
    File        : stringset_c.c++
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a string set toolbox gadget.

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
#include "stringset_c.h"

/*
    Parameters  : value         - The number to set.
    Returns     : stringset_c   - This object.
    Description : Set the value of this gadget. To reduce flicker the value
                  is not updated unless it has changed.
*/
stringset_c &stringset_c::operator=(int value)
{
    stringset_b::operator=(value);
    return *this;
}

/*
    Parameters  : value         - The text string to set.
    Returns     : stringset_c   - This object.
    Description : Set the value of this gadget. To reduce flicker the value
                  is not updated unless it has changed.
*/
stringset_c &stringset_c::operator=(const char *value)
{
    stringset_b::operator=(value);
    return *this;
}

/*
    Parameters  : value         - The text string to set.
    Returns     : stringset_c   - This object.
    Description : Set the value of this gadget. To reduce flicker the value
                  is not updated unless it has changed.
*/
stringset_c &stringset_c::operator=(const string &value)
{
    stringset_b::operator=(value);
    return *this;
}

/*
    Parameters  : allowed   - The new set of allowable characters, or NULL
                              to allow all characters.
    Returns     : void
    Description : Gadget specific function to define the set of allowable
                  characters.
*/
void stringset_c::_set_allowable(const char *allowed)
{
    stringset_set_allowable(0, object, component, allowed);
}

/*
    Parameters  : value - The number to set.
    Returns     : void
    Description : Gadget specific function to set the value.
*/
void stringset_c::_set_value(int value)
{
    stringset_set_selected_index(0, object, component, value);
}

/*
    Parameters  : void
    Returns     : int   - The value
    Description : Gadget specific function to get the value.
*/
int stringset_c::_get_value() const
{
    return stringset_get_selected_index(0, object, component);
}

/*
    Parameters  : value - The text string to set.
    Returns     : void
    Description : Gadget specific function to set the value.
*/
void stringset_c::_set_value(const char *value)
{
    stringset_set_selected_string(0, object, component, value);
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
size_t stringset_c::_get_value(char *value, size_t size) const
{
    return stringset_get_selected_string(0, object, component, value, size);
}

/*
    Parameters  : available - The new list of available strings.
    Returns     : void
    Description : Representation specific function to define the available
                  set of strings.
*/
void stringset_c::_set_available(const char *available)
{
    stringset_set_available(0, object, component, available);
}
