/*
    File        : button_b.c++
    Date        : 19-Sep-02
    Author      : � A.Thoukydides, 1995-2002, 2016
    Description : Base class to represent a button toolbox gadget.

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
#include "button_b.h"

/*
    Parameters  : void
    Returns     : string    - The validation string.
    Description : Get the validation string for this gadget.
*/
string button_b::get_validation() const
{
    size_t size = get_validation_size();
    char *buffer = new char[size];
    get_validation(buffer, size);
    string validation(buffer);
    delete[] buffer;

    return validation;
}

/*
    Parameters  : value     - The text string to set.
    Returns     : button_b  - This object.
    Description : Set the value of this gadget. To reduce flicker the value
                  is not updated unless it has changed.
*/
button_b &button_b::operator=(const char *value)
{
    gadget_w_string::operator=(value);
    return *this;
}

/*
    Parameters  : value     - The text string to set.
    Returns     : button_b  - This object.
    Description : Set the value of this gadget. To reduce flicker the value
                  is not updated unless it has changed.
*/
button_b &button_b::operator=(const string &value)
{
    gadget_w_string::operator=(value);
    return *this;
}
