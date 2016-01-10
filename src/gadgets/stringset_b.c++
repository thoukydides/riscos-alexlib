/*
    File        : stringset_b.c++
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Base class to represent a string set toolbox gadget.

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

// Include header file for this module
#include "stringset_b.h"

/*
    Parameters  : value         - The number to set.
    Returns     : stringset_b   - This object.
    Description : Set the value of this gadget. To reduce flicker the value
                  is not updated unless it has changed.
*/
stringset_b &stringset_b::operator=(int value)
{
    gadget_w_number::operator=(value);
    return *this;
}

/*
    Parameters  : value         - The text string to set.
    Returns     : stringset_b   - This object.
    Description : Set the value of this gadget. To reduce flicker the value
                  is not updated unless it has changed.
*/
stringset_b &stringset_b::operator=(const char *value)
{
    gadget_w_string::operator=(value);
    return *this;
}

/*
    Parameters  : value         - The text string to set.
    Returns     : stringset_b   - This object.
    Description : Set the value of this gadget. To reduce flicker the value
                  is not updated unless it has changed.
*/
stringset_b &stringset_b::operator=(const string &value)
{
    gadget_w_string::operator=(value);
    return *this;
}

/*
    Parameters  : position  - The field justification.
    Returns     : void
    Description : Gadget specific function to set the justification.
*/
void stringset_b::_set_justification(justification position)
{
    gadget_flags flags = _get_flags() & ~stringset_JUSTIFICATION;
    if (position == right)
    {
        flags |= stringset_JUSTIFICATION_RIGHT
                 << stringset_JUSTIFICATION_SHIFT;
    }
    else if (position == centre)
    {
        flags |= stringset_JUSTIFICATION_CENTRED
                 << stringset_JUSTIFICATION_SHIFT;
    }
    _set_flags(flags);
}

/*
    Parameters  : void
    Returns     : bool  - The field justification.
    Description : Gadget specific function to Get the justification.
*/
stringset_b::justification stringset_b::_get_justification() const
{
    gadget_flags flags = _get_flags() >> stringset_JUSTIFICATION_SHIFT;
    return  flags & stringset_JUSTIFICATION_RIGHT
            ? right
            : (flags & stringset_JUSTIFICATION_CENTRED ? centre : left);
}

/*
    Parameters  : available - The new list of available strings.
    Returns     : void
    Description : Define the available set of strings.
*/
void stringset_b::set_available(const list<string> &available)
{
    string result;
    for (list_const_iterator<string> iter = available.begin();
         iter != available.end();
         ++iter)
    {
        string work = *iter;
        for (string::iterator ptr = work.begin(); ptr != work.end(); ++ptr)
        {
            if ((*ptr == ',') || (*ptr == '\\')) work.insert(ptr, '\\');
        }
        if (result.empty()) result = work;
        else result += "," + work;
    }
    _set_available(result.c_str());
}
