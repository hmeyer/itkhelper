#include "itkImage.h"

#include "itkimagearithmetic.h"



typedef unsigned short ShortPixelType;
typedef double DoublePixelType;

typedef itk::Image< ShortPixelType, 2 > Image2DShort;
typedef itk::Image< ShortPixelType, 2 > Image2DDouble;
typedef itk::Image< ShortPixelType, 3 > Image3DShort;
typedef itk::Image< ShortPixelType, 3 > Image3DDouble;

int main( int argc, char **argv ) {
  Image2DShort::Pointer i2s_1, i2s_2, i2s_3;

  i2s_3 += i2s_1 + i2s_2 + 3.0 + i2s_1;
  i2s_3 += i2s_1 / 4.0;

  Image2DDouble::Pointer i2d;
  
  i2d = i2d + i2s_3 + 2.0;

  Image3DShort::Pointer i3s;
  Image3DDouble::Pointer i3d;

  i3d = i3d + i3d;

  
  
  return 0;
}
