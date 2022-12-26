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

    void              addDoctor(KoalaDoctorList       *koalaDoctorList)
    {
        if (this->_koalaDoctorList && this->_koalaDoctorList->getFromName(koalaDoctorList->getDoctor()->getName())) {

            this->_koalaDoctorList->append(koalaDoctorList);
        }
        else {
            this->_koalaDoctorList = koalaDoctorList;
        }
        std::cout << "[HOSPITAL] Doctor " << _koalaDoctorList->getDoctor()->getName() << " just arrived!" << std::endl;
        _koalaDoctorList->getDoctor()->timeCheck();
    }


    //         if (doc1.getDoctor() && doc1.getFromName(doc1.getDoctor()->getName()))
    //     {
    //             cr_log_warn("TEST");
    //             bellevue.getKoalaDoctorList()->append(&doc1);
    //             cr_assert(bellevue.getKoalaDoctorList() != nullptr);
    //     }
	// if (this->doctors) {
	// 	this->doctors->append(doctor);
	// }
	// else {
	// 	this->doctors = doctor;
	// }
	// this->action(doctor->getItem()->getName() + " just arrived !");
	// doctor->getItem()->timeCheck();

};

#endif  // !__TEST_MY_HOSPITAL__