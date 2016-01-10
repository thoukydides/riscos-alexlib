/*
    File        : gadget_w_text.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a toolbox gadget that has an associated
                  text string.

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
#ifndef gadget_w_text_h
#define gadget_w_text_h

// Include cpplib header files
#include "string.h"

// A class to represent a gadget with a text string
class gadget_w_text
{
public:

    /*
        Parameters  : text  - The text string to set.
        Returns     : void
        Description : Set the text of this gadget.
    */
    void set_text(const char *text);

    /*
        Parameters  : text  - The text string to set.
        Returns     : void
        Description : Set the text of this gadget.
    */
    void set_text(const string &text);

    /*
        Parameters  : void
        Returns     : size_t    - The size of buffer required to hold the text.
        Description : Get the size of the buffer required to read the text.
    */
    size_t get_text_size() const;

    /*
        Parameters  : text      - Pointer to buffer to hold the text.
                      size      - The size of the buffer.
        Returns     : size_t    - Number of bytes written to the buffer.
        Description : Get the text of this gadget.
    */
    size_t get_text(char *text, size_t size) const;

    /*
        Parameters  : void
        Returns     : string    - The text.
        Description : Get the text of this gadget.
    */
    string get_text() const;

protected:

    /*
        Parameters  : text  - The text string to set.
        Returns     : void
        Description : Gadget specific function to set the text.
    */
    virtual void _set_text(const char *text) = 0;

    /*
        Parameters  : text      - Pointer to buffer to hold the text, or NULL
                                  to read the size of buffer required.
                      size      - The size of the buffer.
        Returns     : size_t    - Number of bytes written to the buffer, or
                                  the buffer size required if NULL passed.
        Description : Gadget specific function to get the text or the buffer
                      size required.
    */
    virtual size_t _get_text(char *text, size_t size) const = 0;
};

/*
    Parameters  : text  - The text string to set.
    Returns     : void
    Description : Set the text of this gadget.
*/
inline void gadget_w_text::set_text(const char *text)
{
    _set_text(text);
}

/*
    Parameters  : text  - The text string to set.
    Returns     : void
    Description : Set the text of this gadget.
*/
inline void gadget_w_text::set_text(const string &text)
{
    _set_text(text.c_str());
}

/*
    Parameters  : void
    Returns     : size_t    - The size of buffer required to hold the text.
    Description : Get the size of the buffer required to read the text.
*/
inline size_t gadget_w_text::get_text_size() const
{
    return _get_text(NULL, 0);
}

/*
    Parameters  : text      - Pointer to buffer to hold the text.
                  size      - The size of the buffer.
    Returns     : size_t    - Number of bytes written to the buffer.
    Description : Get the text of this gadget.
*/
inline size_t gadget_w_text::get_text(char *text, size_t size) const
{
    return _get_text(text, size);
}

#endif
