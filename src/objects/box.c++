/*
    File        : box.c++
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Template to represent a box.

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
#include "box.h"

/*
    Parameters  : void
    Returns     : os_box    - The corresponding os_box.
    Description : Convert to an os_box.
*/
template<class T>
os_box box<T>::os_box_of() const
{
    os_box b;

    // Copy the details with appropriate casts
    b.x0 = (int) p1.x;
    b.y0 = (int) p1.y;
    b.x1 = (int) p2.x;
    b.y1 = (int) p2.y;

    // Return the constructed os_box
    return b;
}
