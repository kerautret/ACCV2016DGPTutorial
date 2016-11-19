#include "DGtal/base/Common.h"
#include "DGtal/helpers/StdDefs.h"
#include "DGtal/io/readers/PointListReader.h"
#include "DGtal/io/boards/Board2D.h"

// To compute the AlphaThickSegments
#include "DGtal/geometry/curves/AlphaThickSegmentComputer.h"
// For tangential cover
#include "DGtal/geometry/curves/SaturatedSegmentation.h"

// To represent the multiscale profile
#include "DGtal/math/Profile.h"
#include "DGtal/math/MeaningfulScaleAnalysis.h"

// To access to the variable samplesDir, mainDir:
#include "ConfigExercices.h"


using namespace DGtal;


int
main(int argc, char ** argv){
  typedef Z2i::Point Point;
  typedef AlphaThickSegmentComputer<Point> AlphaThickSegmentComputer2D;
  typedef  SaturatedSegmentation<AlphaThickSegmentComputer2D> AlphaSegmentation;
  


  return 0;
}





