#include "fractol.h"

int	ft_jul_iterate(t_fract *fract ,float x, float y, float max_iterate)
{
	float	reale_num;
	float	imge_num;
	float	reale;
	int		iterate;

	iterate = 0;
	reale_num = x;
	imge_num = y;
	while(iterate < max_iterate)
	{
		reale = reale_num;
		reale_num = ft_powf(reale_num, 2) - ft_powf(imge_num, 2) + 0;
		imge_num = (2 * reale * imge_num) + 0;
		if(ft_powf(reale_num, 2) +  ft_powf(imge_num, 2) >= 4)
			break;
		iterate++;
	}
	if (iterate == max_iterate)
		return (0);
	return(HSVtoRGB(255 * iterate / fract->max_iterate, 255, 255, fract->key_ctr));
}

void	ft_julia(t_fract *fract)
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
			my_mlx_pixel_put(&fract->img, j, i, ft_jul_iterate(fract, fract->re_min +  j * fract->interp, fract->im_max - i * fract->interp, fract->max_iterate));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fract->mlx, fract->mlx_win, fract->img.img, 0, 0);
}

t_complex	julia_orient(t_display *mlx, int par)
{
	t_complex	c;

	if (!par)
		c = (t_complex){.real = -0.4, .imag = 0.6};
	else if (par == 1)
		c = (t_complex){.real = -0.8, .imag = 0.156};
	else if (par == 2)
		c = (t_complex){.real = -0.7269, .imag = 0.1889};
	else if (par == 3)
		c = (t_complex){.real = -0.203333, .imag = -0.696667};
	else if (par == 4)
		c = (t_complex){.real = 0.0, .imag = -0.8};
	else if (par == 5)
		c = (t_complex){.real = 0.371504, .imag = -0.153893};
	return (c);
}