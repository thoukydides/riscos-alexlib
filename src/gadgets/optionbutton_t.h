/*
    File        : optionbutton_t.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent an option button toolbox gadget template.

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
#ifndef optionbutton_t_h
#define optionbutton_t_h

// Include alexlib header files
#ifndef gadget_t_h
#include "gadget_t.h"
#endif
#ifndef optionbutton_b_h
#include "optionbutton_b.h"
#endif

// A class to represent an option button gadget template
class optionbutton_t : public virtual gadget_b,
                       public gadget_t,
                       public optionbutton_b
{
public:

    /*
        Parameters  : void
        Returns     : -
        Description : Constructor function.
    */
    optionbutton_t();

    /*
        Parameters  : value             - The value to set.
        Returns     : optionbutton_t    - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    optionbutton_t &operator=(bool value);

protected:

    /*
        Parameters  : value - The value to set.
        Returns     : void
        Description : Gadget specific function to set the value.
    */
    virtual void _set_value(bool value);

    /*
        Parameters  : void
        Returns     : bool  - The value
        Description : Gadget specific function to get the value.
    */
    virtual bool _get_value() const;

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
};

#endif
