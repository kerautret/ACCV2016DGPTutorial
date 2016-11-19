#include "DGtal/base/Common.h"
#include "DGtal/helpers/StdDefs.h"
#include "DGtal/io/readers/PointListReader.h"
#include "DGtal/io/boards/Board2D.h"

// To compute the AlphaThickSegments
#include "DGtal/geometry/curves/AlphaThickSegmentComputer.h"

// To access to the variable samplesDir, mainDir:
#include "ConfigExercices.h"


using namespace DGtal;

int 
main(int argc, char ** argv){
  // question 1:

  // question 2:

  
  // question 3:
  typedef  AlphaThickSegmentComputer< Z2i::Point > AlphaThickSegmentComputer2D;
  AlphaThickSegmentComputer2D aComputer(5);
  
  return 0;
}





