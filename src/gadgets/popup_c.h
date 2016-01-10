/*
    File        : popup_c.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a popup toolbox gadget.

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
#ifndef popup_c_h
#define popup_c_h

// Include alexlib header files
#ifndef popup_b_h
#include "popup_b.h"
#endif
#ifndef gadget_c_h
#include "gadget_c.h"
#endif
#ifndef gadget_w_show_c_h
#include "gadget_w_show_c.h"
#endif

// A class to represent a popup gadget
class popup_c : public virtual gadget_b,
                public gadget_c,
                public popup_b,
                public gadget_w_show_c
{
public:

    /*
        Parameters  : component - The component ID of this popup.
                      object    - The object ID of this popup's parent window.
        Returns     : -
        Description : Constructor function. This does not create a popup;
                      it merely creates an object to represent the popup.
    */
    popup_c(toolbox_c component = toolbox_NULL_COMPONENT,
            toolbox_o object = toolbox_NULL_OBJECT);

protected:

    /*
        Parameters  : object    - The object to show.
        Returns     : void
        Description : Gadget specific function to set the object to show.
    */
    virtual void _set_show(toolbox_o object);

    /*
        Parameters  : void
        Returns     : toolbox_o - The object to show.
        Description : Gadget specific function to get the object to show.
    */
    virtual toolbox_o _get_show() const;
};

/*
    Parameters  : component - The component ID of this popup.
                  object    - The object ID of this popup's parent window.
    Returns     : -
    Description : Constructor function. This does not create a popup;
                  it merely creates an object to represent the popup.
*/
inline popup_c::popup_c(toolbox_c component, toolbox_o object)
: gadget_c(component, object) {}

/*
    Parameters  : object    - The object to show.
    Returns     : void
    Description : Gadget specific function to set the object to show.
*/
inline void popup_c::_set_show(toolbox_o object)
{
    popup_set_menu(0, popup_c::object, component, object);
}

/*
    Parameters  : void
    Returns     : toolbox_o - The object to show.
    Description : Gadget specific function to get the object to show.
*/
inline toolbox_o popup_c::_get_show() const
{
    return popup_get_menu(0, object, component);
}

#endif
