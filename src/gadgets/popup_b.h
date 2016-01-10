/*
    File        : popup_b.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Base class to represent a popup toolbox gadget.

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
#ifndef popup_b_h
#define popup_b_h

// Include oslib header files
#include "oslib/popup.h"

// Include alexlib header files
#ifndef gadget_b_h
#include "gadget_b.h"
#endif

// A base class to represent a popup gadget
class popup_b : public virtual gadget_b
{
public:

    /*
        Parameters  : generate  - The generate event status.
        Returns     : void
        Description : Set the PopUp_AboutToBeShown event status.
    */
    void set_generate_about_to_be_shown(bool generate = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - The generate event status.
        Description : Get the PopUp_AboutToBeShown event status.
    */
    bool get_generate_about_to_be_shown() const;
};

/*
    Parameters  : generate  - The generate event status.
    Returns     : void
    Description : Set the PopUp_AboutToBeShown event status.
*/
inline void popup_b::set_generate_about_to_be_shown(bool generate)
{
    gadget_flags flags = _get_flags();
    _set_flags(generate
               ? flags | popup_GENERATE_ABOUT_TO_BE_SHOWN
               : flags & ~popup_GENERATE_ABOUT_TO_BE_SHOWN);
}

/*
    Parameters  : void
    Returns     : bool  - The generate event status.
    Description : Get the PopUp_AboutToBeShown event status.
*/
inline bool popup_b::get_generate_about_to_be_shown() const
{
    return BOOL(_get_flags() & popup_GENERATE_ABOUT_TO_BE_SHOWN);
}

#endif
