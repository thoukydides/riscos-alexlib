/*
    File        : label_c.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a label toolbox gadget.

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
#ifndef label_c_h
#define label_c_h

// Include alexlib header files
#ifndef gadget_c_h
#include "gadget_c.h"
#endif
#ifndef label_b_h
#include "label_b.h"
#endif

// A class to represent a label gadget
class label_c : public virtual gadget_b,
                public gadget_c,
                public label_b
{
public:

    /*
        Parameters  : component - The component ID of this label.
                      object    - The object ID of this label's parent window.
        Returns     : -
        Description : Constructor function. This does not create a label;
                      it merely creates an object to represent the label.
    */
    label_c(toolbox_c component = toolbox_NULL_COMPONENT,
            toolbox_o object = toolbox_NULL_OBJECT);
};

/*
    Parameters  : component - The component ID of this label.
                  object    - The object ID of this label's parent window.
    Returns     : -
    Description : Constructor function. This does not create a label;
                  it merely creates an object to represent the label.
*/
inline label_c::label_c(toolbox_c component, toolbox_o object)
: gadget_c(component, object) {}

#endif
