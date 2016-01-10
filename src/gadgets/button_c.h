/*
    File        : button_c.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a button toolbox gadget.

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
#ifndef button_c_h
#define button_c_h

// Include alexlib header files
#ifndef button_b_h
#include "button_b.h"
#endif
#ifndef gadget_c_h
#include "gadget_c.h"
#endif
#ifndef gadget_w_font_h
#include "gadget_w_font.h"
#endif

// A class to represent a button gadget
class button_c : public virtual gadget_b,
                 public gadget_c,
                 public button_b,
                 public gadget_w_font
{
public:

    /*
        Parameters  : component - The component ID of this button.
                      object    - The object ID of this button's parent
                                  window.
        Returns     : -
        Description : Constructor function. This does not create a button;
                      it merely creates an object to represent the button.
    */
    button_c(toolbox_c component = toolbox_NULL_COMPONENT,
             toolbox_o object = toolbox_NULL_OBJECT);

    /*
        Parameters  : value     - The text string to set.
        Returns     : button_c  - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    button_c &operator=(const char *value);

    /*
        Parameters  : value     - The text string to set.
        Returns     : button_c  - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    button_c &operator=(const string &value);

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
    Parameters  : component - The component ID of this button.
                  object    - The object ID of this button's parent
                              window.
    Returns     : -
    Description : Constructor function. This does not create a button;
                  it merely creates an object to represent the button.
*/
inline button_c::button_c(toolbox_c component, toolbox_o object)
: gadget_c(component, object) {}

#endif
