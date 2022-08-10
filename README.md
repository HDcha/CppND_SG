# Submission Capstone Project

Based on the [Snake game repo](https://github.com/udacity/CppND-Capstone-Snake-Game).

Requirements:

* README (All Rubric Points REQUIRED)

    * ( ) A README with instructions is included with the project
      The README is included with the project and has instructions for building/running the project.
      If any additional libraries are needed to run the project, these are indicated with cross-platform installation
      instructions.
      You can submit your writeup as markdown or pdf.

    * ( ) The README indicates which project is chosen.
      The README describes the project you have built.
      The README also indicates the file and class structure, along with the expected behavior or output of the program.

    * ( ) The README includes information about each rubric point addressed.
      The README indicates which rubric points are addressed. The README also indicates where in the code (i.e. files
      and
      line numbers) that the rubric points are addressed.


* Compiling and Testing (All Rubric Points REQUIRED)

    * ( ) The submission must compile and run.
      The project code must compile and run without errors.
      We strongly recommend using cmake and make, as provided in the starter repos. If you choose another build system,
      the code must compile on any reviewer platform.


* Loops, Functions, I/O

    * (x) The project demonstrates an understanding of C++ functions and control structures.
      A variety of control structures are used in the project.
      The project code is clearly organized into functions.
      See [game.cpp](src/game.cpp), [renderer.cpp](src/renderer.cpp)

    * ( ) The project reads data from a file and process the data, or the program writes data to a file.
      The project reads data from an external file or writes data to a file as part of the necessary operation of the
      program.

    * ( ) The project accepts user input and processes the input.
      The project accepts input from a user as part of the necessary operation of the program.


* Object Oriented Programming

    * (x) The project uses Object Oriented Programming tesize_tchniques.
      The project code is organized into classes with class attributes to hold the data, and class methods to perform
      tasks.
        * [gui_object.h](src/gui_object.h): line 13
        * [snake.h](src/snake.h): line 10
        * [game.h](src/game.h): line 12

    * (x) Classes use appropriate access specifiers for class members.
      All class data members are explicitly specified as public, protected, or private.
        * [gui_object.h](src/gui_object.h): line 13
        * [snake.h](src/snake.h): line 10
        * [game.h](src/game.h): line 12

    * (x) Class constructors utilize member initialization lists.
      All class members that are set to argument values are initialized through member initialization lists.
        * [gui_object.h](src/gui_object.h): line 13
        * [snake.h](src/snake.h): line 10
        * [game.h](src/game.h): line 27

    * (x) Classes abstract implementation details from their interfaces.
      All class member functions document their effects, either through function names, comments, or formal
      documentation.
      Member functions do not change program state in undocumented ways.
        * [gui_object.h](src/gui_object.h): line 13
        * [snake.h](src/snake.h): line 10
        * [game.h](src/game.h): line 12

    * (x) Classes encapsulate behavior.
      Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden
      from
      the user. State is accessed via member functions.
        * [gui_object.h](src/gui_object.h): line 13
        * [snake.h](src/snake.h): line 10
        * [game.h](src/game.h): line 12

    * (x) Classes follow an appropriate inheritance hierarchy.
      Inheritance hierarchies are logical. Composition is used instead of inheritance when appropriate. Abstract classes
      are composed of pure virtual functions. Override functions are specified.
        * [gui_object.h](src/gui_object.h): line 13
        * [snake.h](src/snake.h): line 10

    * (x) Overloaded functions allow the same function to operate on different parameters.
      One function is overloaded with different signatures for the same function name.
        * [renderer.h](src/renderer.h): lines 13-16

    * (x) Derived class functions override virtual base class functions.
      One member function in an inherited class overrides a virtual base class member function.
        * [snake.h](src/snake.h): line 10

    * (x) Templates generalize functions in the project.
      One function is declared with a template that allows it to accept a generic parameter.
        * [snake.h](src/snake.h): line 10. Snake is a templated class.


* Memory Management

    * (x) The project makes use of references in function declarations.
      At least two variables are defined as references, or two functions use pass-by-reference in the project code.
        * [game.cpp](src/game.cpp) lines 45-48. Passes reference to function.
        * [renderer.h](src/renderer.h): lines 13-16. Ueses pass-by-const-reference.
        * [game.h](src/game.h): line 30. Constructor of class "Frame" uses pass-by-reference.

    * ( ) The project uses destructors appropriately.
      At least one class that uses unmanaged dynamically allocated memory, along with any class that otherwise needs to
      modify state upon the termination of an object, uses a destructor.

    * (x) The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.
      The project follows the Resource Acquisition Is Initialization pattern where appropriate, by allocating objects at
      compile-time, initializing objects when they are declared, and utilizing scope to ensure their automatic
      destruction.
        * [game.cpp](src/game.cpp) lines 45-48. The barriers are initialized within unique pointers within a vector.
          Thus the lifetime of those objects is governed by the same scope as the vector.

    * ( ) The project follows the Rule of 5.
      For all classes, if any one of the copy constructor, copy assignment operator, move constructor, move assignment
      operator, and destructor are defined, then all of these functions are defined.

    * (x) The project uses move semantics to move data, instead of copying it, where possible.
      For classes with move constructors, the project returns objects of that class by value, and relies on the move
      constructor, instead of copying the object.
        * [game.cpp](src/game.cpp) lines 16. A unique pointer of snake is moved to the back of the vector.

    * ( ) The project uses smart pointers instead of raw pointers.
      The project uses at least one smart pointer: unique_ptr, shared_ptr, or weak_ptr. The project does not use raw
      pointers.


* Concurrency

    * ( ) The project uses multithreading.
      The project uses multiple threads in the execution.

    * ( ) A promise and future is used in the project.
      A promise and future is used to pass data from a worker thread to a parent thread in the project code.

    * ( ) A mutex or lock is used in the project.
      A mutex or lock (e.g. std::lock_guard or `std::unique_lock) is used to protect data that is shared across multiple
      threads in the project code.

    * ( ) A condition variable is used in the project.
      A std::condition_variable is used in the project code to synchronize thread execution.

# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in
the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this
repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent
StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will
become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have
learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications
using a wide range of C++ features.

## Dependencies for Running Locally

* cmake >= 3.7
    * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
    * Linux: make is installed by default on most Linux distros
    * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
    * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
    * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  > Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
    * Linux: gcc / g++ is installed by default on most Linux distros
    * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
    * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.
