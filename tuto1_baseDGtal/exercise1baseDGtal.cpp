#include <DGtal/base/Common.h>
#include <DGtal/helpers/StdDefs.h>

// To use the reading of input points:
#include <DGtal/io/readers/PointListReader.h>

// To display the points in 2D:
#include <DGtal/io/boards/Board2D.h>

// To access to the variable samplesDir, mainDir:
#include "ConfigExercices.h"


using namespace DGtal;

int
main(int argc, char ** argv){
  trace.info() << "First programm in DGtal" << std::endl;
  typedef Z2i::Point Point;
  std::vector<Point> contour = PointListReader<Point>::getPointsFromFile(samplesDir+"contourS.sdp");
  trace.info() << "Reading input done: contour size " << contour.size() <<  std::endl;
  Board2D aBoard;

  for (auto&& p :contour) {
    aBoard << p;
  }
  aBoard.saveEPS((mainDir+"resultTuto1.eps").c_str());
  return 0;
}


