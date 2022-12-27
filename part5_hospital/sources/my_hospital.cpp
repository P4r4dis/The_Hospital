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