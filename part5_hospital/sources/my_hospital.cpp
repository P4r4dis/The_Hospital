#include "../includes/my_hospital.hpp"

//CTOR

//CUSTOM CTOR
Hospital::Hospital() :  _sickKoalaList(nullptr), _koalaNurseList(nullptr),
                        _koalaDoctorList(nullptr)
{}
//DTOR
Hospital::~Hospital()
{}
//MEMBER FUNCTION

//GETTER
SickKoalaList       *Hospital::getSickKoalaList(void)
{
    return _sickKoalaList;
}

KoalaNurseList      *Hospital::getKoalaNurseList(void)
{
    return _koalaNurseList;
}

KoalaDoctorList     *Hospital::getKoalaDoctorList(void)
{
    return _koalaDoctorList;
}

void                Hospital::addDoctor(KoalaDoctorList       *koalaDoctorList)
{
    if (this->_koalaDoctorList && this->_koalaDoctorList->getFromName(koalaDoctorList->getDoctor()->getName()))
        return ;
    if (this->_koalaDoctorList)
            this->_koalaDoctorList->append(koalaDoctorList);
    else
        this->_koalaDoctorList = koalaDoctorList;
    std::cout << "[HOSPITAL] Doctor " << koalaDoctorList->getDoctor()->getName() << " just arrived!" << std::endl;
    koalaDoctorList->getDoctor()->timeCheck();
}

void                Hospital::addSick(SickKoalaList       *sickKoalaList)
{
    if (this->_sickKoalaList && this->_sickKoalaList->getFromName(sickKoalaList->getPatient()->get_name()))
        return ;
    if (this->_sickKoalaList)
        this->_sickKoalaList->append(sickKoalaList);
    else
        this->_sickKoalaList = sickKoalaList;
    std::cout << "[HOSPITAL] Patient " << sickKoalaList->getPatient()->get_name() << " just arrived!" << std::endl;
}

void                Hospital::addNurse(KoalaNurseList       *koalaNurseList)
{
    if (this->_koalaNurseList && this->_koalaNurseList->getFromId(koalaNurseList->getNurse()->getID()))
        return ;
    if (this->_koalaNurseList)
        this->_koalaNurseList->append(koalaNurseList);
    else
        this->_koalaNurseList = koalaNurseList;
    std::cout << "[HOSPITAL] Nurse " << koalaNurseList->getNurse()->getID() << " just arrived!" << std::endl;
    koalaNurseList->getNurse()->timeCheck();
}

void                Hospital::dump()
{
    std::cout << "[HOSPITAL] Work starting with:" << std::endl;
    _koalaDoctorList->dump();
    _koalaNurseList->dump();
    _sickKoalaList->dump();
    std::cout << std::endl;
}

void                Hospital::heal()
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

void    Hospital::endWork()
{
    _koalaNurseList->getFromId(1)->timeCheck();
    _koalaNurseList = _koalaNurseList->removeFromId(1);
    _koalaNurseList->getFromId(2)->timeCheck();
    _koalaNurseList = _koalaNurseList->removeFromId(2);

    _koalaDoctorList->getFromName("Cox")->timeCheck();
    _koalaDoctorList = _koalaDoctorList->removeFromName("Cox");
    _koalaDoctorList->getFromName("House")->timeCheck();
    _koalaDoctorList = _koalaDoctorList->removeFromName("House");
    _koalaDoctorList->getFromName("Boudur-Oulot")->timeCheck();
    _koalaDoctorList = _koalaDoctorList->removeFromName("Boudur-Oulot");
}