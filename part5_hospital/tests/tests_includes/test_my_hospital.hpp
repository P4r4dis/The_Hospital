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
            return ;
        }

        if (this->_koalaDoctorList) {
                this->_koalaDoctorList->append(koalaDoctorList);
        }
        else {
            this->_koalaDoctorList = koalaDoctorList;
        }
        std::cout << "[HOSPITAL] Doctor " << koalaDoctorList->getDoctor()->getName() << " just arrived!" << std::endl;
        koalaDoctorList->getDoctor()->timeCheck();
    }

        void              addSick(SickKoalaList       *sickKoalaList)
    {
 	if (this->_sickKoalaList && this->_sickKoalaList->getFromName(sickKoalaList->getPatient()->get_name())) {
		return ;
	}
	if (this->_sickKoalaList) {
		this->_sickKoalaList->append(sickKoalaList);
	}
	else {
		this->_sickKoalaList = sickKoalaList;
	}
        std::cout << "[HOSPITAL] Patient " << sickKoalaList->getPatient()->get_name() << " just arrived!" << std::endl;
    }

    void              addNurse(KoalaNurseList       *koalaNurseList)
    {
        if (this->_koalaNurseList && this->_koalaNurseList->getFromId(koalaNurseList->getNurse()->getID())) {
            return ;
        }
        if (this->_koalaNurseList) {
            this->_koalaNurseList->append(koalaNurseList);
        }
        else {
            this->_koalaNurseList = koalaNurseList;
        }
        std::cout << "[HOSPITAL] Nurse " << koalaNurseList->getNurse()->getID() << " just arrived!" << std::endl;
        koalaNurseList->getNurse()->timeCheck();
    }

    void    dump()
    {
        std::cout << "[HOSPITAL] Work starting with:" << std::endl;
        _koalaDoctorList->dump();
        _koalaNurseList->dump();
        _sickKoalaList->dump();
        std::cout << std::endl;
    }

    void    heal()
    {
        this->getKoalaDoctorList()->getFromName("Cox")->diagnose(this->getSickKoalaList()->getFromName("Ganepar"));
        this->getKoalaNurseList()->getFromId(1)->giveDrug(this->getKoalaNurseList()->getFromId(1)->readReport("Ganepar.report"), this->getSickKoalaList()->getFromName("Ganepar"));
        _sickKoalaList = this->getSickKoalaList()->removeFromName("Ganepar");

        this->getKoalaDoctorList()->getFromName("House")->diagnose(this->getSickKoalaList()->getFromName("Varia"));
        this->getKoalaNurseList()->getFromId(2)->giveDrug(this->getKoalaNurseList()->getFromId(2)->readReport("Varia.report"), this->getSickKoalaList()->getFromName("Varia"));
        _sickKoalaList = this->getSickKoalaList()->removeFromName("Varia");

        this->getKoalaDoctorList()->getFromName("Boudur-Oulot")->diagnose(this->getSickKoalaList()->getFromName("RedFace"));
        this->getKoalaNurseList()->getFromId(1)->giveDrug(this->getKoalaNurseList()->getFromId(1)->readReport("RedFace.report"), this->getSickKoalaList()->getFromName("RedFace"));
        _sickKoalaList = this->getSickKoalaList()->removeFromName("RedFace");

        this->getKoalaDoctorList()->getFromName("Cox")->diagnose(this->getSickKoalaList()->getFromName("Scarface"));
        this->getKoalaNurseList()->getFromId(2)->giveDrug(this->getKoalaNurseList()->getFromId(2)->readReport("Scarface.report"), this->getSickKoalaList()->getFromName("Scarface"));
        _sickKoalaList = this->getSickKoalaList()->removeFromName("Scarface");
    
        this->getKoalaDoctorList()->getFromName("House")->diagnose(this->getSickKoalaList()->getFromName("Falter"));
        this->getKoalaNurseList()->getFromId(1)->giveDrug(this->getKoalaNurseList()->getFromId(1)->readReport("Falter.report"), this->getSickKoalaList()->getFromName("Falter"));
        _sickKoalaList = this->getSickKoalaList()->removeFromName("Falter");
    }

    void    endWork()
    {
        _koalaNurseList->getFromId(1)->timeCheck();
        _koalaNurseList->getFromId(2)->timeCheck();

        _koalaDoctorList->getFromName("Cox")->timeCheck();
        _koalaDoctorList->getFromName("House")->timeCheck();
        _koalaDoctorList->getFromName("Boudur-Oulot")->timeCheck();

    }

    void    process()
    {
        dump();
        heal();
        endWork();
    }
};

#endif  // !__TEST_MY_HOSPITAL__