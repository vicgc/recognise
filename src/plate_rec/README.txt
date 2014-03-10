******************************************************************************
*   Automatic Number Plate Recognition using SVM and Neural Networks
******************************************************************************

This code is to understand how automatic license plate recognition (ANPR) works.
It is not yet ready for production tasks. You can use this code as a sample & guide to create 
your own custom ANPR or OCR applications.
----------------------------------------------------------
Building the project using CMake from the command-line:
----------------------------------------------------------
Linux:
    export OpenCV_DIR="~/OpenCV/build"
    mkdir build
    cd build
    cmake -D OpenCV_DIR=$OpenCV_DIR ..
    make 
    
----------------------------------------------------------
Running the project:
----------------------------------------------------------
    ANPR test/2715DTZ.jpg

You can choose other images that are in the test folder or other images that contain a spanish
license plate taken from 2 to 3 meters. There are also some UNIX Bash scripts in the "utils"
folder for Linux or Mac.
