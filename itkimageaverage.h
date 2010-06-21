#ifndef ITKIMAGEAVERAGE_H
#define ITKIMAGEAVERAGE_H

#include "itkImageRegionConstIterator.h"
#include "itkNumericTraits.h"

namespace itkhelper {

template< typename PixelType, unsigned int Dimension >
typename itk::NumericTraits< PixelType >::AccumulateType averagePixel(
  itk::SmartPointer< itk::Image< PixelType, Dimension > > image) {
  typedef typename itk::Image< PixelType, Dimension > ImageType;
  typedef typename itk::ImageRegionConstIterator< ImageType > IteratorType;
  typedef typename itk::NumericTraits< PixelType >::AccumulateType AccumulatePixelType;
  
  AccumulatePixelType avg = itk::NumericTraits< AccumulatePixelType >::Zero;
  IteratorType it( image, image->GetRequestedRegion() );
  it.GoToBegin();
  while( !it.IsAtEnd() )
  {
    avg += it.Value();
    ++it;
  }  
  typename ImageType::RegionType::SizeType size = image->GetRequestedRegion().GetSize();
  unsigned int numPix = 1;
  for( unsigned int d = 0; d < size.GetSizeDimension(); d++) numPix *= size[d];
  
  return avg/numPix;
}  
  
}

#endif // ITKIMAGEAVERAGE_H
