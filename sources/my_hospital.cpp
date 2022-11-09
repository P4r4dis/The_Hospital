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

bool            SickKoala::takeDrug(std::string     str)
{
        if (str == "Mars")
        {
            std::cout << "Mr." << get_name() << ": Mars, and it kreogs!" << std::endl;
            return true;
        }
        else if (str == "Buronzand")
        {
            std::cout << "Mr." << get_name() << ": And you'll sleep right away!" << std::endl;
            return true;
        }
        else
        {
            std::cout << "Mr." << get_name() << ": Goerkreog!" << std::endl;
            return false;
        }
}

//Getter
std::string     SickKoala::get_name(void)
{
        return _name;
}