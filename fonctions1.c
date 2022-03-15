#include "fractol.h"

int ft_strcmp(char *s1, char *s2){
    int i;

    i = 0;
    while(s1[i] || s2[i]) {
        if(s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}

void ft_init(t_fract *fract) {
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

int	ft_check(t_fract *fract, char *str) {
	if(!ft_strcmp(str, "Mandelbrot"))
		fract->fract_type = 1;
	else if(!ft_strcmp(str, "Julia"))
	{
		fract->fract_type = 2;
	}
	else if(!ft_strcmp(str, "Tricorn"))
		fract->fract_type = 3;
	return(fract->fract_type);
}

void	ft_msg(void){
	printf("\n-------------------------------------------------------------------\n");
	printf("\n                  !! UNVALID FRACTAL !!\n\n");
	printf("You can choose one of those:\n\n");
	printf("-> Mandelbrot\n\n");
	printf("-> Julia [From 0 To 5]\n\n");
	printf("-> Tricorn\n");
	printf("\n-------------------------------------------------------------------\n");
}
