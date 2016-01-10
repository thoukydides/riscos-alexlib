/*
    File        : gadget_w_event.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a toolbox gadget that allows the event
                  code to be changed.

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
#ifndef gadget_w_event_h
#define gadget_w_event_h

// Include oslib header files
#include "oslib/types.h"

// A class to represent a gadget with a selectable event
class gadget_w_event
{
public:

    /*
        Parameters  : event      - The toolbox event code.
        Returns     : void
        Description : Set the toolbox event code which will be raised for this
                      gadget.
    */
    void set_event(bits event);

    /*
        Parameters  : void
        Returns     : bits  - The toolbox event code.
        Description : Get the toolbox event code which will be raised for this
                      gadget.
    */
    bits get_event() const;

protected:

    /*
        Parameters  : event      - The toolbox event code.
        Returns     : void
        Description : Gadget specific function to set the toolbox event code
                      which will be raised for this gadget.
    */
    virtual void _set_event(bits event) = 0;

    /*
        Parameters  : void
        Returns     : bits  - The toolbox event code.
        Description : Gadget specific function to get the toolbox event code
                      which will be raised for this gadget.
    */
    virtual bits _get_event() const = 0;
};

/*
    Parameters  : event      - The toolbox event code.
    Returns     : void
    Description : Set the toolbox event code which will be raised for this
                  gadget.
*/
inline void gadget_w_event::set_event(bits event)
{
    _set_event(event);
}

/*
    Parameters  : void
    Returns     : bits  - The toolbox event code.
    Description : Get the toolbox event code which will be raised for this
                  gadget.
*/
inline bits gadget_w_event::get_event() const
{
    return _get_event();
}

#endif
