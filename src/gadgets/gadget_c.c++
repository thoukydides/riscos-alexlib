/*
    File        : gadget_c.c++
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a generic toolbox gadget.

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
#include "gadget_c.h"

/*
    Parameters  : void
    Returns     : vector<wimp_i>    - The icon list.
    Description : Get the list of Wimp icon numbers for the icons used to
                  implement this gadget.
*/
vector<wimp_i> gadget_c::get_icon_list() const
{
    size_t size = get_icon_list_size();
    size_t icons = size / sizeof(wimp_i);
    wimp_i *buffer = new wimp_i[icons];
    get_icon_list(buffer, size);
    vector<wimp_i> list(buffer, buffer + icons);
    delete[] buffer;

    return list;
}

/*
    Parameters  : help  - The help text.
    Returns     : void
    Description : Representation specific function to set the help text.
*/
void gadget_c::_set_help_message(const char *help)
{
    gadget_set_help_message(0, object, component, help);
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
size_t gadget_c::_get_help_message(char *help, size_t size) const
{
    return gadget_get_help_message(0, object, component, help, size);
}

/*
    Parameters  : bbox  - The new bounding box for this gadget.
    Returns     : void
    Description : Representation specific function to set the bounding box
                  of this gadget.
*/
void gadget_c::_set_bbox(const os_box &bbox)
{
    gadget_move_gadget(0, object, component, &bbox);
}

/*
    Parameters  : void
    Returns     : os_box    - The bounding box of this gadget.
    Description : Representation specific function to get the bounding box
                  of this gadget.
*/
os_box gadget_c::_get_bbox() const
{
    os_box bbox;

    gadget_get_bbox(0, object, component, &bbox);
    return bbox;
}
