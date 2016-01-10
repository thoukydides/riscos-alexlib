/*
    File        : displayfield_c.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a display field toolbox gadget template.

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
#ifndef displayfield_c_h
#define displayfield_c_h

// Include alexlib header files
#ifndef displayfield_b_h
#include "displayfield_b.h"
#endif
#ifndef gadget_t_h
#include "gadget_t.h"
#endif

// A class to represent a display field gadget template
class displayfield_t : public virtual gadget_b,
                       public gadget_t,
                       public displayfield_b
{
public:

    /*
        Parameters  : void
        Returns     : -
        Description : Constructor function.
    */
    displayfield_t();

    /*
        Parameters  : value             - The text string to set.
        Returns     : displayfield_t    - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    displayfield_t &operator=(const char *value);

    /*
        Parameters  : value             - The text string to set.
        Returns     : displayfield_t    - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    displayfield_t &operator=(const string &value);

protected:

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
