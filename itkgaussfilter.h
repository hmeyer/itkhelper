#ifndef ITKGAUSSFILTER_H
#define ITKGAUSSFILTER_H

#include <itkSmoothingRecursiveGaussianImageFilter.h>
#include <itkNumericTraits.h>

namespace itkhelper {
  
  
template< typename NewPixelType >
struct Gauss {
template< typename PixelType, unsigned int Dimension >
static itk::SmartPointer< itk::Image< NewPixelType, Dimension > > filter(
  itk::SmartPointer< itk::Image< PixelType, Dimension > > image,
  typename itk::NumericTraits<PixelType>::ScalarRealType sigma) {
  typedef typename itk::Image< PixelType, Dimension > OldImageType;
  typedef typename itk::Image< NewPixelType, Dimension > NewImageType;
  typedef itk::SmoothingRecursiveGaussianImageFilter< OldImageType, NewImageType > GaussFilterType;
  typename GaussFilterType::Pointer gaussf = GaussFilterType::New();
  gaussf->SetInput( image );
  gaussf->SetSigma ( sigma );
  gaussf->Update();
  typename NewImageType::Pointer result = gaussf->GetOutput();
  return result;
}
};

}

#endif //ITKGAUSSFILTER_H
	