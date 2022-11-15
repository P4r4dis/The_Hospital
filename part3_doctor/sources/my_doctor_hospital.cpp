#include "../includes/my_doctor_hospital.hpp"
//CTOR
KoalaDoctor::KoalaDoctor(std::string      name) : _name(name)
{
        std::cout << "Dr." << _name << ": I'm Dr." 
        << _name << "! How do you kreog?" << std::endl;
}
//DTOR
KoalaDoctor::~KoalaDoctor()
{
}
// //MEMBER FUNCTION
// void            Doctor::giveDrug(std::string    Drug, SickKoala     *patient)
// {
//     patient->takeDrug(Drug);
// }
// //Alternative
// // void    KoalaNurse::giveDrug(std::string    Drug, SickKoala     &patient)
// // {
// //     patient->takeDrug(Drug);
// // }

// //GETTER
std::string             KoalaDoctor::getName(void)
{
        return _name;
}

// //SETTER
// void            Doctor::set_isWorking(bool isWorking)
// {
//         this->_isWorking = isWorking;
// }