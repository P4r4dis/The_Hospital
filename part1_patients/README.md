# The_Hospital
## The_Hospital Part 1 : SickKoala (Patients)
[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com)
## Table Of Contents
<p align="center">
  <a href="#Setup">Setup</a> •
  <a href="#Description">Description</a> •
  <a href="#Objectifs">Objectifs</a> •
  <a href="#Key-learnings">Key learnings</a> •
  <a href="#Installation">Installation</a> •
  <a href="#how-to-use">How To Use</a> 
</p>
## Setup
[(Back to top)](#table-of-contents)

* __Prerequisites__
    * The library is supported on Linux, macOS, FreeBSD, and Windows.
    * The following compilers are supported to compile both the library and the tests:
        * GCC 4.9+ (Can be relaxed to GCC 4.6+ when not using C++)
        * Clang 3.4+
        * MSVC 14+ (Included in Visual Studio 2015 or later)
* __Building from source__
    * First, install dependencies:
        * C/C++ compiler
        * Meson, Ninja
        * CMake (for subprojects)
        * pkg-config
        * libffi (libffi-dev)
        * libgit2 (libgit2-dev)
        * Other runtime dependencies will be bundled if they are not available on the system (BoxFort, debugbreak, klib, nanomsg, nanopb).
    * Clone this repository:
        * ```bash
            $ git clone --recursive https://github.com/Snaipe/Criterion
    * Then, run the following commands to build Criterion:
        * ```bash
            $ meson build
            $ ninja -C build
    * Installing the library and language files (Linux, macOS, FreeBSD)
Run with an elevated shell:
        * ```bash
            $ ninja -C build install
    * On Linux systems, update the dynamic linker runtime bindings:
        * ```bash
            $ ldconfig
    * Usage
        * To compile your tests with Criterion, you need to make sure to:
            * Add the include directory to the header search path
            * Install the library to your library search path
            * Link Criterion to your executable.

This should be all you need.
## Description
[(Back to top)](#table-of-contents)

* You are now working on a simulation of your dear Koalas’ health.
To get started, you’ll need patients to treat.
Therefore, it is time to create a SickKoala class.
## Objectifs
[(Back to top)](#table-of-contents)

* Create a __SickKoala class__
* They can’t be __instantiated__ without a name string,
* Following their __destruction__, the standard output must display :
    ```
    Mr.[name]: Kreooogg!! I'm cuuuured!
    ```
* A __poke member function__ taking no parameters or return value and displaying the following when called:
    ```
    Mr.[name]: Gooeeeeerrk!!
    ```
* A __takeDrug function__ taking a string as parameter and returning true if the string matches Mars or Buronzand (case sensitive).
The function must then display, respectively:
    ```
    Mr.[name]: Mars, and it kreogs!
    ```
    or
    ```
    Mr.[name]: And you'll sleep right away!
    ```
    In any other case, the function returns false and displays:
    ```
    Mr.[name]: Goerkreog!
    ```
* Sometimes, SickKoalas go crazy when their fever is too high.
To simulate this, SickKoalas have an __overDrive member function__ that returns nothing and takes a string as parameter.
It displays the string passed as parameter, preceded by __"Mr.[name]: "__, within which all occurences of __"Kreog!"__ are __replaced__ by __"1337!"__.
    For instance:
    ```
    Kreog! How's it going?
    ```
    becomes:
    ```
    Mr.[name]: 1337! How's it going?
    ```
* For all outputs in this exercise, [name] must be __replaced by the name of the SickKoala__
   
## Key learnings
[(Back to top)](#table-of-contents)
### How to create a class
#### Visibility concept / ENCAPSULATION :
* With C++, __The Visibility concept__ exist.
* with C, any code can have __access to definition of the structure and the structure content__. so the structure is public.
With C++, we can indicate if the __properties or member functions are accessible or not__.
* We call this : __ENCAPSULATION__.
* With the __ENCAPSULATION__ we can indicate if the properties or member functions are public or private and even protected with __keywords : 
public:
private:
protected:__ .
* By default a __class is private__ and a structure is public. 

#### Constructor :
* __Initialisation__ and __destruction object__ is __automatic__ thanks to __Constructor and Destructor__.
* When we call a __Constructor__ it's for __create an Object__.
* When we call a __Destructor__ it's for __destroy an Object__.
* For declare a __Constructor__, we need to use the name of the class :
    ```
    class Bottle
    {
        //CTOR
        Bottle();
    }
    ```
* __Default Constructor not take any parameters__ and will be called when we __create objects normally__ but __Custom Constructor take parameters__.
* implementation of __Constructor__ its like a __member function__ :
    ```
    Bottle::Bottle()
    {
        /* ... */
    }

    type Bottle::MemberFunction()
    {
        /* ... */
        return type;
    }
    ```
    but __no return type__.
* Thanks to __Constructor's implementation we can do stuff or initialise class properties__.
    * Best way for init Constructor list :
        ```
        Bottle::Bottle() ; _isOpen(true), _content(100)
        ```
        __Best way because this practice avoid to execute some code for no reason. (gain performance)__

#### Destructor :
* __Destructor__ is an __automated process in C++__.
* Function calls __Destructor : ~Bottle();__
* A __Destructor__ is a __function__ that will be __called automatically when an object goes out of scope (at the end of the function for the example)__.
* For declare a __Destructor__ :
    ```
    Bottle::~Bottle()
    {
        ...
    }
    ```
* A __Destructor is important because if a class contains a pointer to memory allocated, the Destructor could free the memory automatically__.
This principle of using a Destructor for free ressources is called __RAII__.

## Installation
[(Back to top)](#table-of-contents)

* After downloaded the project and gone to the root path SimpleCatCommand repository you can use the __Makefile__ for compile the program or the units tests and generate a bynary:
    * ```
        make part1
        ```
    or for the unit_tests :
    * ```
        make tests_run_part1
        ```
## How To Use
[(Back to top)](#table-of-contents)

* To clone and run this application from your command line : 

```bash
# Clone this repository
$ git clone https://github.com/P4r4dis/The_hospital.git

# Go into the repository
$ cd The_hospital

# start Makefile for compilation and generate binary
$ make
# Or start Makefile for unit_tests
$ make tests_run

########################################################
#2e possibilities :
# Go into the repository
$ cd The_hospital/part1_patients

# start Makefile for compilation and generate binary
$ make
# Or start Makefile for unit_tests
$ make tests_run
#######################################################
#3e possibilities :
# Go into the repository
$ cd The_hospital

# start Makefile for compilation and generate binary
$ make part1
# Or start Makefile for unit_tests
$ make tests_run_part1
#######################################################

# Use binary
$ ./my_hospital

```
