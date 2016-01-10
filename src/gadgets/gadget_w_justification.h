/*
    File        : gadget_w_justification.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a toolbox gadget that has selectable
                  field justification.

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
#ifndef gadget_w_justification_h
#define gadget_w_justification_h

// A class to represent a gadget with selectable field justification
class gadget_w_justification
{
public:

    // Possible field alignments
    enum justification
    {
        left,
        right,
        centre
    };

    /*
        Parameters  : position  - The field justification.
        Returns     : void
        Description : Set the justification for this gadget.
    */
    void set_justification(justification position = left);

    /*
        Parameters  : void
        Returns     : bool  - The field justification.
        Description : Get the justification for this gadget.
    */
    justification get_justification() const;

protected:

    /*
        Parameters  : position  - The field justification.
        Returns     : void
        Description : Gadget specific function to set the justification.
    */
    virtual void _set_justification(justification position) = 0;

    /*
        Parameters  : void
        Returns     : bool  - The field justification.
        Description : Gadget specific function to Get the justification.
    */
    virtual justification _get_justification() const = 0;
};

/*
    Parameters  : position  - The field justification.
    Returns     : void
    Description : Set the justification for this gadget.
*/
inline void gadget_w_justification::set_justification(justification position)
{
    _set_justification(position);
}

/*
    Parameters  : void
    Returns     : bool  - The field justification.
    Description : Get the justification for this gadget.
*/
inline gadget_w_justification::justification
gadget_w_justification::get_justification() const
{
    return _get_justification();
}

#endif
