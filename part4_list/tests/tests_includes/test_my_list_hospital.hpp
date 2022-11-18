#ifndef __TEST_MY_LIST_HOSPITAL__
#   define __TEST_MY_LIST_HOSPITAL__

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../../../part1_patient/includes/my_patient_hospital.hpp"

void                redirect_all_stdout(void);

class SickKoalaList
{
    private:
        SickKoala   *_patient;
    public:
    //CTOR
        SickKoalaList(SickKoala     *patient);
    //CCTOR
    //DTOR
        ~SickKoalaList();
    //Member Function
    //Getter
        SickKoala   *getPatient();
    //Setter
};



#endif  // !__TEST_MY_LIST_HOSPITAL__

        SickKoalaList::SickKoalaList(SickKoala     *patient)
        {
            this->_patient = patient;
        }

       SickKoalaList::~SickKoalaList()
       {
       }

       SickKoala *SickKoalaList::getPatient(){
        return _patient;
       }
