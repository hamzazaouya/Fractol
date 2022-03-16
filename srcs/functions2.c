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

int	zoom_control(int key, int x, int y, t_fract *fract)
{
	double	zoom_factor;

	zoom_factor = 0.5;
	if (key == 5)
	{
		fract->interp *= zoom_factor;
		zoom_in(fract, x, y);
		fract->max_iterate += 20;
	}
	else if (key == 4)
	{
		zoom_out(fract, x, y);
		if (fract->max_iterate > 60)
			fract->max_iterate -= 20;
		fract->interp /= zoom_factor;
	}
	ft_fractal(fract);
	return (0);
}

void	zoom_in(t_fract *fract, int x, int y)
{
	fract->re_min += (x * fract->interp);
	fract->im_max -= (y * fract->interp);
}

void	zoom_out(t_fract *fract, int x, int y)
{
	fract->re_min -= (x * fract->interp);
	fract->im_max += (y * fract->interp);
}

double	ft_powf(double num, int pow)
{
	int		i;
	float	temp;

	i = 0;
	temp = num;
	while (i < pow - 1)
	{
		num *= temp;
		i++;
	}
	return (num);
}

int	key_control(int key, t_fract *fract)
{
	if (key >= 123 && key <= 126)
	{
		if (key == 123)
			fract->re_min -= (fract->interp * 10);
		else if (key == 124)
			fract->re_min += (fract->interp * 10);
		else if (key == 125)
			fract->im_max -= (fract->interp * 10);
		else if (key == 126)
			fract->im_max += (fract->interp * 10);
		ft_fractal(fract);
	}
	return (0);
}
