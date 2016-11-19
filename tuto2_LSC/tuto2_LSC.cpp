#include <DGtal/base/Common.h>
#include <DGtal/helpers/StdDefs.h>

// To use the reading of input points:
#include <DGtal/io/readers/PGMReader.h>
#include <DGtal/images/imagesSetsUtils/SetFromImage.h>
#include <DGtal/topology/helpers/Surfaces.h>
#include <DGtal/geometry/curves/FreemanChain.h>

// To display the points in 2D:
#include <DGtal/io/boards/Board2D.h>

// To access to the variable samplesDir, mainDir:
#include "ConfigExercices.h"


using namespace DGtal;

int
main(int argc, char ** argv){

  // question 1:
  typedef ImageContainerBySTLVector< DGtal::Z2i::Domain, unsigned char> Image;
 
  // question 2:
  Z2i::KSpace ks;
  
  
  // question 3:
 // Z2i::DigitalSet set (image.domain());
  
  
  // question 4:
  trace.info() << "Extracting the set of cell from intervall 0 128" <<  std::endl;
  Board2D aBoard;
  //aBoard << image.domain();
  aBoard.saveEPS((mainDir+"/resultTuto2questions1-4.eps").c_str());
  
  // question 4 bis:
  
  
  
  
  aBoard.saveEPS((mainDir+"/resultTuto2questions1-4bis.eps").c_str());
  
  
  // question 5: extract boundary
  // define adjacency:
  
  
  // question 6: for each contours constructs FreemanChains and displays them:
  
  
  
  aBoard.saveEPS((mainDir+"/resultTuto2questions5-6bis.eps").c_str());

  return 0;
}





