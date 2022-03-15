#include "fractol.h"

int    zoom_control(int key, int x, int y, t_fract *fract)
{
    double zoom_factor = 0.5;

    if (key == 5)
    {
        fract->interp *=  zoom_factor;
        zoom_in(fract, x, y);
        fract->max_iterate += 20;
    }
    else if (key == 4)
    {
        zoom_out(fract, x, y);
        if(fract->max_iterate > 60)
            fract->max_iterate -= 20;
        fract->interp /= zoom_factor;
    }
    if(fract->fract_type == 1)
        ft_mandelbrot(fract);
    if(fract->fract_type == 2)
        ft_julia(fract);
    return (0);
}

void    zoom_in(t_fract *fract, int x, int y)
{
    fract->re_min += (x * fract->interp);
    fract->im_max -= (y * fract->interp);
}

void    zoom_out(t_fract *fract, int x, int y)
{
    fract->re_min -= (x * fract->interp);
    fract->im_max += (y * fract->interp);
}
