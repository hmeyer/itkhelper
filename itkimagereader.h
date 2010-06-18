#ifndef ITKIMAGEREADER_H
#define ITKIMAGEREADER_H

#include <string>
#include <itkImageFileReader.h>

namespace itkhelper {

template< class ImageType >
typename ImageType::Pointer readImageFile( const std::string &fileName ) {
  typedef itk::ImageFileReader< ImageType > ReaderType;
  typename ReaderType::Pointer reader = ReaderType::New();
  reader->SetFileName( fileName.c_str() );
  reader->Update();
  typename ImageType::Pointer result = reader->GetOutput();
  return result;
}

}

#endif //ITKIMAGEREADER_H