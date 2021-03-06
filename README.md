Recognise
=========

[![BuildStatus](https://travis-ci.org/ianjuma/recognise.png)](https://travis-ci.org/ianjuma/recognise)

Facial detection and recognition using OpenCV and libfacerec

This is a basic template for my class project - modules are being written

```ruby
require 'know-this'
puts 'The project is in its infancy!'
```

Why yes, contribute, open an issue or make a pull-request

####Install openCV and header files
```
./setup-debian.sh
make get-deps
make
sudo make install
```

#### get gpu and cpu info - openCL integration
```
lspci | grep VGA
cat /proc/cpuinfo | grep sse3
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


###Classification
- gender classification
- ethnic classification
- emotion classification


###Validation
- classification
- learning (ML)


###Pattern Recognition
- object recognition
- number plate recognition & extraction
- movement and pattern extraction
- info extraction on movements


###Improving accuracy of the recogniser
- Lighting conditions (webcam)
- Training with 'realistic' images - good training sets
- Camera with high fps - hd
- Camera LED lighting 30m (poe cam)


###Known Bugs :bug:
- [x] libpq exception


### TODO
- [x] Add Separate conf file
- [x] openCL support, cmake OPENCL=ON, intel GPU support
- [x] Add cmake build, autotools+automake
- [x] Python CL extension - openMP
- [ ] Integrate SMS (AfricaIT)
- [ ] Email notifications Sendgrid
- [ ] Redis cache + store - zmq
- [ ] Better logs + elasticsearch on logs
- [ ] ML and entity classification
- [ ] Video4linux + video face detection and recognition
- [ ] openCL kernels monitoring
- [ ] poe cameras - high fps
- [ ] management console, logging
- [ ] notifications (RESTfull) - service hooks
- [x] postgres integration
- [ ] some graphs on neo4j - gremlin+cypher


###some docs and refs :fr:

[Installing OpenCL](https://gist.github.com/ianjuma/9026377)

[libfacerec](http://www.cs.colostate.edu/evalfacerec/index10.php)

[list of algorithms](http://www.cs.colostate.edu/evalfacerec/algorithms5.php)

[papers on face recognition algorithms](http://web.archive.org/web/20080522171806/http:/www.ansatt.hig.no/erikh/papers/hig98_6/node2.html)

[face-rec libs - stackoverflow](http://stackoverflow.com/questions/953714/face-recognition-library)

[face-detection api's](http://blog.mashape.com/post/53379410412/list-of-50-face-detection-recognition-apis)

[face-detection libs](http://www.luxand.com/facesdk/?utm_expid=4075614-16&utm_referrer=http%3A%2F%2Fwww.facedetection.com%2Ffacedetection%2Fsoftware.htm)

[face-recognition techniques](http://www.facedetection.com/facedetection/techniques.htm)

[docs CV and robotics](http://www.intorobotics.com/how-to-detect-and-track-object-with-opencv/)

[classifiers- banana](http://blog.csdn.net/sjz_iron/article/details/8511460)

[opencv demo](http://www.shervinemami.info/faceRecognition.html)

[classifiers - face detect](http://coding-robin.de/2013/07/22/train-your-own-opencv-haar-classifier.html)

[openCL gpu devices support](http://streamcomputing.eu/blog/2011-12-29/opencl-hardware-support/)

[driver camera](http://www.raspberrypi.org/archives/5580)

[The openCL book](http://www.fixstars.com/en/opencl/book/OpenCLProgrammingBook/calling-the-kernel/)

[openCVL in action](http://pdf.th7.cn/down/files/1312/opencl_in_action.pdf)
