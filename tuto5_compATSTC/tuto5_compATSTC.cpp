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
  AlphaThickSegmentComputer2D aComputer(5);
  firstMaximalSegment(aComputer, contour.begin()+index, contour.begin(), contour.end());
  AlphaThickSegmentComputer2D first (aComputer);
  lastMaximalSegment(aComputer, contour.begin()+index, contour.begin(), contour.end());
  AlphaThickSegmentComputer2D last (aComputer);       
  aBoard << SetMode(first.className(), "BoundingBox");

  // question 2:
  while(first.end() != last.end()){
    aBoard << first;
    nextMaximalSegment(first, contour.end());
  }
  aBoard << first;
  aBoard.setPenColor(DGtal::Color::Blue);
  aBoard.setFillColor(DGtal::Color::Blue);
  aBoard.drawCircle(contour[index][0], contour[index][1],1); 

  aBoard.saveEPS((mainDir+"resultTuto5CompATSTC.eps").c_str());
  return 0;
}





