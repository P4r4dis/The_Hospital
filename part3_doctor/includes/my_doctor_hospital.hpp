#ifndef __MY_DOCTOR_HOSPITAL__
#   define __MY_DOCTOR_HOSPITAL__

#include <iostream>
#include <iomanip>
#include <fstream>
#include "../../part1_patient/includes/my_patient_hospital.hpp"

class Doctor
{
    private:
        int     _id;
        bool    _isWorking;

    public:
    //CTOR
        Doctor(int  id);
    //CCTOR
    //DTOR
        ~Doctor();
    //Member Function
        void            giveDrug(std::string    Drug, SickKoala     *patient);
        std::string     readReport(std::string  fileName);
        void            timeCheck(void);
    //Getter
        int             getID(void);
        bool            get_isWorking(void);
    //Setter
        void            set_isWorking(bool  isWorking);
    protected:

};

#endif  // !__MY_DOCTOR_HOSPITAL__