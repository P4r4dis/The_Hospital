#ifndef __MY_DOCTOR_HOSPITAL__
#   define __MY_DOCTOR_HOSPITAL__

#include <iostream>
#include <iomanip>
#include <fstream>
#include "../../part1_patient/includes/my_patient_hospital.hpp"
// #include "../../part2_nurse/includes/my_nurse_hospital.hpp"

class KoalaDoctor
{
    private:
        std::string     _name;

    public:
    //CTOR
        KoalaDoctor(std::string  name);
    //CCTOR
    //DTOR
        ~KoalaDoctor();
    //Member Function

    //Getter
        std::string     getName(void);
    //Setter
    protected:

};

#endif  // !__MY_DOCTOR_HOSPITAL__