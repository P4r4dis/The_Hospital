#ifndef __MY_HOSPITAL__
#   define __MY_HOSPITAL__

#include <iostream>
#include <iomanip>
#include <fstream>
#include "../../part4_list/includes/my_list_hospital.hpp"


class Hospital
{
    private:
    SickKoalaList       *_sickKoalaList;
    KoalaNurseList      *_koalaNurseList;
    KoalaDoctorList     *_koalaDoctorList;

    public:
    Hospital(void);
    ~Hospital(void);

    SickKoalaList       *getSickKoalaList(void);
    KoalaNurseList      *getKoalaNurseList(void);
    KoalaDoctorList     *getKoalaDoctorList(void);
};


#endif  // !__MY_HOSPITAL__