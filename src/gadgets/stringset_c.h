/*
    File        : stringset_c.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a string set toolbox gadget.

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
#ifndef stringset_c_h
#define stringset_c_h

// Include alexlib header files
#ifndef gadget_c_h
#include "gadget_c.h"
#endif
#ifndef stringset_b_h
#include "stringset_b.h"
#endif

// A class to represent a string set gadget
class stringset_c : public virtual gadget_b,
                    public gadget_c,
                    public stringset_b
{
public:

    /*
        Parameters  : component - The component ID of this string set.
                      object    - The object ID of this string set's parent
                                  window.
        Returns     : -
        Description : Constructor function. This does not create a string set;
                      it merely creates an object to represent the string set.
    */
    stringset_c(toolbox_c component = toolbox_NULL_COMPONENT,
                toolbox_o object = toolbox_NULL_OBJECT);

    /*
        Parameters  : void
        Returns     : toolbox_c - The component ID.
        Description : Get the component ID of the alphanumeric component.
    */
    toolbox_c get_alphanumeric_component() const;

    /*
        Parameters  : void
        Returns     : toolbox_c - The component ID.
        Description : Get the component ID of the popup component.
    */
    toolbox_c get_popup_component() const;

    /*
        Parameters  : value         - The number to set.
        Returns     : stringset_c   - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    stringset_c &operator=(int value);

    /*
        Parameters  : value         - The text string to set.
        Returns     : stringset_c   - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    stringset_c &operator=(const char *value);

    /*
        Parameters  : value         - The text string to set.
        Returns     : stringset_c   - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    stringset_c &operator=(const string &value);

protected:

    /*
        Parameters  : allowed   - The new set of allowable characters, or NULL
                                  to allow all characters.
        Returns     : void
        Description : Gadget specific function to define the set of allowable
                      characters.
    */
    virtual void _set_allowable(const char *allowed);

    /*
        Parameters  : value - The number to set.
        Returns     : void
        Description : Gadget specific function to set the value.
    */
    virtual void _set_value(int value);

    /*
        Parameters  : void
        Returns     : int   - The value
        Description : Gadget specific function to get the value.
    */
    virtual int _get_value() const;

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
        Parameters  : available - The new list of available strings.
        Returns     : void
        Description : Representation specific function to define the available
                      set of strings.
    */
    virtual void _set_available(const char *available);
};

/*
    Parameters  : component - The component ID of this string set.
                  object    - The object ID of this string set's parent
                              window.
    Returns     : -
    Description : Constructor function. This does not create a string set;
                  it merely creates an object to represent the string set.
*/
inline stringset_c::stringset_c(toolbox_c component, toolbox_o object)
: gadget_c(component, object) {}

/*
    Parameters  : void
    Returns     : toolbox_c - The component ID.
    Description : Get the component ID of the alphanumeric component.
*/
inline toolbox_c stringset_c::get_alphanumeric_component() const
{
    toolbox_c alphanumeric;
    stringset_get_components(stringset_GET_ALPHANUMERIC_FIELD,
                             object, component,
                             &alphanumeric, NULL);
    return alphanumeric;
}

/*
    Parameters  : void
    Returns     : toolbox_c - The component ID.
    Description : Get the component ID of the popup component.
*/
inline toolbox_c stringset_c::get_popup_component() const
{
    toolbox_c popup;
    stringset_get_components(stringset_GET_POP_UP_MENU, object, component,
                             NULL, &popup);
    return popup;
}

#endif
