#include "../includes/my_hospital.hpp"

int     main(void)
{
        // std::cout << "PATIENT MAIN" << std::endl;
        // //THE PATIENT SICKKOALA
        // SickKoala   cancer("Ganepar");
        // std::cout << cancer.get_name() << std::endl;
        // cancer.poke();
        // std::cout << std::boolalpha << "return value : " << 
        // cancer.takeDrug("Mars") << std::endl;
        // std::cout << std::boolalpha << "return value : " << 
        // cancer.takeDrug("Buronzand") << std::endl;
        // std::cout << std::boolalpha << "return value : " << 
        // cancer.takeDrug("random") << std::endl;
        // cancer.overDrive("Kreog! How's it going?");

        // SickKoala   gangrene("Scarface");
        // std::cout << gangrene.get_name() << std::endl;
        // gangrene.poke();
        // std::cout << std::boolalpha << "return value : " << 
        // gangrene.takeDrug("Mars") << std::endl;
        // std::cout << std::boolalpha << "return value : " << 
        // gangrene.takeDrug("Buronzand") << std::endl;
        // std::cout << std::boolalpha << "return value : " << 
        // gangrene.takeDrug("random") << std::endl;
        // gangrene.overDrive("Kreog! How's it going?");

        // SickKoala   measles("RedFace");
        // std::cout << measles.get_name() << std::endl;
        // measles.poke();
        // std::cout << std::boolalpha << "return value : " << 
        // measles.takeDrug("Mars") << std::endl;
        // std::cout << std::boolalpha << "return value : " << 
        // measles.takeDrug("Buronzand") << std::endl;
        // std::cout << std::boolalpha << "return value : " << 
        // measles.takeDrug("random") << std::endl;
        // measles.overDrive("Kreog! How's it going?");

        // SickKoala   smallpox("Varia");
        // std::cout << smallpox.get_name() << std::endl;
        // smallpox.poke();
        // std::cout << std::boolalpha << "return value : " << 
        // smallpox.takeDrug("Mars") << std::endl;
        // std::cout << std::boolalpha << "return value : " << 
        // smallpox.takeDrug("Buronzand") << std::endl;
        // std::cout << std::boolalpha << "return value : " << 
        // smallpox.takeDrug("random") << std::endl;
        // smallpox.overDrive("Kreog! How's it going?");

        // SickKoala   fracture("Falter");
        // std::cout << fracture.get_name() << std::endl;
        // fracture.poke();
        // std::cout << std::boolalpha << "return value : " << 
        // fracture.takeDrug("Mars") << std::endl;
        // std::cout << std::boolalpha << "return value : " << 
        // fracture.takeDrug("Buronzand") << std::endl;
        // std::cout << std::boolalpha << "return value : " << 
        // fracture.takeDrug("random") << std::endl;
        // // fracture.overDrive("Kreog! How's it going?");

        // // /////////////////////////////
        // SickKoala   sickKoala("SickKoala");
        // std::cout << sickKoala.get_name() << std::endl;
        // sickKoala.poke();
        // std::cout << std::boolalpha << "return value : " << 
        // sickKoala.takeDrug("Mars") << std::endl;
        // std::cout << std::boolalpha << "return value : " << 
        // sickKoala.takeDrug("Buronzand") << std::endl;
        // std::cout << std::boolalpha << "return value : " << 
        // sickKoala.takeDrug("random") << std::endl;
        // sickKoala.overDrive("Kreog! How's it going?");
        //////////////////////////////////////////////////////////
        srandom (42) ;

        KoalaDoctor             cox("Cox");
        KoalaDoctor             house("House");
        KoalaDoctor             tired("Boudur-Oulot");

        KoalaDoctorList         doc1(&cox);
        KoalaDoctorList         doc2(&house);
        KoalaDoctorList         doc3(&tired);

        KoalaNurse              ratched(1);
        KoalaNurse              betty(2);

        KoalaNurseList          nurse1(&ratched);
        KoalaNurseList          nurse2(&betty);

        SickKoala               cancer("Ganepar");
        SickKoala               gangrene("Scarface");
        SickKoala               measles("RedFace");
        SickKoala               smallpox("Varia");
        SickKoala               fracture("Falter");

        SickKoalaList           sick1(&cancer);
        SickKoalaList           sick2(&gangrene);
        SickKoalaList           sick3(&measles);
        SickKoalaList           sick4(&smallpox);
        SickKoalaList           sick5(&fracture);

        Hospital                bellevue;

        bellevue.addDoctor(&doc1);
        bellevue.addDoctor(&doc2);
        bellevue.addDoctor(&doc3);

        bellevue.addSick(&sick1);
        bellevue.addSick(&sick2);
        bellevue.addSick(&sick3);
        bellevue.addSick(&sick4);
        bellevue.addSick(&sick5);

        if (nurse1.isEnd() && sick1.isEnd() && doc1.isEnd())
                std::cout << "Lists cleaned up." << std::endl;
        else
                std::cerr << "You fail! Boo!" << std::endl;
        return (0);
}
