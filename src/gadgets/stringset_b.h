/*
    File        : stringset_b.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Base class to represent a string set toolbox gadget.

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
#ifndef stringset_b_h
#define stringset_b_h

// Include cpplib header files
#include "list.h"

// Include oslib header files
#include "oslib/stringset.h"

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
#ifndef gadget_w_number_h
#include "gadget_w_number.h"
#endif
#ifndef gadget_w_string_h
#include "gadget_w_string.h"
#endif

// A base class to represent a string set gadget
class stringset_b : public virtual gadget_b,
                    public gadget_w_allowable,
                    public gadget_w_justification,
                    public gadget_w_number,
                    public gadget_w_string
{
public:

    /*
        Parameters  : generate  - The generate event status.
        Returns     : void
        Description : Set the StringSet_ValueChanged event status.
    */
    void set_generate_value_changed(bool generate = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - The generate event status.
        Description : Get the StringSet_ValueChanged event status.
    */
    bool get_generate_value_changed() const;

    /*
        Parameters  : generate  - The generate event status.
        Returns     : void
        Description : Set the StringSet_SetValueChanged event status.
    */
    void set_generate_set_value_changed(bool generate = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - The generate event status.
        Description : Get the StringSet_SetValueChanged event status.
    */
    bool get_generate_set_value_changed() const;

    /*
        Parameters  : writable  - Is the field writable.
        Returns     : void
        Description : Set whether the numeric field is writable.
    */
    void set_writable(bool writable = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - Is the field writable.
        Description : Get whether the numeric field is writable.
    */
    bool get_writable() const;

    /*
        Parameters  : generate  - The generate event status.
        Returns     : void
        Description : Set the StringSet_AboutToBeShown event status.
    */
    void set_generate_about_to_be_shown(bool generate = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - The generate event status.
        Description : Get the StringSet_AboutToBeShown event status.
    */
    bool get_generate_about_to_be_shown() const;

    /*
        Parameters  : display   - Is there a display area.
        Returns     : void
        Description : Set whether there is a diplay area.
    */
    void set_has_display(bool display = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - Is there a display area.
        Description : Get whether there is a diplay area.
    */
    bool get_has_display() const;

    /*
        Parameters  : available - The new list of available strings.
        Returns     : void
        Description : Define the available set of strings.
    */
    void set_available(const char *available);

    /*
        Parameters  : available - The new list of available strings.
        Returns     : void
        Description : Define the available set of strings.
    */
    void set_available(const string &available);

    /*
        Parameters  : available - The new list of available strings.
        Returns     : void
        Description : Define the available set of strings.
    */
    void set_available(const list<string> &available);

    /*
        Parameters  : value         - The number to set.
        Returns     : stringset_b   - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    stringset_b &operator=(int value);

    /*
        Parameters  : value         - The text string to set.
        Returns     : stringset_b   - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    stringset_b &operator=(const char *value);

    /*
        Parameters  : value         - The text string to set.
        Returns     : stringset_b   - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    stringset_b &operator=(const string &value);

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

    /*
        Parameters  : available - The new list of available strings.
        Returns     : void
        Description : Representation specific function to define the available
                      set of strings.
    */
    virtual void _set_available(const char *available) = 0;
};

/*
    Parameters  : generate  - The generate event status.
    Returns     : void
    Description : Set the StringSet_ValueChanged event status.
*/
inline void stringset_b::set_generate_value_changed(bool generate)
{
    gadget_flags flags = _get_flags();
    _set_flags(generate
               ? flags | stringset_GENERATE_USER_VALUE_CHANGED
               : flags & ~stringset_GENERATE_USER_VALUE_CHANGED);
}

/*
    Parameters  : void
    Returns     : bool  - The generate event status.
    Description : Get the StringSet_ValueChanged event status.
*/
inline bool stringset_b::get_generate_value_changed() const
{
    return BOOL(_get_flags() & stringset_GENERATE_USER_VALUE_CHANGED);
}

/*
    Parameters  : generate  - The generate event status.
    Returns     : void
    Description : Set the StringSet_SetValueChanged event status.
*/
inline void stringset_b::set_generate_set_value_changed(bool generate)
{
    gadget_flags flags = _get_flags();
    _set_flags(generate
               ? flags | stringset_GENERATE_SET_VALUE_CHANGED
               : flags & ~stringset_GENERATE_SET_VALUE_CHANGED);
}

/*
    Parameters  : void
    Returns     : bool  - The generate event status.
    Description : Get the StringSet_SetValueChanged event status.
*/
inline bool stringset_b::get_generate_set_value_changed() const
{
    return BOOL(_get_flags() & stringset_GENERATE_SET_VALUE_CHANGED);
}

/*
    Parameters  : writable  - Is the field writable.
    Returns     : void
    Description : Set whether the numeric field is writable.
*/
inline void stringset_b::set_writable(bool writable)
{
    gadget_flags flags = _get_flags();
    _set_flags(writable
               ? flags | stringset_WRITABLE
               : flags & ~stringset_WRITABLE);
}

/*
    Parameters  : void
    Returns     : bool  - Is the field writable.
    Description : Get whether the numeric field is writable.
*/
inline bool stringset_b::get_writable() const
{
    return BOOL(_get_flags() & stringset_WRITABLE);
}

/*
    Parameters  : generate  - The generate event status.
    Returns     : void
    Description : Set the StringSet_AboutToBeShown event status.
*/
inline void stringset_b::set_generate_about_to_be_shown(bool generate)
{
    gadget_flags flags = _get_flags();
    _set_flags(generate
               ? flags | stringset_GENERATE_ABOUT_TO_BE_SHOWN
               : flags & ~stringset_GENERATE_ABOUT_TO_BE_SHOWN);
}

/*
    Parameters  : void
    Returns     : bool  - The generate event status.
    Description : Get the StringSet_AboutToBeShown event status.
*/
inline bool stringset_b::get_generate_about_to_be_shown() const
{
    return BOOL(_get_flags() & stringset_GENERATE_ABOUT_TO_BE_SHOWN);
}

/*
    Parameters  : display   - Is there a display area.
    Returns     : void
    Description : Set whether there is a diplay area.
*/
inline void stringset_b::set_has_display(bool display)
{
    gadget_flags flags = _get_flags();
    _set_flags(display
               ? flags & ~stringset_NO_DISPLAY
               : flags | stringset_NO_DISPLAY);
}

/*
    Parameters  : void
    Returns     : bool  - Is there a display area.
    Description : Get whether there is a diplay area.
*/
inline bool stringset_b::get_has_display() const
{
    return BOOL(!(_get_flags() & stringset_NO_DISPLAY));
}

/*
    Parameters  : available - The new list of available strings.
    Returns     : void
    Description : Define the available set of strings.
*/
inline void stringset_b::set_available(const char *available)
{
    _set_available(available);
}

/*
    Parameters  : available - The new list of available strings.
    Returns     : void
    Description : Define the available set of strings.
*/
inline void stringset_b::set_available(const string &available)
{
    _set_available(available.c_str());
}

#endif
