

## Tutorial Exercise 6: Computing the Meaningful Thickness



The main objective is to compute the Meaningful Thickness for a given point and then for all the contour points.

### Extraction on a single point:

  - [ ] **question 1** : starting from previous exercice, iterate on 5 levels of thickness t and store in a file the ratio between t and segment length (in file resultTuto5CompATSTC_lenghts.dat)
  
  - [ ] **question 2** : construct a `Profile` object (`DGtal/math/Profile.h`) and insert the previous ratio of question 1.
  
  - [ ] **question 3** : from the previous profile construct a MeaningfulScaleAnalysis and output the scale levels of point 340 and then 200.
  
  
  
  
  You should obtain such a visualization (point index 340):

  <center>
  <a href="results/res1.png"><img height=150 src="results/res1.png"></a>
  </center>
  
### Extraction on all points:

  By using the same strategy than in the previous step you should obtain such a result:

  <center>
  <a href="results/res2.png"><img height=150 src="results/res2.png"></a>
  </center>
