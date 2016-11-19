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
  
  
  std::vector<Point> contour = PointListReader<Point>::getPointsFromFile(samplesDir+"ellipseBruit.sdp");
  Board2D  aBoard;
  std::vector<Profile<>> vectProfiles;
  unsigned int scaleMax = 10;
  for (unsigned int i=0; i < contour.size(); i++) {
      Profile<> s;
      s.init(scaleMax);
      vectProfiles.push_back(s);
    }
  
  std::vector<Point>::const_iterator itInit = contour.begin();
  unsigned int posT =0;
  for(double thickness = 1.0*sqrt(2.0); thickness <= scaleMax; thickness++){
    AlphaThickSegmentComputer2D aComputer(thickness);
    AlphaSegmentation segmentator(contour.begin(), contour.end(), aComputer);
    typename AlphaSegmentation::SegmentComputerIterator it = segmentator.begin();
    typename AlphaSegmentation::SegmentComputerIterator endSeg = segmentator.end();
    for( ; it != endSeg; ++it){
      trace.info() << ".";
      AlphaThickSegmentComputer2D seg(*it);
      double lengthSegment = seg.getSegmentLength();
      std::vector<Point>::const_iterator itS = seg.begin();
      for ( ; itS != seg.end(); ++itS) {
        unsigned int i = std::distance(itInit, itS);
        vectProfiles[i].addValue(posT, lengthSegment/thickness);
      }
    }
    posT++;
  }
  std::ofstream ex;
  ex.open("exportedNoise.dat");
  
  unsigned int pos=0;
  for (auto&& p :contour) {
    aBoard.setFillColor(DGtal::Color(200, 200, 255));
    aBoard.setPenColor(DGtal::Color(150, 150, 255));
    MeaningfulScaleAnalysis<Profile<>> ms (vectProfiles[pos]);
    double n = ms.noiseLevel(2,0);
    n = n==0 ?  scaleMax-1 : n;
    aBoard.drawRectangle(p[0]-(n/2.0), p[1]+(n/2.0), n, n);
    pos++;
    ex << n << std::endl;
  }
  ex.close();
  aBoard.setPenColor(DGtal::Color(50, 50, 150));
  aBoard.setLineWidth(5);
  Z2i::Point last = contour[0];
  for (auto&& p :contour) {
      aBoard.drawLine(p[0], p[1], last[0], last[1]) ;
    last = p;
  }
  
  aBoard.saveEPS((mainDir+"resultTuto6MT.eps").c_str());

  return 0;
}





