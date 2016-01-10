/*
    File        : numberrange_t.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a number range toolbox gadget template.

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
#ifndef numberrange_t_h
#define numberrange_t_h

// Include alexlib header files
#ifndef gadget_t_h
#include "gadget_t.h"
#endif
#ifndef gadget_w_caret_h
#include "gadget_w_caret.h"
#endif
#ifndef numberrange_b_h
#include "numberrange_b.h"
#endif

// A class to represent a number range gadget template
class numberrange_t : public virtual gadget_b,
                      public gadget_t,
                      public numberrange_b,
                      public gadget_w_caret
{
public:

    /*
        Parameters  : void
        Returns     : -
        Description : Constructor function.
    */
    numberrange_t();

    /*
        Parameters  : value         - The number to set.
        Returns     : numberrange_t - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    numberrange_t &operator=(int value);

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

    /*
        Parameters  : precision - The precision.
        Returns     : void
        Description : Set the precision.
    */
    virtual void _set_precision(int precision);

    /*
        Parameters  : void
        Returns     : int   - The precision.
        Description : Get the precision.
    */
    virtual int _get_precision() const;

    /*
        Parameters  : component - The component ID of the previous field.
        Returns     : void
        Description : Set the component ID of the writable field before this
                      one.
    */
    virtual void _set_before(toolbox_c component);

    /*
        Parameters  : void
        Returns     : toolbox_c - The component ID of the previous field.
        Description : Get the component ID of the writable field before this
                      one.
    */
    virtual toolbox_c _get_before() const;

    /*
        Parameters  : component - The component ID of the next field.
        Returns     : void
        Description : Set the component ID of the writable field after this
                      one.
    */
    virtual void _set_after(toolbox_c component);

    /*
        Parameters  : void
        Returns     : toolbox_c - The component ID of the next field.
        Description : Get the component ID of the writable field after this
                      one.
    */
    virtual toolbox_c _get_after() const;
};

#endif
