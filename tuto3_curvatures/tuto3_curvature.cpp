
#include <DGtal/base/Common.h>
#include <DGtal/helpers/StdDefs.h>

// To use the reading of input points:
#include <DGtal/io/readers/PointListReader.h>


// To display the points in 2D:
#include <DGtal/io/boards/Board2D.h>

// To access to the variable samplesDir, mainDir:
#include "ConfigExercices.h"

#include "DGtal/geometry/curves/GridCurve.h"
#include "DGtal/geometry/curves/estimation/MostCenteredMaximalSegmentEstimator.h"
#include "DGtal/geometry/curves/StabbingCircleComputer.h"



using namespace DGtal;



int
main(int argc, char ** argv){
  trace.info() << "First programm in DGtal" << std::endl;

  typedef Z2i::Point Point;
  std::vector<Point> contour = PointListReader<Point>:: getPointsFromFile(samplesDir+"accFlow.sdp");
  trace.info() << "Reading input done: contour size " << contour.size() <<  std::endl;
  Board2D aBoard;
 
  // question 1:
  GridCurve<> curve;
  curve.initFromVector(contour);
  
  // question 2:
  typedef GridCurve<>::IncidentPointsRange Range;
  typedef Range::ConstIterator ClassicIterator;
  Range r = curve.getIncidentPointsRange();
  std::vector<double> estimations;


  // question 3:
  typedef StabbingCircleComputer<ClassicIterator> SegmentComputer;
  typedef CurvatureFromDCAEstimator<SegmentComputer> SCEstimator;
  typedef MostCenteredMaximalSegmentEstimator<SegmentComputer,SCEstimator> CurvatureEstimator;
  SegmentComputer sc;
  SCEstimator sce;
  CurvatureEstimator estimator(sc, sce);
  
  // question 4:
  
  
  int i=0;
  std::ofstream of;
  of.open(mainDir+"resultTuto3Curvature.sdp", std::ofstream::binary);
  for (auto v: estimations )
  {
    of << i << " " << v << std::endl;
    i++;
  }
  of.close();
  for (auto&& p :contour) {
    aBoard << p;
  }
  aBoard.saveEPS((mainDir+"resultTuto1.eps").c_str());
  return 0;
}



