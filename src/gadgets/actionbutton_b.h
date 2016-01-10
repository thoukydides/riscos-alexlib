/*
    File        : actionbutton_b.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Base class to represent an action button toolbox gadget.

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
#ifndef actionbutton_b_h
#define actionbutton_b_h

// Include oslib header files
#include "oslib/actionbutton.h"

// Include alexlib header files
#ifndef gadget_b_h
#include "gadget_b.h"
#endif
#ifndef gadget_w_event_h
#include "gadget_w_event.h"
#endif
#ifndef gadget_w_text_h
#include "gadget_w_text.h"
#endif

// A base class to represent an action button gadget
class actionbutton_b : public virtual gadget_b,
                       public gadget_w_event,
                       public gadget_w_text
{
public:

    /*
        Parameters  : def   - The Default action button status.
        Returns     : void
        Description : Set the Default status for this action button.
    */
    void set_is_default(bool def = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - The Default action button status.
        Description : Get the Default status for this action button.
    */
    bool get_is_default() const;

    /*
        Parameters  : cancel    - The Cancel action button status.
        Returns     : void
        Description : Set the Cancel status for this action button.
    */
    void set_is_cancel(bool cancel = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - The Cancel action button status.
        Description : Get the Cancel status for this action button.
    */
    bool get_is_cancel() const;

    /*
        Parameters  : local     - The Local action button status.
        Returns     : void
        Description : Set the Local status for this action button.
    */
    void set_is_local(bool local = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - The Local action button status.
        Description : Get the Local status for this action button.
    */
    bool get_is_local() const;

    /*
        Parameters  : menu  - The menu semantics status.
        Returns     : void
        Description : Set the menu sematics status for this action button.
    */
    void set_is_menu(bool menu = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - The menu semantics status.
        Description : Get the menu semantics status for this action button.
    */
    bool get_is_menu() const;
};

/*
    Parameters  : def   - The Default action button status.
    Returns     : void
    Description : Set the Default status for this action button.
*/
inline void actionbutton_b::set_is_default(bool def)
{
    gadget_flags flags = _get_flags();
    _set_flags(def
               ? flags | actionbutton_IS_DEFAULT
               : flags & ~actionbutton_IS_DEFAULT);
}

/*
    Parameters  : void
    Returns     : bool  - The Default action button status.
    Description : Get the Default status for this action button.
*/
inline bool actionbutton_b::get_is_default() const
{
    return BOOL(_get_flags() & actionbutton_IS_DEFAULT);
}

/*
    Parameters  : cancel    - The Cancel action button status.
    Returns     : void
    Description : Set the Cancel status for this action button.
*/
inline void actionbutton_b::set_is_cancel(bool cancel)
{
    gadget_flags flags = _get_flags();
    _set_flags(cancel
               ? flags | actionbutton_IS_CANCEL
               : flags & ~actionbutton_IS_CANCEL);
}

/*
    Parameters  : void
    Returns     : bool  - The Cancel action button status.
    Description : Get the Cancel status for this action button.
*/
inline bool actionbutton_b::get_is_cancel() const
{
    return BOOL(_get_flags() & actionbutton_IS_CANCEL);
}

/*
    Parameters  : local     - The Local action button status.
    Returns     : void
    Description : Set the Local status for this action button.
*/
inline void actionbutton_b::set_is_local(bool local)
{
    gadget_flags flags = _get_flags();
    _set_flags(local
               ? flags | actionbutton_IS_LOCAL
               : flags & ~actionbutton_IS_LOCAL);
}

/*
    Parameters  : void
    Returns     : bool  - The Local action button status.
    Description : Get the Local status for this action button.
*/
inline bool actionbutton_b::get_is_local() const
{
    return BOOL(_get_flags() & actionbutton_IS_LOCAL);
}

/*
    Parameters  : menu  - The menu semantics status.
    Returns     : void
    Description : Set the menu sematics status for this action button.
*/
inline void actionbutton_b::set_is_menu(bool menu)
{
    gadget_flags flags = _get_flags();
    _set_flags(menu
               ? flags | actionbutton_IS_MENU
               : flags & ~actionbutton_IS_MENU);
}

/*
    Parameters  : void
    Returns     : bool  - The menu semantics status.
    Description : Get the menu semantics status for this action button.
*/
inline bool actionbutton_b::get_is_menu() const
{
    return BOOL(_get_flags() & actionbutton_IS_MENU);
}

#endif
