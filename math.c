#include "fractol.h"

double ft_powf(double num, int pow){
    int i;
    float temp;

    i = 0;
    temp = num;
    while(i < pow - 1){
        num *= temp;
        i++;
    }
    return (num);
}