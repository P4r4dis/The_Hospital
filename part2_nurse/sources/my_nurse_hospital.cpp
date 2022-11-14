#include "../includes/my_nurse_hospital.hpp"
//CTOR
KoalaNurse::KoalaNurse(int id) : _id(id)
{
        this->_isWorking = false;
}
//DTOR
KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << _id << ": Finally some rest!" << std::endl;
}
//MEMBER FUNCTION
void            KoalaNurse::giveDrug(std::string    Drug, SickKoala     *patient)
{
    patient->takeDrug(Drug);
}
//Alternative
// void    KoalaNurse::giveDrug(std::string    Drug, SickKoala     &patient)
// {
//     patient->takeDrug(Drug);
// }
std::string     KoalaNurse::readReport(std::string  fileName)
{
    std::fstream    f_stream;
    std::string     buffer;
    const char      delimiter = '\0';
    std::string     fileName_with_extention = fileName + ".report";

    f_stream.open(fileName_with_extention.data(), std::ios::in);
    if (f_stream.is_open()) {
                while (std::getline (f_stream, buffer, delimiter)) {
                        std::cout << "Nurse " << this->_id 
                        << ": Kreog! Mr." << fileName 
                        << " needs a " << buffer << "!" << std::endl;
                        f_stream.close();
                        return "Nurse " + std::to_string(this->_id)
                        + ": Kreog! Mr." + fileName + " needs a " + buffer + "!\n";
                }
        }
        std::cout << "";
        f_stream.close();
        return "";
}

void            KoalaNurse::timeCheck(void)
{
        this->_isWorking = !this->_isWorking;
        if(_isWorking == true) {
                std::cout << "Nurse " << this->_id << ": Time to get to work!" << std::endl;
        }
        else {
                std::cout << "Nurse " << this->_id << ": Time to go home to my eucalyptus forest!" << std::endl;
        }
}
//GETTER
int             KoalaNurse::getID(void)
{
        return _id;
}

bool            KoalaNurse::get_isWorking(void)
{
        return _isWorking;
}

//SETTER
void            KoalaNurse::set_isWorking(bool isWorking)
{
        this->_isWorking = isWorking;
}