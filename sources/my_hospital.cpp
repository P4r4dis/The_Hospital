#include "../includes/my_hospital.hpp"

//CTOR
SickKoala::SickKoala() : _name("SickKoala")
{}

//CUSTOM CTOR
SickKoala::SickKoala(std::string name) : _name(name) 
{}

//DTOR
SickKoala::~SickKoala()
{
        std::cout << "Mr." << _name << ": Kreooogg!! I'm cuuuured!" << std::endl;
}

//MEMBER FUNCTION
void            SickKoala::poke(void)
{
        std::cout << "Mr." << _name << ": Gooeeeeerrk!!" << std::endl;
}

//Getter
std::string     SickKoala::get_name(void)
{
        return _name;
}