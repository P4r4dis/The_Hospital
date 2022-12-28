// #include "../includes/my_hospital.hpp"
#include "./tests_includes/test_my_hospital.hpp"
// #include "../../part4_list/includes/my_list_hospital.hpp"

Test(Hospital, test_KoalaDoctor_objects, .init=redirect_all_stdout)
{
        KoalaDoctor     cox("Cox");
        cr_assert(cox.getName() == "Cox");
        cr_assert(cox.getIsWorking() == false);

        KoalaDoctor     house("House");
        cr_assert(house.getName() == "House");
        cr_assert(house.getIsWorking() == false);

        KoalaDoctor     tired("Boudur-Oulot");
        cr_assert(tired.getName() == "Boudur-Oulot");
        cr_assert(tired.getIsWorking() == false);
        cr_assert_stdout_eq_str(
        "Dr.Cox: I'm Dr.Cox! How do you kreog?\n\
Dr.House: I'm Dr.House! How do you kreog?\n\
Dr.Boudur-Oulot: I'm Dr.Boudur-Oulot! How do you kreog?\n");
}

Test(Hospital, test_KoalaDoctorList_objects, .init=redirect_all_stdout)
{
        KoalaDoctor     cox("Cox");
        cr_assert(cox.getName() == "Cox");
        cr_assert(cox.getIsWorking() == false);

        KoalaDoctor     house("House");
        cr_assert(house.getName() == "House");
        cr_assert(house.getIsWorking() == false);

        KoalaDoctor     tired("Boudur-Oulot");
        cr_assert(tired.getName() == "Boudur-Oulot");
        cr_assert(tired.getIsWorking() == false);

        KoalaDoctorList doc1(&cox);
        cr_assert(doc1.getDoctor() != nullptr);
        cr_assert_eq(doc1.getDoctor(), &cox);
        cr_assert(doc1.getDoctor()->getName() == "Cox");
        cr_assert(doc1.getDoctor()->getIsWorking() == false);
        cr_assert(doc1.getNext() == nullptr);

        KoalaDoctorList doc2(&house);
        cr_assert(doc2.getDoctor() != nullptr);
        cr_assert_eq(doc2.getDoctor(), &house);
        cr_assert(doc2.getDoctor()->getName() == "House");
        cr_assert(doc2.getDoctor()->getIsWorking() == false);
        cr_assert(doc2.getNext() == nullptr);

        KoalaDoctorList doc3(&tired);
        cr_assert(doc3.getDoctor() != nullptr);
        cr_assert_eq(doc3.getDoctor(), &tired);
        cr_assert(doc3.getDoctor()->getName() == "Boudur-Oulot");
        cr_assert(doc3.getDoctor()->getIsWorking() == false);
        cr_assert(doc3.getNext() == nullptr);

        cr_assert_stdout_eq_str(
        "Dr.Cox: I'm Dr.Cox! How do you kreog?\n\
Dr.House: I'm Dr.House! How do you kreog?\n\
Dr.Boudur-Oulot: I'm Dr.Boudur-Oulot! How do you kreog?\n");
}

Test(Hospital, test_KoalaNurse_objects, .signal=SIGPIPE, .init=redirect_all_stdout)
{
        KoalaDoctor     cox("Cox");
        cr_assert(cox.getName() == "Cox");
        cr_assert(cox.getIsWorking() == false);

        KoalaDoctor     house("House");
        cr_assert(house.getName() == "House");
        cr_assert(house.getIsWorking() == false);

        KoalaDoctor     tired("Boudur-Oulot");
        cr_assert(tired.getName() == "Boudur-Oulot");
        cr_assert(tired.getIsWorking() == false);

        KoalaDoctorList doc1(&cox);
        cr_assert(doc1.getDoctor() != nullptr);
        cr_assert_eq(doc1.getDoctor(), &cox);
        cr_assert(doc1.getDoctor()->getName() == "Cox");
        cr_assert(doc1.getDoctor()->getIsWorking() == false);
        cr_assert(doc1.getNext() == nullptr);

        KoalaDoctorList doc2(&house);
        cr_assert(doc2.getDoctor() != nullptr);
        cr_assert_eq(doc2.getDoctor(), &house);
        cr_assert(doc2.getDoctor()->getName() == "House");
        cr_assert(doc2.getDoctor()->getIsWorking() == false);
        cr_assert(doc2.getNext() == nullptr);

        KoalaDoctorList doc3(&tired);
        cr_assert(doc3.getDoctor() != nullptr);
        cr_assert_eq(doc3.getDoctor(), &tired);
        cr_assert(doc3.getDoctor()->getName() == "Boudur-Oulot");
        cr_assert(doc3.getDoctor()->getIsWorking() == false);
        cr_assert(doc3.getNext() == nullptr);

        KoalaNurse      ratched(1);
        cr_assert(ratched.getID() == 1);
        cr_assert(ratched.get_isWorking() == false);

        KoalaNurse      betty(2);
        cr_assert(betty.getID() == 2);
        cr_assert(betty.get_isWorking() == false);

        ratched.~KoalaNurse();
        betty.~KoalaNurse();

        cr_assert_stdout_eq_str(
        "Dr.Cox: I'm Dr.Cox! How do you kreog?\n\
Dr.House: I'm Dr.House! How do you kreog?\n\
Dr.Boudur-Oulot: I'm Dr.Boudur-Oulot! How do you kreog?\n\
Nurse 1: Finally some rest!\n\
Nurse 2: Finally some rest!\n");
}

Test(Hospital, test_KoalaNurseList_objects, .signal=SIGPIPE, .init=redirect_all_stdout)
{
        KoalaDoctor     cox("Cox");
        cr_assert(cox.getName() == "Cox");
        cr_assert(cox.getIsWorking() == false);

        KoalaDoctor     house("House");
        cr_assert(house.getName() == "House");
        cr_assert(house.getIsWorking() == false);

        KoalaDoctor     tired("Boudur-Oulot");
        cr_assert(tired.getName() == "Boudur-Oulot");
        cr_assert(tired.getIsWorking() == false);

        KoalaDoctorList doc1(&cox);
        cr_assert(doc1.getDoctor() != nullptr);
        cr_assert_eq(doc1.getDoctor(), &cox);
        cr_assert(doc1.getDoctor()->getName() == "Cox");
        cr_assert(doc1.getDoctor()->getIsWorking() == false);
        cr_assert(doc1.getNext() == nullptr);

        KoalaDoctorList doc2(&house);
        cr_assert(doc2.getDoctor() != nullptr);
        cr_assert_eq(doc2.getDoctor(), &house);
        cr_assert(doc2.getDoctor()->getName() == "House");
        cr_assert(doc2.getDoctor()->getIsWorking() == false);
        cr_assert(doc2.getNext() == nullptr);

        KoalaDoctorList doc3(&tired);
        cr_assert(doc3.getDoctor() != nullptr);
        cr_assert_eq(doc3.getDoctor(), &tired);
        cr_assert(doc3.getDoctor()->getName() == "Boudur-Oulot");
        cr_assert(doc3.getDoctor()->getIsWorking() == false);
        cr_assert(doc3.getNext() == nullptr);

        KoalaNurse      ratched(1);
        cr_assert(ratched.getID() == 1);
        cr_assert(ratched.get_isWorking() == false);

        KoalaNurse      betty(2);
        cr_assert(betty.getID() == 2);
        cr_assert(betty.get_isWorking() == false);

        KoalaNurseList  nurse1(&ratched);
        cr_assert(nurse1.getNurse() != nullptr);
        cr_assert_eq(nurse1.getNurse(), &ratched);
        cr_assert(nurse1.getNurse()->getID() == 1);
        cr_assert(nurse1.getNurse()->get_isWorking() == false);
        cr_assert(nurse1.getNext() == nullptr);

        KoalaNurseList  nurse2(&betty);
        cr_assert(nurse2.getNurse() != nullptr);
        cr_assert_eq(nurse2.getNurse(), &betty);
        cr_assert(nurse2.getNurse()->getID() == 2);
        cr_assert(nurse2.getNurse()->get_isWorking() == false);
        cr_assert(nurse2.getNext() == nullptr);

        cr_assert_stdout_eq_str(
        "Dr.Cox: I'm Dr.Cox! How do you kreog?\n\
Dr.House: I'm Dr.House! How do you kreog?\n\
Dr.Boudur-Oulot: I'm Dr.Boudur-Oulot! How do you kreog?\n");
}

Test(Hospital, test_SickKoala_objects, .signal=SIGPIPE, .init=redirect_all_stdout)
{
        KoalaDoctor     cox("Cox");
        cr_assert(cox.getName() == "Cox");
        cr_assert(cox.getIsWorking() == false);

        KoalaDoctor     house("House");
        cr_assert(house.getName() == "House");
        cr_assert(house.getIsWorking() == false);

        KoalaDoctor     tired("Boudur-Oulot");
        cr_assert(tired.getName() == "Boudur-Oulot");
        cr_assert(tired.getIsWorking() == false);

        KoalaDoctorList doc1(&cox);
        cr_assert(doc1.getDoctor() != nullptr);
        cr_assert_eq(doc1.getDoctor(), &cox);
        cr_assert(doc1.getDoctor()->getName() == "Cox");
        cr_assert(doc1.getDoctor()->getIsWorking() == false);
        cr_assert(doc1.getNext() == nullptr);

        KoalaDoctorList doc2(&house);
        cr_assert(doc2.getDoctor() != nullptr);
        cr_assert_eq(doc2.getDoctor(), &house);
        cr_assert(doc2.getDoctor()->getName() == "House");
        cr_assert(doc2.getDoctor()->getIsWorking() == false);
        cr_assert(doc2.getNext() == nullptr);

        KoalaDoctorList doc3(&tired);
        cr_assert(doc3.getDoctor() != nullptr);
        cr_assert_eq(doc3.getDoctor(), &tired);
        cr_assert(doc3.getDoctor()->getName() == "Boudur-Oulot");
        cr_assert(doc3.getDoctor()->getIsWorking() == false);
        cr_assert(doc3.getNext() == nullptr);

        KoalaNurse      ratched(1);
        cr_assert(ratched.getID() == 1);
        cr_assert(ratched.get_isWorking() == false);

        KoalaNurse      betty(2);
        cr_assert(betty.getID() == 2);
        cr_assert(betty.get_isWorking() == false);

        KoalaNurseList  nurse1(&ratched);
        cr_assert(nurse1.getNurse() != nullptr);
        cr_assert_eq(nurse1.getNurse(), &ratched);
        cr_assert(nurse1.getNurse()->getID() == 1);
        cr_assert(nurse1.getNurse()->get_isWorking() == false);
        cr_assert(nurse1.getNext() == nullptr);

        KoalaNurseList  nurse2(&betty);
        cr_assert(nurse2.getNurse() != nullptr);
        cr_assert_eq(nurse2.getNurse(), &betty);
        cr_assert(nurse2.getNurse()->getID() == 2);
        cr_assert(nurse2.getNurse()->get_isWorking() == false);
        cr_assert(nurse2.getNext() == nullptr);

        SickKoala       cancer("Ganepar");
        cr_assert(cancer.get_name() == "Ganepar");

        SickKoala       gangrene("Scarface");
        cr_assert(gangrene.get_name() == "Scarface");

        SickKoala       measles("RedFace");
        cr_assert(measles.get_name() == "RedFace");

        SickKoala       smallpox("Varia");
        cr_assert(smallpox.get_name() == "Varia");

        SickKoala       fracture("Falter");
        cr_assert(fracture.get_name() == "Falter");

        cancer.~SickKoala();
        gangrene.~SickKoala();
        measles.~SickKoala();
        smallpox.~SickKoala();
        fracture.~SickKoala();

        cr_assert_stdout_eq_str(
        "Dr.Cox: I'm Dr.Cox! How do you kreog?\n\
Dr.House: I'm Dr.House! How do you kreog?\n\
Dr.Boudur-Oulot: I'm Dr.Boudur-Oulot! How do you kreog?\n\
Mr.Ganepar: Kreooogg!! I'm cuuuured!\n\
Mr.Scarface: Kreooogg!! I'm cuuuured!\n\
Mr.RedFace: Kreooogg!! I'm cuuuured!\n\
Mr.Varia: Kreooogg!! I'm cuuuured!\n\
Mr.Falter: Kreooogg!! I'm cuuuured!\n");
}

Test(Hospital, test_SickKoalaList_objects, .signal=SIGPIPE, .init=redirect_all_stdout)
{
        KoalaDoctor     cox("Cox");
        cr_assert(cox.getName() == "Cox");
        cr_assert(cox.getIsWorking() == false);

        KoalaDoctor     house("House");
        cr_assert(house.getName() == "House");
        cr_assert(house.getIsWorking() == false);

        KoalaDoctor     tired("Boudur-Oulot");
        cr_assert(tired.getName() == "Boudur-Oulot");
        cr_assert(tired.getIsWorking() == false);

        KoalaDoctorList doc1(&cox);
        cr_assert(doc1.getDoctor() != nullptr);
        cr_assert_eq(doc1.getDoctor(), &cox);
        cr_assert(doc1.getDoctor()->getName() == "Cox");
        cr_assert(doc1.getDoctor()->getIsWorking() == false);
        cr_assert(doc1.getNext() == nullptr);

        KoalaDoctorList doc2(&house);
        cr_assert(doc2.getDoctor() != nullptr);
        cr_assert_eq(doc2.getDoctor(), &house);
        cr_assert(doc2.getDoctor()->getName() == "House");
        cr_assert(doc2.getDoctor()->getIsWorking() == false);
        cr_assert(doc2.getNext() == nullptr);

        KoalaDoctorList doc3(&tired);
        cr_assert(doc3.getDoctor() != nullptr);
        cr_assert_eq(doc3.getDoctor(), &tired);
        cr_assert(doc3.getDoctor()->getName() == "Boudur-Oulot");
        cr_assert(doc3.getDoctor()->getIsWorking() == false);
        cr_assert(doc3.getNext() == nullptr);

        KoalaNurse      ratched(1);
        cr_assert(ratched.getID() == 1);
        cr_assert(ratched.get_isWorking() == false);

        KoalaNurse      betty(2);
        cr_assert(betty.getID() == 2);
        cr_assert(betty.get_isWorking() == false);

        KoalaNurseList  nurse1(&ratched);
        cr_assert(nurse1.getNurse() != nullptr);
        cr_assert_eq(nurse1.getNurse(), &ratched);
        cr_assert(nurse1.getNurse()->getID() == 1);
        cr_assert(nurse1.getNurse()->get_isWorking() == false);
        cr_assert(nurse1.getNext() == nullptr);

        KoalaNurseList  nurse2(&betty);
        cr_assert(nurse2.getNurse() != nullptr);
        cr_assert_eq(nurse2.getNurse(), &betty);
        cr_assert(nurse2.getNurse()->getID() == 2);
        cr_assert(nurse2.getNurse()->get_isWorking() == false);
        cr_assert(nurse2.getNext() == nullptr);

        SickKoala       cancer("Ganepar");
        cr_assert(cancer.get_name() == "Ganepar");

        SickKoala       gangrene("Scarface");
        cr_assert(gangrene.get_name() == "Scarface");

        SickKoala       measles("RedFace");
        cr_assert(measles.get_name() == "RedFace");

        SickKoala       smallpox("Varia");
        cr_assert(smallpox.get_name() == "Varia");

        SickKoala       fracture("Falter");
        cr_assert(fracture.get_name() == "Falter");

        SickKoalaList   sick1(&cancer);
        cr_assert(sick1.getPatient() != nullptr);
        cr_assert_eq(sick1.getPatient(), &cancer);
        cr_assert(sick1.getPatient()->get_name() == "Ganepar");
        cr_assert(sick1.getNext() == nullptr);

        SickKoalaList   sick2(&gangrene);
        cr_assert(sick2.getPatient() != nullptr);
        cr_assert_eq(sick2.getPatient(), &gangrene);
        cr_assert(sick2.getPatient()->get_name() == "Scarface");
        cr_assert(sick2.getNext() == nullptr);

        SickKoalaList   sick3(&measles);
        cr_assert(sick3.getPatient() != nullptr);
        cr_assert_eq(sick3.getPatient(), &measles);
        cr_assert(sick3.getPatient()->get_name() == "RedFace");
        cr_assert(sick3.getNext() == nullptr);

        SickKoalaList   sick4(&smallpox);
        cr_assert(sick4.getPatient() != nullptr);
        cr_assert_eq(sick4.getPatient(), &smallpox);
        cr_assert(sick4.getPatient()->get_name() == "Varia");
        cr_assert(sick4.getNext() == nullptr);

        SickKoalaList   sick5(&fracture);
        cr_assert(sick5.getPatient() != nullptr);
        cr_assert_eq(sick5.getPatient(), &fracture);
        cr_assert(sick5.getPatient()->get_name() == "Falter");
        cr_assert(sick5.getNext() == nullptr);

        cr_assert_stdout_eq_str(
        "Dr.Cox: I'm Dr.Cox! How do you kreog?\n\
Dr.House: I'm Dr.House! How do you kreog?\n\
Dr.Boudur-Oulot: I'm Dr.Boudur-Oulot! How do you kreog?\n");
}

Test(Hospital, test_Hospital_objects, .signal=SIGPIPE, .init=redirect_all_stdout)
{
        KoalaDoctor     cox("Cox");
        cr_assert(cox.getName() == "Cox");
        cr_assert(cox.getIsWorking() == false);

        KoalaDoctor     house("House");
        cr_assert(house.getName() == "House");
        cr_assert(house.getIsWorking() == false);

        KoalaDoctor     tired("Boudur-Oulot");
        cr_assert(tired.getName() == "Boudur-Oulot");
        cr_assert(tired.getIsWorking() == false);

        KoalaDoctorList doc1(&cox);
        cr_assert(doc1.getDoctor() != nullptr);
        cr_assert_eq(doc1.getDoctor(), &cox);
        cr_assert(doc1.getDoctor()->getName() == "Cox");
        cr_assert(doc1.getDoctor()->getIsWorking() == false);
        cr_assert(doc1.getNext() == nullptr);

        KoalaDoctorList doc2(&house);
        cr_assert(doc2.getDoctor() != nullptr);
        cr_assert_eq(doc2.getDoctor(), &house);
        cr_assert(doc2.getDoctor()->getName() == "House");
        cr_assert(doc2.getDoctor()->getIsWorking() == false);
        cr_assert(doc2.getNext() == nullptr);

        KoalaDoctorList doc3(&tired);
        cr_assert(doc3.getDoctor() != nullptr);
        cr_assert_eq(doc3.getDoctor(), &tired);
        cr_assert(doc3.getDoctor()->getName() == "Boudur-Oulot");
        cr_assert(doc3.getDoctor()->getIsWorking() == false);
        cr_assert(doc3.getNext() == nullptr);

        KoalaNurse      ratched(1);
        cr_assert(ratched.getID() == 1);
        cr_assert(ratched.get_isWorking() == false);

        KoalaNurse      betty(2);
        cr_assert(betty.getID() == 2);
        cr_assert(betty.get_isWorking() == false);

        KoalaNurseList  nurse1(&ratched);
        cr_assert(nurse1.getNurse() != nullptr);
        cr_assert_eq(nurse1.getNurse(), &ratched);
        cr_assert(nurse1.getNurse()->getID() == 1);
        cr_assert(nurse1.getNurse()->get_isWorking() == false);
        cr_assert(nurse1.getNext() == nullptr);

        KoalaNurseList  nurse2(&betty);
        cr_assert(nurse2.getNurse() != nullptr);
        cr_assert_eq(nurse2.getNurse(), &betty);
        cr_assert(nurse2.getNurse()->getID() == 2);
        cr_assert(nurse2.getNurse()->get_isWorking() == false);
        cr_assert(nurse2.getNext() == nullptr);

        SickKoala       cancer("Ganepar");
        cr_assert(cancer.get_name() == "Ganepar");

        SickKoala       gangrene("Scarface");
        cr_assert(gangrene.get_name() == "Scarface");

        SickKoala       measles("RedFace");
        cr_assert(measles.get_name() == "RedFace");

        SickKoala       smallpox("Varia");
        cr_assert(smallpox.get_name() == "Varia");

        SickKoala       fracture("Falter");
        cr_assert(fracture.get_name() == "Falter");

        SickKoalaList   sick1(&cancer);
        cr_assert(sick1.getPatient() != nullptr);
        cr_assert_eq(sick1.getPatient(), &cancer);
        cr_assert(sick1.getPatient()->get_name() == "Ganepar");
        cr_assert(sick1.getNext() == nullptr);

        SickKoalaList   sick2(&gangrene);
        cr_assert(sick2.getPatient() != nullptr);
        cr_assert_eq(sick2.getPatient(), &gangrene);
        cr_assert(sick2.getPatient()->get_name() == "Scarface");
        cr_assert(sick2.getNext() == nullptr);

        SickKoalaList   sick3(&measles);
        cr_assert(sick3.getPatient() != nullptr);
        cr_assert_eq(sick3.getPatient(), &measles);
        cr_assert(sick3.getPatient()->get_name() == "RedFace");
        cr_assert(sick3.getNext() == nullptr);

        SickKoalaList   sick4(&smallpox);
        cr_assert(sick4.getPatient() != nullptr);
        cr_assert_eq(sick4.getPatient(), &smallpox);
        cr_assert(sick4.getPatient()->get_name() == "Varia");
        cr_assert(sick4.getNext() == nullptr);

        SickKoalaList   sick5(&fracture);
        cr_assert(sick5.getPatient() != nullptr);
        cr_assert_eq(sick5.getPatient(), &fracture);
        cr_assert(sick5.getPatient()->get_name() == "Falter");
        cr_assert(sick5.getNext() == nullptr);

        Hospital        bellevue;
        cr_assert(bellevue.getSickKoalaList() == nullptr);
        cr_assert(bellevue.getKoalaNurseList() == nullptr);
        cr_assert(bellevue.getKoalaDoctorList() == nullptr);

        cr_assert_stdout_eq_str(
        "Dr.Cox: I'm Dr.Cox! How do you kreog?\n\
Dr.House: I'm Dr.House! How do you kreog?\n\
Dr.Boudur-Oulot: I'm Dr.Boudur-Oulot! How do you kreog?\n");
}

Test(Hospital, test_addDoctor, .signal=SIGPIPE, .init=redirect_all_stdout)
{
        KoalaDoctor     cox("Cox");
        cr_assert(cox.getName() == "Cox");
        cr_assert(cox.getIsWorking() == false);

        KoalaDoctor     house("House");
        cr_assert(house.getName() == "House");
        cr_assert(house.getIsWorking() == false);

        KoalaDoctor     tired("Boudur-Oulot");
        cr_assert(tired.getName() == "Boudur-Oulot");
        cr_assert(tired.getIsWorking() == false);

        KoalaDoctorList doc1(&cox);
        cr_assert(doc1.getDoctor() != nullptr);
        cr_assert_eq(doc1.getDoctor(), &cox);
        cr_assert(doc1.getDoctor()->getName() == "Cox");
        cr_assert(doc1.getDoctor()->getIsWorking() == false);
        cr_assert(doc1.getNext() == nullptr);

        KoalaDoctorList doc2(&house);
        cr_assert(doc2.getDoctor() != nullptr);
        cr_assert_eq(doc2.getDoctor(), &house);
        cr_assert(doc2.getDoctor()->getName() == "House");
        cr_assert(doc2.getDoctor()->getIsWorking() == false);
        cr_assert(doc2.getNext() == nullptr);

        KoalaDoctorList doc3(&tired);
        cr_assert(doc3.getDoctor() != nullptr);
        cr_assert_eq(doc3.getDoctor(), &tired);
        cr_assert(doc3.getDoctor()->getName() == "Boudur-Oulot");
        cr_assert(doc3.getDoctor()->getIsWorking() == false);
        cr_assert(doc3.getNext() == nullptr);

        KoalaNurse      ratched(1);
        cr_assert(ratched.getID() == 1);
        cr_assert(ratched.get_isWorking() == false);

        KoalaNurse      betty(2);
        cr_assert(betty.getID() == 2);
        cr_assert(betty.get_isWorking() == false);

        KoalaNurseList  nurse1(&ratched);
        cr_assert(nurse1.getNurse() != nullptr);
        cr_assert_eq(nurse1.getNurse(), &ratched);
        cr_assert(nurse1.getNurse()->getID() == 1);
        cr_assert(nurse1.getNurse()->get_isWorking() == false);
        cr_assert(nurse1.getNext() == nullptr);

        KoalaNurseList  nurse2(&betty);
        cr_assert(nurse2.getNurse() != nullptr);
        cr_assert_eq(nurse2.getNurse(), &betty);
        cr_assert(nurse2.getNurse()->getID() == 2);
        cr_assert(nurse2.getNurse()->get_isWorking() == false);
        cr_assert(nurse2.getNext() == nullptr);

        SickKoala       cancer("Ganepar");
        cr_assert(cancer.get_name() == "Ganepar");

        SickKoala       gangrene("Scarface");
        cr_assert(gangrene.get_name() == "Scarface");

        SickKoala       measles("RedFace");
        cr_assert(measles.get_name() == "RedFace");

        SickKoala       smallpox("Varia");
        cr_assert(smallpox.get_name() == "Varia");

        SickKoala       fracture("Falter");
        cr_assert(fracture.get_name() == "Falter");

        SickKoalaList   sick1(&cancer);
        cr_assert(sick1.getPatient() != nullptr);
        cr_assert_eq(sick1.getPatient(), &cancer);
        cr_assert(sick1.getPatient()->get_name() == "Ganepar");
        cr_assert(sick1.getNext() == nullptr);

        SickKoalaList   sick2(&gangrene);
        cr_assert(sick2.getPatient() != nullptr);
        cr_assert_eq(sick2.getPatient(), &gangrene);
        cr_assert(sick2.getPatient()->get_name() == "Scarface");
        cr_assert(sick2.getNext() == nullptr);

        SickKoalaList   sick3(&measles);
        cr_assert(sick3.getPatient() != nullptr);
        cr_assert_eq(sick3.getPatient(), &measles);
        cr_assert(sick3.getPatient()->get_name() == "RedFace");
        cr_assert(sick3.getNext() == nullptr);

        SickKoalaList   sick4(&smallpox);
        cr_assert(sick4.getPatient() != nullptr);
        cr_assert_eq(sick4.getPatient(), &smallpox);
        cr_assert(sick4.getPatient()->get_name() == "Varia");
        cr_assert(sick4.getNext() == nullptr);

        SickKoalaList   sick5(&fracture);
        cr_assert(sick5.getPatient() != nullptr);
        cr_assert_eq(sick5.getPatient(), &fracture);
        cr_assert(sick5.getPatient()->get_name() == "Falter");
        cr_assert(sick5.getNext() == nullptr);

        Hospital        bellevue;
        cr_assert(bellevue.getSickKoalaList() == nullptr);
        cr_assert(bellevue.getKoalaNurseList() == nullptr);
        cr_assert(bellevue.getKoalaDoctorList() == nullptr);

////////AddDoctor
        cr_assert(doc1.getDoctor() != nullptr);
        cr_assert(doc1.getFromName(doc1.getDoctor()->getName()) == doc1.getDoctor());
        bellevue.addDoctor(&doc1);
        cr_assert(bellevue.getKoalaDoctorList()->getDoctor()->getName() == "Cox");
        bellevue.addDoctor(&doc2);
        // cr_assert(bellevue.getKoalaDoctorList()->getDoctor()->getName() == "House");
        bellevue.addDoctor(&doc3);
        // cr_assert(bellevue.getKoalaDoctorList()->getDoctor()->getName() == "Boudur-Oulot");

        cr_assert_stdout_eq_str(
        "Dr.Cox: I'm Dr.Cox! How do you kreog?\n\
Dr.House: I'm Dr.House! How do you kreog?\n\
Dr.Boudur-Oulot: I'm Dr.Boudur-Oulot! How do you kreog?\n\
[HOSPITAL] Doctor Cox just arrived!\n\
Dr.Cox: Time to get to work!\n\
[HOSPITAL] Doctor House just arrived!\n\
Dr.House: Time to get to work!\n\
[HOSPITAL] Doctor Boudur-Oulot just arrived!\n\
Dr.Boudur-Oulot: Time to get to work!\n");
}

Test(Hospital, test_addSick, .signal=SIGPIPE, .init=redirect_all_stdout)
{
        KoalaDoctor     cox("Cox");
        cr_assert(cox.getName() == "Cox");
        cr_assert(cox.getIsWorking() == false);

        KoalaDoctor     house("House");
        cr_assert(house.getName() == "House");
        cr_assert(house.getIsWorking() == false);

        KoalaDoctor     tired("Boudur-Oulot");
        cr_assert(tired.getName() == "Boudur-Oulot");
        cr_assert(tired.getIsWorking() == false);

        KoalaDoctorList doc1(&cox);
        cr_assert(doc1.getDoctor() != nullptr);
        cr_assert_eq(doc1.getDoctor(), &cox);
        cr_assert(doc1.getDoctor()->getName() == "Cox");
        cr_assert(doc1.getDoctor()->getIsWorking() == false);
        cr_assert(doc1.getNext() == nullptr);

        KoalaDoctorList doc2(&house);
        cr_assert(doc2.getDoctor() != nullptr);
        cr_assert_eq(doc2.getDoctor(), &house);
        cr_assert(doc2.getDoctor()->getName() == "House");
        cr_assert(doc2.getDoctor()->getIsWorking() == false);
        cr_assert(doc2.getNext() == nullptr);

        KoalaDoctorList doc3(&tired);
        cr_assert(doc3.getDoctor() != nullptr);
        cr_assert_eq(doc3.getDoctor(), &tired);
        cr_assert(doc3.getDoctor()->getName() == "Boudur-Oulot");
        cr_assert(doc3.getDoctor()->getIsWorking() == false);
        cr_assert(doc3.getNext() == nullptr);

        KoalaNurse      ratched(1);
        cr_assert(ratched.getID() == 1);
        cr_assert(ratched.get_isWorking() == false);

        KoalaNurse      betty(2);
        cr_assert(betty.getID() == 2);
        cr_assert(betty.get_isWorking() == false);

        KoalaNurseList  nurse1(&ratched);
        cr_assert(nurse1.getNurse() != nullptr);
        cr_assert_eq(nurse1.getNurse(), &ratched);
        cr_assert(nurse1.getNurse()->getID() == 1);
        cr_assert(nurse1.getNurse()->get_isWorking() == false);
        cr_assert(nurse1.getNext() == nullptr);

        KoalaNurseList  nurse2(&betty);
        cr_assert(nurse2.getNurse() != nullptr);
        cr_assert_eq(nurse2.getNurse(), &betty);
        cr_assert(nurse2.getNurse()->getID() == 2);
        cr_assert(nurse2.getNurse()->get_isWorking() == false);
        cr_assert(nurse2.getNext() == nullptr);

        SickKoala       cancer("Ganepar");
        cr_assert(cancer.get_name() == "Ganepar");

        SickKoala       gangrene("Scarface");
        cr_assert(gangrene.get_name() == "Scarface");

        SickKoala       measles("RedFace");
        cr_assert(measles.get_name() == "RedFace");

        SickKoala       smallpox("Varia");
        cr_assert(smallpox.get_name() == "Varia");

        SickKoala       fracture("Falter");
        cr_assert(fracture.get_name() == "Falter");

        SickKoalaList   sick1(&cancer);
        cr_assert(sick1.getPatient() != nullptr);
        cr_assert_eq(sick1.getPatient(), &cancer);
        cr_assert(sick1.getPatient()->get_name() == "Ganepar");
        cr_assert(sick1.getNext() == nullptr);

        SickKoalaList   sick2(&gangrene);
        cr_assert(sick2.getPatient() != nullptr);
        cr_assert_eq(sick2.getPatient(), &gangrene);
        cr_assert(sick2.getPatient()->get_name() == "Scarface");
        cr_assert(sick2.getNext() == nullptr);

        SickKoalaList   sick3(&measles);
        cr_assert(sick3.getPatient() != nullptr);
        cr_assert_eq(sick3.getPatient(), &measles);
        cr_assert(sick3.getPatient()->get_name() == "RedFace");
        cr_assert(sick3.getNext() == nullptr);

        SickKoalaList   sick4(&smallpox);
        cr_assert(sick4.getPatient() != nullptr);
        cr_assert_eq(sick4.getPatient(), &smallpox);
        cr_assert(sick4.getPatient()->get_name() == "Varia");
        cr_assert(sick4.getNext() == nullptr);

        SickKoalaList   sick5(&fracture);
        cr_assert(sick5.getPatient() != nullptr);
        cr_assert_eq(sick5.getPatient(), &fracture);
        cr_assert(sick5.getPatient()->get_name() == "Falter");
        cr_assert(sick5.getNext() == nullptr);

        Hospital        bellevue;
        cr_assert(bellevue.getSickKoalaList() == nullptr);
        cr_assert(bellevue.getKoalaNurseList() == nullptr);
        cr_assert(bellevue.getKoalaDoctorList() == nullptr);

////////AddDoctor
        cr_assert(doc1.getDoctor() != nullptr);
        cr_assert(doc1.getFromName(doc1.getDoctor()->getName()) == doc1.getDoctor());
        bellevue.addDoctor(&doc1);
        cr_assert(bellevue.getKoalaDoctorList()->getDoctor()->getName() == "Cox");
        bellevue.addDoctor(&doc2);
        // cr_assert(bellevue.getKoalaDoctorList()->getDoctor()->getName() == "House");
        bellevue.addDoctor(&doc3);
        // cr_assert(bellevue.getKoalaDoctorList()->getDoctor()->getName() == "Boudur-Oulot");
////////AddSick
        cr_assert(sick1.getPatient() != nullptr);
        cr_assert(sick1.getFromName(sick1.getPatient()->get_name()) == sick1.getPatient());
        cr_assert(sick2.getPatient() != nullptr);
        cr_assert(sick2.getFromName(sick2.getPatient()->get_name()) == sick2.getPatient());
        cr_assert(sick3.getPatient() != nullptr);
        cr_assert(sick3.getFromName(sick3.getPatient()->get_name()) == sick3.getPatient());
        cr_assert(sick4.getPatient() != nullptr);
        cr_assert(sick4.getFromName(sick4.getPatient()->get_name()) == sick4.getPatient());
        cr_assert(sick5.getPatient() != nullptr);
        cr_assert(sick5.getFromName(sick5.getPatient()->get_name()) == sick5.getPatient());
        bellevue.addSick(&sick1);
        cr_assert(bellevue.getSickKoalaList()->getPatient()->get_name() == "Ganepar");
        bellevue.addSick(&sick2);
        cr_assert(bellevue.getSickKoalaList()->getNext()->getPatient()->get_name() == "Scarface");
        bellevue.addSick(&sick3);
        cr_assert(bellevue.getSickKoalaList()->getNext()->getNext()->getPatient()->get_name() == "RedFace");
        bellevue.addSick(&sick4);
        cr_assert(bellevue.getSickKoalaList()->getNext()->getNext()->getNext()->getPatient()->get_name() == "Varia");
        bellevue.addSick(&sick5);
        cr_assert(bellevue.getSickKoalaList()->getNext()->getNext()->getNext()->getNext()->getPatient()->get_name() == "Falter");

        cr_assert_stdout_eq_str(
        "Dr.Cox: I'm Dr.Cox! How do you kreog?\n\
Dr.House: I'm Dr.House! How do you kreog?\n\
Dr.Boudur-Oulot: I'm Dr.Boudur-Oulot! How do you kreog?\n\
[HOSPITAL] Doctor Cox just arrived!\n\
Dr.Cox: Time to get to work!\n\
[HOSPITAL] Doctor House just arrived!\n\
Dr.House: Time to get to work!\n\
[HOSPITAL] Doctor Boudur-Oulot just arrived!\n\
Dr.Boudur-Oulot: Time to get to work!\n\
[HOSPITAL] Patient Ganepar just arrived!\n\
[HOSPITAL] Patient Scarface just arrived!\n\
[HOSPITAL] Patient RedFace just arrived!\n\
[HOSPITAL] Patient Varia just arrived!\n\
[HOSPITAL] Patient Falter just arrived!\n");
}

Test(Hospital, test_addNurse, .signal=SIGPIPE, .init=redirect_all_stdout)
{
        KoalaDoctor     cox("Cox");
        cr_assert(cox.getName() == "Cox");
        cr_assert(cox.getIsWorking() == false);

        KoalaDoctor     house("House");
        cr_assert(house.getName() == "House");
        cr_assert(house.getIsWorking() == false);

        KoalaDoctor     tired("Boudur-Oulot");
        cr_assert(tired.getName() == "Boudur-Oulot");
        cr_assert(tired.getIsWorking() == false);

        KoalaDoctorList doc1(&cox);
        cr_assert(doc1.getDoctor() != nullptr);
        cr_assert_eq(doc1.getDoctor(), &cox);
        cr_assert(doc1.getDoctor()->getName() == "Cox");
        cr_assert(doc1.getDoctor()->getIsWorking() == false);
        cr_assert(doc1.getNext() == nullptr);

        KoalaDoctorList doc2(&house);
        cr_assert(doc2.getDoctor() != nullptr);
        cr_assert_eq(doc2.getDoctor(), &house);
        cr_assert(doc2.getDoctor()->getName() == "House");
        cr_assert(doc2.getDoctor()->getIsWorking() == false);
        cr_assert(doc2.getNext() == nullptr);

        KoalaDoctorList doc3(&tired);
        cr_assert(doc3.getDoctor() != nullptr);
        cr_assert_eq(doc3.getDoctor(), &tired);
        cr_assert(doc3.getDoctor()->getName() == "Boudur-Oulot");
        cr_assert(doc3.getDoctor()->getIsWorking() == false);
        cr_assert(doc3.getNext() == nullptr);

        KoalaNurse      ratched(1);
        cr_assert(ratched.getID() == 1);
        cr_assert(ratched.get_isWorking() == false);

        KoalaNurse      betty(2);
        cr_assert(betty.getID() == 2);
        cr_assert(betty.get_isWorking() == false);

        KoalaNurseList  nurse1(&ratched);
        cr_assert(nurse1.getNurse() != nullptr);
        cr_assert_eq(nurse1.getNurse(), &ratched);
        cr_assert(nurse1.getNurse()->getID() == 1);
        cr_assert(nurse1.getNurse()->get_isWorking() == false);
        cr_assert(nurse1.getNext() == nullptr);

        KoalaNurseList  nurse2(&betty);
        cr_assert(nurse2.getNurse() != nullptr);
        cr_assert_eq(nurse2.getNurse(), &betty);
        cr_assert(nurse2.getNurse()->getID() == 2);
        cr_assert(nurse2.getNurse()->get_isWorking() == false);
        cr_assert(nurse2.getNext() == nullptr);

        SickKoala       cancer("Ganepar");
        cr_assert(cancer.get_name() == "Ganepar");

        SickKoala       gangrene("Scarface");
        cr_assert(gangrene.get_name() == "Scarface");

        SickKoala       measles("RedFace");
        cr_assert(measles.get_name() == "RedFace");

        SickKoala       smallpox("Varia");
        cr_assert(smallpox.get_name() == "Varia");

        SickKoala       fracture("Falter");
        cr_assert(fracture.get_name() == "Falter");

        SickKoalaList   sick1(&cancer);
        cr_assert(sick1.getPatient() != nullptr);
        cr_assert_eq(sick1.getPatient(), &cancer);
        cr_assert(sick1.getPatient()->get_name() == "Ganepar");
        cr_assert(sick1.getNext() == nullptr);

        SickKoalaList   sick2(&gangrene);
        cr_assert(sick2.getPatient() != nullptr);
        cr_assert_eq(sick2.getPatient(), &gangrene);
        cr_assert(sick2.getPatient()->get_name() == "Scarface");
        cr_assert(sick2.getNext() == nullptr);

        SickKoalaList   sick3(&measles);
        cr_assert(sick3.getPatient() != nullptr);
        cr_assert_eq(sick3.getPatient(), &measles);
        cr_assert(sick3.getPatient()->get_name() == "RedFace");
        cr_assert(sick3.getNext() == nullptr);

        SickKoalaList   sick4(&smallpox);
        cr_assert(sick4.getPatient() != nullptr);
        cr_assert_eq(sick4.getPatient(), &smallpox);
        cr_assert(sick4.getPatient()->get_name() == "Varia");
        cr_assert(sick4.getNext() == nullptr);

        SickKoalaList   sick5(&fracture);
        cr_assert(sick5.getPatient() != nullptr);
        cr_assert_eq(sick5.getPatient(), &fracture);
        cr_assert(sick5.getPatient()->get_name() == "Falter");
        cr_assert(sick5.getNext() == nullptr);

        Hospital        bellevue;
        cr_assert(bellevue.getSickKoalaList() == nullptr);
        cr_assert(bellevue.getKoalaNurseList() == nullptr);
        cr_assert(bellevue.getKoalaDoctorList() == nullptr);

////////AddDoctor
        cr_assert(doc1.getDoctor() != nullptr);
        cr_assert(doc1.getFromName(doc1.getDoctor()->getName()) == doc1.getDoctor());
        bellevue.addDoctor(&doc1);
        cr_assert(bellevue.getKoalaDoctorList()->getDoctor()->getName() == "Cox");
        bellevue.addDoctor(&doc2);
        // cr_assert(bellevue.getKoalaDoctorList()->getDoctor()->getName() == "House");
        bellevue.addDoctor(&doc3);
        // cr_assert(bellevue.getKoalaDoctorList()->getDoctor()->getName() == "Boudur-Oulot");
////////AddSick
        cr_assert(sick1.getPatient() != nullptr);
        cr_assert(sick1.getFromName(sick1.getPatient()->get_name()) == sick1.getPatient());
        cr_assert(sick2.getPatient() != nullptr);
        cr_assert(sick2.getFromName(sick2.getPatient()->get_name()) == sick2.getPatient());
        cr_assert(sick3.getPatient() != nullptr);
        cr_assert(sick3.getFromName(sick3.getPatient()->get_name()) == sick3.getPatient());
        cr_assert(sick4.getPatient() != nullptr);
        cr_assert(sick4.getFromName(sick4.getPatient()->get_name()) == sick4.getPatient());
        cr_assert(sick5.getPatient() != nullptr);
        cr_assert(sick5.getFromName(sick5.getPatient()->get_name()) == sick5.getPatient());
        bellevue.addSick(&sick1);
        cr_assert(bellevue.getSickKoalaList()->getPatient()->get_name() == "Ganepar");
        bellevue.addSick(&sick2);
        cr_assert(bellevue.getSickKoalaList()->getNext()->getPatient()->get_name() == "Scarface");
        bellevue.addSick(&sick3);
        cr_assert(bellevue.getSickKoalaList()->getNext()->getNext()->getPatient()->get_name() == "RedFace");
        bellevue.addSick(&sick4);
        cr_assert(bellevue.getSickKoalaList()->getNext()->getNext()->getNext()->getPatient()->get_name() == "Varia");
        bellevue.addSick(&sick5);
        cr_assert(bellevue.getSickKoalaList()->getNext()->getNext()->getNext()->getNext()->getPatient()->get_name() == "Falter");
////////AddNurse
        cr_assert(nurse1.getNurse() != nullptr);
        cr_assert(nurse1.getFromId(nurse1.getNurse()->getID()) == nurse1.getNurse());
        bellevue.addNurse(&nurse1);
        cr_assert(bellevue.getKoalaNurseList()->getNurse()->getID() == 1);
        bellevue.addNurse(&nurse2);
        cr_assert(bellevue.getKoalaNurseList()->getNext()->getNurse()->getID() == 2);

        cr_assert_stdout_eq_str(
        "Dr.Cox: I'm Dr.Cox! How do you kreog?\n\
Dr.House: I'm Dr.House! How do you kreog?\n\
Dr.Boudur-Oulot: I'm Dr.Boudur-Oulot! How do you kreog?\n\
[HOSPITAL] Doctor Cox just arrived!\n\
Dr.Cox: Time to get to work!\n\
[HOSPITAL] Doctor House just arrived!\n\
Dr.House: Time to get to work!\n\
[HOSPITAL] Doctor Boudur-Oulot just arrived!\n\
Dr.Boudur-Oulot: Time to get to work!\n\
[HOSPITAL] Patient Ganepar just arrived!\n\
[HOSPITAL] Patient Scarface just arrived!\n\
[HOSPITAL] Patient RedFace just arrived!\n\
[HOSPITAL] Patient Varia just arrived!\n\
[HOSPITAL] Patient Falter just arrived!\n\
[HOSPITAL] Nurse 1 just arrived!\n\
Nurse 1: Time to get to work!\n\
[HOSPITAL] Nurse 2 just arrived!\n\
Nurse 2: Time to get to work!\n");
}

Test(Hospital, test_dump, .signal=SIGPIPE, .init=redirect_all_stdout)
{
        KoalaDoctor     cox("Cox");
        cr_assert(cox.getName() == "Cox");
        cr_assert(cox.getIsWorking() == false);

        KoalaDoctor     house("House");
        cr_assert(house.getName() == "House");
        cr_assert(house.getIsWorking() == false);

        KoalaDoctor     tired("Boudur-Oulot");
        cr_assert(tired.getName() == "Boudur-Oulot");
        cr_assert(tired.getIsWorking() == false);

        KoalaDoctorList doc1(&cox);
        cr_assert(doc1.getDoctor() != nullptr);
        cr_assert_eq(doc1.getDoctor(), &cox);
        cr_assert(doc1.getDoctor()->getName() == "Cox");
        cr_assert(doc1.getDoctor()->getIsWorking() == false);
        cr_assert(doc1.getNext() == nullptr);

        KoalaDoctorList doc2(&house);
        cr_assert(doc2.getDoctor() != nullptr);
        cr_assert_eq(doc2.getDoctor(), &house);
        cr_assert(doc2.getDoctor()->getName() == "House");
        cr_assert(doc2.getDoctor()->getIsWorking() == false);
        cr_assert(doc2.getNext() == nullptr);

        KoalaDoctorList doc3(&tired);
        cr_assert(doc3.getDoctor() != nullptr);
        cr_assert_eq(doc3.getDoctor(), &tired);
        cr_assert(doc3.getDoctor()->getName() == "Boudur-Oulot");
        cr_assert(doc3.getDoctor()->getIsWorking() == false);
        cr_assert(doc3.getNext() == nullptr);

        KoalaNurse      ratched(1);
        cr_assert(ratched.getID() == 1);
        cr_assert(ratched.get_isWorking() == false);

        KoalaNurse      betty(2);
        cr_assert(betty.getID() == 2);
        cr_assert(betty.get_isWorking() == false);

        KoalaNurseList  nurse1(&ratched);
        cr_assert(nurse1.getNurse() != nullptr);
        cr_assert_eq(nurse1.getNurse(), &ratched);
        cr_assert(nurse1.getNurse()->getID() == 1);
        cr_assert(nurse1.getNurse()->get_isWorking() == false);
        cr_assert(nurse1.getNext() == nullptr);

        KoalaNurseList  nurse2(&betty);
        cr_assert(nurse2.getNurse() != nullptr);
        cr_assert_eq(nurse2.getNurse(), &betty);
        cr_assert(nurse2.getNurse()->getID() == 2);
        cr_assert(nurse2.getNurse()->get_isWorking() == false);
        cr_assert(nurse2.getNext() == nullptr);

        SickKoala       cancer("Ganepar");
        cr_assert(cancer.get_name() == "Ganepar");

        SickKoala       gangrene("Scarface");
        cr_assert(gangrene.get_name() == "Scarface");

        SickKoala       measles("RedFace");
        cr_assert(measles.get_name() == "RedFace");

        SickKoala       smallpox("Varia");
        cr_assert(smallpox.get_name() == "Varia");

        SickKoala       fracture("Falter");
        cr_assert(fracture.get_name() == "Falter");

        SickKoalaList   sick1(&cancer);
        cr_assert(sick1.getPatient() != nullptr);
        cr_assert_eq(sick1.getPatient(), &cancer);
        cr_assert(sick1.getPatient()->get_name() == "Ganepar");
        cr_assert(sick1.getNext() == nullptr);

        SickKoalaList   sick2(&gangrene);
        cr_assert(sick2.getPatient() != nullptr);
        cr_assert_eq(sick2.getPatient(), &gangrene);
        cr_assert(sick2.getPatient()->get_name() == "Scarface");
        cr_assert(sick2.getNext() == nullptr);

        SickKoalaList   sick3(&measles);
        cr_assert(sick3.getPatient() != nullptr);
        cr_assert_eq(sick3.getPatient(), &measles);
        cr_assert(sick3.getPatient()->get_name() == "RedFace");
        cr_assert(sick3.getNext() == nullptr);

        SickKoalaList   sick4(&smallpox);
        cr_assert(sick4.getPatient() != nullptr);
        cr_assert_eq(sick4.getPatient(), &smallpox);
        cr_assert(sick4.getPatient()->get_name() == "Varia");
        cr_assert(sick4.getNext() == nullptr);

        SickKoalaList   sick5(&fracture);
        cr_assert(sick5.getPatient() != nullptr);
        cr_assert_eq(sick5.getPatient(), &fracture);
        cr_assert(sick5.getPatient()->get_name() == "Falter");
        cr_assert(sick5.getNext() == nullptr);

        Hospital        bellevue;
        cr_assert(bellevue.getSickKoalaList() == nullptr);
        cr_assert(bellevue.getKoalaNurseList() == nullptr);
        cr_assert(bellevue.getKoalaDoctorList() == nullptr);

////////AddDoctor
        cr_assert(doc1.getDoctor() != nullptr);
        cr_assert(doc1.getFromName(doc1.getDoctor()->getName()) == doc1.getDoctor());
        bellevue.addDoctor(&doc1);
        cr_assert(bellevue.getKoalaDoctorList()->getDoctor()->getName() == "Cox");
        bellevue.addDoctor(&doc2);
        cr_assert(bellevue.getKoalaDoctorList()->getNext()->getDoctor()->getName() == "House");
        bellevue.addDoctor(&doc3);
        cr_assert(bellevue.getKoalaDoctorList()->getNext()->getNext()->getDoctor()->getName() == "Boudur-Oulot");
////////AddSick
        cr_assert(sick1.getPatient() != nullptr);
        cr_assert(sick1.getFromName(sick1.getPatient()->get_name()) == sick1.getPatient());
        cr_assert(sick2.getPatient() != nullptr);
        cr_assert(sick2.getFromName(sick2.getPatient()->get_name()) == sick2.getPatient());
        cr_assert(sick3.getPatient() != nullptr);
        cr_assert(sick3.getFromName(sick3.getPatient()->get_name()) == sick3.getPatient());
        cr_assert(sick4.getPatient() != nullptr);
        cr_assert(sick4.getFromName(sick4.getPatient()->get_name()) == sick4.getPatient());
        cr_assert(sick5.getPatient() != nullptr);
        cr_assert(sick5.getFromName(sick5.getPatient()->get_name()) == sick5.getPatient());
       bellevue.addSick(&sick1);
        cr_assert(bellevue.getSickKoalaList()->getPatient()->get_name() == "Ganepar");
        bellevue.addSick(&sick2);
        cr_assert(bellevue.getSickKoalaList()->getNext()->getPatient()->get_name() == "Scarface");
        bellevue.addSick(&sick3);
        cr_assert(bellevue.getSickKoalaList()->getNext()->getNext()->getPatient()->get_name() == "RedFace");
        bellevue.addSick(&sick4);
        cr_assert(bellevue.getSickKoalaList()->getNext()->getNext()->getNext()->getPatient()->get_name() == "Varia");
        bellevue.addSick(&sick5);
        cr_assert(bellevue.getSickKoalaList()->getNext()->getNext()->getNext()->getNext()->getPatient()->get_name() == "Falter");
////////AddNurse
        cr_assert(nurse1.getNurse() != nullptr);
        cr_assert(nurse1.getFromId(nurse1.getNurse()->getID()) == nurse1.getNurse());
        bellevue.addNurse(&nurse1);
        cr_assert(bellevue.getKoalaNurseList()->getNurse()->getID() == 1);
        bellevue.addNurse(&nurse2);
        cr_assert(bellevue.getKoalaNurseList()->getNext()->getNurse()->getID() == 2);
////////Dump
        bellevue.dump();
        cr_assert_stdout_eq_str(
        "Dr.Cox: I'm Dr.Cox! How do you kreog?\n\
Dr.House: I'm Dr.House! How do you kreog?\n\
Dr.Boudur-Oulot: I'm Dr.Boudur-Oulot! How do you kreog?\n\
[HOSPITAL] Doctor Cox just arrived!\n\
Dr.Cox: Time to get to work!\n\
[HOSPITAL] Doctor House just arrived!\n\
Dr.House: Time to get to work!\n\
[HOSPITAL] Doctor Boudur-Oulot just arrived!\n\
Dr.Boudur-Oulot: Time to get to work!\n\
[HOSPITAL] Patient Ganepar just arrived!\n\
[HOSPITAL] Patient Scarface just arrived!\n\
[HOSPITAL] Patient RedFace just arrived!\n\
[HOSPITAL] Patient Varia just arrived!\n\
[HOSPITAL] Patient Falter just arrived!\n\
[HOSPITAL] Nurse 1 just arrived!\n\
Nurse 1: Time to get to work!\n\
[HOSPITAL] Nurse 2 just arrived!\n\
Nurse 2: Time to get to work!\n\
[HOSPITAL] Work starting with:\n\
Doctors: Cox, House, Boudur-Oulot.\n\
Nurses: 1, 2.\n\
Patients: Ganepar, Scarface, RedFace, Varia, Falter.\n\
\n");
}

Test(Hospital, test_heal, .signal=SIGPIPE, .init=redirect_all_stdout)
{
        KoalaDoctor     cox("Cox");
        cr_assert(cox.getName() == "Cox");
        cr_assert(cox.getIsWorking() == false);

        KoalaDoctor     house("House");
        cr_assert(house.getName() == "House");
        cr_assert(house.getIsWorking() == false);

        KoalaDoctor     tired("Boudur-Oulot");
        cr_assert(tired.getName() == "Boudur-Oulot");
        cr_assert(tired.getIsWorking() == false);

        KoalaDoctorList doc1(&cox);
        cr_assert(doc1.getDoctor() != nullptr);
        cr_assert_eq(doc1.getDoctor(), &cox);
        cr_assert(doc1.getDoctor()->getName() == "Cox");
        cr_assert(doc1.getDoctor()->getIsWorking() == false);
        cr_assert(doc1.getNext() == nullptr);

        KoalaDoctorList doc2(&house);
        cr_assert(doc2.getDoctor() != nullptr);
        cr_assert_eq(doc2.getDoctor(), &house);
        cr_assert(doc2.getDoctor()->getName() == "House");
        cr_assert(doc2.getDoctor()->getIsWorking() == false);
        cr_assert(doc2.getNext() == nullptr);

        KoalaDoctorList doc3(&tired);
        cr_assert(doc3.getDoctor() != nullptr);
        cr_assert_eq(doc3.getDoctor(), &tired);
        cr_assert(doc3.getDoctor()->getName() == "Boudur-Oulot");
        cr_assert(doc3.getDoctor()->getIsWorking() == false);
        cr_assert(doc3.getNext() == nullptr);

        KoalaNurse      ratched(1);
        cr_assert(ratched.getID() == 1);
        cr_assert(ratched.get_isWorking() == false);

        KoalaNurse      betty(2);
        cr_assert(betty.getID() == 2);
        cr_assert(betty.get_isWorking() == false);

        KoalaNurseList  nurse1(&ratched);
        cr_assert(nurse1.getNurse() != nullptr);
        cr_assert_eq(nurse1.getNurse(), &ratched);
        cr_assert(nurse1.getNurse()->getID() == 1);
        cr_assert(nurse1.getNurse()->get_isWorking() == false);
        cr_assert(nurse1.getNext() == nullptr);

        KoalaNurseList  nurse2(&betty);
        cr_assert(nurse2.getNurse() != nullptr);
        cr_assert_eq(nurse2.getNurse(), &betty);
        cr_assert(nurse2.getNurse()->getID() == 2);
        cr_assert(nurse2.getNurse()->get_isWorking() == false);
        cr_assert(nurse2.getNext() == nullptr);

        SickKoala       cancer("Ganepar");
        cr_assert(cancer.get_name() == "Ganepar");

        SickKoala       gangrene("Scarface");
        cr_assert(gangrene.get_name() == "Scarface");

        SickKoala       measles("RedFace");
        cr_assert(measles.get_name() == "RedFace");

        SickKoala       smallpox("Varia");
        cr_assert(smallpox.get_name() == "Varia");

        SickKoala       fracture("Falter");
        cr_assert(fracture.get_name() == "Falter");

        SickKoalaList   sick1(&cancer);
        cr_assert(sick1.getPatient() != nullptr);
        cr_assert_eq(sick1.getPatient(), &cancer);
        cr_assert(sick1.getPatient()->get_name() == "Ganepar");
        cr_assert(sick1.getNext() == nullptr);

        SickKoalaList   sick2(&gangrene);
        cr_assert(sick2.getPatient() != nullptr);
        cr_assert_eq(sick2.getPatient(), &gangrene);
        cr_assert(sick2.getPatient()->get_name() == "Scarface");
        cr_assert(sick2.getNext() == nullptr);

        SickKoalaList   sick3(&measles);
        cr_assert(sick3.getPatient() != nullptr);
        cr_assert_eq(sick3.getPatient(), &measles);
        cr_assert(sick3.getPatient()->get_name() == "RedFace");
        cr_assert(sick3.getNext() == nullptr);

        SickKoalaList   sick4(&smallpox);
        cr_assert(sick4.getPatient() != nullptr);
        cr_assert_eq(sick4.getPatient(), &smallpox);
        cr_assert(sick4.getPatient()->get_name() == "Varia");
        cr_assert(sick4.getNext() == nullptr);

        SickKoalaList   sick5(&fracture);
        cr_assert(sick5.getPatient() != nullptr);
        cr_assert_eq(sick5.getPatient(), &fracture);
        cr_assert(sick5.getPatient()->get_name() == "Falter");
        cr_assert(sick5.getNext() == nullptr);

        Hospital        bellevue;
        cr_assert(bellevue.getSickKoalaList() == nullptr);
        cr_assert(bellevue.getKoalaNurseList() == nullptr);
        cr_assert(bellevue.getKoalaDoctorList() == nullptr);

////////AddDoctor
        cr_assert(doc1.getDoctor() != nullptr);
        cr_assert(doc1.getFromName(doc1.getDoctor()->getName()) == doc1.getDoctor());
        bellevue.addDoctor(&doc1);
        cr_assert(bellevue.getKoalaDoctorList()->getDoctor()->getName() == "Cox");
        bellevue.addDoctor(&doc2);
        cr_assert(bellevue.getKoalaDoctorList()->getNext()->getDoctor()->getName() == "House");
        bellevue.addDoctor(&doc3);
        cr_assert(bellevue.getKoalaDoctorList()->getNext()->getNext()->getDoctor()->getName() == "Boudur-Oulot");
////////AddSick
        cr_assert(sick1.getPatient() != nullptr);
        cr_assert(sick1.getFromName(sick1.getPatient()->get_name()) == sick1.getPatient());
        cr_assert(sick2.getPatient() != nullptr);
        cr_assert(sick2.getFromName(sick2.getPatient()->get_name()) == sick2.getPatient());
        cr_assert(sick3.getPatient() != nullptr);
        cr_assert(sick3.getFromName(sick3.getPatient()->get_name()) == sick3.getPatient());
        cr_assert(sick4.getPatient() != nullptr);
        cr_assert(sick4.getFromName(sick4.getPatient()->get_name()) == sick4.getPatient());
        cr_assert(sick5.getPatient() != nullptr);
        cr_assert(sick5.getFromName(sick5.getPatient()->get_name()) == sick5.getPatient());
       bellevue.addSick(&sick1);
        cr_assert(bellevue.getSickKoalaList()->getPatient()->get_name() == "Ganepar");
        bellevue.addSick(&sick2);
        cr_assert(bellevue.getSickKoalaList()->getNext()->getPatient()->get_name() == "Scarface");
        bellevue.addSick(&sick3);
        cr_assert(bellevue.getSickKoalaList()->getNext()->getNext()->getPatient()->get_name() == "RedFace");
        bellevue.addSick(&sick4);
        cr_assert(bellevue.getSickKoalaList()->getNext()->getNext()->getNext()->getPatient()->get_name() == "Varia");
        bellevue.addSick(&sick5);
        cr_assert(bellevue.getSickKoalaList()->getNext()->getNext()->getNext()->getNext()->getPatient()->get_name() == "Falter");
////////AddNurse
        cr_assert(nurse1.getNurse() != nullptr);
        cr_assert(nurse1.getFromId(nurse1.getNurse()->getID()) == nurse1.getNurse());
        bellevue.addNurse(&nurse1);
        cr_assert(bellevue.getKoalaNurseList()->getNurse()->getID() == 1);
        bellevue.addNurse(&nurse2);
        cr_assert(bellevue.getKoalaNurseList()->getNext()->getNurse()->getID() == 2);
////////Dump
        bellevue.dump();
////////DoctorHgeals
        srandom (42) ;

        // bellevue.getKoalaDoctorList()->getFromName("Cox")->diagnose(bellevue.getSickKoalaList()->getFromName("Ganepar"));
        // bellevue.getKoalaNurseList()->getFromId(1)->giveDrug(bellevue.getKoalaNurseList()->getFromId(1)->readReport("Ganepar.report"), bellevue.getSickKoalaList()->getFromName("Ganepar"));
        // bellevue.getSickKoalaList()->removeFromName("Ganepar");
        bellevue.heal();
        // bellevue.endWork();

        cr_assert_stdout_eq_str(
        "Dr.Cox: I'm Dr.Cox! How do you kreog?\n\
Dr.House: I'm Dr.House! How do you kreog?\n\
Dr.Boudur-Oulot: I'm Dr.Boudur-Oulot! How do you kreog?\n\
[HOSPITAL] Doctor Cox just arrived!\n\
Dr.Cox: Time to get to work!\n\
[HOSPITAL] Doctor House just arrived!\n\
Dr.House: Time to get to work!\n\
[HOSPITAL] Doctor Boudur-Oulot just arrived!\n\
Dr.Boudur-Oulot: Time to get to work!\n\
[HOSPITAL] Patient Ganepar just arrived!\n\
[HOSPITAL] Patient Scarface just arrived!\n\
[HOSPITAL] Patient RedFace just arrived!\n\
[HOSPITAL] Patient Varia just arrived!\n\
[HOSPITAL] Patient Falter just arrived!\n\
[HOSPITAL] Nurse 1 just arrived!\n\
Nurse 1: Time to get to work!\n\
[HOSPITAL] Nurse 2 just arrived!\n\
Nurse 2: Time to get to work!\n\
[HOSPITAL] Work starting with:\n\
Doctors: Cox, House, Boudur-Oulot.\n\
Nurses: 1, 2.\n\
Patients: Ganepar, Scarface, RedFace, Varia, Falter.\n\
\n\
Dr.Cox: So what's goerking you Mr.Ganepar?\n\
Mr.Ganepar: Gooeeeeerrk!!\n\
Nurse 1: Kreog! Mr.Ganepar needs a Buronzand!\n\
Mr.Ganepar: And you'll sleep right away!\n\
Dr.House: So what's goerking you Mr.Varia?\n\
Mr.Varia: Gooeeeeerrk!!\n\
Nurse 2: Kreog! Mr.Varia needs a Mars!\n\
Mr.Varia: Mars, and it kreogs!\n\
Dr.Boudur-Oulot: So what's goerking you Mr.RedFace?\n\
Mr.RedFace: Gooeeeeerrk!!\n\
Nurse 1: Kreog! Mr.RedFace needs a Buronzand!\n\
Mr.RedFace: And you'll sleep right away!\n\
Dr.Cox: So what's goerking you Mr.Scarface?\n\
Mr.Scarface: Gooeeeeerrk!!\n\
Nurse 2: Kreog! Mr.Scarface needs a Buronzand!\n\
Mr.Scarface: And you'll sleep right away!\n\
Dr.House: So what's goerking you Mr.Falter?\n\
Mr.Falter: Gooeeeeerrk!!\n\
Nurse 1: Kreog! Mr.Falter needs a Viagra!\n\
Mr.Falter: Goerkreog!\n");
}


Test(Hospital, test_endWork, .signal=SIGPIPE, .init=redirect_all_stdout)
{
        KoalaDoctor     cox("Cox");
        cr_assert(cox.getName() == "Cox");
        cr_assert(cox.getIsWorking() == false);

        KoalaDoctor     house("House");
        cr_assert(house.getName() == "House");
        cr_assert(house.getIsWorking() == false);

        KoalaDoctor     tired("Boudur-Oulot");
        cr_assert(tired.getName() == "Boudur-Oulot");
        cr_assert(tired.getIsWorking() == false);

        KoalaDoctorList doc1(&cox);
        cr_assert(doc1.getDoctor() != nullptr);
        cr_assert_eq(doc1.getDoctor(), &cox);
        cr_assert(doc1.getDoctor()->getName() == "Cox");
        cr_assert(doc1.getDoctor()->getIsWorking() == false);
        cr_assert(doc1.getNext() == nullptr);

        KoalaDoctorList doc2(&house);
        cr_assert(doc2.getDoctor() != nullptr);
        cr_assert_eq(doc2.getDoctor(), &house);
        cr_assert(doc2.getDoctor()->getName() == "House");
        cr_assert(doc2.getDoctor()->getIsWorking() == false);
        cr_assert(doc2.getNext() == nullptr);

        KoalaDoctorList doc3(&tired);
        cr_assert(doc3.getDoctor() != nullptr);
        cr_assert_eq(doc3.getDoctor(), &tired);
        cr_assert(doc3.getDoctor()->getName() == "Boudur-Oulot");
        cr_assert(doc3.getDoctor()->getIsWorking() == false);
        cr_assert(doc3.getNext() == nullptr);

        KoalaNurse      ratched(1);
        cr_assert(ratched.getID() == 1);
        cr_assert(ratched.get_isWorking() == false);

        KoalaNurse      betty(2);
        cr_assert(betty.getID() == 2);
        cr_assert(betty.get_isWorking() == false);

        KoalaNurseList  nurse1(&ratched);
        cr_assert(nurse1.getNurse() != nullptr);
        cr_assert_eq(nurse1.getNurse(), &ratched);
        cr_assert(nurse1.getNurse()->getID() == 1);
        cr_assert(nurse1.getNurse()->get_isWorking() == false);
        cr_assert(nurse1.getNext() == nullptr);

        KoalaNurseList  nurse2(&betty);
        cr_assert(nurse2.getNurse() != nullptr);
        cr_assert_eq(nurse2.getNurse(), &betty);
        cr_assert(nurse2.getNurse()->getID() == 2);
        cr_assert(nurse2.getNurse()->get_isWorking() == false);
        cr_assert(nurse2.getNext() == nullptr);

        SickKoala       cancer("Ganepar");
        cr_assert(cancer.get_name() == "Ganepar");

        SickKoala       gangrene("Scarface");
        cr_assert(gangrene.get_name() == "Scarface");

        SickKoala       measles("RedFace");
        cr_assert(measles.get_name() == "RedFace");

        SickKoala       smallpox("Varia");
        cr_assert(smallpox.get_name() == "Varia");

        SickKoala       fracture("Falter");
        cr_assert(fracture.get_name() == "Falter");

        SickKoalaList   sick1(&cancer);
        cr_assert(sick1.getPatient() != nullptr);
        cr_assert_eq(sick1.getPatient(), &cancer);
        cr_assert(sick1.getPatient()->get_name() == "Ganepar");
        cr_assert(sick1.getNext() == nullptr);

        SickKoalaList   sick2(&gangrene);
        cr_assert(sick2.getPatient() != nullptr);
        cr_assert_eq(sick2.getPatient(), &gangrene);
        cr_assert(sick2.getPatient()->get_name() == "Scarface");
        cr_assert(sick2.getNext() == nullptr);

        SickKoalaList   sick3(&measles);
        cr_assert(sick3.getPatient() != nullptr);
        cr_assert_eq(sick3.getPatient(), &measles);
        cr_assert(sick3.getPatient()->get_name() == "RedFace");
        cr_assert(sick3.getNext() == nullptr);

        SickKoalaList   sick4(&smallpox);
        cr_assert(sick4.getPatient() != nullptr);
        cr_assert_eq(sick4.getPatient(), &smallpox);
        cr_assert(sick4.getPatient()->get_name() == "Varia");
        cr_assert(sick4.getNext() == nullptr);

        SickKoalaList   sick5(&fracture);
        cr_assert(sick5.getPatient() != nullptr);
        cr_assert_eq(sick5.getPatient(), &fracture);
        cr_assert(sick5.getPatient()->get_name() == "Falter");
        cr_assert(sick5.getNext() == nullptr);

        Hospital        bellevue;
        cr_assert(bellevue.getSickKoalaList() == nullptr);
        cr_assert(bellevue.getKoalaNurseList() == nullptr);
        cr_assert(bellevue.getKoalaDoctorList() == nullptr);

////////AddDoctor
        cr_assert(doc1.getDoctor() != nullptr);
        cr_assert(doc1.getFromName(doc1.getDoctor()->getName()) == doc1.getDoctor());
        bellevue.addDoctor(&doc1);
        cr_assert(bellevue.getKoalaDoctorList()->getDoctor()->getName() == "Cox");
        bellevue.addDoctor(&doc2);
        cr_assert(bellevue.getKoalaDoctorList()->getNext()->getDoctor()->getName() == "House");
        bellevue.addDoctor(&doc3);
        cr_assert(bellevue.getKoalaDoctorList()->getNext()->getNext()->getDoctor()->getName() == "Boudur-Oulot");
////////AddSick
        cr_assert(sick1.getPatient() != nullptr);
        cr_assert(sick1.getFromName(sick1.getPatient()->get_name()) == sick1.getPatient());
        cr_assert(sick2.getPatient() != nullptr);
        cr_assert(sick2.getFromName(sick2.getPatient()->get_name()) == sick2.getPatient());
        cr_assert(sick3.getPatient() != nullptr);
        cr_assert(sick3.getFromName(sick3.getPatient()->get_name()) == sick3.getPatient());
        cr_assert(sick4.getPatient() != nullptr);
        cr_assert(sick4.getFromName(sick4.getPatient()->get_name()) == sick4.getPatient());
        cr_assert(sick5.getPatient() != nullptr);
        cr_assert(sick5.getFromName(sick5.getPatient()->get_name()) == sick5.getPatient());
       bellevue.addSick(&sick1);
        cr_assert(bellevue.getSickKoalaList()->getPatient()->get_name() == "Ganepar");
        bellevue.addSick(&sick2);
        cr_assert(bellevue.getSickKoalaList()->getNext()->getPatient()->get_name() == "Scarface");
        bellevue.addSick(&sick3);
        cr_assert(bellevue.getSickKoalaList()->getNext()->getNext()->getPatient()->get_name() == "RedFace");
        bellevue.addSick(&sick4);
        cr_assert(bellevue.getSickKoalaList()->getNext()->getNext()->getNext()->getPatient()->get_name() == "Varia");
        bellevue.addSick(&sick5);
        cr_assert(bellevue.getSickKoalaList()->getNext()->getNext()->getNext()->getNext()->getPatient()->get_name() == "Falter");
////////AddNurse
        cr_assert(nurse1.getNurse() != nullptr);
        cr_assert(nurse1.getFromId(nurse1.getNurse()->getID()) == nurse1.getNurse());
        bellevue.addNurse(&nurse1);
        cr_assert(bellevue.getKoalaNurseList()->getNurse()->getID() == 1);
        bellevue.addNurse(&nurse2);
        cr_assert(bellevue.getKoalaNurseList()->getNext()->getNurse()->getID() == 2);
////////Dump
        bellevue.dump();
////////DoctorHgeals
        srandom (42) ;

        bellevue.heal();
/////////////////////////
        bellevue.endWork();
/////////////////////////////
        cr_assert_stdout_eq_str(
        "Dr.Cox: I'm Dr.Cox! How do you kreog?\n\
Dr.House: I'm Dr.House! How do you kreog?\n\
Dr.Boudur-Oulot: I'm Dr.Boudur-Oulot! How do you kreog?\n\
[HOSPITAL] Doctor Cox just arrived!\n\
Dr.Cox: Time to get to work!\n\
[HOSPITAL] Doctor House just arrived!\n\
Dr.House: Time to get to work!\n\
[HOSPITAL] Doctor Boudur-Oulot just arrived!\n\
Dr.Boudur-Oulot: Time to get to work!\n\
[HOSPITAL] Patient Ganepar just arrived!\n\
[HOSPITAL] Patient Scarface just arrived!\n\
[HOSPITAL] Patient RedFace just arrived!\n\
[HOSPITAL] Patient Varia just arrived!\n\
[HOSPITAL] Patient Falter just arrived!\n\
[HOSPITAL] Nurse 1 just arrived!\n\
Nurse 1: Time to get to work!\n\
[HOSPITAL] Nurse 2 just arrived!\n\
Nurse 2: Time to get to work!\n\
[HOSPITAL] Work starting with:\n\
Doctors: Cox, House, Boudur-Oulot.\n\
Nurses: 1, 2.\n\
Patients: Ganepar, Scarface, RedFace, Varia, Falter.\n\
\n\
Dr.Cox: So what's goerking you Mr.Ganepar?\n\
Mr.Ganepar: Gooeeeeerrk!!\n\
Nurse 1: Kreog! Mr.Ganepar needs a Buronzand!\n\
Mr.Ganepar: And you'll sleep right away!\n\
Dr.House: So what's goerking you Mr.Varia?\n\
Mr.Varia: Gooeeeeerrk!!\n\
Nurse 2: Kreog! Mr.Varia needs a Mars!\n\
Mr.Varia: Mars, and it kreogs!\n\
Dr.Boudur-Oulot: So what's goerking you Mr.RedFace?\n\
Mr.RedFace: Gooeeeeerrk!!\n\
Nurse 1: Kreog! Mr.RedFace needs a Buronzand!\n\
Mr.RedFace: And you'll sleep right away!\n\
Dr.Cox: So what's goerking you Mr.Scarface?\n\
Mr.Scarface: Gooeeeeerrk!!\n\
Nurse 2: Kreog! Mr.Scarface needs a Buronzand!\n\
Mr.Scarface: And you'll sleep right away!\n\
Dr.House: So what's goerking you Mr.Falter?\n\
Mr.Falter: Gooeeeeerrk!!\n\
Nurse 1: Kreog! Mr.Falter needs a Viagra!\n\
Mr.Falter: Goerkreog!\n\
Nurse 1: Time to go home to my eucalyptus forest!\n\
Nurse 2: Time to go home to my eucalyptus forest!\n\
Dr.Cox: Time to go home to my eucalyptus forest!\n\
Dr.House: Time to go home to my eucalyptus forest!\n\
Dr.Boudur-Oulot: Time to go home to my eucalyptus forest!\n");

}
