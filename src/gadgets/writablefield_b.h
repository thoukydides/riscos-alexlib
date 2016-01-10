/*
    File        : writablefield_b.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Base class to represent a writable field toolbox gadget.

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
#ifndef writablefield_b_h
#define writablefield_b_h

// Include oslib header files
#include "oslib/writablefield.h"

// Include alexlib header files
#ifndef gadget_b_h
#include "gadget_b.h"
#endif
#ifndef gadget_w_allowable_h
#include "gadget_w_allowable.h"
#endif
#ifndef gadget_w_justification_h
#include "gadget_w_justification.h"
#endif
#ifndef gadget_w_string_h
#include "gadget_w_string.h"
#endif

// A base class to represent a writable field gadget
class writablefield_b : public virtual gadget_b,
                        public gadget_w_allowable,
                        public gadget_w_justification,
                        public gadget_w_string
{
public:

    /*
        Parameters  : generate  - The generate event status.
        Returns     : void
        Description : Set the WritableField_ValueChanged event status.
    */
    void set_generate_value_changed(bool generate = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - The generate event status.
        Description : Get the WritableField_ValueChanged event status.
    */
    bool get_generate_value_changed() const;

    /*
        Parameters  : conceal   - The conceal text status.
        Returns     : void
        Description : Set the conceal text status for this writable field.
    */
    void set_conceal_text(bool conceal = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - The conceal text status.
        Description : Get the conceal text status for this writable field.
    */
    bool get_conceal_text() const;

    /*
        Parameters  : value             - The text string to set.
        Returns     : writablefield_b   - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    writablefield_b &operator=(const char *value);

    /*
        Parameters  : value             - The text string to set.
        Returns     : writablefield_b   - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    writablefield_b &operator=(const string &value);

protected:

    /*
        Parameters  : position  - The field justification.
        Returns     : void
        Description : Gadget specific function to set the justification.
    */
    virtual void _set_justification(justification position);

    /*
        Parameters  : void
        Returns     : bool  - The field justification.
        Description : Gadget specific function to Get the justification.
    */
    virtual justification _get_justification() const;
};

/*
    Parameters  : generate  - The generate event status.
    Returns     : void
    Description : Set the WritableField_ValueChanged event status.
*/
inline void writablefield_b::set_generate_value_changed(bool generate)
{
    gadget_flags flags = _get_flags();
    _set_flags(generate
               ? flags | writablefield_GENERATE_USER_VALUE_CHANGED
               : flags & ~writablefield_GENERATE_USER_VALUE_CHANGED);
}

/*
    Parameters  : void
    Returns     : bool  - The generate event status.
    Description : Get the WritableField_ValueChanged event status.
*/
inline bool writablefield_b::get_generate_value_changed() const
{
    return BOOL(_get_flags() & writablefield_GENERATE_USER_VALUE_CHANGED);
}

/*
    Parameters  : conceal   - The conceal text status.
    Returns     : void
    Description : Set the conceal text status for this writable field.
*/
inline void writablefield_b::set_conceal_text(bool conceal)
{
    gadget_flags flags = _get_flags();
    _set_flags(conceal
               ? flags | writablefield_CONCEAL_TEXT
               : flags & ~writablefield_CONCEAL_TEXT);
}

/*
    Parameters  : void
    Returns     : bool  - The conceal text status.
    Description : Get the conceal text status for this writable field.
*/
inline bool writablefield_b::get_conceal_text() const
{
    return BOOL(_get_flags() & writablefield_CONCEAL_TEXT);
}

#endif
