/*
    File        : labelledbox_c.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a labelled box toolbox gadget.

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
#ifndef labelledbox_c_h
#define labelledbox_c_h

// Include alexlib header files
#ifndef gadget_c_h
#include "gadget_c.h"
#endif
#ifndef labelledbox_b_h
#include "labelledbox_b.h"
#endif

// A class to represent a label gadget
class labelledbox_c : virtual public gadget_b,
                      public gadget_c,
                      public labelledbox_b
{
public:

    /*
        Parameters  : component - The component ID of this labelled box.
                      object    - The object ID of this labelled box's parent
                                  window.
        Returns     : -
        Description : Constructor function. This does not create a labelled box;
                      it merely creates an object to represent the labelled box.
    */
    labelledbox_c(toolbox_c component = toolbox_NULL_COMPONENT,
                  toolbox_o object = toolbox_NULL_OBJECT);
};

/*
        Parameters  : component - The component ID of this labelled box.
                      object    - The object ID of this labelled box's parent
                                  window.
        Returns     : -
        Description : Constructor function. This does not create a labelled box;
                      it merely creates an object to represent the labelled box.
*/
inline labelledbox_c::labelledbox_c(toolbox_c component, toolbox_o object)
: gadget_c(component, object) {}

#endif
