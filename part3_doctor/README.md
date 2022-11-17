# The_Hospital
## The_Hospital Part 3 : KoalaDoctor (Doctor)
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

* Now that we have patients, we have a nurse to take care of them.
We still need a doctor to give instructions to the nurses.
You are now coding the Doctor for the koala: the __KoalaDoctor class.__
## Objectifs
[(Back to top)](#table-of-contents)
* Before we get started, __add a getName member function__ to the __SickKoala class__, taking __no parameters__ and __returning the name of the patient as a string.__

* Create a __KoalaDoctor class__.
it must be __instantiated__ with a __name string__.
During __construction__, it must __print__ the following to the __standard output__:
    ```
    Dr .[ name ]: I ' m Dr .[ name ]! How do you kreog ?
    ```
*  It can __diagnose patients__ using the __diagnose member function__ that takes a __pointer to the patient to diagnose as parameter__.
    * This __member function prints__ the following to the __standard output__:
        ```
        Dr .[ name ]: So what ' s goerking you Mr .[ patientName ]?
        ```
    * It then calls the __poke member function__ of the __SickKoala__.
    * The doctor then __writes a report__ for nurses, in a __file named [patientname].report__.
    * This __file contains the name of the drug to give to the patient__.
    * The name will be __picked__ at __random__ from the following __list__:
        * Mars
        * Buronzand
        * Viagra
        * Extasy
        * Eucalyptus leaf
            * To do this, you must __use random() % 5__ on the previous list, in the given order.
            The __srandom__ function will be called by the __correction main__.
* The __KoalaDoctor__ clocks in through a __timeCheck member function__, which takes __no parameters__ and does __not return anything__.
    * When it __starts working__, it says:
        ```
        Dr .[ name ]: Time to get to work !
        ```
    * When it __stops working__, it says:
        ```
        Dr .[ name ]: Time to go home to my eucalyptus forest !
        ```
    * The __KoalaDoctor__ being very diligent, it will take any job.
    Even outside the hospital.
* In this exercise, any occurence of __[name]__ must be replaced with the __name of the KoalaDoctor__, and occurences of __[patientName]__ must be replaced with the __name of the SickKoala__ that is currently being treated.

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

#### Getter and Setter (Accessors and Mutators)
* In C++ __getters and setters__, a “setter” or “setter method” is a method whose primary purpose is to write to or change a class field. A “getter” or “getter method,” on the other hand, is a method whose sole purpose is to return the current data of a class field

* In C++, __encapsulation__ is the process in which some __important information is kept private_ and can not be assessed by other members, which makes it impossible to change the values from outside the class. So, we need a special kind of function to retrieve those data and set values.

* Object-oriented programming offers the getter and setter functions to meet our retrieving and setting values. __Getter and setter functions allow access to the private data in a safe mode__. As the setter function C++ is used along with the data validation, and checks whether the user enters a valid value or not.

* In some cases, you can not use getter and setter functions. If you retrieve a member function but can not set the value, then it is read-only. The __getter function__ is also known as __“accessors”__ whereas the __setter function__ is known as the __“mutator”__ function.
##### How to create Getter function :
*   ```
    Bottle::getInt()
    {
        return _int; //_int is a private variable init in class
    }
    ```
##### How to create Setter function :
*   ```
    Bottle::setInt(int newInt)
    {
        _int = newInt;  //_int is a private variable init in class
                        //_int takes a value of newInt;
    }
    ```
#### The fstream Library
* __The fstream library__ provides C++ programmers with three classes for working with files. These classes include:
    * __ofstream__ This class represents an output stream. It’s used for creating files and writing information to files.
    * __ifstream__ This class represents an input stream. It’s used for reading information from data files.
    * __fstream__ This class generally represents a file stream. It comes with ofstream/ifstream capabilities. This means it’s capable of creating files, writing to files, reading from data files.

fstream | fstream | fstream |
------- | ------- | ------- |
ofstream| ifstream| fstream |
For creating files / writing information to files | For reading information from data file | For creating files, writing and reading from files |

* We used __fstream__

##### How open files
[(Back to top)](#table-of-contents)

* Before performing any operation on a file, you must first open it. If you need to write to the file, open it using __fstream__ or ofstream objects. If you only need to read from the file, open it using the ifstream object.

* The three objects, that is, fstream, ofstream, and ifstream, have the open() function defined in them. The function takes this syntax:
    * ```
        #include <fstream>
	    fstream my_file;
	    my_file.open(file_name, mode);
        ```
        * The file_name parameter denotes the name of the file to open.
        * The mode parameter is optional. It can take any of the following values:
            * Value | Description |
              ----- | ----------- |
              std::fstream::app | The Append mode. The output sent to the file is appended to it. |
              std::fstream::ate | It opens the file for the output then moves the read and write control to file’s end. |
              std::fsteram::in | It opens the file for a read. |
              std::fsteram::out | It opens the file for a write. |
              std::fstream::trunc | If a file exists, the file elements should be truncated prior to its opening. |
##### How to close files
[(Back to top)](#table-of-contents)
* Once a C++ program terminates, it automatically
    * flushes the streams
    * releases the allocated memory
    * closes opened files.
    * However, as a programmer, you should learn to close open files before the program terminates.

* The fstream, ofstream, and ifstream objects have the close() function for closing files. The function takes this syntax:
    * ```
        #include <fstream>
	    fstream my_file;
	    my_file.close();
        ```
##### How to Write to Files
* You can write to file right from your C++ program. You use stream insertion operator (<<) for this. The text to be written to the file should be enclosed within double-quotes.
* ```
    #include <iostream>
    #include <fstream>
    using namespace std;
    int main() {
        fstream my_file;
        my_file.open("my_file.txt", ios::out);
        if (!my_file) {
            cout << "File not created!";
        }
        else {
            cout << "File created successfully!";
            my_file << "TEST";
            my_file.close();
        }
        return 0;
    }
    ```
##### How to read files
[(Back to top)](#table-of-contents)

* For our use case, there’s little point in processing every character separately — after all, we want to print every line from our shopping list to the screen one by one. This calls for getline(), another member function, which reads in the text until it encounters a line break.
* Here’s how we would modify our code:
    * ```
        #include <fstream>

	    fstream my_file;
	    my_file.open(file_name, mode);

        std::string my_line;
        if (my_file.is_open()) {
            while (my_file) {
                std::getline (fstream, buffer, delimiter); //fstream = my_file, buffer = my_line, delimiter = '\0'
                std::cout << myline << std::endl;
            }
        }
        my_file.close();
        ```
## Installation
[(Back to top)](#table-of-contents)

* After downloaded the project and gone to the root path SimpleCatCommand repository you can use the __Makefile__ for compile the program or the units tests and generate a bynary:
    * ```
        make part3
        ```
    or for the unit_tests :
    * ```
        make tests_run_part3
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
$ cd The_hospital/part3_doctor

# start Makefile for compilation and generate binary
$ make
# Or start Makefile for unit_tests
$ make tests_run
#######################################################
#3e possibilities :
# Go into the repository
$ cd The_hospital

# start Makefile for compilation and generate binary
$ make part
# Or start Makefile for unit_tests
$ make tests_run_part3
#######################################################

# Use binary
$ ./my_hospital

```

<!-- # The_Hospital
## The_Hospital Part 2 : KoalaNurse (Nurse)
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

* Now that we have patients, we need a nurse to take care of them.
You are now coding the nurse for the koala: the KoalaNurse class.
## Objectifs
[(Back to top)](#table-of-contents)

* Create a __KoalaNurse class__
* Each __KoalaNurse__ has a __numerical identifier (ID)__ which must be provided when the object is created,
but it is not possible to create a nurse without __specifying her ID__.
* when a __KoalaNurse is destroyed__, it’ll express its relief like so:
    ```
    Nurse [ID]: Finally some rest!
    ```
* The nurse can give drugs to patients, through a __giveDrug member function__ with the following __parameters a string (Drug) and a pointer to the patient__.
This member function does not return anything.
When it is called, the nurse gives medication to the patient.
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

``` -->
