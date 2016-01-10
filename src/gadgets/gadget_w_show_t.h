/*
    File        : gadget_w_show_t.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a toolbox gadget template that allows
                  another object to be shown.

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
#ifndef gadget_w_show_t_h
#define gadget_w_show_t_h

// Include cpplib header files
#include "string.h"

// A class to represent a gadget template with a selectable event
class gadget_w_show_t
{
public:

    /*
        Parameters  : object    - The name of the object to show.
        Returns     : void
        Description : Set the object to show.
    */
    void set_show(const char *object);

    /*
        Parameters  : object    - The name of the object to show.
        Returns     : void
        Description : Set the object to show.
    */
    void set_show(const string &object);

    /*
        Parameters  : void
        Returns     : size_t    - The size of buffer required to hold the
                                  object name.
        Description : Get the size of the buffer required to read the object
                      to show.
    */
    size_t get_show_size() const;

    /*
        Parameters  : object    - Pointer to buffer to hold the object name.
                      size      - The size of the buffer.
        Returns     : size_t    - Number of bytes written to the buffer.
        Description : Get the object to show.
    */
    size_t get_show(char *object, size_t size) const;

    /*
        Parameters  : void
        Returns     : string    - The name of the object to show.
        Description : Get the object to show.
    */
    string get_show() const;

protected:

    /*
        Parameters  : object    - The name of the object to show.
        Returns     : void
        Description : Gadget specific function to set the object to show.
    */
    virtual void _set_show(const char *object) = 0;

    /*
        Parameters  : object    - Pointer to buffer to hold the object name,
                                  or NULL to read the size of buffer required.
                      size      - The size of the buffer.
        Returns     : size_t    - Number of bytes written to the buffer, or
                                  the buffer size required if NULL passed.
        Description : Gadget specific function to get the object to show or
                      the buffer size required.
    */
    virtual size_t _get_show(char *object, size_t size) const = 0;
};

/*
    Parameters  : object    - The name of the object to show.
    Returns     : void
    Description : Set the object to show.
*/
inline void gadget_w_show_t::set_show(const char *object)
{
    _set_show(object);
}

/*
    Parameters  : object    - The name of the object to show.
    Returns     : void
    Description : Set the object to show.
*/
inline void gadget_w_show_t::set_show(const string &object)
{
    _set_show(object.c_str());
}

/*
    Parameters  : void
    Returns     : size_t    - The size of buffer required to hold the
                              object name.
    Description : Get the size of the buffer required to read the object
                  to show.
*/
inline size_t gadget_w_show_t::get_show_size() const
{
    return _get_show(NULL, 0);
}

/*
    Parameters  : object    - Pointer to buffer to hold the object name.
                  size      - The size of the buffer.
    Returns     : size_t    - Number of bytes written to the buffer.
    Description : Get the object to show.
*/
inline size_t gadget_w_show_t::get_show(char *object, size_t size) const
{
    return _get_show(object, size);
}

#endif
