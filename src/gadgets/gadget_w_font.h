/*
    File        : gadget_w_font.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Class to represent a toolbox gadget that has a selectable
                  font.

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
#ifndef gadget_w_font_h
#define gadget_w_font_h

// Include cpplib header files
#include "string.h"

// A class to represent a gadget with selectable font
class gadget_w_font
{
public:

    /*
        Parameters  : font  - The name of the font to use, or NULL to use the
                              system font.
                      xsize - The width in 16ths of a point.
                      ysize - The height in 16ths of a point.
        Returns     : void
        Description : Set the font for this gadget.
    */
    void set_font(const char *font = NULL, int xsize = 0, int ysize = 0);

    /*
        Parameters  : font  - The name of the font to use.
                      xsize - The width in 16ths of a point.
                      ysize - The height in 16ths of a point.
        Returns     : void
        Description : Set the font for this gadget.
    */
    void set_font(const string &font, int xsize, int ysize);

protected:

    /*
        Parameters  : font  - The name of the font to use, or NULL to use the
                              system font.
                      xsize - The width in 16ths of a point.
                      ysize - The height in 16ths of a point.
        Returns     : void
        Description : Gadget specific function to set the font.
    */
    virtual void _set_font(const char *font, int xsize, int ysize) = 0;
};

/*
    Parameters  : font  - The name of the font to use.
                  xsize - The width in 16ths of a point.
                  ysize - The height in 16ths of a point.
    Returns     : void
    Description : Set the font for this gadget.
*/
inline void gadget_w_font::set_font(const char *font, int xsize, int ysize)
{
    _set_font(font, xsize, ysize);
}

/*
    Parameters  : font  - The name of the font to use.
                  xsize - The width in 16ths of a point.
                  ysize - The height in 16ths of a point.
    Returns     : void
    Description : Set the font for this gadget.
*/
inline void gadget_w_font::set_font(const string &font,
                                       int xsize, int ysize)
{
    _set_font(font.c_str(), xsize, ysize);
}

#endif
