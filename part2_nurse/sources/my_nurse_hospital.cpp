#include "../includes/my_nurse_hospital.hpp"
//CTOR
KoalaNurse::KoalaNurse(int id) : _id(id)
{

}
//DTOR
KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << _id << ": Finally some rest!" << std::endl;
}
//MEMBER FUNCTION

//GETTER
int     KoalaNurse::getID(void)
{
        return _id;
}