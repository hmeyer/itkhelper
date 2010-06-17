#ifndef ITKIMAGEARITHMETIC_H
#define ITKIMAGEARITHMETIC_H


#define itkArithmeticOperators1(OP, ImageFilter, ConstantImageFilter) \
template< class ImagePointerType >\
ImagePointerType operator OP ## =( ImagePointerType im1, double c ) {\
        typedef typename ImagePointerType::ObjectType ImageType;\
        typedef itk::ConstantImageFilter< ImageType, double, ImageType > FilterType;\
        typename FilterType::Pointer f = FilterType::New();\
        f->SetInput( im1 );\
        f->SetConstant( c );\
        f->Update();\
        ImagePointerType result = f->GetOutput();\
        return result;\
}\
template< class ImagePointerType >\
ImagePointerType operator OP( ImagePointerType im, double c ) {\
	return ImagePointerType( im ) OP ## = c;\
}\
template< class ImagePointerType1, class ImagePointerType2 >\
ImagePointerType1 operator OP ## =( ImagePointerType1 im1, ImagePointerType2 im2 ) {\
	typedef typename ImagePointerType1::ObjectType ImageType1;\
	typedef typename ImagePointerType2::ObjectType ImageType2;\
	typedef itk::ImageFilter< ImageType1, ImageType2, ImageType1 > FilterType;\
	typename FilterType::Pointer f = FilterType::New();\
	f->SetInput1( im1 );\
	f->SetInput2( im2 );\
	f->Update();\
	ImagePointerType1 result = f->GetOutput();\
	return result;\
}\
template< class ImagePointerType1, class ImagePointerType2 >\
ImagePointerType1 operator OP( ImagePointerType1 im1, ImagePointerType2 im2 ) {\
	return ImagePointerType1( im1 ) OP ## = im2;\
}
#define itkArithmeticOperators2(OP, ImageFilter, ConstantImageFilter) \
template< class ImagePointerType >\
ImagePointerType operator OP( double c, ImagePointerType im ) {\
	return ImagePointerType( im ) OP ## = c;\
}
#define itkArithmeticOperators(OP, ImageFilter, ConstantImageFilter) \
itkArithmeticOperators1(OP, ImageFilter, ConstantImageFilter)\
itkArithmeticOperators2(OP, ImageFilter, ConstantImageFilter)

#include <itkAddImageFilter.h>
#include <../Review/itkAddConstantToImageFilter.h>
itkArithmeticOperators(+,AddImageFilter,AddConstantToImageFilter)

#include <itkSubtractImageFilter.h>
#include <../Review/itkSubtractConstantFromImageFilter.h>
itkArithmeticOperators1(-,SubtractImageFilter,SubtractConstantFromImageFilter)

#include <itkMultiplyImageFilter.h>
#include <../Review/itkMultiplyByConstantImageFilter.h>
itkArithmeticOperators(*,MultiplyImageFilter,MultiplyByConstantImageFilter)

#include <itkDivideImageFilter.h>
#include <../Review/itkDivideByConstantImageFilter.h>
itkArithmeticOperators1(/,DivideImageFilter,DivideByConstantImageFilter)

#undef itkArithmeticOperators
#undef itkArithmeticOperators1
#undef itkArithmeticOperators2

#endif // ITKIMAGEARITHMETIC_H
