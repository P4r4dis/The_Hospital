#ifndef __MY_HOSPITAL__
#   define __MY_HOSPITAL__

#include <iostream>
#include <iomanip>
#include <fstream>
#include "../../part1_patient/includes/my_patient_hospital.hpp"

class KoalaNurse
{
    private:
        int     _id;
        bool    _isWorking;

    public:
    //CTOR
        KoalaNurse(int  id);
    //CCTOR
    //DTOR
        ~KoalaNurse();
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

#endif  // !__MY_HOSPITAL__