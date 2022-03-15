#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}



void	ft_fractal(t_fract *fract)
{
	fract->mlx = mlx_init();
	fract->mlx_win = mlx_new_window(fract->mlx, HEIGHT, WIDTH, "Fractol");
	fract->img.img = mlx_new_image(fract->mlx, HEIGHT, WIDTH);
	fract->img.addr = mlx_get_data_addr(fract->img.img, &fract->img.bits_per_pixel, &fract->img.line_length, &fract->img.endian);
	if(fract->fract_type == 0)
		ft_mandelbrot(fract);
	else if(fract->fract_type == 1)
		ft_julia(fract);
	mlx_mouse_hook (fract->mlx_win, zoom_control, fract);
	mlx_key_hook ( fract->mlx_win, key_control, fract);
	mlx_put_image_to_window(fract->mlx, fract->mlx_win, fract->img.img, 0, 0);
	mlx_loop(fract->mlx);	
}

int	main(void)
{
	t_fract	fract;

	fract.re_max = 2.0;
	fract.re_min = -2.0;
	fract.im_max = 2.0;
	fract.im_min = -2.0;
	fract.key_ctr = 0;
	fract.fract_type = 1;
	fract.interp = (fract.re_max) / (WIDTH / 2.0);
	fract.max_iterate = 60;
	ft_fractal(&fract);
}
