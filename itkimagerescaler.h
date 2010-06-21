#ifndef ITKIMAGERESCALER_H
#define ITKIMAGERESCALER_H

#include <itkRescaleIntensityImageFilter.h>
#include <itkNumericTraits.h>

namespace itkhelper {

template< typename NewPixelType >
struct Rescaler {
template< typename PixelType, unsigned int Dimension >
static itk::SmartPointer< itk::Image< NewPixelType, Dimension > > rescale(
  itk::SmartPointer< itk::Image< PixelType, Dimension > > image,
  NewPixelType min = itk::NumericTraits<NewPixelType>::min() ,
  NewPixelType max = itk::NumericTraits<NewPixelType>::max()) {
  typedef typename itk::Image< PixelType, Dimension > OldImageType;
  typedef typename itk::Image< NewPixelType, Dimension > NewImageType;
  typedef itk::RescaleIntensityImageFilter< OldImageType, NewImageType > RescaleFilterType;
  typename RescaleFilterType::Pointer rescaler = RescaleFilterType::New();
  rescaler->SetInput( image );
  rescaler->SetOutputMinimum( min );
  rescaler->SetOutputMaximum( max );
  rescaler->Update();
  typename NewImageType::Pointer result = rescaler->GetOutput();
  return result;
}
};

}


#endif //ITKIMAGERESCALER_H