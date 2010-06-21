#ifndef ITKIMAGECASTER_H
#define ITKIMAGECASTER_H

#include <itkCastImageFilter.h>

namespace itkhelper {
  
template< typename NewPixelType >
struct Caster {
template< typename PixelType, unsigned int Dimension >
static itk::SmartPointer< itk::Image< NewPixelType, Dimension > > cast( 
  itk::SmartPointer< itk::Image< PixelType, Dimension > > image ) {
  typedef typename itk::Image< PixelType, Dimension > OldImageType;
  typedef typename itk::Image< NewPixelType, Dimension > NewImageType;
  typedef itk::CastImageFilter< OldImageType, NewImageType > CastFilterType;
  typename CastFilterType::Pointer caster = CastFilterType::New();
  caster->SetInput( image );
  caster->Update();
  typename NewImageType::Pointer result = caster->GetOutput();
  return result;
}
};

}

#endif //ITKIMAGECASTER_H