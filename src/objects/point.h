/*
    File        : point.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Template to represent a point.

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
#ifndef point_h
#define point_h

// A class to represent a point
template<class T>
class point
{
public:

    // The coordinates of the point
    T x;
    T y;

    /*
        Parameters  : void
        Returns     : -
        Description : Constructor function.
    */
    point() {}

    /*
        Parameters  : x - The x coordinate.
                      y - The y coordinate.
        Returns     : -
        Description : Constructor function.
    */
    point(T x, T y) : x(x), y(y) {}

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
};

/*
    Parameters  : rhs       - The point to add.
    Returns     : point<T>  - The updated point.
    Description : Add another point.
*/
template<class T>
inline point<T> &point<T>::operator+=(const point<T> &rhs)
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

/*
    Parameters  : rhs       - The point to subtract.
    Returns     : point<T>  - The updated point.
    Description : Subtract another point.
*/
template<class T>
inline point<T> &point<T>::operator-=(const point<T> &rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

/*
    Parameters  : p1        - The first point.
                  p2        - The second point.
    Returns     : point<T>  - The resulting point.
    Description : Add two points together.
*/
template<class T>
inline point<T> operator+(const point<T> &p1, const point<T> &p2)
{
    return point<T>(p1) += p2;
}

/*
    Parameters  : p1        - The first point.
                  p2        - The second point.
    Returns     : point<T>  - The resulting point.
    Description : Subtract one point from another.
*/
template<class T>
inline point<T> operator-(const point<T> &p1, const point<T> &p2)
{
    return point<T>(p1) -= p2;
}

// Instantiation of the template using doubles
class point_double : public point<double>
{
public:

    /*
        Parameters  : void
        Returns     : -
        Description : Constructor function.
    */
    point_double() {}

    /*
        Parameters  : p - The point.
        Returns     : -
        Description : Constructor function.
    */
    point_double(const point<double> &p) : point<double>(p.x, p.y) {}

    /*
        Parameters  : p - The point.
        Returns     : -
        Description : Constructor function.
    */
    point_double(const point<float> &p) : point<double>(p.x, p.y) {}

    /*
        Parameters  : p - The point.
        Returns     : -
        Description : Constructor function.
    */
    point_double(const point<int> &p) : point<double>(p.x, p.y) {}

    /*
        Parameters  : x - The x coordinate.
                      y - The y coordinate.
        Returns     : -
        Description : Constructor function.
    */
    point_double(double x, double y) : point<double>(x, y) {}
};

// Instantiation of the template using floats
class point_float : public point<float>
{
public:

    /*
        Parameters  : void
        Returns     : -
        Description : Constructor function.
    */
    point_float() {}

    /*
        Parameters  : p - The point.
        Returns     : -
        Description : Constructor function.
    */
    point_float(const point<double> &p) : point<float>(p.x, p.y) {}

    /*
        Parameters  : p - The point.
        Returns     : -
        Description : Constructor function.
    */
    point_float(const point<float> &p) : point<float>(p.x, p.y) {}

    /*
        Parameters  : p - The point.
        Returns     : -
        Description : Constructor function.
    */
    point_float(const point<int> &p) : point<float>(p.x, p.y) {}

    /*
        Parameters  : x - The x coordinate.
                      y - The y coordinate.
        Returns     : -
        Description : Constructor function.
    */
    point_float(float x, float y) : point<float>(x, y) {}
};

// Instantiation of the template using ints
class point_int : public point<int>
{
public:

    /*
        Parameters  : void
        Returns     : -
        Description : Constructor function.
    */
    point_int() {}

    /*
        Parameters  : p - The point.
        Returns     : -
        Description : Constructor function.
    */
    point_int(const point<double> &p) : point<int>((int) p.x, (int) p.y) {}

    /*
        Parameters  : p - The point.
        Returns     : -
        Description : Constructor function.
    */
    point_int(const point<float> &p) : point<int>((int) p.x, (int) p.y) {}

    /*
        Parameters  : p - The point.
        Returns     : -
        Description : Constructor function.
    */
    point_int(const point<int> &p) : point<int>(p.x, p.y) {}

    /*
        Parameters  : x - The x coordinate.
                      y - The y coordinate.
        Returns     : -
        Description : Constructor function.
    */
    point_int(int x, int y) : point<int>(x, y) {}
};

#endif
