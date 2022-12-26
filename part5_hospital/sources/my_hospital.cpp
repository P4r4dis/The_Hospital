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
    if (_koalaDoctorList && _koalaDoctorList->getFromName(koalaDoctorList->getDoctor()->getName()))
        _koalaDoctorList->append(koalaDoctorList);
    else
        _koalaDoctorList = koalaDoctorList;
    std::cout << "[HOSPITAL] Doctor " << _koalaDoctorList->getDoctor()->getName() << " just arrived!" << std::endl;
    _koalaDoctorList->getDoctor()->timeCheck();
}

void                Hospital::addSick(SickKoalaList       *sickKoalaList)
{
    if (_sickKoalaList && _sickKoalaList->getFromName(sickKoalaList->getPatient()->get_name()))
        _sickKoalaList->append(sickKoalaList);
    else
        _sickKoalaList = sickKoalaList;
    std::cout << "[HOSPITAL] Patient " << _sickKoalaList->getPatient()->get_name() << " just arrived!" << std::endl;
}

void                Hospital::addNurse(KoalaNurseList       *koalaNurseList)
{
    if (_koalaNurseList && _koalaNurseList->getFromId(koalaNurseList->getNurse()->getID()))
        _koalaNurseList->append(koalaNurseList);
    else
        _koalaNurseList = koalaNurseList;
    std::cout << "[HOSPITAL] Nurse " << _koalaNurseList->getNurse()->getID() << " just arrived!" << std::endl;
    _koalaNurseList->getNurse()->timeCheck();
}