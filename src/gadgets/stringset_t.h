/*
    File        : stringset_t.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a string set toolbox gadget template.

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
#ifndef stringset_t_h
#define stringset_t_h

// Include alexlib header files
#ifndef gadget_t_h
#include "gadget_t.h"
#endif
#ifndef gadget_w_caret_h
#include "gadget_w_caret.h"
#endif
#ifndef stringset_b_h
#include "stringset_b.h"
#endif

// A class to represent a string set gadget template
class stringset_t : public virtual gadget_b,
                    public gadget_t,
                    public stringset_b,
                    public gadget_w_caret
{
public:

    /*
        Parameters  : void
        Returns     : -
        Description : Constructor function.
    */
    stringset_t();

    /*
        Parameters  : value         - The number to set.
        Returns     : stringset_t   - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    stringset_t &operator=(int value);

    /*
        Parameters  : value         - The text string to set.
        Returns     : stringset_t   - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    stringset_t &operator=(const char *value);

    /*
        Parameters  : value         - The text string to set.
        Returns     : stringset_t   - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    stringset_t &operator=(const string &value);

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

    /*
        Parameters  : component - The component ID of the previous field.
        Returns     : void
        Description : Set the component ID of the writable field before this
                      one.
    */
    virtual void _set_before(toolbox_c component);

    /*
        Parameters  : void
        Returns     : toolbox_c - The component ID of the previous field.
        Description : Get the component ID of the writable field before this
                      one.
    */
    virtual toolbox_c _get_before() const;

    /*
        Parameters  : component - The component ID of the next field.
        Returns     : void
        Description : Set the component ID of the writable field after this
                      one.
    */
    virtual void _set_after(toolbox_c component);

    /*
        Parameters  : void
        Returns     : toolbox_c - The component ID of the next field.
        Description : Get the component ID of the writable field after this
                      one.
    */
    virtual toolbox_c _get_after() const;
};

#endif
