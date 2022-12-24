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

        Hospital        bellevue;
        cr_assert(bellevue.getSickKoalaList() == nullptr);
        cr_assert(bellevue.getKoalaNurseList() == nullptr);
        cr_assert(bellevue.getKoalaDoctorList() == nullptr);

        cr_assert_stdout_eq_str(
        "Dr.Cox: I'm Dr.Cox! How do you kreog?\n\
Dr.House: I'm Dr.House! How do you kreog?\n\
Dr.Boudur-Oulot: I'm Dr.Boudur-Oulot! How do you kreog?\n");
}