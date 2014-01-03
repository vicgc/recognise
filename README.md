Recognise
=========

[![BuildStatus](https://travis-ci.org/ianjuma/recognise.png)](https://travis-ci.org/ianjuma/recognise)

Facial detection and recognition using OpenCV and libfacerec

**Feel free to contribute, open an issue or make a _pull-request_**

####Install openCV and header files
```
make get-deps
make
sudo make install
```

#### Don't forget to run tests
```
make test
```

###Algorithms Used

- Principal based approach - eigenfaces
- PCA algorithm
- fisherfaces (local template matching)


###Problem description

- problems of face-detection
- feature extraction
- problems of facial recognition


###Image classification

###Validation
- classification
- learning (ML)

###Pattern Recognition

![alt tag](https://raw.github.com/ianjuma/sample-play-search/master/public/images/app.png)

### TODO
- [x] Add Separate conf file
- [x] Add direct openCL support
- [x] Add cmake build, autotools+automake
- [x] Python CL extension
- [ ] Redis cache + store
- [ ] Better logs + elasticsearch on logs
- [ ] ML and entity classification


###some docs and tuts

http://www.cs.colostate.edu/evalfacerec/index10.php
http://www.cs.colostate.edu/evalfacerec/algorithms5.php
http://web.archive.org/web/20080522171806/http:/www.ansatt.hig.no/erikh/papers/hig98_6/node2.html
http://stackoverflow.com/questions/953714/face-recognition-library
http://blog.mashape.com/post/53379410412/list-of-50-face-detection-recognition-apis
http://www.luxand.com/facesdk/?utm_expid=4075614-16&utm_referrer=http%3A%2F%2Fwww.facedetection.com%2Ffacedetection%2Fsoftware.htm
http://www.facedetection.com/facedetection/techniques.htm
