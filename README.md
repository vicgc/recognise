Recognise
=========

[![BuildStatus](https://travis-ci.org/ianjuma/recognise.png)](https://travis-ci.org/ianjuma/recognise)

Facial detection and recognition using OpenCV and libfacerec

this is a basic template for my project - modules yet to be written

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
- feature extraction techniques
- problems of facial recognition, pattern-matching


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
- [x] Python CL extension - openMP
- [ ] Redis cache + store - zmq
- [ ] Better logs + elasticsearch on logs
- [ ] ML and entity classification
- [ ] Video4linux + video face detection and recognition
- [ ] openCL kernels monitoring
- [ ] poe cameras - high fps
- [ ] management console
- [ ] notifications (RESTfull)


###some docs and refs

[libfacerex](http://www.cs.colostate.edu/evalfacerec/index10.php)
[list of algorithms](http://www.cs.colostate.edu/evalfacerec/algorithms5.php)
[papers on face recognition algorithms](http://web.archive.org/web/20080522171806/http:/www.ansatt.hig.no/erikh/papers/hig98_6/node2.html)
[face-rec libs - stackoverflow](http://stackoverflow.com/questions/953714/face-recognition-library)
[face-detection api's](http://blog.mashape.com/post/53379410412/list-of-50-face-detection-recognition-apis)
[face-detection libs](http://www.luxand.com/facesdk/?utm_expid=4075614-16&utm_referrer=http%3A%2F%2Fwww.facedetection.com%2Ffacedetection%2Fsoftware.htm)
[face-recognition techniques](http://www.facedetection.com/facedetection/techniques.htm)
