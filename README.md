# A simple Gtk / OpenCV application in C++

_C++_, _OpenCV_ and _Gtk_ are a nice triplet to build applications that run on a Raspberry PI, taking images from the camera, process them, display them and have an unlimited user interface. In this example I'm showing a straight-forward way to display camera captures into a full screen window. In the next example, [gtk-opencv-patterns](https://github.com/raspberry-cpp-tutorials/gtk-opencv-patterns), I amend some of the shortcomings of this too naive method. I hope these two examples can help you through the boring problems you need to solve before reaching the place where you can have fun.

I'm using the following technical stack:

* **_Raspberry Pi_** - The ultimate goal is to launch the application on it.
* **_CMake_** - This is the needed ingredient to make your code buildable on most of the platforms. It also exports your project to  Xcode, VisualStudio, Eclipse and a long list of others, so you will be able to choose your preferred IDE.
* **_Mac OS X_, _Ubuntu_, _Windows_** - Where you can write and test your application.
* **_C++_** - _Python_ is fashionable, young, efficient and well supported by Raspberry folks. But I happen to like _C++_ more. If _Python_ is your thing, then stop reading.
* **_OpenCV_** - One very widely used open source (hence the Open) computer vision (hence the CV) library.
* **_Gtkmm_**, which is the _C++_ oriented port of _Gtk_ - Although _OpenCV_ lets you display images on screen, it is somewhat limited when interacting with the user. Being easily compatible, _Gtk / Gtkmm_ are a great complement to _OpenCV_ for building real user interfaces around computer vision applications.

# The branches structure
In the [Wiki](https://github.com/raspberry-cpp-tutorials/gtk-opencv-simple/wiki) articles I'm explaining the code quite in detail. To help the exposition order, I split the code into multiple steps:
- Master branch contains step 1.
- Step2 branch contains step 2.
- Etc.

# Cross-platform application
An important element is to be able to build and test your project in your preferred desktop computer or notebook. _Raspberry Pi_ is meant to be an embedded system platform, and it is an amazing one. Still, it lacks the right keyboard, mouse, monitor or amount of memory required to be a comfortable as a development tool.

You find in Wiki the detailed instructions to install a working development environment in the three major operative systems:

* [Installing Mac OS X development environment](https://github.com/raspberry-cpp-tutorials/gtk-opencv-simple/wiki/Mac-OS-X-development-environment)
* [Installing Windows development environment](https://github.com/raspberry-cpp-tutorials/gtk-opencv-simple/wiki/Windows-development-environment)
* [Installing Linux development environment](https://github.com/raspberry-cpp-tutorials/gtk-opencv-simple/wiki/Linux-development-environment)


Last but not least:

* [Installing the project on Raspberry PI](https://github.com/raspberry-cpp-tutorials/gtk-opencv-simple/wiki/Installing-on-Raspberry-PI)

# The project's folder structure

There are several great articles that discuss about the best folder structure for a project built with _CMake_:

 * [https://arne-mertz.de/2018/06/cmake-project-structure/](https://arne-mertz.de/2018/06/cmake-project-structure/): I like this one because it discusses how to integrate those header-only libraries, and uses _Catch_ as an example.
 * [https://rix0r.nl/blog/2015/08/13/cmake-guide/](https://rix0r.nl/blog/2015/08/13/cmake-guide/): I like this one because it shows in detail how to configure CMake and why, and also acknowledges the difference between library (which is easily unit tested) and application (which is the user interface, and not very easy to unit test).


In this first stage (there is more on the second part of the article), I'm proposing a simplified folder structure. Projects having multiple executables and libraries need one folder per module, and the structure is much more complex. In this case, as there will be one single executable, I'm just having one root folder, called ``src`` and, in it, one folder for each type of file - sources, headers and resources.

```
.gitignore        <-- Ignore xcode, codeb, build folders.
/src              <-- All sources are here
   CMakeList.txt  <--- The CMake configuration file.
      /cpp        <----- Contains the C++ source files.
      /hpp        <----- Contains the C++ header files.
      /res        <----- Contains resource files.
/build            <-- Contains the temporary build files. 
                      Not under version control
/xcode            <-- Contains the XCode project.
                      Not under version control.
/codeb            <-- Contains the Code::Blocks project. 
                      Not under version control. 
```
