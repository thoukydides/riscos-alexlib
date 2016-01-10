/*
    File        : object_c.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a generic object gadget.

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
#ifndef object_c_h
#define object_c_h

// Include cpplib header files
#include "string.h"

// Include oslib header files
#include "oslib/toolbox.h"
#include "oslib/macros.h"

// Include alexlib header files
#ifndef object_b_h
#include "object_b.h"
#endif

// A class to represent a generic gadget
class object_c : public virtual object_b
{
public:

    // IDs for this object
    toolbox_o object;

    /*
        Parameters  : object    - The ID of this object.
        Returns     : -
        Description : Constructor function. This does not create an object; it
                      merely creates an object to represent the object.
    */
    object_c(toolbox_o object = toolbox_NULL_OBJECT);

    /*
        Parameters  : object    - The ID of this object.
        Returns     : object_c  - This object.
        Description : Set the ID of this object.
    */
    object_c &operator=(toolbox_o object);

    /*
        Parameters  : void
        Returns     : object_c  - The ID of this object.
        Description : Conversion to an object ID.
    */
    operator object_c() const;

    /*
        Parameters  : name      - The name of the template to base this object
                                  on.
        Returns     : toolbox_o - The ID of the new object.
        Description : Create a new toolbox object based on the specified
                      template.
    */
    toolbox_o void create(const char *name);

    /*
        Parameters  : name      - The name of the template to base this object
                                  on.
        Returns     : toolbox_o - The ID of the new object.
        Description : Create a new toolbox object based on the specified
                      template.
    */
    toolbox_o void create(string name);

    /*
        Parameters  : name      - The name of the template to base this object
                                  on.
        Returns     : toolbox_o - The ID of the new object.
        Description : Create a new toolbox object based on the specified
                      template.
    */
    toolbox_o create(gadget_t &description);

    void destroy(bool recurse = TRUE);

    /*
        Parameters  :
        Returns     :
        Description :
    */
    void show(toolbox_show_flags flags = 0,
              toolbox_position_tag tag = toolbox_POSITION_DEFAULT,
              const toolbox_position &position = NULL,
              toolbox_o parent_obj = toolbox_NULL_OBJECT,
              toolbox_c parent_cmp = toolbox_NULL_COMPONENT);

    // Add a position class... with derived types for each variant

    /*
        Parameters  : void
        Returns     : void
        Description : Remove this object from the screen if it is currently
                      being shown.
    */
    void hide();

    /*
        Parameters  : void
        Returns     : toolbox_info  - The current state.
        Description : Get the state of this object.
    */
    toolbox_info get_info() const;

    /*
        Parameters  : void
        Returns     : bool  - Is the object currently showing.
        Description : Get whether this object is visible.
    */
    bool get_is_showing() const;

    void set_handle(void *handle = NULL);
    void *get_handle() const;

    toolbox_class get_class() const;

    component_c get_parent() const;
    toolbox_o get_parent_object() const;
    toolbox_c get_parent_component() const;
    component_c get_ancestor() const;
    toolbox_o get_ancestor_object() const;
    toolbox_c get_ancestor_component() const;

    /*
        Parameters  : void
        Returns     : size_t    - The size of buffer required to hold the
                                  template name.
        Description : Get the size of the buffer required to read the template
                      name.
    */
    size_t get_template_name_size() const;

    /*
        Parameters  : name      - Pointer to buffer to hold the template name.
                      size      - The size of the buffer.
        Returns     : size_t    - Number of bytes written to the buffer.
        Description : Get the template name of this object.
    */
    size_t get_template_name(char *name, size_t size) const;

    /*
        Parameters  : void
        Returns     : string    - The template name.
        Description : Get the template name of this object.
    */
    string get_template_name() const;

    void raise_event(const toolbox_action &action);
};

/*
    Parameters  : object    - The ID of this object.
    Returns     : -
    Description : Constructor function. This does not create an object; it
                  merely creates an object to represent the object.
*/
inline object_c::object_c(toolbox_o object)
{
    object_c::object = object;
}

/*
    Parameters  : object    - The ID of this object.
    Returns     : object_c  - This object.
    Description : Set the ID of this object.
*/
inline object_c &object_c::operator=(toolbox_o object)
{
    object_c::object = object;
    return *this;
}

/*
    Parameters  : void
    Returns     : object_c  - The ID of this object.
    Description : Conversion to an object ID.
*/
inline object_c::operator object_c() const
{
    return object;
}

#endif
