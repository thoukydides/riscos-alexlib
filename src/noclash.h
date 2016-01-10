/*
    File        : noclash.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Prevent clashes between OSLib and CathLibCPP due to bugs in
                  CFront. This should be included before any header files from
                  either of those libraries.

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
#ifndef NOCLASH_H
#define NOCLASH_H

// Rename structure fields
#define map _map

// Include oslib header files
#include "oslib/os.h"

// Clear temporary redefinition
#undef map

#endif
