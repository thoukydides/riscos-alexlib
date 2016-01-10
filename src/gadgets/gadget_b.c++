/*
    File        : gadget_b.c++
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Base class to represent a generic toolbox gadget.

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
#include "gadget_b.h"

/*
    Parameters  : void
    Returns     : string    - The help message.
    Description : Get the help message that is associated with this gadget.
*/
string gadget_b::get_help_message() const
{
    size_t size = get_help_message_size();
    char *buffer = new char[size];
    get_help_message(buffer, size);
    string help(buffer);
    delete[] buffer;

    return help;
}

/*
    Parameters  : flags - The new flag settings.
    Returns     : void
    Description : Representation specific function to set the flags for
                  this gadget.
*/
void gadget_b::_set_flags(bits flags)
{
    NOT_USED(flags);
}

/*
    Parameters  : void
    Returns     : gadget_flags  - The flag settings for this gadget.
    Description : Representation specific function to get the flags for
                  this gadget.
*/
gadget_flags gadget_b::_get_flags() const
{
    return 0;
}

/*
    Parameters  : help  - The help text.
    Returns     : void
    Description : Representation specific function to set the help text.
*/
void gadget_b::_set_help_message(const char *help)
{
    NOT_USED(help);
}

/*
    Parameters  : help      - Pointer to buffer to hold the help text, or
                              NULL to read the size of buffer required.
                  size      - The size of the buffer.
    Returns     : size_t    - Number of bytes written to the buffer, or
                              the buffer size required if NULL passed.
    Description : Representation specific function to get the help text or
                  the buffer size required.
*/
size_t gadget_b::_get_help_message(char *help, size_t size) const
{
    NOT_USED(help);
    NOT_USED(size);
    return 0;
}

/*
    Parameters  : void
    Returns     : int   - The type of this gadget.
    Description : Representation specific function to get the type of this
                  gadget.
*/
int gadget_b::_get_type() const
{
    return 0;
}

/*
    Parameters  : bbox  - The new bounding box for this gadget.
    Returns     : void
    Description : Representation specific function to set the bounding box
                  of this gadget.
*/
void gadget_b::_set_bbox(const os_box &bbox)
{
    NOT_USED((os_box &) bbox);
}

/*
    Parameters  : void
    Returns     : os_box    - The bounding box of this gadget.
    Description : Representation specific function to get the bounding box
                  of this gadget.
*/
os_box gadget_b::_get_bbox() const
{
    os_box box;
    box.x0 = 0;
    box.y0 = 0;
    box.x1 = 0;
    box.y1 = 0;
    return box;
}
