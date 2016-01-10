/*
    File        : raise.c
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

// Include header file for this module
#include "raise.h"

// Include clib header files
#include <signal.h>
#include <stdlib.h>

// Include oslib header files
#include "oslib/osbyte.h"

// External variables required to prevent optimisation
double raise_zero = 0.0;
bits raise_value = 0;

/*
    Parameters  : data  - A dummy data pointer used to prevent warnings.
    Returns     : void
    Description : Use up all available stack space.
*/
static void raise_stack(void *data)
{
    byte block[1024 * 1024];
    raise_stack(block);
}

/*
    Parameters  : type  - The type of signal to raise.
    Returns     : void
    Description : Raise the specified signal by performing an appropriate
                  action. This does not explicitly call raise() for most
                  signals.
*/
void raise_signal(raise_type type)
{
    // Action depend on the selected signal
    switch (type)
    {
        case RAISE_ABRT:
            // Abnormal termination
            abort();
            break;

        case RAISE_FPE:
            // Arithmetic error
            raise_zero = 1.0 / raise_zero;
            break;

        case RAISE_ILL_INSTR:
            // Illegal instruction
            {
                bits illegal = 0x07ffffff;
                void (*branch)() = (void (*)()) &illegal;
                (*branch)();
            }
            break;

        case RAISE_ILL_ZERO:
            // Branch through zero
            {
                void (*branch)() = NULL;
                (*branch)();
            }
            break;

        case RAISE_INT:
            // Escape
            osbyte(osbyte_SET_ESCAPE, 0, 0);
            break;

        case RAISE_SEGV_PREF:
            // Abort on instruction prefetch
            {
                void (*branch)() = (void (*)()) 0x1d00000;
                (*branch)();
            }
            break;

        case RAISE_SEGV_ABORT:
            // Abort on data transfer
            raise_value = * (bits *) 0x1d00000;
            break;

        case RAISE_SEGV_ADDR:
            // Address exception
            raise_value = * (bits *) 0x40000000;
            break;

        case RAISE_TERM:
            // Termination request received
            raise(SIGTERM);
            break;

        case RAISE_STAK:
            // Stack overflow
            raise_stack(NULL);
            break;

        case RAISE_OSERROR:
            // Operating system error
            {
                os_error err = {0, "An operating system error"};
                os_generate_error(&err);
            }
            break;

        default:
            // Unrecognised signal - no action
            break;
    }
}
