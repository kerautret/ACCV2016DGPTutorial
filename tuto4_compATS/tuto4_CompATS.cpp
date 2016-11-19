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
  typedef Z2i::Point Point;
  std::vector<Point> contour = PointListReader<Point>::getPointsFromFile(samplesDir+"contourS.sdp");
  Board2D aBoard;
  for (auto&& p :contour) {
    aBoard << p;
  }
  
  // question 2:
  aBoard.setPenColor(DGtal::Color::Red);
  aBoard.setFillColor(DGtal::Color::Red);
  aBoard.drawCircle(contour[30][0], contour[30][1],1); 
  unsigned int startIndex = 30;

  // question 3:
  typedef  AlphaThickSegmentComputer< Z2i::Point > AlphaThickSegmentComputer2D;
  AlphaThickSegmentComputer2D aComputer(5);
  aComputer.init(contour.begin()+30);
  while(aComputer.extendFront()){
  }

  aBoard  << CustomStyle( aComputer.className(), new CustomColors( DGtal::Color::Blue, DGtal::Color::None ) );  
  aBoard << aComputer;
  aBoard.saveEPS((mainDir+"resultTuto4CompATS.eps").c_str());
  
  return 0;
}





