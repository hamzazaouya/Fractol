#include <stdio.h>
#include <mlx.h>
#include <math.h>
#define WIDTH 600
#define HEIGHT 600

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct d_complex {
	double	imag;
	double	real;
}				t_complex;

typedef struct fract{
	void	*mlx;
	void	*mlx_win;
	float	im_max;
	float	im_min;
	float	re_max;
	float	re_min;
	float	re_ftr;
	float	im_ftr;
	float	zoom_facture;
	float	interp;
	int		max_iterate;
	int		key_ctr;
	int		fract_type;
    t_data img;
}	t_fract;

int		HSVtoRGB(float H, float S,float V, int key_ctr);
int		zoom_control(int key, int x, int y, t_fract *fract);
void    zoom_in(t_fract *fract, int x, int y);
void    zoom_out(t_fract *fract, int x, int y);
void	ft_printer(t_fract *fract);
float	ft_powf(float num, int pow);
int		ft_getcolor(t_fract *fract ,int iterate);
void	ft_mandelbrot(t_fract *fract);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_julia(t_fract *fract);
int		key_control(int key, t_fract *fract);