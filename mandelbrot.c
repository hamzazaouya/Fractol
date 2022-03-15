#include "fractol.h"

int	ft_brot_iterate(t_fract *fract ,float x, float y, float max_iterate)
{
	float	reale_num;
	float	imge_num;
	float	reale;
	int		iterate;

	iterate = 0;
	reale_num = 0;
	imge_num = 0;
	while(iterate < max_iterate)
	{
		reale = reale_num;
		reale_num = ft_powf(reale_num, 2) - ft_powf(imge_num, 2) + x;
		imge_num = (2 * reale * imge_num) + y;
		if(ft_powf(reale_num, 2) +  ft_powf(imge_num, 2) >= 4)
			break;
		iterate++;
	}
	if (iterate == max_iterate)
		return (0);
	return(HSVtoRGB(255 * iterate / fract->max_iterate, 255, 255, fract->key_ctr));
}

void	ft_mandelbrot(t_fract *fract)
{	
	int i;
	int j;
	int	color;


	i = 0;
	while(i < HEIGHT)
	{
		j = 0;
		while(j < WIDTH)
		{
			my_mlx_pixel_put(&fract->img, j, i, ft_brot_iterate(fract, fract->re_min +  j * fract->interp, fract->im_max - i * fract->interp, fract->max_iterate));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fract->mlx, fract->mlx_win, fract->img.img, 0, 0);
}