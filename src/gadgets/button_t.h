/*
    File        : button_t.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a button toolbox gadget template.

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
#ifndef button_t_h
#define button_t_h

// Include alexlib header files
#ifndef button_b_h
#include "button_b.h"
#endif
#ifndef gadget_t_h
#include "gadget_t.h"
#endif

// A class to represent a button gadget template
class button_t : public virtual gadget_b,
                 public gadget_t,
                 public button_b
{
public:

    /*
        Parameters  : void
        Returns     : -
        Description : Constructor function.
    */
    button_t();

    /*
        Parameters  : value     - The text string to set.
        Returns     : button_t  - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    button_t &operator=(const char *value);

    /*
        Parameters  : value     - The text string to set.
        Returns     : button_t  - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    button_t &operator=(const string &value);

protected:

    /*
        Parameters  : clear - Icon flags to clear.
                      eor   - Icon flags to toggle.
        Returns     : void
        Description : Representation specific function to set the icon flags
                      for this button.
    */
    virtual void _set_icon_flags(wimp_icon_flags clear, wimp_icon_flags eor);

    /*
        Parameters  : void
        Returns     : wimp_icon_flags   - The current icon flags.
        Description : Representation specific function to get the icon flags
                      for this button.
    */
    virtual wimp_icon_flags _get_icon_flags() const;

    /*
        Parameters  : validation    - The text string to set.
        Returns     : void
        Description : Representation specific function to set the validation
                      string.
    */
    virtual void _set_validation(const char *validation);

    /*
        Parameters  : validation    - Pointer to buffer to hold the validation
                                      string, or NULL to read the size of
                                      buffer required.
                      size          - The size of the buffer.
        Returns     : size_t        - Number of bytes written to the buffer, or
                                      the buffer size required if NULL passed.
        Description : Representation specific function to get the validation
                      string or the buffer size required.
    */
    virtual size_t _get_validation(char *validation, size_t size) const;

    /*
        Parameters  : value - The text string to set.
        Returns     : void
        Description : Gadget specific function to set the value.
    */
    virtual void _set_value(const char *value);

    /*
        Parameters  : value     - Pointer to buffer to hold the value, or NULL
                                  to read the size of buffer required.
                      size      - The size of the buffer.
        Returns     : size_t    - Number of bytes written to the buffer, or
                                  the buffer size required if NULL passed.
        Description : Gadget specific function to get the value or the buffer
                      size required.
    */
    virtual size_t _get_value(char *value, size_t size) const;
};

#endif
