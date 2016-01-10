/*
    File        : gadget_c.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a generic toolbox gadget.

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
#ifndef gadget_c_h
#define gadget_c_h

// Include cpplib header files
#include "vector.h"

// Include alexlib header files
#ifndef gadget_b_h
#include "gadget_b.h"
#endif

// A class to represent a generic gadget
class gadget_c : public virtual gadget_b
{
public:

    // IDs for this gadget
    toolbox_o object;
    toolbox_c component;

    /*
        Parameters  : component - The component ID of this gadget.
                      object    - The object ID of this gadget's parent window.
        Returns     : -
        Description : Constructor function. This does not create a gadget; it
                      merely creates an object to represent the gadget.
    */
    gadget_c(toolbox_c component = toolbox_NULL_COMPONENT,
             toolbox_o object = toolbox_NULL_OBJECT);

    /*
        Parameters  : object    - The object ID of this gadget's parent window.
        Returns     : void
        Description : Set the object ID of this gadget's parent window.
    */
    void set_object(toolbox_o object = toolbox_NULL_OBJECT);

    /*
        Parameters  : void
        Returns     : toolbox_o - The object ID of this gadget's parent window.
        Description : Get the object ID of this gadget's parent window.
    */
    toolbox_o get_object() const;

    /*
        Parameters  : component - The component ID of this gadget.
        Returns     : void
        Description : Set the component ID of this gadget.
    */
    void set_component(toolbox_c component = toolbox_NULL_COMPONENT);

    /*
        Parameters  : void
        Returns     : toolbox_c - The component ID of this gadget.
        Description : Get the component ID of this gadget.
    */
    toolbox_c get_component() const;

    /*
        Parameters  : void
        Returns     : size_t    - The size of buffer required to hold the icon
                                  list.
        Description : Get the size of buffer required to read the icon list.
    */
    size_t get_icon_list_size() const;

    /*
        Parameters  : buffer    - Pointer to buffer to hold the icon list.
                      size      - The size of the buffer.
        Returns     : size_t    - The number of bytes written to the buffer.
        Description : Get the list of Wimp icon numbers for the icons used to
                      implement this gadget.
    */
    size_t get_icon_list(wimp_i *buffer, size_t size) const;

    /*
        Parameters  : void
        Returns     : vector<wimp_i>    - The icon list.
        Description : Get the list of Wimp icon numbers for the icons used to
                      implement this gadget.
    */
    vector<wimp_i> get_icon_list() const;

    /*
        Parameters  : void
        Returns     : void
        Description : Set the input focus to this gadget.
    */
    void set_focus();

protected:

    /*
        Parameters  : flags - The new flag settings.
        Returns     : void
        Description : Representation specific function to set the flags for
                      this gadget.
    */
    virtual void _set_flags(bits flags);

    /*
        Parameters  : void
        Returns     : gadget_flags  - The flag settings for this gadget.
        Description : Representation specific function to get the flags for
                      this gadget.
    */
    virtual gadget_flags _get_flags() const;

    /*
        Parameters  : help  - The help text.
        Returns     : void
        Description : Representation specific function to set the help text.
    */
    virtual void _set_help_message(const char *help);

    /*
        Parameters  : help      - Pointer to buffer to hold the help text, or
                                  NULL to read the size of buffer required.
                      size      - The size of the buffer.
        Returns     : size_t    - Number of bytes written to the buffer, or
                                  the buffer size required if NULL passed.
        Description : Representation specific function to get the help text or
                      the buffer size required.
    */
    virtual size_t _get_help_message(char *help, size_t size) const;

    /*
        Parameters  : void
        Returns     : int   - The type of this gadget.
        Description : Representation specific function to get the type of this
                      gadget.
    */
    virtual int _get_type() const;

    /*
        Parameters  : bbox  - The new bounding box for this gadget.
        Returns     : void
        Description : Representation specific function to set the bounding box
                      of this gadget.
    */
    virtual void _set_bbox(const os_box &bbox);

    /*
        Parameters  : void
        Returns     : os_box    - The bounding box of this gadget.
        Description : Representation specific function to get the bounding box
                      of this gadget.
    */
    virtual os_box _get_bbox() const;
};

/*
    Parameters  : component - The component ID of this gadget.
                  object    - The object ID of this gadget's parent window.
    Returns     : -
    Description : Constructor function. This does not create a gadget; it
                  merely creates an object to represent the gadget.
*/
inline gadget_c::gadget_c(toolbox_c component, toolbox_o object)
{
    gadget_c::object = object;
    gadget_c::component = component;
}

/*
    Parameters  : object    - The object ID of this gadget's parent window.
    Returns     : void
    Description : Set the object ID of this gadget's parent window.
*/
inline void gadget_c::set_object(toolbox_o object)
{
    gadget_c::object = object;
}

/*
    Parameters  : void
    Returns     : toolbox_o - The object ID of this gadget's parent window.
    Description : Get the object ID of this gadget's parent window.
*/
inline toolbox_o gadget_c::get_object() const
{
    return object;
}

/*
    Parameters  : component - The component ID of this gadget.
    Returns     : void
    Description : Set the component ID of this gadget.
*/
inline void gadget_c::set_component(toolbox_c component)
{
    gadget_c::component = component;
}

/*
    Parameters  : void
    Returns     : toolbox_c - The component ID of this gadget.
    Description : Get the component ID of this gadget.
*/
inline toolbox_c gadget_c::get_component() const
{
    return component;
}

/*
    Parameters  : void
    Returns     : size_t    - The size of buffer required to hold the icon
                              list.
    Description : Get the size of buffer required to read the icon list.
*/
inline size_t gadget_c::get_icon_list_size() const
{
    return gadget_get_icon_list(0, object, component, NULL, 0);
}

/*
    Parameters  : buffer    - Pointer to buffer to hold the icon list.
                  size      - The size of the buffer.
    Returns     : size_t    - The number of bytes written to the buffer.
    Description : Get the list of Wimp icon numbers for the icons used to
                  implement this gadget.
*/
inline size_t gadget_c::get_icon_list(wimp_i *buffer, size_t size) const
{
    return gadget_get_icon_list(0, object, component, buffer, size);
}

/*
    Parameters  : void
    Returns     : void
    Description : Set the input focus to this gadget.
*/
inline void gadget_c::set_focus()
{
    gadget_set_focus(0, object, component);
}

/*
    Parameters  : flags - The new flag settings.
    Returns     : void
    Description : Representation specific function to set the flags for
                  this gadget.
*/
inline void gadget_c::_set_flags(bits flags)
{
    gadget_set_flags(0, object, component, flags);
}

/*
    Parameters  : void
    Returns     : gadget_flags  - The flag settings for this gadget.
    Description : Representation specific function to get the flags for
                  this gadget.
*/
inline gadget_flags gadget_c::_get_flags() const
{
    return gadget_get_flags(0, object, component);
}

/*
    Parameters  : void
    Returns     : int   - The type of this gadget.
    Description : Representation specific function to get the type of this
                  gadget.
*/
inline int gadget_c::_get_type() const
{
    return gadget_get_type(0, object, component);
}

#endif
