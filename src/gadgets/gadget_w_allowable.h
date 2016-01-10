/*
    File        : gadget_w_allowable.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a toolbox gadget that has an associated
                  allowable range of characters.

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
#ifndef gadget_w_allowable_h
#define gadget_w_allowable_h

// Include cpplib header files
#include "string.h"

// A class to represent a gadget with an allowable range of characters
class gadget_w_allowable
{
public:

    /*
        Parameters  : allowed   - The new set of allowable characters, or NULL
                                  to allow all characters.
        Returns     : void
        Description : Define the set of allowable characters for this gadget.
    */
    void set_allowable(const char *allowed = NULL);

    /*
        Parameters  : allowed   - The new set of allowable characters.
        Returns     : void
        Description : Define the set of allowable characters for this gadget.
    */
    void set_allowable(const string &allowed);

protected:

    /*
        Parameters  : allowed   - The new set of allowable characters, or NULL
                                  to allow all characters.
        Returns     : void
        Description : Gadget specific function to define the set of allowable
                      characters.
    */
    virtual void _set_allowable(const char *allowed) = 0;
};

/*
    Parameters  : allowed   - The new set of allowable characters, or NULL
                              to allow all characters.
    Returns     : void
    Description : Define the set of allowable characters for this gadget.
*/
inline void gadget_w_allowable::set_allowable(const char *allowed)
{
    _set_allowable(allowed);
}

/*
    Parameters  : allowed   - The new set of allowable characters.
    Returns     : void
    Description : Define the set of allowable characters for this gadget.
*/
inline void gadget_w_allowable::set_allowable(const string &allowed)
{
    _set_allowable(allowed.c_str());
}

#endif
