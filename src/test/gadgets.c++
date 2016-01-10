/*
    File        : gadgets.c++
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : A short program to test instantiation of the toolbox gadget
                  classes.

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

#include <stdio.h>

#include "actionbutton_c.h"
#include "actionbutton_t.h"
#include "adjuster_c.h"
#include "adjuster_t.h"
#include "button_c.h"
#include "button_t.h"
#include "displayfield_c.h"
#include "displayfield_t.h"
#include "draggable_c.h"
#include "draggable_t.h"
#include "labelledbox_c.h"
#include "labelledbox_t.h"
#include "label_c.h"
#include "label_t.h"
#include "numberrange_c.h"
#include "numberrange_t.h"
#include "optionbutton_c.h"
#include "optionbutton_t.h"
#include "popup_c.h"
#include "popup_t.h"
#include "radiobutton_c.h"
#include "radiobutton_t.h"
#include "slider_c.h"
#include "slider_t.h"
#include "stringset_c.h"
#include "stringset_t.h"
#include "writablefield_c.h"
#include "writablefield_t.h"

int main()
{
    actionbutton_c actionbutton_c_obj;
    // actionbutton_t actionbutton_t_obj;
    printf("sizeof(actionbutton_c_obj) = %d bytes\n", sizeof(actionbutton_c_obj));

    adjuster_c adjuster_c_obj;
    // adjuster_t adjuster_t_obj;
    printf("sizeof(adjuster_c_obj) = %d bytes\n", sizeof(adjuster_c_obj));

    button_c button_c_obj;
    // button_t button_t_obj;
    printf("sizeof(button_c_obj) = %d bytes\n", sizeof(button_c_obj));

    displayfield_c displayfield_c_obj;
    // displayfield_t displayfield_t_obj;
    printf("sizeof(displayfield_c_obj) = %d bytes\n", sizeof(displayfield_c_obj));

    draggable_c draggable_c_obj;
    // draggable_t draggable_t_obj;
    printf("sizeof(draggable_c_obj) = %d bytes\n", sizeof(draggable_c_obj));

    labelledbox_c labelledbox_c_obj;
    // labelledbox_t labelledbox_t_obj;
    printf("sizeof(labelledbox_c_obj) = %d bytes\n", sizeof(labelledbox_c_obj));

    label_c label_c_obj;
    // label_t label_t_obj;
    printf("sizeof(label_c_obj) = %d bytes\n", sizeof(label_c_obj));

    numberrange_c numberrange_c_obj;
    // numberrange_t numberrange_t_obj;
    printf("sizeof(numberrange_c_obj) = %d bytes\n", sizeof(numberrange_c_obj));

    optionbutton_c optionbutton_c_obj;
    // optionbutton_t optionbutton_t_obj;
    printf("sizeof(optionbutton_c_obj) = %d bytes\n", sizeof(optionbutton_c_obj));

    popup_c popup_c_obj;
    // popup_t popup_t_obj;
    printf("sizeof(popup_c_obj) = %d bytes\n", sizeof(popup_c_obj));

    radiobutton_c radiobutton_c_obj;
    // radiobutton_t radiobutton_t_obj;
    printf("sizeof(radiobutton_c_obj) = %d bytes\n", sizeof(radiobutton_c_obj));

    slider_c slider_c_obj;
    // slider_t slider_t_obj;
    printf("sizeof(slider_c_obj) = %d bytes\n", sizeof(slider_c_obj));

    stringset_c stringset_c_obj;
    // stringset_t stringset_t_obj;
    printf("sizeof(stringset_c_obj) = %d bytes\n", sizeof(stringset_c_obj));

    writablefield_c writablefield_c_obj;
    // writablefield_t writablefield_t_obj;
    printf("sizeof(writablefield_c_obj) = %d bytes\n", sizeof(writablefield_c_obj));

    return 0;
}
