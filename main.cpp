#include "itkImage.h"

#include "itkimagearithmetic.h"
#include "itkimagereader.h"
#include "itkimagewriter.h"
#include "itkimagecaster.h"

using namespace itkhelper;

typedef unsigned short IntPixelType;
typedef double DoublePixelType;

typedef itk::Image< IntPixelType, 2 > Image2DShort;
typedef itk::Image< DoublePixelType, 2 > Image2DDouble;
typedef itk::Image< IntPixelType, 3 > Image3DShort;
typedef itk::Image< DoublePixelType, 3 > Image3DDouble;


int main( int argc, char **argv ) {
  
  Image2DDouble::Pointer t1 = readImageFile<Image2DDouble>("/home/hmeyer/Desktop/thorax1.png");

  Image2DDouble::Pointer t2 = readImageFile<Image2DDouble>("/home/hmeyer/Desktop/thorax2.png");
  Image2DDouble::Pointer t3 = readImageFile<Image2DDouble>("/home/hmeyer/Desktop/thorax3.png");
  
  Image2DDouble::Pointer diff = t2 - t3 *2.0;
  diff+=t2*t3;
  t3/=5.0;
//  Image2DShort::Pointer diff_short = cast< IntPixelType >( diff );
  writeImageFile(diff, "/home/hmeyer/Desktop/thorax_diff.png");
/*  
  Image2DShort::Pointer i2s_1, i2s_2, i2s_3;

  i2s_3 += i2s_1 + i2s_2 + 3.0 + i2s_1;
  i2s_3 += i2s_1 / 4.0;

  Image2DDouble::Pointer i2d;
  
  i2d = i2d + i2s_3 + 2.0;

  Image3DShort::Pointer i3s;
  Image3DDouble::Pointer i3d;

  i3d = i3d + i3d;
*/
  
  
  return 0;
}
