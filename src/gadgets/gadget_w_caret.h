/*
    File        : gadget_w_caret.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a toolbox gadget that allows the writable
                  fields before and after it to be changed.

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
#ifndef gadget_w_caret_h
#define gadget_w_caret_h

// Include oslib header files
#include "oslib/gadget.h"
#include "oslib/macros.h"

// A class to represent a gadget with selectable before and after fields
class gadget_w_caret
{
public:

    /*
        Parameters  : component - The component ID of the previous field.
        Returns     : void
        Description : Set the component ID of the writable field before this
                      one.
    */
    void set_before(toolbox_c component = toolbox_NULL_COMPONENT);

    /*
        Parameters  : void
        Returns     : toolbox_c - The component ID of the previous field.
        Description : Get the component ID of the writable field before this
                      one.
    */
    toolbox_c get_before() const;

    /*
        Parameters  : component - The component ID of the next field.
        Returns     : void
        Description : Set the component ID of the writable field after this
                      one.
    */
    void set_after(toolbox_c component = toolbox_NULL_COMPONENT);

    /*
        Parameters  : void
        Returns     : toolbox_c - The component ID of the next field.
        Description : Get the component ID of the writable field after this
                      one.
    */
    toolbox_c get_after() const;

protected:

    /*
        Parameters  : component - The component ID of the previous field.
        Returns     : void
        Description : Set the component ID of the writable field before this
                      one.
    */
    virtual void _set_before(toolbox_c component) = 0;

    /*
        Parameters  : void
        Returns     : toolbox_c - The component ID of the previous field.
        Description : Get the component ID of the writable field before this
                      one.
    */
    virtual toolbox_c _get_before() const = 0;

    /*
        Parameters  : component - The component ID of the next field.
        Returns     : void
        Description : Set the component ID of the writable field after this
                      one.
    */
    virtual void _set_after(toolbox_c component) = 0;

    /*
        Parameters  : void
        Returns     : toolbox_c - The component ID of the next field.
        Description : Get the component ID of the writable field after this
                      one.
    */
    virtual toolbox_c _get_after() const = 0;
};

/*
    Parameters  : component - The component ID of the previous field.
    Returns     : void
    Description : Set the component ID of the writable field before this
                  one.
*/
inline void gadget_w_caret::set_before(toolbox_c component)
{
    _set_before(component);
}

/*
    Parameters  : void
    Returns     : toolbox_c - The component ID of the previous field.
    Description : Get the component ID of the writable field before this
                  one.
*/
inline toolbox_c gadget_w_caret::get_before() const
{
    return _get_before();
}

/*
    Parameters  : component - The component ID of the next field.
    Returns     : void
    Description : Set the component ID of the writable field after this
                  one.
*/
inline void gadget_w_caret::set_after(toolbox_c component)
{
    _set_after(component);
}

/*
    Parameters  : void
    Returns     : toolbox_c - The component ID of the next field.
    Description : Get the component ID of the writable field after this
                  one.
*/
inline toolbox_c gadget_w_caret::get_after() const
{
    return _get_after();
}

#endif
