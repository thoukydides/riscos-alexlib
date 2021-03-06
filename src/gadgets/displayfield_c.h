/*
    File        : displayfield_c.h
    Date        : 19-Sep-02
    Author      : � A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a display field toolbox gadget.

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
#ifndef gadget_c_h
#include "gadget_c.h"
#endif
#ifndef gadget_w_font_h
#include "gadget_w_font.h"
#endif

// A class to represent a display field gadget
class displayfield_c : public virtual gadget_b,
                       public gadget_c,
                       public displayfield_b,
                       public gadget_w_font
{
public:

    /*
        Parameters  : component - The component ID of this display field.
                      object    - The object ID of this display field's parent
                                  window.
        Returns     : -
        Description : Constructor function. This does not create a
                      display field; it merely creates an object to represent
                      the display field.
    */
    displayfield_c(toolbox_c component = toolbox_NULL_COMPONENT,
                   toolbox_o object = toolbox_NULL_OBJECT);

    /*
        Parameters  : value             - The text string to set.
        Returns     : displayfield_c    - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    displayfield_c &operator=(const char *value);

    /*
        Parameters  : value             - The text string to set.
        Returns     : displayfield_c    - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    displayfield_c &operator=(const string &value);

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

    /*
        Parameters  : font  - The name of the font to use, or NULL to use the
                              system font.
                      xsize - The width in 16ths of a point.
                      ysize - The height in 16ths of a point.
        Returns     : void
        Description : Gadget specific function to set the font.
    */
    virtual void _set_font(const char *font, int xsize, int ysize);
};

/*
    Parameters  : component - The component ID of this display field.
                  object    - The object ID of this display field's parent
                              window.
    Returns     : -
    Description : Constructor function. This does not create a
                  display field; it merely creates an object to represent
                  the display field.
*/
inline displayfield_c::displayfield_c(toolbox_c component, toolbox_o object)
: gadget_c(component, object) {}

#endif
