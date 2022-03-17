/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:13:09 by hazaouya          #+#    #+#             */
/*   Updated: 2022/03/16 10:17:32 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_mandelbrot(t_fract *fract, double x, double y)
{
	double	reale_num;
	double	imge_num;
	double	reale;
	int		iterate;

	iterate = 0;
	reale_num = 0;
	imge_num = 0;
	while (iterate < fract->max_iterate)
	{
		reale = reale_num;
		reale_num = ft_powf(reale_num, 2) - ft_powf(imge_num, 2) + x;
		imge_num = (2 * reale * imge_num) + y;
		if (ft_powf(reale_num, 2) + ft_powf(imge_num, 2) >= 4)
			break ;
		iterate++;
	}
	if (iterate == fract->max_iterate)
		return (0);
	return (calc_color(fract, iterate));
}

int	ft_julia(t_fract *fract, double x, double y)
{
	double		reale_num;
	double		imge_num;
	double		reale;
	int			iterate;

	iterate = 0;
	reale_num = x;
	imge_num = y;
	while (iterate < fract->max_iterate)
	{
		reale = reale_num;
		reale_num = ft_powf(reale_num, 2) - ft_powf(imge_num, 2) + \
		fract->c.real;
		imge_num = (2 * reale * imge_num) + fract->c.imag;
		if (ft_powf(reale_num, 2) + ft_powf(imge_num, 2) >= 4)
			break ;
		iterate++;
	}
	if (iterate == fract->max_iterate)
		return (0);
	return (calc_color(fract, iterate));
}

void	ft_fractal(t_fract *fract)
{	
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (fract->fract_type == 1)
				color = ft_mandelbrot(fract, fract->re_min + (j * \
				fract->interp), fract->im_max - (i * fract->interp));
			else if (fract->fract_type == 2)
				color = ft_julia(fract, fract->re_min + (j * \
				fract->interp), fract->im_max - (i * fract->interp));
			my_mlx_pixel_put(&fract->img, j, i, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fract->mlx, fract->mlx_win, fract->img.img, 0, 0);
}

void	julia_orient2(t_complex *c)
{
	if (c->par == 3)
	{
		c->real = -0.203333;
		c->imag = -0.696667;
	}
	else if (c->par == 4)
	{
		c->real = 0.0;
		c->imag = -0.8;
	}
	else if (c->par == 5)
	{
		c->real = 0.371504;
		c->imag = -0.153893;
	}
}

void	julia_orient(t_complex *c)
{
	if (!c->par)
	{
		c->real = -0.4;
		c->imag = 0.6;
	}
	else if (c->par == 1)
	{
		c->real = -0.8;
		c->imag = 0.156;
	}
	else if (c->par == 2)
	{
		c->real = -0.7269;
		c->imag = 0.1889;
	}
	else
		julia_orient2(c);
}
