/*
    File        : labelledbox_t.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a labelled box toolbox gadget template.

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
#ifndef labelledbox_t_h
#define labelledbox_t_h

// Include alexlib header files
#ifndef gadget_t_h
#include "gadget_t.h"
#endif
#ifndef gadget_w_text_h
#include "gadget_w_text.h"
#endif
#ifndef labelledbox_b_h
#include "labelledbox_b.h"
#endif

// A class to represent a label gadget
class labelledbox_t : virtual public gadget_b,
                      public gadget_t,
                      public labelledbox_b,
                      public gadget_w_text
{
public:

    /*
        Parameters  : void
        Returns     : -
        Description : Constructor function.
    */
    labelledbox_t();

protected:

    /*
        Parameters  : void
        Returns     : -
        Description : Dummy pure virtual function for an abstract base class.
    */
    virtual void _abstract() const;

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
