#include "itkImage.h"

#include "itkimagearithmetic.h"
#include "itkimagereader.h"
#include "itkimagewriter.h"
#include "itkimagecaster.h"
#include "itkimagerescaler.h"
#include "itkgaussfilter.h"

#include "itkimagevariance.h"

#include "itkimageaverage.h"

using namespace itkhelper;

typedef signed short IntPixelType;
typedef double FloatPixelType;

typedef itk::Image< IntPixelType, 2 > Image2DInt;
typedef itk::Image< FloatPixelType, 2 > Image2DFloat;
typedef itk::Image< IntPixelType, 3 > Image3DInt;
typedef itk::Image< FloatPixelType, 3 > Image3DFloat;


int main( int argc, char **argv ) {
  
  if (argc != 4) { std::cerr << "usage:" << argv[0] << " image1 image2 ssim-map-out" << std::endl; exit(0); }
  
  Image2DFloat::Pointer x = readImageFile<Image2DFloat>(argv[1]);
  Image2DFloat::Pointer y = readImageFile<Image2DFloat>(argv[2]);
  
  const float FilterSigma = 11;
  const float DynRange = 255;
  const float K1 = 0.01;
  const float K2 = 0.03;
  const float C1 = (K1 * DynRange) * (K1 * DynRange);
  const float C2 = (K2 * DynRange) * (K2 * DynRange);
  Image2DFloat::Pointer mu_x_sq, mu_y_sq, mu_x_y, sigma_x_sq, sigma_y_sq, sigma_x_y;
  {
    Image2DFloat::Pointer mu_x, mu_y;
    mu_x = Gauss<FloatPixelType>::filter(x, FilterSigma);
    mu_x_sq = mu_x * mu_x;
    mu_y = Gauss<FloatPixelType>::filter(y, FilterSigma);
    mu_y_sq = mu_y * mu_y;
    mu_x_y = mu_x * mu_y;
  }
  
  sigma_x_sq = Gauss<FloatPixelType>::filter( x * x, FilterSigma ) - mu_x_sq;
  sigma_y_sq = Gauss<FloatPixelType>::filter( y * y, FilterSigma ) - mu_y_sq;
  sigma_x_y  = Gauss<FloatPixelType>::filter( x * y, FilterSigma ) - mu_x_y;
  
  
  Image2DFloat::Pointer ssim = ( mu_x_y * 2 + C1 ) * ( sigma_x_y * 2 + C2)
			      / (( mu_x_sq + mu_y_sq + C1 ) * ( sigma_x_sq + sigma_y_sq + C2 ) );
			      
  std::cout << "SSIM:" << averagePixel( ssim ) << std::endl;
  
  writeImageFile(Rescaler<unsigned char>::rescale(ssim), argv[3]);
  
  return 0;
}
