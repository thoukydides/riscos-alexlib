/*
    File        : raise.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Raise common signal types.

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
#ifndef RAISE_H
#define RAISE_H

// Signal types
typedef int raise_type;
#define RAISE_ABRT ((raise_type) 0x10)
#define RAISE_FPE ((raise_type) 0x20)
#define RAISE_ILL_INSTR ((raise_type) 0x30)
#define RAISE_ILL_ZERO ((raise_type) 0x31)
#define RAISE_INT ((raise_type) 0x40)
#define RAISE_SEGV_PREF ((raise_type) 0x50)
#define RAISE_SEGV_ABORT ((raise_type) 0x51)
#define RAISE_SEGV_ADDR ((raise_type) 0x52)
#define RAISE_TERM ((raise_type) 0x60)
#define RAISE_STAK ((raise_type) 0x70)
#define RAISE_OSERROR ((raise_type) 0xa0)

#ifdef __cplusplus
    extern "C" {
#endif

/*
    Parameters  : type  - The type of signal to raise.
    Returns     : void
    Description : Raise the specified signal by performing an appropriate
                  action. This does not explicitly call raise() for most
                  signals.
*/
void raise_signal(raise_type type);

#ifdef __cplusplus
    }
#endif

#endif
