/*
    File        : actionbutton_t.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent an action button field toolbox gadget
                  template.

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
#ifndef actionbutton_t_h
#define actionbutton_t_h

// Include alexlib header files
#ifndef actionbutton_b_h
#include "actionbutton_b.h"
#endif
#ifndef gadget_t_h
#include "gadget_t.h"
#endif
#ifndef gadget_w_show_t_h
#include "gadget_w_show_t.h"
#endif

// A class to represent an action button gadget template
class actionbutton_t : public virtual gadget_b,
                       public gadget_t,
                       public actionbutton_b,
                       public gadget_w_show_t
{
public:

    /*
        Parameters  : void
        Returns     : -
        Description : Constructor function.
    */
    actionbutton_t();

protected:

    /*
        Parameters  : event      - The toolbox event code.
        Returns     : void
        Description : Gadget specific function to set the toolbox event code
                      which will be raised for this gadget.
    */
    virtual void _set_event(bits event);

    /*
        Parameters  : void
        Returns     : bits  - The toolbox event code.
        Description : Gadget specific function to get the toolbox event code
                      which will be raised for this gadget.
    */
    virtual bits _get_event() const;

    /*
        Parameters  : text  - The text string to set.
        Returns     : void
        Description : Gadget specific function to set the text.
    */
    virtual void _set_text(const char *text);

    /*
        Parameters  : text      - Pointer to buffer to hold the text, or NULL
                                  to read the size of buffer required.
                      size      - The size of the buffer.
        Returns     : size_t    - Number of bytes written to the buffer, or
                                  the buffer size required if NULL passed.
        Description : Gadget specific function to get the text or the buffer
                      size required.
    */
    virtual size_t _get_text(char *text, size_t size) const;

    /*
        Parameters  : object    - The name of the object to show.
        Returns     : void
        Description : Gadget specific function to set the object to show.
    */
    virtual void _set_show(const char *object);

    /*
        Parameters  : object    - Pointer to buffer to hold the object name,
                                  or NULL to read the size of buffer required.
                      size      - The size of the buffer.
        Returns     : size_t    - Number of bytes written to the buffer, or
                                  the buffer size required if NULL passed.
        Description : Gadget specific function to get the object to show or
                      the buffer size required.
    */
    virtual size_t _get_show(char *object, size_t size) const;
};

#endif
