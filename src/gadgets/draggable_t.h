/*
    File        : draggable_t.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a draggable toolbox gadget template.

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
#ifndef draggable_t_h
#define draggable_t_h

// Include alexlib header files
#ifndef draggable_b_h
#include "draggable_b.h"
#endif
#ifndef gadget_t_h
#include "gadget_t.h"
#endif

// A class to represent a button gadget template
class draggable_t : public virtual gadget_b,
                    public gadget_t,
                    public draggable_b
{
public:

    /*
        Parameters  : void
        Returns     : -
        Description : Constructor function.
    */
    draggable_t();

protected:

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
        Parameters  : sprite    - The sprite name.
        Returns     : void
        Description : Representation specific function to set the sprite name.
    */
    virtual void _set_sprite(const char *sprite);

    /*
        Parameters  : sprite    - Pointer to buffer to hold the sprite name,
                                  or NULL to read the size of buffer required.
                      size      - The size of the buffer.
        Returns     : size_t    - Number of bytes written to the buffer, or
                                  the buffer size required if NULL passed.
        Description : Representation specific function to get the sprite name
                      or the buffer size required.
    */
    virtual size_t _get_sprite(char *sprite, size_t size) const;
};

#endif
