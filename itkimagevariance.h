#ifndef ITKIMAGEVARIANCE_H
#define ITKIMAGEVARIANCE_H

#include "itkimagearithmetic.h"
#include "itkgaussfilter.h"


namespace itkhelper {
  
template< typename PixelType, unsigned int Dimension >
itk::SmartPointer< itk::Image< PixelType, Dimension > > variance(
  itk::SmartPointer< itk::Image< PixelType, Dimension > > image,
  typename itk::NumericTraits<PixelType>::ScalarRealType sigma) {
  typedef typename itk::Image< PixelType, Dimension >::Pointer ImagePointerType;
  
  ImagePointerType sigma_sq;
  {
    ImagePointerType mu_sq;
    {
      ImagePointerType mu = Gauss<PixelType>::filter(image, sigma);
      mu_sq = mu * mu;
    }
    sigma_sq = Gauss<PixelType>::filter(image * image, sigma) - mu_sq;
  }
  
  return sigma_sq;
}

template< typename PixelType, unsigned int Dimension >
itk::SmartPointer< itk::Image< PixelType, Dimension > > covariance(
  itk::SmartPointer< itk::Image< PixelType, Dimension > > image1,
  itk::SmartPointer< itk::Image< PixelType, Dimension > > image2,
  typename itk::NumericTraits<PixelType>::ScalarRealType sigma) {
  typedef typename itk::Image< PixelType, Dimension >::Pointer ImagePointerType;
  ImagePointerType mu12 = Gauss<PixelType>::filter(image2, sigma) * Gauss<PixelType>::filter(image2, sigma);
  return Gauss<PixelType>::filter(image1 * image2, sigma) - mu12;
}


}


#endif //ITKIMAGEVARIANCE_H
