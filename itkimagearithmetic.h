#ifndef ITKIMAGEARITHMETIC_H
#define ITKIMAGEARITHMETIC_H

#define itkArithmeticOperators1(OP, ImageFilter, ConstantImageFilter) \
template< typename PixelType, unsigned int Dimension >\
itk::SmartPointer< itk::Image< PixelType, Dimension> > operator OP ## =( \
  itk::SmartPointer< itk::Image< PixelType, Dimension> > im1, double c ) {\
  typedef typename itk::Image< PixelType, Dimension> ImageType;\
  typedef itk::ConstantImageFilter< ImageType, double, ImageType > FilterType;\
  typename FilterType::Pointer f = FilterType::New();\
  f->SetInput( im1 );\
  f->SetConstant( c );\
  f->Update();\
  typename ImageType::Pointer result = f->GetOutput();\
  return result;\
}\
template< typename PixelType, unsigned int Dimension >\
itk::SmartPointer< itk::Image< PixelType, Dimension> > operator OP( \
  itk::SmartPointer< itk::Image< PixelType, Dimension> > im, double c ) {\
  return typename itk::SmartPointer< itk::Image< PixelType, Dimension> >( im ) OP ## = c;\
}\
template< typename PixelType1,  typename PixelType2, unsigned int Dimension >\
itk::SmartPointer< itk::Image< PixelType1, Dimension> > operator OP ## =( \
  itk::SmartPointer< itk::Image< PixelType1, Dimension> > im1, \
  itk::SmartPointer< itk::Image< PixelType2, Dimension> > im2 ) {\
  typedef typename itk::Image< PixelType1, Dimension> ImageType1;\
  typedef typename itk::Image< PixelType2, Dimension> ImageType2;\
  typedef itk::ImageFilter< ImageType1, ImageType2, ImageType1 > FilterType;\
  typename FilterType::Pointer f = FilterType::New();\
  f->SetInput1( im1 );\
  f->SetInput2( im2 );\
  f->Update();\
  typename ImageType1::Pointer result = f->GetOutput();\
  return result;\
}\
template< typename PixelType1,  typename PixelType2, unsigned int Dimension >\
itk::SmartPointer< itk::Image< PixelType1, Dimension> > operator OP ( \
  itk::SmartPointer< itk::Image< PixelType1, Dimension> > im1, \
  itk::SmartPointer< itk::Image< PixelType2, Dimension> > im2 ) {\
  return typename itk::SmartPointer< itk::Image< PixelType1, Dimension> >( im1 ) OP ## = im2;\
}

#define itkArithmeticOperators(OP, ImageFilter, ConstantImageFilter) \
itkArithmeticOperators1(OP, ImageFilter, ConstantImageFilter)\
template< typename PixelType, unsigned int Dimension >\
itk::SmartPointer< itk::Image< PixelType, Dimension> > operator OP( \
  double c, itk::SmartPointer< itk::Image< PixelType, Dimension> > im ) {\
  return typename itk::SmartPointer< itk::Image< PixelType, Dimension> >( im ) OP ## = c;\
}

  
#include <itkAddImageFilter.h>
#include <../Review/itkAddConstantToImageFilter.h>

#include <itkSubtractImageFilter.h>
#include <../Review/itkSubtractConstantFromImageFilter.h>

#include <itkMultiplyImageFilter.h>
#include <../Review/itkMultiplyByConstantImageFilter.h>

#include <itkDivideImageFilter.h>
#include <../Review/itkDivideByConstantImageFilter.h>

namespace itkhelper {
itkArithmeticOperators(+,AddImageFilter,AddConstantToImageFilter)
itkArithmeticOperators1(-,SubtractImageFilter,SubtractConstantFromImageFilter)
itkArithmeticOperators(*,MultiplyImageFilter,MultiplyByConstantImageFilter)
itkArithmeticOperators1(/,DivideImageFilter,DivideByConstantImageFilter)
}

#undef itkArithmeticOperators
#undef itkArithmeticOperators1


#endif // ITKIMAGEARITHMETIC_H
