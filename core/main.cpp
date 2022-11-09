#include "../includes/my_hospital.hpp"

int     main(int ac, char **av)
{
    if (ac < 2 && av) {
        //THE PATIENT SICKKOALA
        SickKoala   cancer("Ganepar");
        std::cout << cancer.get_name() << std::endl;
        SickKoala   gangrene("Scarface");
        std::cout << gangrene.get_name() << std::endl;
        SickKoala   measles("RedFace");
        std::cout << measles.get_name() << std::endl;
        SickKoala   smallpox("Varia");
        std::cout << smallpox.get_name() << std::endl;
        SickKoala   fracture("Falter");
        std::cout << fracture.get_name() << std::endl;


        /////////////////////////////
    }
    return 0;
}
