/*
    File        : adjuster_t.h
    Date        : 19-Sep-02
    Author      : � A.Thoukydides, 1995-2002, 2016
    Description : Class to represent an adjuster arrow toolbox gadget template.

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
#ifndef adjuster_t_h
#define adjuster_t_h

// Include alexlib header files
#ifndef adjuster_b_h
#include "adjuster_b.h"
#endif
#ifndef gadget_t_h
#include "gadget_t.h"
#endif

// A class to represent a adjuster arrow gadget template
class adjuster_t : public virtual gadget_b,
                   public gadget_t,
                   public adjuster_b
{
public:

    /*
        Parameters  : void
        Returns     : -
        Description : Constructor function.
    */
    adjuster_t();
};

#endif
