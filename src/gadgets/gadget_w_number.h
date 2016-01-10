/*
    File        : gadget_w_number.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a toolbox gadget that has a numeric value.

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
#ifndef gadget_w_number_h
#define gadget_w_number_h

// A class to represent a gadget with a numeric value
class gadget_w_number
{
public:

    /*
        Parameters  : value - The number to set.
        Returns     : void
        Description : Set the value of this gadget.
    */
    void set_value(int value);

    /*
        Parameters  : value             - The number to set.
        Returns     : gadget_w_number   - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    gadget_w_number &operator=(int value);

    /*
        Parameters  : void
        Returns     : int   - The value
        Description : Get the value of this gadget.
    */
    int get_value() const;

    /*
        Parameters  : void
        Returns     : int   - The value.
        Description : Get the value of this gadget.
    */
    int operator()() const;

protected:

    /*
        Parameters  : value - The number to set.
        Returns     : void
        Description : Gadget specific function to set the value.
    */
    virtual void _set_value(int value) = 0;

    /*
        Parameters  : void
        Returns     : int   - The value
        Description : Gadget specific function to get the value.
    */
    virtual int _get_value() const = 0;
};

/*
    Parameters  : value - The number to set.
    Returns     : void
    Description : Set the value of this gadget.
*/
inline void gadget_w_number::set_value(int value)
{
    _set_value(value);
}

/*
    Parameters  : value             - The number to set.
    Returns     : gadget_w_number   - This object.
    Description : Set the value of this gadget. To reduce flicker the value
                  is not updated unless it has changed.
*/
inline gadget_w_number &gadget_w_number::operator=(int value)
{
    if (value != _get_value()) _set_value(value);
    return *this;
}

/*
    Parameters  : void
    Returns     : int   - The value
    Description : Get the value of this gadget.
*/
inline int gadget_w_number::get_value() const
{
    return _get_value();
}

/*
    Parameters  : void
    Returns     : int   - The value.
    Description : Get the value of this gadget.
*/
inline int gadget_w_number::operator()() const
{
    return _get_value();
}

#endif
