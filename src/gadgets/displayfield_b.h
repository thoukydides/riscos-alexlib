/*
    File        : displayfield_b.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Base class to represent a display field toolbox gadget.

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
#ifndef displayfield_b_h
#define displayfield_b_h

// Include oslib header files
#include "oslib/displayfield.h"

// Include alexlib header files
#ifndef gadget_b_h
#include "gadget_b.h"
#endif
#ifndef gadget_w_justification_h
#include "gadget_w_justification.h"
#endif
#ifndef gadget_w_string_h
#include "gadget_w_string.h"
#endif

// A base class to represent a display field gadget
class displayfield_b : public virtual gadget_b,
                       public gadget_w_justification,
                       public gadget_w_string
{
public:

    /*
        Parameters  : value             - The text string to set.
        Returns     : displayfield_b    - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    displayfield_b &operator=(const char *value);

    /*
        Parameters  : value             - The text string to set.
        Returns     : displayfield_b    - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    displayfield_b &operator=(const string &value);

protected:

    /*
        Parameters  : position  - The field justification.
        Returns     : void
        Description : Gadget specific function to set the justification.
    */
    virtual void _set_justification(justification position);

    /*
        Parameters  : void
        Returns     : bool  - The field justification.
        Description : Gadget specific function to Get the justification.
    */
    virtual justification _get_justification() const;
};

#endif
