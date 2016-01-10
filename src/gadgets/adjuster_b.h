/*
    File        : adjuster_b.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Base class to represent an adjuster arrow toolbox gadget.

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
#ifndef adjuster_b_h
#define adjuster_b_h

// Include oslib header files
#include "oslib/adjuster.h"

// Include alexlib header files
#ifndef gadget_b_h
#include "gadget_b.h"
#endif

// A base class to represent a adjuster arrow gadget
class adjuster_b : public virtual gadget_b
{
public:

    /*
        Parameters  : increment - The increment status.
        Returns     : void
        Description : Set the increment/decrement status for this adjuster
                      arrow.
    */
    void set_increment(bool increment = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - The increment status.
        Description : Get the increment/decrement status for this adjuster
                      arrow.
    */
    bool get_increment() const;

    /*
        Parameters  : vertical  - The vertical status.
        Returns     : void
        Description : Set the vertical/horizontal status for this adjuster
                      arrow.
    */
    void set_vertical(bool vertical = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - The vertical status.
        Description : Get the vertical/horizontal status for this adjuster
                      arrow.
    */
    bool get_vertical() const;
};

/*
    Parameters  : increment - The increment status.
    Returns     : void
    Description : Set the increment/decrement status for this adjuster
                  arrow.
*/
inline void adjuster_b::set_increment(bool increment)
{
    gadget_flags flags = _get_flags();
    _set_flags(increment
               ? flags | adjuster_INCREMENT
               : flags & ~adjuster_INCREMENT);
}

/*
    Parameters  : void
    Returns     : bool  - The increment status.
    Description : Get the increment/decrement status for this adjuster
                  arrow.
*/
inline bool adjuster_b::get_increment() const
{
    return BOOL(_get_flags() & adjuster_INCREMENT);
}

/*
    Parameters  : vertical  - The vertical status.
    Returns     : void
    Description : Set the vertical/horizontal status for this adjuster
                  arrow.
*/
inline void adjuster_b::set_vertical(bool vertical)
{
    gadget_flags flags = _get_flags();
    _set_flags(vertical
               ? flags | adjuster_VERTICAL
               : flags & ~adjuster_VERTICAL);
}

/*
    Parameters  : void
    Returns     : bool  - The vertical status.
    Description : Get the vertical/horizontal status for this adjuster
                  arrow.
*/
inline bool adjuster_b::get_vertical() const
{
    return BOOL(_get_flags() & adjuster_VERTICAL);
}

#endif
