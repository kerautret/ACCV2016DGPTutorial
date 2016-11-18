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
  Image image = DGtal::PGMReader<Image>::importPGM(samplesDir + "contourS.pgm");
 
  // question 2:
  Z2i::KSpace ks;
  ks.init(image.domain().lowerBound(), image.domain().upperBound(), false);
  
  
  // question 3:
  Z2i::DigitalSet set (image.domain());
  SetFromImage<Z2i::DigitalSet>::append(set, image, 0, 108);
  
  
  // question 4:
  trace.info() << "Extracting the set of cell from intervall 0 128" <<  std::endl;
  Board2D aBoard;
  aBoard << set;
  aBoard << image.domain();
  aBoard.saveEPS((mainDir+"/resultTuto2questions1-4.eps").c_str());
  
  // question 4 bis:
  Z2i::DigitalSet set2 (image.domain());
  SetFromImage<Z2i::DigitalSet>::append(set2, image, 109, 140);
  for(auto p : set2)
  {
    aBoard << CustomStyle(p.className(), new CustomColors(Color::Blue, Color::Blue));
    aBoard << p;
  }
  
  aBoard.saveEPS((mainDir+"/resultTuto2questions1-4bis.eps").c_str());
  
  
  // question 5: extract boundary
  // define adjacency:
  SurfelAdjacency<2> sAdj(true);
  std::vector<std::vector<Z2i::Point>> vCnt;
  Surfaces<Z2i::KSpace>::extractAllPointContours4C(vCnt, ks, set, sAdj);
  
  // question 6: for each contours constructs FreemanChains and displays them:
  for (const auto &c: vCnt)
  {
    FreemanChain<int> fc (c);
    aBoard << SetMode( fc.className(), "InterGrid" );
    aBoard.setPenColor(Color::Red);
    aBoard.setLineWidth(10.0);
    CustomStyle( fc.className(),
                new CustomPen( Color::Red, Color::Red, 3.0,
                              Board2D::Shape::SolidStyle ) );
    aBoard << fc;
  }
  aBoard.saveEPS((mainDir+"/resultTuto2questions5-6bis.eps").c_str());

  return 0;
}





