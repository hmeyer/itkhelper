CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT( itkhelper )


FIND_PACKAGE ( ITK )
IF ( ITK_FOUND )
      INCLUDE( ${USE_ITK_FILE} )
ELSE(ITK_FOUND)
  MESSAGE(FATAL_ERROR "Cannot build without ITK.  Please set ITK_DIR.")
ENDIF( ITK_FOUND )

SET( src
  main.cpp 
)

INCLUDE_DIRECTORIES(
  ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}
#  ${MYLIBS}
)


ADD_EXECUTABLE( itkhelper ${src} )
TARGET_LINK_LIBRARIES ( itkhelper
  ITKBasicFilters ITKCommon ITKIO
  )

