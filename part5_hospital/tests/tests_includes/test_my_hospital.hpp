#ifndef __TEST_MY_HOSPITAL__
#   define __TEST_MY_HOSPITAL__

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>
#include "../../part4_list/includes/my_list_hospital.hpp"

void                redirect_all_stdout(void);

class Hospital
{
    private:
    SickKoalaList   *_sickKoalaList;
    KoalaNurseList  *_koalaNurseList;
    KoalaDoctorList *_koalaDoctorList;

    public:
    Hospital()
    {
        this->_sickKoalaList = nullptr;
        this->_koalaNurseList = nullptr; 
        this->_koalaDoctorList = nullptr;
    }
    ~Hospital()
    {}

    SickKoalaList   *getSickKoalaList(void)
    {
        return _sickKoalaList;
    }

    KoalaNurseList   *getKoalaNurseList(void)
    {
        return _koalaNurseList;
    }

    KoalaDoctorList   *getKoalaDoctorList(void)
    {
        return _koalaDoctorList;
    }
};

#endif  // !__TEST_MY_HOSPITAL__