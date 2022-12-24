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