# The_Hospital
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
### The_Hospital Part 1 : SickKoala (Patients)

* You are now working on a simulation of your dear Koalas’ health.
To get started, you’ll need patients to treat.
Therefore, it is time to create a __SickKoala class__.

### The_Hospital Part 2 : KoalaNurse (Nurse)
* Now that we have patients, we need a nurse to take care of them.
You are now coding the nurse for the koala: the __KoalaNurse class__.
Here is the information you need in order to create the KoalaNurse.

### The_Hospital Part 3 : KoalaDoctor (Doctor)
* Before we get started, add a getName member function to the SickKoala class, taking no parameters and returning the name of the patient as a string.

* We now have patients and nurses taking care of them.
* We still need a doctor to give instructions to the nurses.
* __Implement a simulation__ of the doctor with the __KoalaDoctor class__.

### The_Hospital Part 4 : List
* Before we get started, __modify__ your __KoalaNurse__ and __KoalaDoctor classes__:
    * Add a __getID__ member function to the __KoalaNurse class__.
    This function __takes no parameter and returns an int__.
    * Add a __getName__ member function to the __KoalaDoctor class__.
    This function __takes no parameter and returns a string__.

We now need to watch over all these people working together in harmony.
It is necessary to be able to __handle several patients, doctors and/or nurses at the same time__.
To do so, we need a __list for each of these categories__.

### The_Hospital Part 5 : Hospital
* It is now possible to manage several patients, nurses and doctors.
* It is time to move on and manage the entire __Hospital__!
* You will now code without any help.



## Objectifs
[(Back to top)](#table-of-contents)
### The_Hospital Part 1 : SickKoala (Patients)

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

### The_Hospital Part 2 : KoalaNurse (Nurse)
* Each __KoalaNurse has a numerical identifier (ID)__ which must be provided when the object is created,
but it is not possible to create a nurse without specifying her ID.
* When a __KoalaNurse is destroyed__, it’ll express its relief like so:
    ```
    Nurse [ID]: Finally some rest!
    ```
* The nurse can give drugs to patients, through a __giveDrug member function__ with the following __parameters a string (Drug)__ and a __pointer to the patient__.
This member function does not __return anything__.
When it is called, the nurse gives medication to the patient.

* The nurse can read the doctor’s report through a __readReport member function__ that takes a __filename
string as parameter__.
    * The filename is built from the sick Koala’s name, followed by the __.report extension__.
    * The __file contains the name of the drug__ to give to the patient.
This member function __returns the name of the drug as a string__ and prints the following to the standard output:
    ```
    Nurse [ID]: Kreog! Mr.[patientName] needs a [drugName]!
    ```
If the __.report__ file doesn’t exist or is not valid, nothing must be displayed and the return value must be
an __empty string__.

* The nurse can clock in thanks to a __timeCheck member function__ that takes __no parameter__ and doesn’t __return anything__.
The nurse calls this member function when it __starts working__ and when it __stops working__ (as it is a very diligent worker).
When it clocks in at the __start__ of her job, it says:
```
Nurse [ID]: Time to get to work!
```
When it __stops__ working, it says:
```
Nurse [ID]: Time to go home to my eucalyptus forest!
```
By default, when the program starts, the nurse is not working yet.
The KoalaNurse being very diligent, it will take any job.
Even outsided the hospital.
Only a call to the __timeCheck member function__ lets the KoalaNurse change her working status: if it is not
working, it __starts__ to work; if it is working, it __stops__.

### The_Hospital Part 3 : KoalaDoctor (Doctor)
* It must be __instantiated with a name string__.
During __construction__, it must print the following to the standard output:
```
Dr.[name]: I'm Dr.[name]! How do you kreog?
```

* It can __diagnose__ patients using the __diagnose member function__ that takes a __pointer to the patient to
diagnose as parameter__.
This member function prints the following to the standard output:
    ```
    Dr.[name]: So what's goerking you Mr.[patientName]?
    ```

    * It then calls the _poke member function of the SickKoala__.
    The doctor then __writes a report for nurses__, in a __file named [patientname].report__.
    This file contains the __name of the drug to give to the patient__.
    * The name will be picked at __random__ from the following list:
        * Mars
        * Buronzand
        * Viagra
        * Extasy
        * Eucalyptusleaf

* The KoalaDoctor clocks in through a __timeCheck member function__, which takes __no parameters__ and does not __return anything__.
When it __starts working__, it says:
    ```
    Dr.[name]: Time to get to work!
    ```

    When it __stops__ working, it says:
    ```
    Dr.[name]: Time to go home to my eucalyptus forest!
    ```
    The KoalaDoctor being very diligent, it will take any job.
    Even outside the hospital.

### The_Hospital Part 4 : List
__Implement the 3 following classes.__
___
__SICKKOALALIST__ :
* Takes a __pointer to a SickKoala__ as a __constructor parameter__.
This pointer can be a __nullptr__.
* Has an __isEnd__ member function which takes no parameter and __returns a boolean__ set to true if the __SickKoalaList__ is the last node of its list.
* Has an __append__ member function which takes a __pointer to a SickKoalaList__ as a parameter and does not __return__ anything.
The node passed as parameter is __added to the end of the linked list__.
* Has a __getFromName__ member function which takes a __string__ as a parameter and __returns__ a pointer to the first SickKoala in the list whose name __matches that string__.
* Has a __remove__ member function which takes a pointer to a SickKoalaList as a parameter and removes the SickKoalaList __matching__ this pointer from the list.
It __returns__ a pointer to the first node of the list.
* Has a __removeFromName__ member function which takes a __string__ as a parameter and removes the first SickKoala whose name __matches__ that string from the list.
It __returns__ a pointer to the first node of the list.
* Has a __getContent__ member function which takes __no parameter__ and __returns__ a pointer to the element held in the current instance.
* Has a __getNext__ member function which takes __no parameter__ and __returns__ a pointer to the next node of the list.
If there is no such node, the function __returns__ a nullptr.
* Has a __dump__ member function which takes __no parameter__ and does not __return__ anything.
It __displays__ the name of all the SickKoalas in the list in order (begin -> end):
    ```
    Patients: name1, name2, ..., nameX.
    ```
___
__KOALANURSELIST__ :
* takes a pointer to a __KoalaNurse__ as a constructor parameter.
This pointer can be a __nullptr__.
* Has an __isEnd__ member function which takes no parameter and returns a boolean set to __true__ if the __KoalaNurseList__ is the last node of its list.
* Has an __append__ member function which takes a pointer to a __KoalaNurseList__ as a parameter and does not return anything.
The node passed as parameter is added to the end of the linked list.
* Has a __getFromID__ member function which takes an __int__ as a parameter and returns a pointer to the first __KoalaNurse__ in the list whose ID matches that __int__.
* Has a __remove__ member function which takes a pointer to a __KoalaNurseList__ and removes the __KoalaNurseList__ matching this pointer from the list.
It returns a pointer to the first node of the list.
* Has a __removeFromID__ member function which takes an __int__ as parameter and removes the first __KoalaNurse__ whose ID matches that __int__ from the list.
It returns a pointer to the first node of the list.
* Has a __dump__ member function which takes no parameter and does not return anything.
It displays the ID of all the __KoalaNurses__ in the list in order (begin -> end):
    ```
    Nurses: id1, id2, ..., idX.
    ```
___
__KOALADOCTORLIST__ :
* Takes a pointer to a __KoalaDoctor__ as a constructor parameter.
This pointer can be a __nullptr__.
* Has an __isEnd__ member function which takes no parameter and returns a boolean set to __true__ if the __KoalaDoctorList__ is the last node of its list.
* Has an __append__ member function which takes a pointer to a __KoalaDoctorList__ as a parameter and does not return anything.
The node passed as parameter is added to the end of the linked list.
* Has a __getFromName__ member function which takes a __string__ as a parameter and returns the first __KoalaDoctor__ in the list whose name matches that __string__.
* Has a __remove__ member function which takes a pointer to a __KoalaDoctorList__ as a parameter and removes the __KoalaDoctorList__ matching this pointer from the list.
It returns a pointer to the first node of the list.
* Has a __removeFromName__ member function which takes a __string__ as a parameter and removes the first __KoalaDoctor__ whose name matches that __string__ from the list.
It returns a pointer to the first node of the list.
* Has a __dump__ member function which takes no parameter and does not return anything.
It displays the name of all __KoalaDoctors__ in the list in order (begin -> end):
    ```
    Doctors: name1, name2, ..., nameX.
    ```
___
### The_Hospital Part 5 : Hospital

* You must __deduce__ the member functions of the __Hospital__ based on the sample __main__ function you will find below.
* The __Hospital__ must distribute work between doctors and nurses.
For this exercise, you may have to modify existing classes.
You are responsible for these modifications, as long as they comply with the requirements and descriptions of the previous exercises!
```
#include "../part5_hospital/includes/my_hospital.hpp"
# include <iostream>
# include <string>
# include <cstdlib>
# include "SickKoala.hpp"
# include "KoalaNurse.hpp"
# include "KoalaDoctor.hpp"
# include "SickKoalaList.hpp"
# include "KoalaNurseList.hpp"
# include "KoalaDoctorList.hpp"
# include "Hospital.hpp"

int     main(void)
{
        srandom (42) ;

        KoalaDoctor             cox("Cox");
        KoalaDoctor             house("House");
        KoalaDoctor             tired("Boudur-Oulot");

        KoalaDoctorList         doc1(&cox);
        KoalaDoctorList         doc2(&house);
        KoalaDoctorList         doc3(&tired);

        KoalaNurse              ratched(1);
        KoalaNurse              betty(2);

        KoalaNurseList          nurse1(&ratched);
        KoalaNurseList          nurse2(&betty);

        SickKoala               cancer("Ganepar");
        SickKoala               gangrene("Scarface");
        SickKoala               measles("RedFace");
        SickKoala               smallpox("Varia");
        SickKoala               fracture("Falter");

        SickKoalaList           sick1(&cancer);
        SickKoalaList           sick2(&gangrene);
        SickKoalaList           sick3(&measles);
        SickKoalaList           sick4(&smallpox);
        SickKoalaList           sick5(&fracture);

        Hospital                bellevue;

        bellevue.addDoctor(&doc1);
        bellevue.addDoctor(&doc2);
        bellevue.addDoctor(&doc3);

        bellevue.addSick(&sick1);
        bellevue.addSick(&sick2);
        bellevue.addSick(&sick3);
        bellevue.addSick(&sick4);
        bellevue.addSick(&sick5);

        bellevue.addNurse(&nurse1);
        bellevue.addNurse(&nurse2);

        bellevue.run();
        if (nurse1.isEnd() && sick1.isEnd() && doc1.isEnd())
                std::cout << "Lists cleaned up." << std::endl;
        else
                std::cerr << "You fail! Boo!" << std::endl;
        return (0);
}
```
OUTPUT :
```
∼/B-CPP-300>./a.out
Dr.Cox: I'm Dr.Cox! How do you kreog?
Dr.House: I'm Dr.House! How do you kreog?
Dr.Boudur-Oulot: I'm Dr.Boudur-Oulot! How do you kreog?
[HOSPITAL] Doctor Cox just arrived!
Dr.Cox: Time to get to work!
[HOSPITAL] Doctor House just arrived!
Dr.House: Time to get to work!
[HOSPITAL] Doctor Boudur-Oulot just arrived!
Dr.Boudur-Oulot: Time to get to work!
[HOSPITAL] Patient Ganepar just arrived!
[HOSPITAL] Patient Varia just arrived!
[HOSPITAL] Patient RedFace just arrived!
[HOSPITAL] Patient Scarface just arrived!
[HOSPITAL] Patient Falter just arrived!
[HOSPITAL] Nurse 1 just arrived!
Nurse 1: Time to get to work!
[HOSPITAL] Nurse 2 just arrived!
Nurse 2: Time to get to work!
[HOSPITAL] Work starting with:
Doctors: Cox, House, Boudur-Oulot.
Nurses: 1, 2.
Patients: Ganepar, Varia, RedFace, Scarface, Falter.

Dr.Cox: So what's goerking you Mr.Ganepar?
Mr.Ganepar: Gooeeeeerrk!!
Nurse 1: Kreog! Mr.Ganepar needs a Buronzand!
Mr.Ganepar: And you'll sleep right away!
Dr.House: So what's goerking you Mr.Varia?
Mr.Varia: Gooeeeeerrk!!
Nurse 2: Kreog! Mr.Varia needs a Mars!
Mr.Varia: Mars, and it kreogs!
Dr.Boudur-Oulot: So what's goerking you Mr.RedFace?
Mr.RedFace: Gooeeeeerrk!!
Nurse 1: Kreog! Mr.RedFace needs a Buronzand!
Mr.RedFace: And you'll sleep right away!
Dr.Cox: So what's goerking you Mr.Scarface?
Mr.Scarface: Gooeeeeerrk!!
Nurse 2: Kreog! Mr.Scarface needs a Buronzand!
Mr.Scarface: And you'll sleep right away!
Dr.House: So what's goerking you Mr.Falter?
Mr.Falter: Gooeeeeerrk!!
Nurse 1: Kreog! Mr.Falter needs a Viagra!
Mr.Falter: Goerkreog!
Nurse 1: Time to go home to my eucalyptus forest!
Nurse 2: Time to go home to my eucalyptus forest!
Dr.Cox: Time to go home to my eucalyptus forest!
Dr.House: Time to go home to my eucalyptus forest!
Dr.Boudur-Oulot: Time to go home to my eucalyptus forest!
Lists cleaned up.
Mr.Falter: Kreooogg!! I'm cuuuured!
Mr.Varia: Kreooogg!! I'm cuuuured!
Mr.RedFace: Kreooogg!! I'm cuuuured!
Mr.Scarface: Kreooogg!! I'm cuuuured!
Mr.Ganepar: Kreooogg!! I'm cuuuured!
Nurse 2: Finally some rest!
Nurse 1: Finally some rest!
```

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

* After downloaded the project and gone to the root path The_Hospital repository you can use the __Makefile__ for compile the program or the units tests and generate a bynary:
    *   ```
        #Example
        make part1
        ```
    or for the unit_tests :
    *   ```
        #Example
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
$ cd The_hospital/part1_patient
# or
$ cd The_hospital/part1_nurse
# or
$ cd The_hospital/part1_doctor
# or
$ cd The_hospital/part1_list
# or
$ cd The_hospital/part1_hospital
# or

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
# or
$ make part2
# or
$ make part3
# or
$ make part4
# or
$ make part5

# Or start Makefile for unit_tests
$ make tests_run_part1
# or
$ make tests_run_part2
# or
$ make tests_run_part3
# or
$ make tests_run_part4
# or
$ make tests_run_part5
# or
#######################################################

# Use binary
$ ./a.out

```
