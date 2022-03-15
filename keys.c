#include "fractol.h"

void ft_fract_applay(t_fract *fract)
{
    if(fract->fract_type == 0)
        ft_mandelbrot(fract);
    else if(fract->fract_type == 1)
        ft_julia(fract);
}

int    key_control(int key, t_fract *fract)
{
    float temp;
    if(key >= 123 && key <= 126){
        if(key == 123)
            fract->re_min += (fract->interp * 10);
        else if(key == 124)
            fract->re_min -= (fract->interp * 10);
        else if(key == 125)
            fract->im_max -= (fract->interp * 10);
        else if(key == 126)
            fract->im_max += (fract->interp * 10);
        ft_fract_applay(fract);
    }
    return (0);
}