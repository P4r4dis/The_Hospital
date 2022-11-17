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
void                    KoalaDoctor::diagnose(SickKoala         *patient)
{
        std::ofstream   file_drReport;
        std::string     file_nameReport = patient->get_name() + ".report";
        std::string     drug[5] = {"Mars", "Buronzand", 
        "Viagra", "Extasy", "Eucalyptus leaf"};
        long            number_random = random() % 5;

        std::cout << "Dr." << _name
        << ": So what's goerking you Mr." 
        << patient->get_name() << "?" << std::endl;
        patient->poke();
        file_drReport.open(file_nameReport);
        if (file_drReport.is_open())
        {
                file_drReport << drug[number_random];
                file_drReport.close();
        }
}
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