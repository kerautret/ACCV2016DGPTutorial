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
  typedef Z2i::Point Point;
  std::vector<Point> contour = PointListReader<Point>::getPointsFromFile(samplesDir+"contourS.sdp");
  Board2D aBoard;
  for (auto&& p :contour) {
    aBoard << p;
  }
  unsigned int index = 200;
  typedef AlphaThickSegmentComputer<Z2i::Point> AlphaThickSegmentComputer2D;
  
  // question 1:
  
  
  // question 2:
 
  
  aBoard.saveEPS((mainDir+"resultTuto5CompATSTC.eps").c_str());
  return 0;
}





