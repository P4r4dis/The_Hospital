#include "../../part3_doctor/includes/my_doctor_hospital.hpp"
// #include "../../part2_nurse/includes/my_nurse_hospital.hpp"
#include "../../part1_patient/includes/my_patient_hospital.hpp"
#include "../includes/my_list_hospital.hpp"

int     main(int ac, char **av)
{
    if (ac < 2 && av) {

        std::cout << "NURSE MAIN" << std::endl;
        // //THE PATIENT SICKKOALA
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

        // /////////////////////////////
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

        ///////////////////////////////////////////////////
        //                      NURSE                    //
        ///////////////////////////////////////////////////
        // KoalaNurse      ratched(1);
        // KoalaNurse      betty(2);
        // ratched.giveDrug("Drug", &sickKoala);
        // betty.readReport("SickKoala");
        // std::cout << std::boolalpha << "bool : " << 
        // betty.get_isWorking() << std::endl;
        // betty.timeCheck();
        // std::cout << std::boolalpha << "bool : " << 
        // betty.get_isWorking() << std::endl;
        // betty.timeCheck();
        // std::cout << std::boolalpha << "bool : " << 
        // betty.get_isWorking() << std::endl;
        ////////////////////////////////////////////////////
        //DOCTOR
        ////////////////////////////////////////////////////
        KoalaDoctor     cox("Cox");

        std::cout << cox.getName() << std::endl;
        cox.diagnose(&sickKoala);
        std::cout << "TEST" << std::endl;
        std::cout << std::boolalpha << "bool : " << 
        cox.getIsWorking() << std::endl;
        cox.timeCheck();
        std::cout << std::boolalpha << "bool : " << 
        cox.getIsWorking() << std::endl;
        cox.timeCheck();
        std::cout << std::boolalpha << "bool : " << 
        cox.getIsWorking() << std::endl;
        std::cout << "END TEST" << std::endl;
        //////////////////////////////////////////////////////
        //SICKKOALALIST
        /////////////////////////////////////////////////////
        // SickKoalaList   sickkoalaList(&cancer);

        // std::cout << "getContent " << sickkoalaList.getContent() << std::endl;
        // std::cout << "getNext " << sickkoalaList.getNext() << std::endl;
        // std::cout << std::boolalpha << "bool : " << 
        // sickkoalaList.isEnd() << std::endl;
        // sickkoalaList.setNext(&sickkoalaList);
        // std::cout << std::boolalpha << "bool : " << 
        // sickkoalaList.isEnd() << std::endl;

        // SickKoalaList   sickkoalaList1(&cancer);
        // SickKoalaList   sickkoalaList2(&gangrene);
        // SickKoalaList   sickkoalaList3(&measles);
        // SickKoalaList   sickkoalaList4(&smallpox);
        // SickKoalaList   sickkoalaList5(&fracture);

        // sickkoalaList1.append(&sickkoalaList2);
        // sickkoalaList1.append(&sickkoalaList3);
        // sickkoalaList1.append(&sickkoalaList4);
        // sickkoalaList1.append(&sickkoalaList5);


        // SickKoalaList* temp = sickkoalaList1.getThis();
        // std::cout<<"Patients : ";
        // while(temp) {
        //     std::cout << temp->getContent()->get_name() <<" ";
        //     temp = temp->getNext();
        // }
        // std::cout<<std::endl;

        // SickKoala *koala = sickkoalaList1.getFromName("Varia");
        
        // if (koala == nullptr)
		//     std::cout << "ERROR nullptr" << std::endl;
        // else if (koala->get_name().compare("Varia") == 0)
		//     std::cout << "OK Varia found" << std::endl;
        // else
		//     std::cout << "ERROR " << koala->get_name() << " found instead of Varia" << std::endl;

        // temp = sickkoalaList1.remove(&sickkoalaList4);
        // std::cout<<"Patients after remove : ";
        // while(temp) {
        //     std::cout << temp->getContent()->get_name() <<" ";
        //     temp = temp->getNext();
        // }
        // std::cout<<std::endl;

        // temp = sickkoalaList1.removeFromName("RedFace");
        // koala = sickkoalaList1.getFromName("RedFace");
        // if (koala == nullptr)
		//     std::cout << "ERROR nullptr" << std::endl;
        // else if (koala->get_name().compare("RedFace") == 0)
		//     std::cout << "OK RedFace found" << std::endl;
        // else
		//     std::cout << "ERROR " << koala->get_name() << " found instead of RedFace" << std::endl;

        // std::cout<<"Patients after removeFromName : ";
        // while(temp) {
        //     std::cout << temp->getContent()->get_name() <<" ";
        //     temp = temp->getNext();
        // }
        // std::cout<<std::endl;
        // sickkoalaList1.dump();

        //////////////////////////////////////////////////////
        //NURSEKOALALIST
        /////////////////////////////////////////////////////
        // KoalaNurseList   koalaNurseList1(&ratched);
        // KoalaNurseList   koalaNurseList2(&betty);

        // std::cout << "KOALANURSELIST getNurse " << koalaNurseList1.getNurse()->getID() << std::endl;
        // std::cout << "getNext " << koalaNurseList1.getNext() << std::endl;
        // std::cout << std::boolalpha << "bool : " << 
        // koalaNurseList1.isEnd() << std::endl;
        // koalaNurseList1.setNext(&koalaNurseList1);
        // std::cout << std::boolalpha << "bool : " << 
        // koalaNurseList1.isEnd() << std::endl;



        // KoalaNurseList   nurse1(&ratched);
        // KoalaNurseList   nurse2(&betty);

        // nurse1.append(&nurse2);



        // KoalaNurseList* temp2 = &nurse1;  

        // std::cout<<"Nurses: ";
        // while(temp2)
        // {
        //     std::cout << (temp2 == &nurse1 ? "" : ", ");
        //     std::cout << "id" << (temp2->getNurse() ? std::to_string(temp2->getNurse()->getID()) : "[nullptr]");
        //     temp2 = temp2->getNext();
        // }
        // std::cout<< "." << std::endl;

        // KoalaNurse *koalaNurse = nurse1.getFromId(2);
        
        // if (koalaNurse == nullptr)
		//     std::cout << "ERROR nullptr" << std::endl;
        // else if (koalaNurse->getID() == 2)
		//     std::cout << "getFromId OK id2 found" << std::endl;
        // else
		//     std::cout << "ERROR " << koalaNurse->getID() << " found instead of id2" << std::endl;

        // temp2 = nurse1.remove(&nurse2);
        // std::cout<<"Nurse after remove : ";
        // while(temp2)
        // {
        //     std::cout << (temp2 == &nurse1 ? "" : ", ");
        //     std::cout << "id" << (temp2->getNurse() ? std::to_string(temp2->getNurse()->getID()) : "[nullptr]");
        //     temp2 = temp2->getNext();
        // }
        // std::cout<<std::endl;

        // koalaNurse = nurse1.getFromId(2);
        // if (koalaNurse == nullptr)
		//     std::cout << "ID2 was deleted good nullptr" << std::endl;
        // else if (koalaNurse->getID() == 2)
		//     std::cout << "error id2 found" << std::endl;
        // else
		//     std::cout << "ERROR " << koalaNurse->getID() << " found instead of null" << std::endl;
        // KoalaNurseList* temp3;  

        // temp3 = nurse1.removeFromId(nurse1.getNurse()->getID());

        // std::cout << "after removeFromId :" << std::endl;
        // koalaNurse = nurse1.getFromId(1);
        // if (koalaNurse == nullptr)
		//     std::cout << "ID1 was delete good nullptr" << std::endl;
        // else if (koalaNurse->getID() == 1)
		//     std::cout << "error id1 found" << std::endl;
        // else
		//     std::cout << "ERROR " << koalaNurse->getID() << " found instead of null" << std::endl;

        // if (temp3 == nullptr){
        //     std::cout << "empty list" << std::endl;
        // }
        // while(temp3) {
        //     std::cout << temp3->getNurse()->getID() <<" ,";
        //     temp3 = temp3->getNext();
        // }

        // std::cout<<std::endl;
        // nurse1.dump();
//////////////////////////////////////////////////////////////////////////////////////
        KoalaDoctor     house("House");
        KoalaDoctor     tired("Boudur-Oulot");

        KoalaDoctorList doc1(&cox);
        KoalaDoctorList doc2(&house);
        KoalaDoctorList doc3(&tired);

        // std::cout << "KoalaDoctorList getName " << doc1.getDoctor()->getName() << std::endl;
        // std::cout << "getNext " << doc1.getNext() << std::endl;
        // std::cout << std::boolalpha << "bool : " << 
        // doc1.isEnd() << std::endl;
        // doc1.setNext(&doc1);
        // std::cout << std::boolalpha << "bool : " << 
        // doc1.isEnd() << std::endl;

        doc1.append(&doc2);
        doc1.append(&doc3);
        // doc1.dump();
       KoalaDoctorList* temp_doc = &doc1;  

        std::cout<<"Doctors: ";
        while(temp_doc)
        {
            std::cout << (temp_doc == &doc1 ? "" : ", ");
            std::cout << "Dr." << (temp_doc->getDoctor() ? temp_doc->getDoctor()->getName() : "[nullptr]");
            temp_doc = temp_doc->getNext();
        }
        std::cout<< "." << std::endl;

        KoalaDoctor *koalaDoctor = doc1.getFromName("House");
        
        if (koalaDoctor == nullptr)
		    std::cout << "ERROR nullptr" << std::endl;
        else if (koalaDoctor->getName() == "House")
		    std::cout << "getFromName OK House found" << std::endl;
        else
		    std::cout << "ERROR " << koalaDoctor->getName() << " found instead of House" << std::endl;

        doc1.remove(&doc2);
        doc1.dump();

        doc1.removeFromName("Boudur-Oulot");
        koalaDoctor = doc1.getFromName("Boudur-Oulot");
        
        if (koalaDoctor == nullptr)
		    std::cout << "GOOD = ERROR nullptr" << std::endl;
        else if (koalaDoctor->getName() == "Boudur-Oulot")
		    std::cout << "getFromName OK Boudur-Oulot found" << std::endl;
        else
		    std::cout << "ERROR " << koalaDoctor->getName() << " found instead of Boudur-Oulot" << std::endl;
        doc1.dump();    
    }
    return 0;
}
