/*
    File        : box.h
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

// Only include header file once
#ifndef box_h
#define box_h

// Include oslib header files
#include "oslib/os.h"

// Include alexlib header files
#ifndef point_h
#include "point.h"
#endif

// A class to represent a box
template<class T>
class box
{
    // The coordinates of the box
    point<T> bl;
    point<T> tr;

public:

    /*
        Parameters  : void
        Returns     : -
        Description : Constructor function.
    */
    box() {}

    /*
        Parameters  : b - The coordinates of the box.
        Returns     : -
        Description : Constructor function.
    */
    box(const os_box &b) : bl(b.x0, b.y0), tr(b.x1, b.y1) {}

    /*
        Parameters  : bl    - The bottom-left corner.
                      tr    - The top-right corner.
        Returns     : -
        Description : Constructor function.
    */
    box(const point<T> &bl, const point<T> &tr)
    : bl(bl), tr(tr) {}

    /*
        Parameters  : l     - The first x coordinate.
                      b     - The first y coordinate.
                      r     - The second x coordinate.
                      t     - The second y coordinate.
        Returns     : -
        Description : Constructor function.
    */
    box(const T &l, const T &b, const T &r, const T &t)
    : bl(l, b), tr(r, t) {}

#if 0
    T &top()
    {
        if (p1.y < p2.y) return p1.y;
        else return p2.y;
    }

    const T &top() const
    {
        if (p1.y < p2.y) return p1.y;
        else return p2.y;
    }

    point<T> top_left() const
    {
        return point<T>(left(), top());
    }

    /*
        Parameters  : rhs       - The point to add.
        Returns     : point<T>  - The updated point.
        Description : Add another point.
    */
    point<T> &operator+=(const point<T> &rhs);

    /*
        Parameters  : rhs       - The point to subtract.
        Returns     : point<T>  - The updated point.
        Description : Subtract another point.
    */
    point<T> &operator-=(const point<T> &rhs);
#endif

    T top() const;
    T bottom() const;
    T left() const;
    T right() const;

    /*
        Parameters  : void
        Returns     : point<T>  - The top-left corner.
        Description : Return the position of the top-left corner.
    */
    point<T> top_left() const;

    /*
        Parameters  : void
        Returns     : point<T>  - The top-right corner.
        Description : Return the position of the top-right corner.
    */
    point<T> top_right() const;

    /*
        Parameters  : void
        Returns     : point<T>  - The bottom-left corner.
        Description : Return the position of the bottom-left corner.
    */
    point<T> bottom_left() const;

    /*
        Parameters  : void
        Returns     : point<T>  - The bottom-right corner.
        Description : Return the position of the bottom-right corner.
    */
    point<T> bottom_right() const;

    /*
        Parameters  : void
        Returns     : point<T>  - The size of the box.
        Description : Return the size of the box. One or both dimensions may
                      be zero or negative if no area is enclosed.
    */
    point<T> size() const;

    /*
        Parameters  : void
        Returns     : os_box    - The corresponding os_box.
        Description : Convert to an os_box.
    */
    os_box os_box_of() const;

    /*
        Parameters  : void
        Returns     : bool  - Is the box valid.
        Description : Check whether both coordinates of the bottom-left
                      point are less-than or equal-to the corresponding
                      coordinates of the top-right point.
    */
    bool validate() const;
};

/*
    Parameters  : void
    Returns     : bool  - Is the box valid.
    Description : Check whether both coordinates of the bottom-left
                  point are less-than or equal-to the corresponding
                  coordinates of the top-right point.
*/
template<class T>
inline bool box<T>::validate() const
{
    // Return the result
    return (bl.x <= tr.x) && (bl.y <= tr.y);
}

// Instantiation of the template using doubles
class box_double : public box<double>
{
public:

    box_double() {}
    box_double(const box<double> &b) : box<double>(b) {}
    box_double(const box<float> &b) : box<double>(b) {}
    box_double(const box<int> &b) : box<double>(b) {}

    /*
        Parameters  : b - The coordinates of the box.
        Returns     : -
        Description : Constructor function.
    */
    box_double(const os_box &b) : p1(b.x0, b.y0), p2(b.x1, b.y1) {}
}

#endif
