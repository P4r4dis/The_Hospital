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