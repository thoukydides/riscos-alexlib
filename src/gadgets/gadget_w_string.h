/*
    File        : gadget_w_string.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a toolbox gadget that has a string value.

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
#ifndef gadget_w_string_h
#define gadget_w_string_h

// Include cpplib header files
#include "string.h"

// A class to represent a gadget with a string value
class gadget_w_string
{
public:

    /*
        Parameters  : value - The text string to set.
        Returns     : void
        Description : Set the value of this gadget.
    */
    void set_value(const char *value);

    /*
        Parameters  : value - The text string to set.
        Returns     : void
        Description : Set the value of this gadget.
    */
    void set_value(const string &value);

    /*
        Parameters  : value             - The text string to set.
        Returns     : gadget_w_string   - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    gadget_w_string &operator=(const char *value);

    /*
        Parameters  : value             - The text string to set.
        Returns     : gadget_w_string   - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    gadget_w_string &operator=(const string &value);

    /*
        Parameters  : void
        Returns     : size_t    - The size of buffer required to hold the value.
        Description : Get the size of the buffer required to read the value.
    */
    size_t get_value_size() const;

    /*
        Parameters  : value     - Pointer to buffer to hold the value.
                      size      - The size of the buffer.
        Returns     : size_t    - Number of bytes written to the buffer.
        Description : Get the value of this gadget.
    */
    size_t get_value(char *value, size_t size) const;

    /*
        Parameters  : void
        Returns     : string    - The value.
        Description : Get the value of this gadget.
    */
    string get_value() const;

    /*
        Parameters  : void
        Returns     : string    - The value.
        Description : Get the value of this gadget.
    */
    string operator()() const;

protected:

    /*
        Parameters  : value - The text string to set.
        Returns     : void
        Description : Gadget specific function to set the value.
    */
    virtual void _set_value(const char *value) = 0;

    /*
        Parameters  : value     - Pointer to buffer to hold the value, or NULL
                                  to read the size of buffer required.
                      size      - The size of the buffer.
        Returns     : size_t    - Number of bytes written to the buffer, or
                                  the buffer size required if NULL passed.
        Description : Gadget specific function to get the value or the buffer
                      size required.
    */
    virtual size_t _get_value(char *value, size_t size) const = 0;
};

/*
    Parameters  : value - The text string to set.
    Returns     : void
    Description : Set the value of this gadget.
*/
inline void gadget_w_string::set_value(const char *value)
{
    _set_value(value);
}

/*
    Parameters  : value - The text string to set.
    Returns     : void
    Description : Set the value of this gadget.
*/
inline void gadget_w_string::set_value(const string &value)
{
    _set_value(value.c_str());
}

/*
    Parameters  : value             - The text string to set.
    Returns     : gadget_w_string   - This object.
    Description : Set the value of this gadget. To reduce flicker the value
                  is not updated unless it has changed.
*/
inline gadget_w_string &gadget_w_string::operator=(const char *value)
{
    if (string(value) != get_value()) _set_value(value);
    return *this;
}

/*
    Parameters  : value             - The text string to set.
    Returns     : gadget_w_string   - This object.
    Description : Set the value of this gadget. To reduce flicker the value
                  is not updated unless it has changed.
*/
inline gadget_w_string &gadget_w_string::operator=(const string &value)
{
    if (value != get_value()) _set_value(value.c_str());
    return *this;
}

/*
    Parameters  : void
    Returns     : size_t    - The size of buffer required to hold the value.
    Description : Get the size of the buffer required to read the value.
*/
inline size_t gadget_w_string::get_value_size() const
{
    return _get_value(NULL, 0);
}

/*
    Parameters  : value     - Pointer to buffer to hold the value.
                  size      - The size of the buffer.
    Returns     : size_t    - Number of bytes written to the buffer.
    Description : Get the value of this gadget.
*/
inline size_t gadget_w_string::get_value(char *value, size_t size) const
{
    return _get_value(value, size);
}

/*
    Parameters  : void
    Returns     : string    - The value.
    Description : Get the value of this gadget.
*/
inline string gadget_w_string::operator()() const
{
    return get_value();
}

#endif
