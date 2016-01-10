/*
    File        : draggable_c.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a draggable toolbox gadget.

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
#ifndef draggable_c_h
#define draggable_c_h

// Include alexlib header files
#ifndef draggable_b_h
#include "draggable_b.h"
#endif
#ifndef gadget_c_h
#include "gadget_c.h"
#endif
#ifndef gadget_w_boolean_h
#include "gadget_w_boolean.h"
#endif

// A class to represent a button gadget
class draggable_c : public virtual gadget_b,
                    public gadget_c,
                    public draggable_b,
                    public gadget_w_boolean
{
public:

    /*
        Parameters  : component - The component ID of this draggable gadget.
                      object    - The object ID of this draggable gadget's
                                  parent window.
        Returns     : -
        Description : Constructor function. This does not create a draggable
                      gadget; it merely creates an object to represent the
                      draggable gadget.
    */
    draggable_c(toolbox_c component = toolbox_NULL_COMPONENT,
                toolbox_o object = toolbox_NULL_OBJECT);

    /*
        Parameters  : value         - The value to set.
        Returns     : draggable_c   - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    draggable_c &operator=(bool value);

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

/*
    Parameters  : component - The component ID of this draggable gadget.
                  object    - The object ID of this draggable gadget's
                              parent window.
    Returns     : -
    Description : Constructor function. This does not create a draggable
                  gadget; it merely creates an object to represent the
                  draggable gadget.
*/
inline draggable_c::draggable_c(toolbox_c component, toolbox_o object)
: gadget_c(component, object) {}

#endif
