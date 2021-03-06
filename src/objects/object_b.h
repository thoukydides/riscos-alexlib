/*
    File        : object_b.h
    Date        : 19-Sep-02
    Author      : � A.Thoukydides, 1995-2002, 2016
    Description : Base class to represent a generic toolbox object.

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
#ifndef object_b_h
#define object_b_h

// A class to represent a generic object
class object_b
{
public:

    /*
        Parameters  : void
        Returns     : -
        Description : Destructor function.
    */
    virtual ~object_b();

protected:

    /*
        Parameters  : void
        Returns     : -
        Description : Protected constructor to prevent creation of abstract
                      base class.
    */
    object_b();
};

/*
    Parameters  : void
    Returns     : -
    Description : Destructor function.
*/
inline object_b::~object_b() {}

#endif
