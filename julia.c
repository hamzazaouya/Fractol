#include "fractol.h"

int	ft_jul_iterate(t_fract *fract ,float x, float y, float max_iterate)
{
	double	reale_num;
	double	imge_num;
	double	reale;
	int		iterate;
	t_complex	c;

	iterate = 0;
	reale_num = x;
	imge_num = y;
	while(iterate < max_iterate)
	{
		reale = reale_num;
		reale_num = ft_powf(reale_num, 2) - ft_powf(imge_num, 2) + fract->c.real;
		imge_num = (2 * reale * imge_num) + fract->c.imag;
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

void	julia_orient(t_complex *c)
{
	printf("%d\n", c->par);
	if (!c->par)
	{
		c->real = -0.4;
		c->imag = 0.6;
	}
	else if (c->par == 1){
		c->real = -0.8;
		c->imag = 0.156;
	}
	else if (c->par == 2){
		c->real = -0.7269;
		c->imag = 0.1889;
	}	
	else if (c->par == 3){
		c->real = -0.203333;
		c->imag = -0.696667;
	}
	else if (c->par == 4){
		c->real = 0.0;
		c->imag = -0.8;
	}
	else if (c->par == 5){
		c->real = 0.371504;
		c->imag = -0.153893;
	}
}