#include "fractol.h"

void ft_getrgb(float H, float X, float S, float *rgb){
  if(H >= 0 && H < 60){
      rgb[0] = S;
		  rgb[1] = X;
		  rgb[2] = 0;
    }
    else if(H >= 60 && H < 120){
      rgb[0] = X;
		  rgb[1] = S;
		  rgb[2] = 0;
    }
    else if(H >= 120 && H < 180){
    rgb[0] = 0;
		rgb[1] = S;
		rgb[2] = X;
    }
    else if(H >= 180 && H < 240){
    rgb[0] = 0;
		rgb[1] = X;
		rgb[2] = S;
    }
    else if(H >= 240 && H < 300){
    rgb[0] = X;
		rgb[1] = 0;
		rgb[2] = S;
    }
    else{
    rgb[0] = S;
		rgb[1]= 0;
		rgb[2] = X;
    }
}

int HSVtoRGB(float H, float S,float V, int key_ctr)
{
  float X;
  float m; 
  float rgb[3];
  int RGB[3];

	S = S * 0.39215686274;
	if (V == 255)
		V = 100;
  S /= 100;
  V /= 100;
  S *= V;
  m = V-S;
  X = S * (1-fabs(fmod(H/60.0, 2)-1));
  ft_getrgb(H, X, S, rgb);
  RGB[0] = (rgb[0]+m) * 255;
  RGB[1] = (rgb[1]+m)*255;
  RGB[2] = (rgb[2]+m)*255;
	RGB[0] = RGB[key_ctr % 3] << 16;
	RGB[1] = RGB[(1 + key_ctr) % 3] << 8;
	return ( RGB[0] | RGB[1] | RGB[2]);
}
