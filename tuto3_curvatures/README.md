

## Tutorial Exercise 3: Applying recent cuvature estimator

In this tutorial exercice, we show a simple curvature extraction
defined from the recognition of Digital Circular Arcs.
[Roussillon, T.; Sivignon, I. & L. Tougne On-line Recognition of Digital Circular Arc, 15-th IAPR International Conference on Discrete Geometry for Computer Imagery (DGCI) 2009]



  - [ ] **question 1** : from reading the sample fils ```accFlow.sdp```, construct a ```GridCurve``` which will be initialized from the set of points.
     => you will need to add this include ```"DGtal/geometry/curves/GridCurve.h```

  - [ ] **question 2** : define the type need to iterate on the input contour:
     ```
     typedef GridCurve<>::IncidentPointsRange Range;
     typedef Range::ConstIterator ClassicIterator;
     ```
     and construct a vector to save the estimated curvature values and construct a range associated to the input curve .
     
  - [ ] **question 3** : to compute the curvature from DCA you need to include the class to compute the circular arc (StabbingCircleComputer)   and to compute the curvature and add the given types:
    ```
     #include "DGtal/geometry/curves/estimation/MostCenteredMaximalSegmentEstimator.h"
     #include "DGtal/geometry/curves/StabbingCircleComputer.h"

     typedef StabbingCircleComputer<ClassicIterator> SegmentComputer;
     typedef CurvatureFromDCAEstimator<SegmentComputer> SCEstimator;
     typedef MostCenteredMaximalSegmentEstimator<SegmentComputer,SCEstimator> CurvatureEstimator; 
     ```
     Then you will be able to construct the `CurvatureEstimator` object from the instance of `SegmentComputer` and `SCEstimator`.


   - [ ] **question 4** : to finalisze the esitamation you simply have to **init** and **evaluate** and export the results with for instance gnuplot.
   
  

