/*
    File        : label_b.c++
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Base class to represent a label toolbox gadget.

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

// Include header file for this module
#include "label_b.h"

/*
    Parameters  : position  - The field justification.
    Returns     : void
    Description : Gadget specific function to set the justification.
*/
void label_b::_set_justification(justification position)
{
    gadget_flags flags = _get_flags()
                         & ~(label_RJUSTIFIED | label_HCENTRED);
    if (position == right) flags |= label_RJUSTIFIED;
    else if (position == centre) flags |= label_HCENTRED;
    _set_flags(flags);
}

/*
    Parameters  : void
    Returns     : bool  - The field justification.
    Description : Gadget specific function to Get the justification.
*/
label_b::justification label_b::_get_justification() const
{
    gadget_flags flags = _get_flags();
    return  flags & label_RJUSTIFIED
            ? right
            : (flags & label_HCENTRED ? centre : left);
}
