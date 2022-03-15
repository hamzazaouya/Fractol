#include "fractol.h"

float ft_powf(float num, int pow){
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