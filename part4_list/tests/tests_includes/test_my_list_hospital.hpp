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
        SickKoala       *_patient;
        SickKoalaList   *_next;
    public:
    //CTOR
        SickKoalaList(SickKoala     *patient);
    //CCTOR
    //DTOR
        ~SickKoalaList();
    //Member Function
        bool            isEnd(void);
        void            append(SickKoalaList            *sickKoalaList);
        SickKoalaList   *remove(SickKoalaList           *sickKoalaList);
        SickKoalaList   *removeFromName(std::string     name);
        void            dump(void);

    //Getter
        SickKoala       *getPatient();
        SickKoala       *getFromName(std::string        name);
        SickKoala       *getContent(void);
        SickKoalaList   *getNext(void);
    //Setter
};



#endif  // !__TEST_MY_LIST_HOSPITAL__



