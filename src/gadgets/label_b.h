/*
    File        : label_b.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Base class to represent a label toolbox gadget.

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
#ifndef label_b_h
#define label_b_h

// Include oslib header files
#include "oslib/label.h"

// Include alexlib header files
#ifndef gadget_b_h
#include "gadget_b.h"
#endif
#ifndef gadget_w_justification_h
#include "gadget_w_justification.h"
#endif

// A base class to represent a label gadget
class label_b : public virtual gadget_b,
                public gadget_w_justification
{
public:

    /*
        Parameters  : omit  - Should the bounding box be omitted.
        Returns     : void
        Description : Set whether the bounding box should be omitted for this
                      label.
    */
    void set_omit_box(bool omit = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - Should the bounding box be omitted.
        Description : Get whether the bounding box should be omitted for this
                      label.
    */
    bool get_omit_box() const;

protected:

    /*
        Parameters  : position  - The field justification.
        Returns     : void
        Description : Gadget specific function to set the justification.
    */
    virtual void _set_justification(justification position);

    /*
        Parameters  : void
        Returns     : bool  - The field justification.
        Description : Gadget specific function to Get the justification.
    */
    virtual justification _get_justification() const;
};

/*
    Parameters  : omit  - Should the bounding box be omitted.
    Returns     : void
    Description : Set whether the bounding box should be omitted for this
                  label.
*/
inline void label_b::set_omit_box(bool omit)
{
    gadget_flags flags = _get_flags();
    _set_flags(omit
               ? flags | label_NO_BOX
               : flags & ~label_NO_BOX);
}

/*
    Parameters  : void
    Returns     : bool  - Should the bounding box be omitted.
    Description : Get whether the bounding box should be omitted for this
                  label.
*/
inline bool label_b::get_omit_box() const
{
    return BOOL(_get_flags() & label_NO_BOX);
}

#endif
