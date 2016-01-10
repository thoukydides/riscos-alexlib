/*
    File        : draggable_b.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Base class to represent a draggable toolbox gadget.

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
#ifndef draggable_b_h
#define draggable_b_h

// Include oslib header files
#include "oslib/draggable.h"

// Include alexlib header files
#ifndef gadget_b_h
#include "gadget_b.h"
#endif
#ifndef gadget_w_text_h
#include "gadget_w_text.h"
#endif

// A class to represent a button gadget
class draggable_b : public virtual gadget_b,
                    public gadget_w_text
{
public:

    // Possible drag types
    enum drag_type
    {
        drag,
        click_drag,
        click_double_drag
    };

    /*
        Parameters  : generate  - The generate event status.
        Returns     : void
        Description : Set the Draggable_DragStarted event status.
    */
    void set_generate_drag_started(bool generate = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - The generate event status.
        Description : Get the Draggable_DragStarted event status.
    */
    bool get_generate_drag_started() const;

    /*
        Parameters  : sprite    - Does the draggable gadget contain a sprite.
        Returns     : void
        Description : Set the contains sprite status for this draggable gadget.
    */
    void set_contains_sprite(bool sprite = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - Does the draggable gadget contain a sprite.
        Description : Get the contains sprite status for this draggable gadget.
    */
    bool get_contains_sprite() const;

    /*
        Parameters  : text  - Does the draggable gadget contain text.
        Returns     : void
        Description : Set the contains text status for this draggable gadget.
    */
    void set_contains_text(bool text = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - Does the draggable gadget contain text.
        Description : Get the contains text status for this draggable gadget.
    */
    bool get_contains_text() const;

    /*
        Parameters  : type  - The draggable type.
        Returns     : void
        Description : Set the draggable type of this draggable gadget.
    */
    void set_draggable_type(drag_type type = drag);

    /*
        Parameters  : void
        Returns     : drag_type - The draggable type.
        Description : Get the draggable type of this draggable gadget.
    */
    drag_type get_draggable_type() const;

    /*
        Parameters  : toolbox   - Are toolbox IDs used instead of Wimp windows.
        Returns     : void
        Description : Set whether drag ended events are delivered as Toolbox
                      IDs rather than Wimp windows for this draggable gadget.
    */
    void set_use_toolbox_ids(bool toolbox = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - Are toolbox IDs used instead of Wimp windows.
        Description : Get whether drag ended events are delivered as Toolbox
                      IDs rather than Wimp windows for this draggable gadget.
    */
    bool get_use_toolbox_ids() const;

    /*
        Parameters  : shadow    - Does the dragged object have a drop shadow.
        Returns     : void
        Description : Set whether the dragged object has a drop shadow.
    */
    void set_has_shadow(bool shadow = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - Does the dragged object have a drop shadow.
        Description : Get whether the dragged object has a drop shadow.
    */
    bool get_has_shadow() const;

    /*
        Parameters  : dithered  - Is the dragged object dithered.
        Returns     : void
        Description : Set whether the dragged object is dithered.
    */
    void set_is_dithered(bool dithered = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - Is the dragged object dithered.
        Description : Get whether the dragged object is dithered.
    */
    bool get_is_dithered() const;

    /*
        Parameters  : sprite    - The sprite name.
        Returns     : void
        Description : Set the sprite name for this draggable gadget.
    */
    void set_sprite(const char *sprite);

    /*
        Parameters  : sprite    - The sprite name.
        Returns     : void
        Description : Set the sprite name for this button.
    */
    void set_sprite(const string &sprite);

    /*
        Parameters  : void
        Returns     : size_t    - The size of buffer required to hold the
                                  sprite name.
        Description : Get the size of buffer required to read the sprite name.
    */
    size_t get_sprite_size() const;

    /*
        Parameters  : sprite    - Pointer to buffer to hold the sprite name.
                      size      - The size of the buffer.
        Returns     : size_t    - Number of bytes written to the buffer.
        Description : Get the sprite name for this gadget.
    */
    size_t get_sprite(char *sprite, size_t size) const;

    /*
        Parameters  : void
        Returns     : string    - The sprite name.
        Description : Get the sprite name for this gadget.
    */
    string get_sprite() const;

protected:

    /*
        Parameters  : sprite    - The sprite name.
        Returns     : void
        Description : Representation specific function to set the sprite name.
    */
    virtual void _set_sprite(const char *sprite) = 0;

    /*
        Parameters  : sprite    - Pointer to buffer to hold the sprite name,
                                  or NULL to read the size of buffer required.
                      size      - The size of the buffer.
        Returns     : size_t    - Number of bytes written to the buffer, or
                                  the buffer size required if NULL passed.
        Description : Representation specific function to get the sprite name
                      or the buffer size required.
    */
    virtual size_t _get_sprite(char *sprite, size_t size) const = 0;
};

/*
    Parameters  : generate  - The generate event status.
    Returns     : void
    Description : Set the Draggable_DragStarted event status.
*/
inline void draggable_b::set_generate_drag_started(bool generate)
{
    gadget_flags flags = _get_flags();
    _set_flags(generate
               ? flags | draggable_GENERATE_DRAG_STARTED
               : flags & ~draggable_GENERATE_DRAG_STARTED);
}

/*
    Parameters  : void
    Returns     : bool  - The generate event status.
    Description : Get the Draggable_DragStarted event status.
*/
inline bool draggable_b::get_generate_drag_started() const
{
    return BOOL(_get_flags() & draggable_GENERATE_DRAG_STARTED);
}

/*
    Parameters  : sprite    - Does the draggable gadget contain a sprite.
    Returns     : void
    Description : Set the contains sprite status for this draggable gadget.
*/
inline void draggable_b::set_contains_sprite(bool sprite)
{
    gadget_flags flags = _get_flags();
    _set_flags(sprite
               ? flags | draggable_SPRITE
               : flags & ~draggable_SPRITE);
}

/*
    Parameters  : void
    Returns     : bool  - Does the draggable gadget contain a sprite.
    Description : Get the contains sprite status for this draggable gadget.
*/
inline bool draggable_b::get_contains_sprite() const
{
    return BOOL(_get_flags() & draggable_SPRITE);
}

/*
    Parameters  : text  - Does the draggable gadget contain text.
    Returns     : void
    Description : Set the contains text status for this draggable gadget.
*/
inline void draggable_b::set_contains_text(bool text)
{
    gadget_flags flags = _get_flags();
    _set_flags(text
               ? flags | draggable_TEXT
               : flags & ~draggable_TEXT);
}

/*
    Parameters  : void
    Returns     : bool  - Does the draggable gadget contain text.
    Description : Get the contains text status for this draggable gadget.
*/
inline bool draggable_b::get_contains_text() const
{
    return BOOL(_get_flags() & draggable_TEXT);
}

/*
    Parameters  : type  - The draggable type.
    Returns     : void
    Description : Set the draggable type of this draggable gadget.
*/
inline void draggable_b::set_draggable_type(drag_type type)
{
    gadget_flags flags = _get_flags()
                         & ~((draggable_TYPE_CLICK_DRAG
                              | draggable_TYPE_CLICK_DOUBLE_DRAG)
                             << draggable_TYPE_SHIFT);
    if (type == click_drag)
    {
        flags |= draggable_TYPE_CLICK_DRAG << draggable_TYPE_SHIFT;
    }
    else if (type == click_double_drag)
    {
        flags |= draggable_TYPE_CLICK_DOUBLE_DRAG << draggable_TYPE_SHIFT;
    }
    _set_flags(flags);
}

/*
    Parameters  : void
    Returns     : drag_type - The draggable type.
    Description : Get the draggable type of this draggable gadget.
*/
inline draggable_b::drag_type draggable_b::get_draggable_type() const
{
    gadget_flags flags = _get_flags() >> draggable_TYPE_SHIFT;
    return  flags & draggable_TYPE_CLICK_DRAG
            ? click_drag
            : (flags & draggable_TYPE_CLICK_DOUBLE_DRAG
               ? click_double_drag : drag);
}

/*
    Parameters  : toolbox   - Are toolbox IDs used instead of Wimp windows.
    Returns     : void
    Description : Set whether drag ended events are delivered as Toolbox
                  IDs rather than Wimp windows for this draggable gadget.
*/
inline void draggable_b::set_use_toolbox_ids(bool toolbox)
{
    gadget_flags flags = _get_flags();
    _set_flags(toolbox
               ? flags | draggable_USE_TOOLBOX_IDS
               : flags & ~draggable_USE_TOOLBOX_IDS);
}

/*
    Parameters  : void
    Returns     : bool  - Are toolbox IDs used instead of Wimp windows.
    Description : Get whether drag ended events are delivered as Toolbox
                  IDs rather than Wimp windows for this draggable gadget.
*/
inline bool draggable_b::get_use_toolbox_ids() const
{
    return BOOL(_get_flags() & draggable_USE_TOOLBOX_IDS);
}

/*
    Parameters  : shadow    - Does the dragged object have a drop shadow.
    Returns     : void
    Description : Set whether the dragged object has a drop shadow.
*/
inline void draggable_b::set_has_shadow(bool shadow)
{
    gadget_flags flags = _get_flags();
    _set_flags(shadow
               ? flags | draggable_DROP_SHADOW
               : flags & ~draggable_DROP_SHADOW);
}

/*
    Parameters  : void
    Returns     : bool  - Does the dragged object have a drop shadow.
    Description : Get whether the dragged object has a drop shadow.
*/
inline bool draggable_b::get_has_shadow() const
{
    return BOOL(_get_flags() & draggable_DROP_SHADOW);
}

/*
    Parameters  : dithered  - Is the dragged object dithered.
    Returns     : void
    Description : Set whether the dragged object is dithered.
*/
inline void draggable_b::set_is_dithered(bool dithered)
{
    gadget_flags flags = _get_flags();
    _set_flags(!dithered
               ? flags | draggable_NO_DITHER
               : flags & ~draggable_NO_DITHER);
}

/*
    Parameters  : void
    Returns     : bool  - Is the dragged object dithered.
    Description : Get whether the dragged object is dithered.
*/
inline bool draggable_b::get_is_dithered() const
{
    return BOOL(!(_get_flags() & draggable_NO_DITHER));
}

/*
    Parameters  : sprite    - The sprite name.
    Returns     : void
    Description : Set the sprite name for this draggable gadget.
*/
inline void draggable_b::set_sprite(const char *sprite)
{
    _set_sprite(sprite);
}

/*
    Parameters  : sprite    - The sprite name.
    Returns     : void
    Description : Set the sprite name for this button.
*/
inline void draggable_b::set_sprite(const string &sprite)
{
    _set_sprite(sprite.c_str());
}

/*
    Parameters  : void
    Returns     : size_t    - The size of buffer required to hold the
                              sprite name.
    Description : Get the size of buffer required to read the sprite name.
*/
inline size_t draggable_b::get_sprite_size() const
{
    return _get_sprite(NULL, 0);
}

/*
    Parameters  : sprite    - Pointer to buffer to hold the sprite name.
                  size      - The size of the buffer.
    Returns     : size_t    - Number of bytes written to the buffer.
    Description : Get the sprite name for this gadget.
*/
inline size_t draggable_b::get_sprite(char *sprite, size_t size) const
{
    return _get_sprite(sprite, size);
}

#endif
