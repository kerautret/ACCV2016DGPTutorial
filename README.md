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
 
 
## Getting the source base file of exerices based on DGtal:

To start using the Libray and check the installation, we will first
need to clone this main repository (and/or fork it):
  ```
  git clone  git@github.com:kerautret/ACCV2016DGPTutorial.git
  ```
Then you can configure 

input contour given from a simple list of points:






