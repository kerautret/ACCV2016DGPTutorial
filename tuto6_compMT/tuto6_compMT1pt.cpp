#include "DGtal/base/Common.h"
#include "DGtal/helpers/StdDefs.h"
#include "DGtal/io/readers/PointListReader.h"
#include "DGtal/io/boards/Board2D.h"

// To compute the AlphaThickSegments
#include "DGtal/geometry/curves/AlphaThickSegmentComputer.h"
// For tangential cover
#include "DGtal/geometry/curves/SegmentComputerUtils.h"
// To represent the multiscale profile
#include "DGtal/math/Profile.h"
#include "DGtal/math/MeaningfulScaleAnalysis.h"


// To access to the variable samplesDir, mainDir:
#include "ConfigExercices.h"



using namespace DGtal;


int
main(int argc, char ** argv){
  typedef Z2i::Point Point;
  std::vector<Point> contour = PointListReader<Point>::getPointsFromFile(samplesDir+"contourS.sdp");
  Board2D  aBoards[5];
  aBoards[0] = Board2D();
  aBoards[1] = Board2D();
  aBoards[2] = Board2D();
  aBoards[3] = Board2D();
  aBoards[4] = Board2D();
  
  for(unsigned int thickness = 1; thickness<=5; thickness++){
    for (auto&& p :contour) {
      aBoards[thickness-1] << p;
    }
  }
  
  
  std::ofstream ofLength;
  ofLength.open(mainDir+"resultTuto5CompATSTC_lenghts.dat");
  
  typedef AlphaThickSegmentComputer<Z2i::Point> AlphaThickSegmentComputer2D;
  //unsigned indexPt = 200;
  
  unsigned indexPt = 430;
  // (part of question 2)
  Profile<> s;
  s.init(5);
  
  // question 1
  for(unsigned int thickness = 1; thickness<=5; thickness++){
    AlphaThickSegmentComputer2D aComputer(thickness);
    firstMaximalSegment(aComputer, contour.begin()+indexPt, contour.begin(), contour.end());
    AlphaThickSegmentComputer2D first (aComputer);
    lastMaximalSegment(aComputer, contour.begin()+indexPt, contour.begin(), contour.end());
    AlphaThickSegmentComputer2D last (aComputer);
    aBoards[thickness-1] << SetMode(first.className(), "BoundingBox");
    
    while(first.end() != last.end()){
      aBoards[thickness-1] << first;
      ofLength << thickness << " " << first.getSegmentLength()/thickness << std::endl;
      // question 2
      s.addValue(thickness - 1, first.getSegmentLength()/thickness);
      nextMaximalSegment(first, contour.end());
    }
    aBoards[thickness-1] << first;
    s.addValue(thickness - 1, first.getSegmentLength()/thickness);
    ofLength << thickness << " " << first.getSegmentLength()/thickness << std::endl;
    
    aBoards[thickness-1].setPenColor(DGtal::Color::Blue);
    aBoards[thickness-1].setFillColor(DGtal::Color::Blue);
    aBoards[thickness-1].drawCircle(contour[indexPt][0], contour[indexPt][1],1);
    std::stringstream ss; ss << mainDir << "resultTuto5CompATSTC_" << thickness << ".eps";
    std::stringstream ss2; ss2 << mainDir << "resultTuto5CompATSTC_" << thickness << ".fig";
    
    aBoards[thickness-1].saveEPS(ss.str().c_str());
    aBoards[thickness-1].saveFIG(ss2.str().c_str());
    
  }
  std::ofstream ofScale;
  ofScale.open(mainDir+"resultTuto5CompATSTC_MSP.dat");
  std::vector<double> x,y;
  s.getProfile(x, y);
  for (unsigned int i =0; i< x.size(); i++) {
    ofScale <<x[i]<< " " << y[i] << std::endl;
  }
  ofScale.close();
  ofLength.close();
  MeaningfulScaleAnalysis<Profile<> > msa (s);
  
  trace.info() << "Noise level of index point " << indexPt << ": " << msa.noiseLevel() << std::endl;
  return 0;
}





