#ifndef ITKIMAGEWRITER_H
#define ITKIMAGEWRITER_H

#include <string>
#include <itkImageFileWriter.h>

namespace itkhelper {

template< class ImagePointerType >
void writeImageFile( ImagePointerType image, const std::string &fileName ) {
  typedef typename ImagePointerType::ObjectType ImageType;
  typedef itk::ImageFileWriter< ImageType > WriterType;
  typename WriterType::Pointer writer = WriterType::New();
  writer->SetInput( image );
  writer->SetFileName( fileName.c_str() );
  writer->Update();
}

}

#endif //ITKIMAGEWRITER_H