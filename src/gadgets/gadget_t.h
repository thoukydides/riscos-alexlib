/*
    File        : gadget_t.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a generic toolbox gadget template.

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
#ifndef gadget_t_h
#define gadget_t_h

// Include alexlib header files
#ifndef gadget_b_h
#include "gadget_b.h"
#endif

// A class to represent a generic gadget template
class gadget_t : public virtual gadget_b
{
public:

#if 0

    /*
        Constructors need to allocate a block of memory for help_message
        and set help_limit appropriately.
        class_no and size should be set to the correct constants.
        By default component ID should be -1 (toolbox_NULL_COMPONENT)

        Need to provide mechanism to read/write component ID
    */

    /*
        Parameters  : header    - Pointer to a gadget template structure.
                      size      - Optional size of the gadget object. If
                                  omitted then the size field in the header
                                  must be correct.
        Returns     : -
        Description : Constructor function.
    */
    gadget_t(const gadget_object *header, size_t size = 0);

    /*
        Parameters  : header    - Gadget template to base this on.
        Returns     : -
        Description : Constructor function.
    */
    gadget_t(const gadget_t &header);

    /*
        Parameters  : void
        Returns     : -
        Description : Destructor function.
    */
    virtual ~gadget_t();

    /*
        Parameters  : header            - Gadget template to assign.
        Returns     : gadget_t & - The modified template.
        Description : Assign another gadget template.
    */
    gadget_t &operator=(const gadget_t &header);

    /*
        Parameters  : void
        Returns     : gadget_t * - Pointer to a new gadget template.
        Description : Clone this gadget template.
    */
    virtual gadget_t *clone() const;

    /*
        Parameters  : void
        Returns     : gadget_object *   - Pointer to the corresponding
                                          gadget object. This pointer will
                                          remain valid until this object
                                          is destroyed.
        Description : Conversion to a pointer to a gadget object.
    */
    operator (const gadget_object *)();

    /*
        Parameters  : limit - Maximum help message size including terminator.
        Returns     : void
        Description : Set the maximum help message length.
    */
    void set_help_message_limit(size_t limit);

    /*
        Parameters  : void
        Returns     : size_t    - Maximum help message size including
                                  terminator.
        Description : Get the maximum help message length.
    */
    size_t get_help_message_limit() const;

protected:

    // Details for this gadget
    gadget_object *header;

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

private:

    /*
        Parameters  : header    - Pointer to a gadget template structure,
                                  or NULL to create a default gadget.
                      size      - Size of the gadget object.
        Returns     : void
        Description : Allocate a block of memory for the gadget template, and
                      either copy the supplied structure or create a default.
    */
    void _create(const gadget_object *header, size_t size);

    /*
        Parameters  : void
        Returns     : void
        Description : Deallocate the block of memory used for the gadget
                      template.
    */
    void _destroy();

#endif

};

#if 0

/*
    Parameters  : header    - Pointer to a gadget template structure.
                  size      - Optional size of the gadget object. If
                              omitted then the size field in the header
                              must be correct.
    Returns     : -
    Description : Constructor function.
*/
inline gadget_t::gadget_t(const gadget_object *header,
                                        size_t size)
{
    _create(header, size ? size : header->size);
}

/*
    Parameters  : header    - Gadget template to base this on.
    Returns     : -
    Description : Constructor function.
*/
inline gadget_t::gadget_t(const gadget_t &header)
{
    _create(header.header, header.header->size);
}

/*
    Parameters  : void
    Returns     : -
    Description : Destructor function.
*/
inline gadget_t::~gadget_t()
{
    _destroy();
}

/*
    Parameters  : header            - Gadget template to assign.
    Returns     : gadget_t & - The modified template.
    Description : Assign another gadget template.
*/
inline gadget_t &gadget_t::operator=(const gadget_t &header)
{
    _destroy();
    _create(header.header, header.header->size);
    return *this;
}

/*
    Parameters  : void
    Returns     : gadget_t * - Pointer to a new gadget template.
    Description : Clone this gadget template.
*/
inline gadget_t *gadget_t::clone() const
{
    return new gadget_t(*this);
}

/*
    Parameters  : limit - Maximum help message size including terminator.
    Returns     : void
    Description : Set the maximum help message length.
*/
inline void gadget_t::set_help_message_limit(size_t limit)
{
    if (limit < 1) limit = 1;
    char *ptr = new char[limit];
    if (ptr)
    {
        strncpy(ptr, header->help_message, limit - 1);
        ptr[limit - 1] = '\0';
        delete[] header->help_message;
        header->help_message = ptr;
        header->help_limit = limit;
    }
}

/*
    Parameters  : void
    Returns     : size_t    - Maximum help message size including
                              terminator.
    Description : Get the maximum help message length.
*/
inline size_t gadget_t::get_help_message_limit() const
{
    return header->help_limit;
}

/*
    Parameters  : flags - The new flag settings.
    Returns     : void
    Description : Representation specific function to set the flags for
                  this gadget.
*/
inline void gadget_t::_set_flags(bits flags)
{
    header->flags = flags;
}

/*
    Parameters  : void
    Returns     : gadget_flags  - The flag settings for this gadget.
    Description : Representation specific function to get the flags for
                  this gadget.
*/
inline gadget_flags gadget_t::_get_flags() const
{
    return header->flags;
}

/*
    Parameters  : help  - The help text.
    Returns     : void
    Description : Representation specific function to set the help text.
*/
inline void gadget_t::_set_help_message(const char *help)
{
    NOT_USED(help);
    /*
    // Constructor from window block will need to copy any help text buffers
    // Also need to update help_limit
    delete[] header->help_message;
    if (help)
    {
        header->help_message = new char[strlen(help) + 1];
        // Should throw an error if memory allocation failed
        strcpy(header->help_message, help);
    }
    else header->help_message = NULL;
    */
}

/*
    Parameters  : help      - Pointer to buffer to hold the help text, or
                              NULL to read the size of buffer required.
                  size      - The size of the buffer.
    Returns     : size_t    - Number of bytes written to the buffer, or
                              the buffer size required if NULL passed.
    Description : Representation specific function to get the help text or
                  the buffer size required.
*/
inline size_t gadget_t::_get_help_message(char *help, size_t size) const
{
    size_t req = header->help_message ? strlen(header->help_message) + 1 : 1;
    if (help)
    {
        if (req < size) size = req;
        if (1 < size) strncpy(help, header->help_message, size - 1);
        if (size) help[size - 1] = '\0';
    }
    return req;
}

/*
    Parameters  : void
    Returns     : int   - The type of this gadget.
    Description : Representation specific function to get the type of this
                  gadget.
*/
inline int gadget_t::_get_type() const
{
    return header->class_no;
}

/*
    Parameters  : bbox  - The new bounding box for this gadget.
    Returns     : void
    Description : Representation specific function to set the bounding box
                  of this gadget.
*/
inline void gadget_t::_set_bbox(const os_box &bbox)
{
    header->bbox = bbox;
}

/*
    Parameters  : void
    Returns     : os_box    - The bounding box of this gadget.
    Description : Representation specific function to get the bounding box
                  of this gadget.
*/
inline os_box gadget_t::_get_bbox() const
{
    return header->bbox;
}

inline void gadget_t::_default(toolbox_c class_no, size_t size)
{
    header->flags = 0;
    header->class_no = class_no;
    header->size = size;
    header->bbox.x0 = header->bbox.y0 = header->bbox.x1 = header->bbox.y1 = 0;
    header->cmp = toolbox_NULL_COMPONENT;
    header->help_message = NULL;
    header->help_limit = 0;
    _add_string(&header->help_message, &header->help_limit);
}

/*
    Parameters  : header    - Pointer to a gadget template structure,
                              or NULL to create a default gadget.
                  size      - Size of the gadget object.
    Returns     : void
    Description : Allocate a block of memory for the gadget template, and
                  either copy the supplied structure or create a default.
*/
inline void gadget_t::_create(const gadget_object *header, size_t size)
{
    gadget_t::header = (gadget_object *) new char[size];
    if (header) memcpy(gadget_t::header, header, size);
    else
    {
        gadget_t::flags = 0;
        gadget_t::class_no = 0; // Can't have this!
        gadget_t::
    }
}

/*
    Parameters  : void
    Returns     : void
    Description : Deallocate the block of memory used for the gadget
                  template.
*/
inline void gadget_t::_destroy()
{
    delete[] (char *) header;
}

#endif

#endif
