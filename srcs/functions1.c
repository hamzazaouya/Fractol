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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_init(t_fract *fract)
{
	fract->re_max = 2.0;
	fract->re_min = -2.0;
	fract->im_max = 2.0;
	fract->im_min = -2.0;
	fract->key_ctr = 0;
	fract->fract_type = 0;
	fract->c.par = 0;
	fract->interp = (fract->re_max) / (WIDTH / 2.0);
	fract->max_iterate = 60;
}

void	ft_msg(void)
{
	write(1, "\n<------------------------------------------------>\n", 53);
	write(1, "\n                  !! UNVALID FRACTAL !!\n\n", 42);
	write(1, "You can choose one of those:\n\n", 30);
	write(1, "-> Mandelbrot\n\n", 15);
	write(1, "-> Julia [From 0 To 5]\n\n", 24);
	write(1, "-> Tricorn\n", 11);
	write(1, "\n<------------------------------------------------->\n", 70);
}

int	calc_color(t_fract *fract, int i)
{
	uint8_t	rgb[3];
	double	div;

	div = (double)i / fract->max_iterate;
	rgb[0] = 9 * (1 - div) * (int )ft_powf(div, 3) * 255;
	rgb[1] = 15 * (int )ft_powf((1 - div), 2) * (int )ft_powf(div, 2) * 255;
	rgb[2] = 9 * (int )ft_powf((1 - div), 3) * div * 255;
	return (0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}
