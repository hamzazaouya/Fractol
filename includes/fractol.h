/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:56:03 by hazaouya          #+#    #+#             */
/*   Updated: 2022/03/16 10:13:00 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>
# define WIDTH 800
# define HEIGHT 800

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

typedef struct d_complex {
	int		par;
	double	imag;
	double	real;
}		t_complex;

typedef struct fract{
	void		*mlx;
	void		*mlx_win;
	double		im_max;
	double		im_min;
	double		re_max;
	double		re_min;
	double		re_ftr;
	double		im_ftr;
	double		interp;
	int			max_iterate;
	int			key_ctr;
	int			fract_type;
	t_complex	c;
	t_data		img;
}	t_fract;

int		HSVtoRGB(float H, float S, float V, int key_ctr);
int		zoom_control(int key, int x, int y, t_fract *fract);
void	zoom_in(t_fract *fract, int x, int y);
void	zoom_out(t_fract *fract, int x, int y);
void	ft_printer(t_fract *fract);
double	ft_powf(double num, int pow);
int		ft_getcolor(t_fract *fract, int iterate);
void	ft_fractal(t_fract *fract);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_julia(t_fract *fract, float x, float y);
int		key_control(int key, t_fract *fract);
void	ft_init(t_fract *fract);
int		ft_check(t_fract *fract, char *str, int arc);
void	ft_msg(void);
void	julia_orient(t_complex *c);
int		ft_atoi(const char *str);
int		calc_color(t_fract *frctl, int i);
int		ft_strcmp(char *s1, char *s2);
#endif
