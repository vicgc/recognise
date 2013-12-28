Recognise
=========

[![BuildStatus](https://travis-ci.org/ianjuma/recognise.png)](https://travis-ci.org/ianjuma/recognise)

Facial detection and recognition using OpenCV and libfacerec
** Feel free to contribute, open an issue or make a _pull-request_**

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
- fisherfaces

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
- [ ] Python CL extension
- [ ] Redis cache + store
- [ ] Better logs + elasticsearch on logs
- [ ] ML and entity classification
