/*
    File        : button_b.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Base class to represent a button toolbox gadget.

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
#ifndef button_b_h
#define button_b_h

// Include oslib header files
#include "oslib/button.h"
#include "oslib/wimp.h"

// Include alexlib header files
#ifndef gadget_b_h
#include "gadget_b.h"
#endif
#ifndef gadget_w_string_h
#include "gadget_w_string.h"
#endif

// A base class to represent a button gadget
class button_b : public virtual gadget_b,
                 public gadget_w_string
{
public:

    /*
        Parameters  : task  - Should the task's sprite area be used instead
                              of the Wimp sprite pool.
        Returns     : void
        Description : Set the task sprite area status for this button.
    */
    void set_task_sprite_area(bool task = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - The task sprite area status.
        Description : Get the task sprite area status for this button.
    */
    bool get_task_sprite_area() const;

    /*
        Parameters  : menu  - The return menu clicks status.
        Returns     : void
        Description : Set the return menu clicks status for this button.
    */
    void set_allow_menu_clicks(bool menu = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - The return menu clicks status.
        Description : Get the return menu clicks status for this button.
    */
    bool get_allow_menu_clicks() const;

    /*
        Parameters  : clear - Icon flags to clear.
                      eor   - Icon flags to toggle.
        Returns     : void
        Description : Set the icon flags for this button.
    */
    void set_icon_flags(wimp_icon_flags clear, wimp_icon_flags eor);

    /*
        Parameters  : void
        Returns     : wimp_icon_flags   - The current icon flags.
        Description : Get the icon flags for this button.
    */
    wimp_icon_flags get_icon_flags() const;

    /*
        Parameters  : validation    - The validation string.
        Returns     : void
        Description : Set the validation string for this button.
    */
    void set_validation(const char *validation);

    /*
        Parameters  : validation    - The validation string.
        Returns     : void
        Description : Set the validation string for this button.
    */
    void set_validation(const string &validation);

    /*
        Parameters  : void
        Returns     : size_t    - The size of buffer required to hold the
                                  validation string.
        Description : Get the size of buffer required to read the validation
                      string.
    */
    size_t get_validation_size() const;

    /*
        Parameters  : validation    - Pointer to buffer to hold the validation
                                      string.
                      size          - The size of the buffer.
        Returns     : size_t        - Number of bytes written to the buffer.
        Description : Get the validation string for this gadget.
    */
    size_t get_validation(char *validation, size_t size) const;

    /*
        Parameters  : void
        Returns     : string    - The validation string.
        Description : Get the validation string for this gadget.
    */
    string get_validation() const;

    /*
        Parameters  : value     - The text string to set.
        Returns     : button_b  - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    button_b &operator=(const char *value);

    /*
        Parameters  : value     - The text string to set.
        Returns     : button_b  - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    button_b &operator=(const string &value);

protected:

    /*
        Parameters  : clear - Icon flags to clear.
                      eor   - Icon flags to toggle.
        Returns     : void
        Description : Representation specific function to set the icon flags
                      for this button.
    */
    virtual void _set_icon_flags(wimp_icon_flags clear,
                                 wimp_icon_flags eor) = 0;

    /*
        Parameters  : void
        Returns     : wimp_icon_flags   - The current icon flags.
        Description : Representation specific function to get the icon flags
                      for this button.
    */
    virtual wimp_icon_flags _get_icon_flags() const = 0;

    /*
        Parameters  : validation    - The text string to set.
        Returns     : void
        Description : Representation specific function to set the validation
                      string.
    */
    virtual void _set_validation(const char *validation) = 0;

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
    virtual size_t _get_validation(char *validation, size_t size) const = 0;
};

/*
    Parameters  : task  - Should the task's sprite area be used instead
                          of the Wimp sprite pool.
    Returns     : void
    Description : Set the task sprite area status for this button.
*/
inline void button_b::set_task_sprite_area(bool task)
{
    gadget_flags flags = _get_flags();
    _set_flags(task
               ? flags | button_TASK_SPRITE_AREA
               : flags & ~button_TASK_SPRITE_AREA);
}

/*
    Parameters  : void
    Returns     : bool  - The task sprite area status.
    Description : Get the task sprite area status for this button.
*/
inline bool button_b::get_task_sprite_area() const
{
    return BOOL(_get_flags() & button_TASK_SPRITE_AREA);
}

/*
    Parameters  : menu  - The return menu clicks status.
    Returns     : void
    Description : Set the return menu clicks status for this button.
*/
inline void button_b::set_allow_menu_clicks(bool menu)
{
    gadget_flags flags = _get_flags();
    _set_flags(menu
               ? flags | button_ALLOW_MENU_CLICKS
               : flags & ~button_ALLOW_MENU_CLICKS);
}

/*
    Parameters  : void
    Returns     : bool  - The return menu clicks status.
    Description : Get the return menu clicks status for this button.
*/
inline bool button_b::get_allow_menu_clicks() const
{
    return BOOL(_get_flags() & button_ALLOW_MENU_CLICKS);
}

/*
    Parameters  : clear - Icon flags to clear.
                  eor   - Icon flags to toggle.
    Returns     : void
    Description : Set the icon flags for this button.
*/
inline void button_b::set_icon_flags(wimp_icon_flags clear,
                                        wimp_icon_flags eor)
{
    _set_icon_flags(clear, eor);
}

/*
    Parameters  : void
    Returns     : wimp_icon_flags   - The current icon flags.
    Description : Get the icon flags for this button.
*/
inline wimp_icon_flags button_b::get_icon_flags() const
{
    return _get_icon_flags();
}

/*
    Parameters  : validation    - The validation string.
    Returns     : void
    Description : Set the validation string for this button.
*/
inline void button_b::set_validation(const char *validation)
{
    _set_validation(validation);
}

/*
    Parameters  : validation    - The validation string.
    Returns     : void
    Description : Set the validation string for this button.
*/
inline void button_b::set_validation(const string &validation)
{
    _set_validation(validation.c_str());
}

/*
    Parameters  : void
    Returns     : size_t    - The size of buffer required to hold the
                              validation string.
    Description : Get the size of buffer required to read the validation
                  string.
*/
inline size_t button_b::get_validation_size() const
{
    return _get_validation(NULL, 0);
}

/*
    Parameters  : validation    - Pointer to buffer to hold the validation
                                  string.
                  size          - The size of the buffer.
    Returns     : size_t        - Number of bytes written to the buffer.
    Description : Get the validation string for this gadget.
*/
inline size_t button_b::get_validation(char *validation, size_t size) const
{
    return _get_validation(validation, size);
}

#endif
