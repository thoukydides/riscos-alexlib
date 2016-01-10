/*
    File        : gadget_w_show_c.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a toolbox gadget that allows another
                  object to be shown.

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

// Only include header file once
#ifndef gadget_w_show_c_h
#define gadget_w_show_c_h

// Include oslib header files
#include "oslib/gadget.h"

// A class to represent a gadget with a selectable event
class gadget_w_show_c
{
public:

    /*
        Parameters  : object    - The object to show.
        Returns     : void
        Description : Set the object to show.
    */
    void set_show(toolbox_o object = toolbox_NULL_OBJECT);

    /*
        Parameters  : void
        Returns     : toolbox_o - The object to show.
        Description : Get the object to show.
    */
    toolbox_o get_show() const;

protected:

    /*
        Parameters  : object    - The object to show.
        Returns     : void
        Description : Gadget specific function to set the object to show.
    */
    virtual void _set_show(toolbox_o object) = 0;

    /*
        Parameters  : void
        Returns     : toolbox_o - The object to show.
        Description : Gadget specific function to get the object to show.
    */
    virtual toolbox_o _get_show() const = 0;
};

/*
    Parameters  : object    - The object to show.
    Returns     : void
    Description : Set the object to show.
*/
inline void gadget_w_show_c::set_show(toolbox_o object)
{
    _set_show(object);
}

/*
    Parameters  : void
    Returns     : toolbox_o - The object to show.
    Description : Get the object to show.
*/
inline toolbox_o gadget_w_show_c::get_show() const
{
    return _get_show();
}

#endif
