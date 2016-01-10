/*
    File        : gadget_with_text.c++
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a toolbox gadget that has an associated
                  text string.

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
#include "gadget_w_text.h"

/*
    Parameters  : void
    Returns     : string    - The text.
    Description : Get the text of this gadget.
*/
string gadget_w_text::get_text() const
{
    size_t size = get_text_size();
    char *buffer = new char[size];
    get_text(buffer, size);
    string text(buffer);
    delete[] buffer;

    return text;
}
