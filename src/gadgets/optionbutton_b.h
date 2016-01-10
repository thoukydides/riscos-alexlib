/*
    File        : optionbutton_b.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Base class to represent an option button toolbox gadget.

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
#ifndef optionbutton_b_h
#define optionbutton_b_h

// Include oslib header files
#include "oslib/optionbutton.h"

// Include alexlib header files
#ifndef gadget_b_h
#include "gadget_b.h"
#endif
#ifndef gadget_w_boolean_h
#include "gadget_w_boolean.h"
#endif
#ifndef gadget_w_event_h
#include "gadget_w_event.h"
#endif
#ifndef gadget_w_text_h
#include "gadget_w_text.h"
#endif

// Extra oslib style definitions for option buttons
#define optionbutton_GENERATE_STATE_CHANGED ((gadget_flags) 0x1u)
#define optionbutton_ON ((gadget_flags) 0x4u)

// A base class to represent an option button gadget
class optionbutton_b : public virtual gadget_b,
                       public gadget_w_boolean,
                       public gadget_w_event,
                       public gadget_w_text
{
public:

    /*
        Parameters  : generate  - The generate event status.
        Returns     : void
        Description : Set the OptionButton_StateChanged event status.
    */
    void set_generate_state_changed(bool generate = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - The generate event status.
        Description : Get the OptionButton_StateChanged event status.
    */
    bool get_generate_state_changed() const;

    /*
        Parameters  : value             - The value to set.
        Returns     : optionbutton_b    - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    optionbutton_b &operator=(bool value);
};

/*
    Parameters  : generate  - The generate event status.
    Returns     : void
    Description : Set the OptionButton_StateChanged event status.
*/
inline void optionbutton_b::set_generate_state_changed(bool generate)
{
    gadget_flags flags = _get_flags();
    _set_flags(generate
               ? flags | optionbutton_GENERATE_STATE_CHANGED
               : flags & ~optionbutton_GENERATE_STATE_CHANGED);
}

/*
    Parameters  : void
    Returns     : bool  - The generate event status.
    Description : Get the OptionButton_StateChanged event status.
*/
inline bool optionbutton_b::get_generate_state_changed() const
{
    return BOOL(_get_flags() & optionbutton_GENERATE_STATE_CHANGED);
}

#endif
