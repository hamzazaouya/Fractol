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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	destroy(t_fract *fract)
{
	mlx_destroy_image(fract->mlx, fract->img.img);
	mlx_destroy_window(fract->mlx, fract->mlx_win);
	exit(0);
}

void	ft_make_fract(t_fract *fract)
{
	fract->mlx = mlx_init();
	fract->mlx_win = mlx_new_window(fract->mlx, HEIGHT, WIDTH, "Fractol");
	fract->img.img = mlx_new_image(fract->mlx, HEIGHT, WIDTH);
	fract->img.addr = mlx_get_data_addr(fract->img.img, \
	&fract->img.bits_per_pixel, &fract->img.line_length, &fract->img.endian);
	if (fract->fract_type == 2)
		julia_orient(&fract->c);
	ft_fractal(fract);
	mlx_mouse_hook (fract->mlx_win, zoom_control, fract);
	mlx_key_hook (fract->mlx_win, key_control, fract);
	mlx_hook(fract->mlx_win, 17, 0L, destroy, fract);
	mlx_put_image_to_window(fract->mlx, fract->mlx_win, fract->img.img, 0, 0);
	mlx_loop(fract->mlx);
}

int	ft_check(t_fract *fract, char *str, int arc)
{
	if (!ft_strcmp(str, "Mandelbrot"))
	{
		if (arc == 2)
			fract->fract_type = 1;
	}
	else if (!ft_strcmp(str, "Julia"))
	{
		if (arc == 2 || arc == 3)
			fract->fract_type = 2;
	}
	else if (!ft_strcmp(str, "Tricorn"))
	{
		if (arc == 2)
			fract->fract_type = 3;
	}
	return (fract->fract_type);
}

int	main(int arc, char **arv)
{
	t_fract	fract;
	int		checker;

	ft_init(&fract);
	checker = -1;
	if (arc > 1)
		checker = ft_check(&fract, arv[1], arc);
	if (checker == 2 && (arc == 3 || arc == 2))
	{
		if (arc == 2)
			fract.c.par = 0;
		else if ((arv[2][0] >= '0' && arv[2][0] <= '5') && arv[2][1] == 0)
			fract.c.par = arv[2][0] - '0';
		else
			checker = 0;
	}
	if (!checker || arc == 1)
	{
		ft_msg();
		return (0);
	}
	if (checker != -1)
		ft_make_fract(&fract);
	return (0);
}
