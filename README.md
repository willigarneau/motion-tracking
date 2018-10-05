 <h1 align="center">Real-Time Object Tracking</h1> 
  <p align="center">
  <img src="https://img.shields.io/badge/License-MIT-blue.svg"><br>
  Made with OpenCV in C++
  </p>



> 🕺 💃 Practical Work in Computer Vision at Cegep Lévis-Lauzon. Put our knowledge of OpenCV into practice to create an object tracking program. 📸  🖼

### Detect and track real-time objects via a camera.

The goal of this project was to make it a very simple motion detector, by simply displaying objects that differed from the previous image. I added some interesting features that could be favorable for your projects, such as the detection of the direction of objects and a display of the threshold of the base image.

---

## Prerequisites

Ensure you have following installed:

  - [x] [gcc](https://gcc.gnu.org/) with C++11 support.
  - [x] [OpenCV 3.x](http://opencv.org/downloads.html) **with contribution package**
  - [x] A Webcamera !


## Compile and run

As simple as:

```
$ make
$ bin/track
```

The tracking program runs until you press `Echap`. Tab `Ctrl + C` inside your terminal 
window to terminate.


## Disclaimer

The build is configured to perfectly fit on Windows 10 (Visual Studio Entreprise 2017). 
Your mileage may vary if you are compiling the code on a different OS. 

---

## My build environment

In case you face difficulty building on your own machine, 
following is the specifications of my environment which may be 
helpful for you to spot the difference to yours.

<b>OS</b>

```
Windows 10 Professionnal 2018
```

<b>OpenCV3</b>

OpenCV 3.2.0 built and installed via following [homebrew](https://brew.sh/) params:

---

# Licence

MIT License
