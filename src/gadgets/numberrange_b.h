/*
    File        : numberrange_b.h
    Date        : 19-Sep-02
    Author      : © A.Thoukydides, 1995-2002, 2016
    Description : Base class to represent a number range toolbox gadget.

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
#ifndef numberrange_b_h
#define numberrange_b_h

// Include oslib header files
#include "oslib/numberrange.h"

// Include alexlib header files
#ifndef gadget_b_h
#include "gadget_b.h"
#endif
#ifndef gadget_w_justification_h
#include "gadget_w_justification.h"
#endif
#ifndef gadget_w_slider_h
#include "gadget_w_slider.h"
#endif

// A base class to represent a number range gadget
class numberrange_b : public virtual gadget_b,
                      public gadget_w_justification,
                      public gadget_w_slider
{
public:

    // Possible field alignments
    enum slider_type
    {
        slider_none,
        slider_right,
        slider_left
    };

    // Possible rounding modes
    enum rounding_mode
    {
        nearest,
        positive,
        negative,
        zero
    };

    /*
        Parameters  : generate  - The generate event status.
        Returns     : void
        Description : Set the NumberRange_ValueChanged event status.
    */
    void set_generate_value_changed(bool generate = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - The generate event status.
        Description : Get the NumberRange_ValueChanged event status.
    */
    bool get_generate_value_changed() const;

    /*
        Parameters  : writable  - Is the field writable.
        Returns     : void
        Description : Set whether the numeric field is writable.
    */
    void set_writable(bool writable = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - Is the field writable.
        Description : Get whether the numeric field is writable.
    */
    bool get_writable() const;

    /*
        Parameters  : display   - Is there a display area.
        Returns     : void
        Description : Set whether there is a diplay area.
    */
    void set_has_display(bool display = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - Is there a display area.
        Description : Get whether there is a diplay area.
    */
    bool get_has_display() const;

    /*
        Parameters  : adjusters - Are there adjuster arrows.
        Returns     : void
        Description : Set whether there are adjuster arrows.
    */
    void set_has_adjusters(bool adjusters = TRUE);

    /*
        Parameters  : void
        Returns     : bool  - Are there adjuster arrows.
        Description : Get whether there are adjuster arrows.
    */
    bool get_has_adjusters() const;

    /*
        Parameters  : slider    - The type of slider.
        Returns     : void
        Description : Set the type of slider, if any.
    */
    void set_slider_type(slider_type slider = slider_none);

    /*
        Parameters  : void
        Returns     : slider_type   - The type of slider.
        Description : Get the type of slider, if any.
    */
    slider_type get_slider_type() const;

    /*
        Parameters  : precision - The precision.
        Returns     : void
        Description : Set the precision.
    */
    void set_precision(int precision);

    /*
        Parameters  : void
        Returns     : int   - The precision.
        Description : Get the precision.
    */
    int get_precision() const;

    /*
        Parameters  : value     - The value.
                      rounding  - The optional rounding mode.
        Returns     : void
        Description : Set the value scaled as displayed.
    */
    void set_value_scaled(double value, rounding_mode rounding = nearest);

    /*
        Parameters  : void
        Returns     : double    - The value.
        Description : Get the value scaled as displayed.
    */
    double get_value_scaled() const;

    /*
        Parameters  : lower     - The lower bound.
                      rounding  - The optional rounding mode.
        Returns     : void
        Description : Set the lower bound scaled as displayed.
    */
    void set_lower_bound_scaled(double lower, rounding_mode rounding = nearest);

    /*
        Parameters  : void
        Returns     : double    - The value.
        Description : Get the lower bound scaled as displayed.
    */
    double get_lower_bound_scaled() const;

    /*
        Parameters  : upper     - The lower bound.
                      rounding  - The optional rounding mode.
        Returns     : void
        Description : Set the upper bound scaled as displayed.
    */
    void set_upper_bound_scaled(double upper, rounding_mode rounding = nearest);

    /*
        Parameters  : void
        Returns     : double    - The value.
        Description : Get the upper bound scaled as displayed.
    */
    double get_upper_bound_scaled() const;

    /*
        Parameters  : step      - The step size.
                      rounding  - The optional rounding mode.
        Returns     : void
        Description : Set the step size scaled as displayed.
    */
    void set_step_size_scaled(double step, rounding_mode rounding = nearest);

    /*
        Parameters  : void
        Returns     : double    - The value.
        Description : Get the step size scaled as displayed.
    */
    double get_step_size_scaled() const;

    /*
        Parameters  : value         - The number to set.
        Returns     : numberrange_b - This object.
        Description : Set the value of this gadget. To reduce flicker the value
                      is not updated unless it has changed.
    */
    numberrange_b &operator=(int value);

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

    /*
        Parameters  : colour    - The slider colour.
        Returns     : void
        Description : Gadget specific function to set the colour of the slider.
    */
    virtual void _set_slider_colour(wimp_colour colour);

    /*
        Parameters  : void
        Returns     : wimp_colour   - The slider colour.
        Description : Gadget specific function to get the colour of the slider.
    */
    virtual wimp_colour _get_slider_colour() const;

    /*
        Parameters  : colour    - The well colour.
        Returns     : void
        Description : Gadget specific function to set the colour of the well.
    */
    virtual void _set_well_colour(wimp_colour colour);

    /*
        Parameters  : void
        Returns     : wimp_colour   - The well colour.
        Description : Gadget specific function to get the colour of the well.
    */
    virtual wimp_colour _get_well_colour() const;

    /*
        Parameters  : precision - The precision.
        Returns     : void
        Description : Set the precision.
    */
    virtual void _set_precision(int precision) = 0;

    /*
        Parameters  : void
        Returns     : int   - The precision.
        Description : Get the precision.
    */
    virtual int _get_precision() const = 0;

private:

    /*
        Parameters  : value     - The floating point value to scale.
                      rounding  - The required rounding mode.
        Returns     : int       - The scaled and rounded value.
        Description : Scale the specified value according to the current
                      precision and round to an integer.
    */
    int scale(double value, rounding_mode rounding) const;

    /*
        Parameters  : value     - The integer value to scale.
        Returns     : double    - The scaled.
        Description : Scale the specified value according to the current
                      precision.
    */
    double scale(int value) const;
};

/*
    Parameters  : generate  - The generate event status.
    Returns     : void
    Description : Set the NumberRange_ValueChanged event status.
*/
inline void numberrange_b::set_generate_value_changed(bool generate)
{
    gadget_flags flags = _get_flags();
    _set_flags(generate
               ? flags | numberrange_GENERATE_VALUE_CHANGED
               : flags & ~numberrange_GENERATE_VALUE_CHANGED);
}

/*
    Parameters  : void
    Returns     : bool  - The generate event status.
    Description : Get the NumberRange_ValueChanged event status.
*/
inline bool numberrange_b::get_generate_value_changed() const
{
    return BOOL(_get_flags() & numberrange_GENERATE_VALUE_CHANGED);
}

/*
    Parameters  : writable  - Is the field writable.
    Returns     : void
    Description : Set whether the numeric field is writable.
*/
inline void numberrange_b::set_writable(bool writable)
{
    gadget_flags flags = _get_flags();
    _set_flags(writable
               ? flags | numberrange_WRITABLE
               : flags & ~numberrange_WRITABLE);
}

/*
    Parameters  : void
    Returns     : bool  - Is the field writable.
    Description : Get whether the numeric field is writable.
*/
inline bool numberrange_b::get_writable() const
{
    return BOOL(_get_flags() & numberrange_WRITABLE);
}

/*
    Parameters  : display   - Is there a display area.
    Returns     : void
    Description : Set whether there is a diplay area.
*/
inline void numberrange_b::set_has_display(bool display)
{
    gadget_flags flags = _get_flags();
    _set_flags(display
               ? flags | numberrange_HAS_NUMERICAL_DISPLAY
               : flags & ~numberrange_HAS_NUMERICAL_DISPLAY);
}

/*
    Parameters  : void
    Returns     : bool  - Is there a display area.
    Description : Get whether there is a diplay area.
*/
inline bool numberrange_b::get_has_display() const
{
    return BOOL(_get_flags() & numberrange_HAS_NUMERICAL_DISPLAY);
}

/*
    Parameters  : adjusters - Are there adjuster arrows.
    Returns     : void
    Description : Set whether there are adjuster arrows.
*/
inline void numberrange_b::set_has_adjusters(bool adjusters)
{
    gadget_flags flags = _get_flags();
    _set_flags(adjusters
               ? flags | numberrange_ADJUSTERS
               : flags & ~numberrange_ADJUSTERS);
}

/*
    Parameters  : void
    Returns     : bool  - Are there adjuster arrows.
    Description : Get whether there are adjuster arrows.
*/
inline bool numberrange_b::get_has_adjusters() const
{
    return BOOL(_get_flags() & numberrange_ADJUSTERS);
}

/*
    Parameters  : slider    - The type of slider.
    Returns     : void
    Description : Set the type of slider, if any.
*/
inline void numberrange_b::set_slider_type(slider_type slider)
{
    gadget_flags flags = _get_flags() & ~numberrange_SLIDER_TYPE;
    if (slider == slider_right)
    {
        flags |= numberrange_SLIDER_TYPE_RIGHT << numberrange_SLIDER_TYPE_SHIFT;
    }
    else if (slider == slider_left)
    {
        flags |= numberrange_SLIDER_TYPE_LEFT << numberrange_SLIDER_TYPE_SHIFT;
    }
    _set_flags(flags);
}

/*
    Parameters  : void
    Returns     : slider_type   - The type of slider.
    Description : Get the type of slider, if any.
*/
inline numberrange_b::slider_type numberrange_b::get_slider_type() const
{
    gadget_flags flags = _get_flags() >> numberrange_SLIDER_TYPE_SHIFT;
    return  flags & numberrange_SLIDER_TYPE_RIGHT
            ? slider_right
            : (flags & numberrange_SLIDER_TYPE_LEFT
               ? slider_left : slider_none);
}

/*
    Parameters  : precision - The precision.
    Returns     : void
    Description : Set the precision.
*/
inline void numberrange_b::set_precision(int precision)
{
    _set_precision(precision);
}

/*
    Parameters  : void
    Returns     : int   - The precision.
    Description : Get the precision.
*/
inline int numberrange_b::get_precision() const
{
    return _get_precision();
}

/*
    Parameters  : value     - The value.
                  rounding  - The optional rounding mode.
    Returns     : void
    Description : Set the value scaled as displayed.
*/
inline void numberrange_b::set_value_scaled(double value,
                                            rounding_mode rounding)
{
    _set_value(scale(value, rounding));
}

/*
    Parameters  : void
    Returns     : double    - The value.
    Description : Get the value scaled as displayed.
*/
inline double numberrange_b::get_value_scaled() const
{
    return scale(_get_value());
}

/*
    Parameters  : lower     - The lower bound.
                  rounding  - The optional rounding mode.
    Returns     : void
    Description : Set the lower bound scaled as displayed.
*/
inline void numberrange_b::set_lower_bound_scaled(double lower,
                                                  rounding_mode rounding)
{
    _set_lower_bound(scale(lower, rounding));
}

/*
    Parameters  : void
    Returns     : double    - The value.
    Description : Get the lower bound scaled as displayed.
*/
inline double numberrange_b::get_lower_bound_scaled() const
{
    return scale(_get_lower_bound());
}

/*
    Parameters  : upper     - The lower bound.
                  rounding  - The optional rounding mode.
    Returns     : void
    Description : Set the upper bound scaled as displayed.
*/
inline void numberrange_b::set_upper_bound_scaled(double upper,
                                                  rounding_mode rounding)
{
    _set_upper_bound(scale(upper, rounding));
}

/*
    Parameters  : void
    Returns     : double    - The value.
    Description : Get the upper bound scaled as displayed.
*/
inline double numberrange_b::get_upper_bound_scaled() const
{
    return scale(_get_upper_bound());
}

/*
    Parameters  : step      - The step size.
                  rounding  - The optional rounding mode.
    Returns     : void
    Description : Set the step size scaled as displayed.
*/
inline void numberrange_b::set_step_size_scaled(double step,
                                                rounding_mode rounding)
{
    _set_step_size(scale(step, rounding));
}

/*
    Parameters  : void
    Returns     : double    - The value.
    Description : Get the step size scaled as displayed.
*/
inline double numberrange_b::get_step_size_scaled() const
{
    return scale(_get_step_size());
}

#endif
