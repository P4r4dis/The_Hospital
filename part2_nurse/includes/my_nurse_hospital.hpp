#ifndef __MY_HOSPITAL__
#   define __MY_HOSPITAL__

#include <iostream>
#include <iomanip>
#include "../../part1_patient/includes/my_patient_hospital.hpp"

class KoalaNurse
{
    private:
        int     _id;

    public:
    //CTOR
        KoalaNurse(int  id);
    //CCTOR
    //DTOR
        ~KoalaNurse();
    //Member Function
        void    giveDrug(std::string    Drug, SickKoala     *patient);
    //Getter
        int     getID(void);
    //Setter

    protected:

};

#endif  // !__MY_HOSPITAL__