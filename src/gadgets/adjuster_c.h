/*
    File        : adjuster_c.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent an adjuster arrow toolbox gadget.

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
#ifndef adjuster_c_h
#define adjuster_c_h

// Include alexlib header files
#ifndef adjuster_b_h
#include "adjuster_b.h"
#endif
#ifndef gadget_c_h
#include "gadget_c.h"
#endif

// A class to represent a adjuster arrow gadget
class adjuster_c : public virtual gadget_b,
                   public gadget_c,
                   public adjuster_b
{
public:

    /*
        Parameters  : component - The component ID of this adjuster arrow.
                      object    - The object ID of this adjuster arrow's
                                  parent window.
        Returns     : -
        Description : Constructor function. This does not create an adjuster
                      arrow; it merely creates an object to represent
                      the adjuster arrow.
    */
    adjuster_c(toolbox_c component = toolbox_NULL_COMPONENT,
               toolbox_o object = toolbox_NULL_OBJECT);
};

/*
    Parameters  : component - The component ID of this adjuster arrow.
                  object    - The object ID of this adjuster arrow's
                              parent window.
    Returns     : -
    Description : Constructor function. This does not create an adjuster
                  arrow; it merely creates an object to represent
                  the adjuster arrow.
*/
inline adjuster_c::adjuster_c(toolbox_c component, toolbox_o object)
: gadget_c(component, object) {}

#endif
