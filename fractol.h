#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include <string.h>
#define WIDTH 800
#define HEIGHT 800

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct d_complex {
	int		par;
	double	imag;
	double	real;
}				t_complex;

typedef struct fract{
	void	*mlx;
	void	*mlx_win;
	double	im_max;
	double	im_min;
	double	re_max;
	double	re_min;
	double	re_ftr;
	double	im_ftr;
	double	interp;
	int		max_iterate;
	int		key_ctr;
	int		fract_type;
	t_complex c;
    t_data img;
}	t_fract;

int HSVtoRGB(float H, float S,float V, int key_ctr);
int		zoom_control(int key, int x, int y, t_fract *fract);
void    zoom_in(t_fract *fract, int x, int y);
void    zoom_out(t_fract *fract, int x, int y);
void	ft_printer(t_fract *fract);
double	ft_powf(double num, int pow);
int		ft_getcolor(t_fract *fract ,int iterate);
void	ft_mandelbrot(t_fract *fract);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_julia(t_fract *fract);
int		key_control(int key, t_fract *fract);
void	ft_init(t_fract *fract);
int		ft_check(t_fract *fract, char *str);
void	ft_msg(void);
void	julia_orient(t_complex *c);
int	ft_atoi(const char *str);