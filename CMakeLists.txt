PROJECT(ACCVDGT)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

# ConfigExamples.h instanciation.
configure_file(${PROJECT_SOURCE_DIR}/ConfigExercices.h.in 
  ${PROJECT_BINARY_DIR}/ConfigExercices.h)
  
include_directories (${PROJECT_BINARY_DIR})

SET(Boost_USE_STATIC_LIBS   ON)
SET(Boost_USE_MULTITHREADED ON)
SET(Boost_USE_STATIC_RUNTIME OFF)
SET(Boost_FOUND FALSE)

  
FIND_PACKAGE(DGtal REQUIRED)
INCLUDE_DIRECTORIES(${DGTAL_INCLUDE_DIRS})
LINK_DIRECTORIES(${DGTAL_LIBRARY_DIRS})

FIND_PACKAGE(Boost 1.46.0 REQUIRED COMPONENTS program_options)
if ( Boost_FOUND )
  message(STATUS "Boost found.")
  ADD_DEFINITIONS(${BOOST_DEFINITIONS} -DBOOST_ALL_NO_LIB)
  include_directories( ${Boost_INCLUDE_DIRS} )
     SET(TutoDependencies ${TutoDependencies} 
     ${Boost_LIBRAIRIES}  
     ${Boost_PROGRAM_OPTIONS_LIBRARY} Boost::program_options)
   SET(DGtalLibInc ${Boost_INCLUDE_DIRS})
endif( Boost_FOUND) 


add_subdirectory(tuto1_baseDGtal)
add_subdirectory(tuto2_LSC)
add_subdirectory(tuto3_curvatures)
add_subdirectory(tuto4_compATS)
add_subdirectory(tuto5_compATSTC)
add_subdirectory(tuto6_compMT)

