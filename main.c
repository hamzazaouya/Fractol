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
	if(fract->fract_type == 1)
		ft_mandelbrot(fract);
	else if(fract->fract_type == 2){
		julia_orient(&fract->c);
		ft_julia(fract);
	}
	mlx_mouse_hook (fract->mlx_win, zoom_control, fract);
	mlx_key_hook ( fract->mlx_win, key_control, fract);
	mlx_put_image_to_window(fract->mlx, fract->mlx_win, fract->img.img, 0, 0);
	mlx_loop(fract->mlx);	
}


int	main(int arc, char **arv)
{
	t_fract	fract;
	int checker;

	ft_init(&fract);
	checker = 0;
	if(arc > 1)
		checker = ft_check(&fract, arv[1]);
	if(checker == 2 && arc == 3)
		fract.c.par = ft_atoi(arv[2]);
	if(!checker || (!(fract.c.par >= 0 && fract.c.par <= 5) && checker == 2))
	{
		ft_msg();
		return(0);
	}
	if(checker)
		ft_fractal(&fract);
	return (0);
}
