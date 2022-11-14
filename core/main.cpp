#include "../part1_patient/includes/my_patient_hospital.hpp"
#include "../part2_nurse/includes/my_nurse_hospital.hpp"


int     main(int ac, char **av)
{
    if (ac < 2 && av) {
        std::cout << "CORE MAIN" << std::endl;
        //THE PATIENT SICKKOALA
        SickKoala   cancer("Ganepar");
        std::cout << cancer.get_name() << std::endl;
        cancer.poke();
        std::cout << std::boolalpha << "return value : " << 
        cancer.takeDrug("Mars") << std::endl;
        std::cout << std::boolalpha << "return value : " << 
        cancer.takeDrug("Buronzand") << std::endl;
        std::cout << std::boolalpha << "return value : " << 
        cancer.takeDrug("random") << std::endl;
        cancer.overDrive("Kreog! How's it going?");

        SickKoala   gangrene("Scarface");
        std::cout << gangrene.get_name() << std::endl;
        gangrene.poke();
        std::cout << std::boolalpha << "return value : " << 
        gangrene.takeDrug("Mars") << std::endl;
        std::cout << std::boolalpha << "return value : " << 
        gangrene.takeDrug("Buronzand") << std::endl;
        std::cout << std::boolalpha << "return value : " << 
        gangrene.takeDrug("random") << std::endl;
        gangrene.overDrive("Kreog! How's it going?");

        SickKoala   measles("RedFace");
        std::cout << measles.get_name() << std::endl;
        measles.poke();
        std::cout << std::boolalpha << "return value : " << 
        measles.takeDrug("Mars") << std::endl;
        std::cout << std::boolalpha << "return value : " << 
        measles.takeDrug("Buronzand") << std::endl;
        std::cout << std::boolalpha << "return value : " << 
        measles.takeDrug("random") << std::endl;
        measles.overDrive("Kreog! How's it going?");

        SickKoala   smallpox("Varia");
        std::cout << smallpox.get_name() << std::endl;
        smallpox.poke();
        std::cout << std::boolalpha << "return value : " << 
        smallpox.takeDrug("Mars") << std::endl;
        std::cout << std::boolalpha << "return value : " << 
        smallpox.takeDrug("Buronzand") << std::endl;
        std::cout << std::boolalpha << "return value : " << 
        smallpox.takeDrug("random") << std::endl;
        smallpox.overDrive("Kreog! How's it going?");

        SickKoala   fracture("Falter");
        std::cout << fracture.get_name() << std::endl;
        fracture.poke();
        std::cout << std::boolalpha << "return value : " << 
        fracture.takeDrug("Mars") << std::endl;
        std::cout << std::boolalpha << "return value : " << 
        fracture.takeDrug("Buronzand") << std::endl;
        std::cout << std::boolalpha << "return value : " << 
        fracture.takeDrug("random") << std::endl;
        fracture.overDrive("Kreog! How's it going?");

        /////////////////////////////
        SickKoala   sickKoala("SickKoala");
        std::cout << sickKoala.get_name() << std::endl;
        sickKoala.poke();
        std::cout << std::boolalpha << "return value : " << 
        sickKoala.takeDrug("Mars") << std::endl;
        std::cout << std::boolalpha << "return value : " << 
        sickKoala.takeDrug("Buronzand") << std::endl;
        std::cout << std::boolalpha << "return value : " << 
        sickKoala.takeDrug("random") << std::endl;
        sickKoala.overDrive("Kreog! How's it going?");
        ////////////////////////////////////////////////////
        //NURSE
        ////////////////////////////////////////////////////
        KoalaNurse      ratched(1);
        KoalaNurse      betty(2);
        
        ratched.giveDrug("Drug", &sickKoala);
        betty.readReport("SickKoala");
        std::cout << std::boolalpha << "bool : " << 
        betty.get_isWorking() << std::endl;
        betty.timeCheck();
        std::cout << std::boolalpha << "bool : " << 
        betty.get_isWorking() << std::endl;
        betty.timeCheck();
        std::cout << std::boolalpha << "bool : " << 
        betty.get_isWorking() << std::endl;
    }
    return 0;
}
