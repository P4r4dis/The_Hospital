#ifndef __TEST_MY_HOSPITAL__
#   define __TEST_MY_HOSPITAL__

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <iostream>
#include <iomanip>
// struct parameter_tuple {
//     double temp_fahrenheit;
//     double temp_celsius;
// };

void                redirect_all_stdout(void);

// class SickKoala {
//     public:
//             SickKoala();
//             SickKoala(std::string name);
//     private:
//             std::string     _name;
// };

// //CTOR
// SickKoala::SickKoala() : _name("SickKoala")
// {
//     std::cout << "Default" << std::endl;
// }

// //CUSTOM CTOR
// SickKoala::SickKoala(std::string name) : _name(name) {
//     std::cout << "Cusotm" << std::endl;
// }

#endif  // !__TEST_MY_HOSPITAL__