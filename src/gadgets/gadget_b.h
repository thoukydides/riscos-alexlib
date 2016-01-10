/*
    File        : gadget_b.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Base class to represent a generic toolbox gadget.

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
#ifndef gadget_b_h
#define gadget_b_h

// Include cpplib header files
#include "string.h"

// Include oslib header files
#include "oslib/gadget.h"
#include "oslib/macros.h"

// A class to represent a generic gadget
class gadget_b
{
public:

    /*
        Parameters  : void
        Returns     : -
        Description : Destructor function.
    */
    virtual ~gadget_b();

    /*
        Parameters  : flags - The new flag settings.
        Returns     : void
        Description : Set the flags for this gadget.
    */
    void set_flags(bits flags = 0);

    /*
        Parameters  : void
        Returns     : gadget_flags  - The flag settings for this gadget.
        Description : Return the flag word for this gadget.
    */
    gadget_flags get_flags() const;

    /*
        Parameters  : faded     - The new faded state.
        Returns     : void
        Description : Set the faded state for this gadget.
    */
    void set_faded(bool faded = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - The faded state.
        Description : Get the faded state for this gadget.
    */
    bool get_faded() const;

    /*
        Parameters  : back  - The at back state.
        Returns     : void
        Description : Set the at back state for this gadget.
    */
    void set_at_back(bool back = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - The at back state.
        Description : Get the at back state for this gadget.
    */
    bool get_at_back() const;

    /*
        Parameters  : help  - The help message text.
        Returns     : void
        Description : Set the help message text for this gadget.
    */
    void set_help_message(const char *help);

    /*
        Parameters  : help  - The help message text.
        Returns     : void
        Description : Set the help message text for this gadget.
    */
    void set_help_message(const string &help);

    /*
        Parameters  : void
        Returns     : size_t    - The size of buffer required to hold the help
                                  message.
        Description : Get the size of buffer required to read the help message.
    */
    size_t get_help_message_size() const;

    /*
        Parameters  : help      - Pointer to buffer to hold the help text.
                      size      - The size of the buffer.
        Returns     : size_t    - Number of bytes written to the buffer.
        Description : Get the help message that is associated with this gadget.
    */
    size_t get_help_message(char *help, size_t size) const;

    /*
        Parameters  : void
        Returns     : string    - The help message.
        Description : Get the help message that is associated with this gadget.
    */
    string get_help_message() const;

    /*
        Parameters  : void
        Returns     : int   - The type of this gadget.
        Description : Get the type of this gadget.
    */
    int get_type() const;

    /*
        Parameters  : bbox  - The new bounding box for this gadget.
        Returns     : void
        Description : Set the bounding box of this gadget.
    */
    void set_bbox(const os_box &bbox);

    /*
        Parameters  : void
        Returns     : os_box    - The bounding box of this gadget.
        Description : Get the bounding box of this gadget.
    */
    os_box get_bbox() const;

protected:

    /*
        Parameters  : void
        Returns     : -
        Description : Protected constructor to prevent creation of abstract
                      base class.
    */
    gadget_b();

    /*
        Parameters  : flags - The new flag settings.
        Returns     : void
        Description : Representation specific function to set the flags for
                      this gadget.
    */
    virtual void _set_flags(bits flags);

    /*
        Parameters  : void
        Returns     : gadget_flags  - The flag settings for this gadget.
        Description : Representation specific function to get the flags for
                      this gadget.
    */
    virtual gadget_flags _get_flags() const;

    /*
        Parameters  : help  - The help text.
        Returns     : void
        Description : Representation specific function to set the help text.
    */
    virtual void _set_help_message(const char *help);

    /*
        Parameters  : help      - Pointer to buffer to hold the help text, or
                                  NULL to read the size of buffer required.
                      size      - The size of the buffer.
        Returns     : size_t    - Number of bytes written to the buffer, or
                                  the buffer size required if NULL passed.
        Description : Representation specific function to get the help text or
                      the buffer size required.
    */
    virtual size_t _get_help_message(char *help, size_t size) const;

    /*
        Parameters  : void
        Returns     : int   - The type of this gadget.
        Description : Representation specific function to get the type of this
                      gadget.
    */
    virtual int _get_type() const;

    /*
        Parameters  : bbox  - The new bounding box for this gadget.
        Returns     : void
        Description : Representation specific function to set the bounding box
                      of this gadget.
    */
    virtual void _set_bbox(const os_box &bbox);

    /*
        Parameters  : void
        Returns     : os_box    - The bounding box of this gadget.
        Description : Representation specific function to get the bounding box
                      of this gadget.
    */
    virtual os_box _get_bbox() const;
};

/*
    Parameters  : void
    Returns     : -
    Description : Destructor function.
*/
inline gadget_b::~gadget_b() {}

/*
    Parameters  : flags - The new flag settings.
    Returns     : void
    Description : Set the flags for this gadget.
*/
inline void gadget_b::set_flags(bits flags)
{
    _set_flags(flags);
}

/*
    Parameters  : void
    Returns     : gadget_flags  - The flag settings for this gadget.
    Description : Return the flag word for this gadget.
*/
inline gadget_flags gadget_b::get_flags() const
{
    return _get_flags();
}

/*
    Parameters  : faded     - The new faded state.
    Returns     : void
    Description : Set the faded state for this gadget.
*/
inline void gadget_b::set_faded(bool faded)
{
    gadget_flags flags = _get_flags();
    _set_flags(faded ? flags | gadget_FADED : flags & ~gadget_FADED);
}

/*
    Parameters  : void
    Returns     : bool  - The faded state.
    Description : Get the faded state for this gadget.
*/
inline bool gadget_b::get_faded() const
{
    return BOOL(_get_flags() & gadget_FADED);
}

/*
    Parameters  : back  - The at back state.
    Returns     : void
    Description : Set the at back state for this gadget.
*/
inline void gadget_b::set_at_back(bool back)
{
    gadget_flags flags = _get_flags();
    _set_flags(back ? flags | gadget_AT_BACK : flags & ~gadget_AT_BACK);
}

/*
    Parameters  : void
    Returns     : bool  - The at back state.
    Description : Get the at back state for this gadget.
*/
inline bool gadget_b::get_at_back() const
{
    return BOOL(_get_flags() & gadget_AT_BACK);
}

/*
    Parameters  : help  - The help message text.
    Returns     : void
    Description : Set the help message text for this gadget.
*/
inline void gadget_b::set_help_message(const char *help)
{
    _set_help_message(help);
}

/*
    Parameters  : help  - The help message text.
    Returns     : void
    Description : Set the help message text for this gadget.
*/
inline void gadget_b::set_help_message(const string &help)
{
    _set_help_message(help.c_str());
}

/*
    Parameters  : void
    Returns     : size_t    - The size of buffer required to hold the help
                              message.
    Description : Get the size of buffer required to read the help message.
*/
inline size_t gadget_b::get_help_message_size() const
{
    return _get_help_message(NULL, 0);
}

/*
    Parameters  : help      - Pointer to buffer to hold the help text.
                  size      - The size of the buffer.
    Returns     : size_t    - Number of bytes written to the buffer.
    Description : Get the help message that is associated with this gadget.
*/
inline size_t gadget_b::get_help_message(char *help, size_t size) const
{
    return _get_help_message(help, size);
}

/*
    Parameters  : void
    Returns     : int   - The type of this gadget.
    Description : Get the type of this gadget.
*/
inline int gadget_b::get_type() const
{
    return _get_type();
}

/*
    Parameters  : bbox  - The new bounding box for this gadget.
    Returns     : void
    Description : Set the bounding box of this gadget.
*/
inline void gadget_b::set_bbox(const os_box &bbox)
{
    _set_bbox(bbox);
}

/*
    Parameters  : void
    Returns     : os_box    - The bounding box of this gadget.
    Description : Get the bounding box of this gadget.
*/
inline os_box gadget_b::get_bbox() const
{
    return _get_bbox();
}

/*
    Parameters  : void
    Returns     : -
    Description : Protected constructor to prevent creation of abstract
                  base class.
*/
inline gadget_b::gadget_b() {}

#endif
