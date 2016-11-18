# ACCV2016DGPTutorial
ACCV 2016 Tutorial on  Digital Geometry Processing : Extracting High Quality Geometric Features


## Preliminary
Before starting the tutorial you need to have the following dependancies:



## Simple Installation of the DGtal Library 
To follow the tutorial exercice based on the DGtal Library, you can follow the given step:

 - Clone the current version of DGtal: (or get the archive from a given USB key):
    ```
      git clone git@github.com:DGtal-team/DGtal.git
    ```
 
 - Do to the given downloaded directory of the Library and recopy the given command lines: 
   - ```cd DGtal;``` 
   - ```mkdir build; cd build```
   - cmake .. -DBUILD_EXAMPLES=FALSE -DBUILD_TESTING=FALSE
   - make -j 5 
 
 - Alternatively you can use ccmake and selects in the interface the associated options.
 
 
## Getting the source base file of exercises based on DGtal:

To start using the Libray and check the installation, we will first
need to clone this main repository (and/or fork it):
  ```
  git clone  git@github.com:kerautret/ACCV2016DGPTutorial.git
  ```
Then you can configure 

input contour given from a simple list of points:



### exercice 1: 


### Exercice 2:
   - step 1: Reading input file: 
     => choose an image type: #include <DGtal/images/ImageContainerBySTLVector.h>
     => use the PGMReader from io/readers 
       Image image = DGtal::PGMReader<Image>::importPGM(filename); 
  
   - step 2: Init a Khalimksy Space (to extract boundary object from topology definitions)
     => use  Z2i::KSpace to obtain directly the 
     => use lower bounds from the domain of the image.
     
   - step 3: defines a Digital set2d
     => use Z2i::DigitalSet constructed from the image domain
     => use static method SetFromImage to append the cells defined from an interval of values (DGtal/images/imagesSetsUtils/SetFromImage.h)
     
   - step 4: displays the cells with a Board2D and displays the image domain.
     =>  by using the operator ```<<``` on the Board2D.
   - => extensions: use  CustomStyle and  CustomColors to display other of intervals of pixels
   
   
   - step 5: By constructing a surfel adjacency (SurfelAdjacency<2> sAdj( true )) and by using the method to extract all the Contour 4 connexe defined in Surfaces<Z2i::KSpace>.
   
   - step 6: for each contours, constructs its associated FreemanChain and displays them.







