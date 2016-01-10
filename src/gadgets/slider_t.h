/*
    File        : slider_t.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a slider toolbox gadget template.

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
#ifndef slider_t_h
#define slider_t_h

// Include alexlib header files
#ifndef gadget_t_h
#include "gadget_t.h"
#endif
#ifndef slider_b_h
#include "slider_b.h"
#endif

// A class to represent a slider gadget template
class slider_t : public virtual gadget_b,
                 public gadget_t,
                 public slider_b
{
public:

    /*
        Parameters  : void
        Returns     : -
        Description : Constructor function.
    */
    slider_t();

    /*
        Parameters  : value     - The number to set.
        Returns     : slider_t  - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    slider_t &operator=(int value);

protected:

    /*
        Parameters  : value - The number to set.
        Returns     : void
        Description : Gadget specific function to set the value.
    */
    virtual void _set_value(int value);

    /*
        Parameters  : void
        Returns     : int   - The value
        Description : Gadget specific function to get the value.
    */
    virtual int _get_value() const;

    /*
        Parameters  : lower - The lower bound.
        Returns     : void
        Description : Gadget specific function to set the lower bound.
    */
    virtual void _set_lower_bound(int lower);

    /*
        Parameters  : void
        Returns     : int   - The lower bound.
        Description : Gadget specific function to get the lower bound.
    */
    virtual int _get_lower_bound() const;

    /*
        Parameters  : upper - The upper bound.
        Returns     : void
        Description : Gadget specific function to set the upper bound.
    */
    virtual void _set_upper_bound(int upper);

    /*
        Parameters  : void
        Returns     : int   - The upper bound.
        Description : Gadget specific function to get the upper bound.
    */
    virtual int _get_upper_bound() const;

    /*
        Parameters  : step  - The step size.
        Returns     : void
        Description : Gadget specific function to set the step size.
    */
    virtual void _set_step_size(int step);

    /*
        Parameters  : void
        Returns     : int   - The step size.
        Description : Gadget specific function to get the step size.
    */
    virtual int _get_step_size() const;
};

#endif
