/*
    File        : labelledbox_b.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Base class to represent a labelled box toolbox gadget.

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
#ifndef labelledbox_b_h
#define labelledbox_b_h

// Include oslib header files
#include "oslib/labelledbox.h"

// Include alexlib header files
#ifndef gadget_b_h
#include "gadget_b.h"
#endif

// A base class to represent a label gadget
class labelledbox_b : virtual public gadget_b
{
public:

    /*
        Parameters  : sprite    - Is the label a sprite.
        Returns     : void
        Description : Set whether the labelled box has a sprite label.
    */
    void set_has_sprite(bool sprite = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - Is the label a sprite.
        Description : Get whether the labelled box has a sprite label.
    */
    bool get_has_sprite() const;

    /*
        Parameters  : filled    - Does the label have a filled background.
        Returns     : void
        Description : Set whether the label has a filled background.
    */
    void set_is_filled(bool filled = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - Does the label have a filled background.
        Description : Get whether the label has a filled background.
    */
    bool get_is_filled() const;
};

/*
    Parameters  : sprite    - Is the label a sprite.
    Returns     : void
    Description : Set whether the labelled box has a sprite label.
*/
inline void labelledbox_b::set_has_sprite(bool sprite)
{
    gadget_flags flags = _get_flags();
    _set_flags(sprite
               ? flags | labelledbox_SPRITE
               : flags & ~labelledbox_SPRITE);
}

/*
    Parameters  : void
    Returns     : bool  - Is the label a sprite.
    Description : Get whether the labelled box has a sprite label.
*/
inline bool labelledbox_b::get_has_sprite() const
{
    return BOOL(_get_flags() & labelledbox_SPRITE);
}

/*
    Parameters  : filled    - Does the label have a filled background.
    Returns     : void
    Description : Set whether the label has a filled background.
*/
inline void labelledbox_b::set_is_filled(bool filled)
{
    gadget_flags flags = _get_flags();
    _set_flags(filled
               ? flags | labelledbox_SPRITE_IS_FILLED
               : flags & ~labelledbox_SPRITE_IS_FILLED);
}

/*
    Parameters  : void
    Returns     : bool  - Does the label have a filled background.
    Description : Get whether the label has a filled background.
*/
inline bool labelledbox_b::get_is_filled() const
{
    return BOOL(_get_flags() & labelledbox_SPRITE_IS_FILLED);
}

#endif
