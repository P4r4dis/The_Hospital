#include "../includes/my_doctor_hospital.hpp"
#include "../../part2_nurse/includes/my_nurse_hospital.hpp"
#include "../../part1_patient/includes/my_patient_hospital.hpp"
#include "./tests_includes/test_my_doctor_hospital.hpp"


Test(KoalaDoctor, test_ctor_stdout,.init=redirect_all_stdout) {
    KoalaDoctor     cox("Cox");

    cr_assert_stdout_eq_str("Dr.Cox: I'm Dr.Cox! How do you kreog?\n");
}

Test(KoalaDoctor, test_getName) {
    KoalaDoctor     cox("Cox");

    cr_assert(not(zero(str, cox.getName())));
    cr_assert(not(eq(str, cox.getName(), "")));
    cr_assert(eq(str, cox.getName(), "Cox"));
}


//////////////////////////////////////////////////////////////////////////////
// Test(KoalaNurse, test_ctor_and_getID) {
//         int             id = 1;
//         KoalaNurse      koalaNurse(id);

//         cr_assert(id);
//         cr_assert(eq(int, koalaNurse.getID(), 1));
//         cr_assert(eq(int, koalaNurse.getID(), id));
// }

// Test(KoalaNurse, test_dtor_stdcout,  .signal=SIGPIPE, .init=redirect_all_stdout) {
//         KoalaNurse koalaNurse(1);
//         koalaNurse.~KoalaNurse();
//         cr_assert_stdout_eq_str("Nurse 1: Finally some rest!\n");
// }



// Test(KoalaNurse, test_giveDrug_strParameter) {
//         std::string     Drug;

//         cr_assert(zero(str, Drug));
//         cr_assert(eq(str, Drug, ""));
//         cr_assert_str_empty(Drug.data());
//         Drug = "drug";
//         cr_assert(not(zero(str, Drug)));
//         cr_assert(not(eq(str, Drug, "")));
//         cr_assert(eq(str, Drug, "drug"));
// }

// Test(KoalaNurse, test_giveDrug_pointerPatient, .signal=SIGPIPE, .init=redirect_all_stdout) {
//         std::string     Drug;

//         cr_assert(zero(str, Drug));
//         cr_assert(eq(str, Drug, ""));
//         cr_assert_str_empty(Drug.data());
//         Drug = "drug";
        // cr_assert(not(zero(str, Drug)));
        // cr_assert(not(eq(str, Drug, "")));
        // cr_assert(eq(str, Drug, "drug"));

//         SickKoala patient;
//         patient.takeDrug(Drug);
//         cr_assert_stdout_eq_str("Mr.SickKoala: Goerkreog!\n");
// }

// Test(giveDrug, test_giveDrug_memberFunction, .signal=SIGPIPE, .init=redirect_all_stdout) {
//         KoalaNurse koalaNurse(1);
//         SickKoala patient;
//         koalaNurse.giveDrug("Drug", &patient);
//         cr_assert_stdout_eq_str("Mr.SickKoala: Goerkreog!\n");
// }

// Test(readReport, test_readReport_params) {
//         SickKoala       sickKoala;

        // cr_assert(ne(str, sickKoala.get_name().data(), ""));
        // cr_assert(eq(str, sickKoala.get_name().data(), "SickKoala"));
// //////////////////////////////////////////////////////////////////////////
//         std::string     filename_param = sickKoala.get_name() + ".report";

//         cr_assert(not(zero(str, filename_param)));
//         cr_assert(not(eq(str, filename_param, "")));        
//         cr_assert(ne(str, filename_param.data(), ""));
//         cr_assert(eq(str, filename_param.data(), "SickKoala.report"));
// //////////////////////////////////////////////////////////////////////////
//         int             id = 1;
//         KoalaNurse      koalaNurse(id);

//         cr_assert(id);
//         cr_assert(eq(int, koalaNurse.getID(), 1));
//         cr_assert(eq(int, koalaNurse.getID(), id));
// //////////////////////////////////////////////////////////////////////////
//         std::string     my_line;

//         cr_assert(zero(str, my_line));
//         cr_assert(eq(str, my_line, ""));
//         cr_assert_str_empty(my_line.data());
// //////////////////////////////////////////////////////////////////////////
//         std::string     return_value;

//         cr_assert(zero(str, return_value));
//         cr_assert(eq(str, return_value, ""));
//         cr_assert_str_empty(return_value.data());
// //////////////////////////////////////////////////////////////////////////
// }

// Test(readReport, test_readReport_openfile) {
//         SickKoala       sickKoala;

//         cr_assert(ne(str, sickKoala.get_name().data(), ""));
//         cr_assert(eq(str, sickKoala.get_name().data(), "SickKoala"));
// //////////////////////////////////////////////////////////////////////////
//         std::string     filename_param = sickKoala.get_name() + ".report";

//         cr_assert(not(zero(str, filename_param)));
//         cr_assert(not(eq(str, filename_param, "")));        
//         cr_assert(ne(str, filename_param.data(), ""));
//         cr_assert(eq(str, filename_param.data(), "SickKoala.report"));
// //////////////////////////////////////////////////////////////////////////
//         int             id = 1;
//         KoalaNurse      koalaNurse(id);

//         cr_assert(id);
//         cr_assert(eq(int, koalaNurse.getID(), 1));
//         cr_assert(eq(int, koalaNurse.getID(), id));
// //////////////////////////////////////////////////////////////////////////
//         std::string     my_line;

//         cr_assert(zero(str, my_line));
//         cr_assert(eq(str, my_line, ""));
//         cr_assert_str_empty(my_line.data());
// // //////////////////////////////////////////////////////////////////////////
//         std::string     return_value;

//         cr_assert(zero(str, return_value));
//         cr_assert(eq(str, return_value, ""));
//         cr_assert_str_empty(return_value.data());
// // //////////////////////////////////////////////////////////////////////////
//         std::fstream    f_stream;

//         f_stream.open(filename_param.data(), std::ios::in);
//         cr_assert(f_stream.is_open() == true);
// }

// Test(readReport, test_readReport_notOpenFile) {
//         SickKoala       sickKoala("TEST");

//         cr_assert(ne(str, sickKoala.get_name().data(), ""));
//         cr_assert(eq(str, sickKoala.get_name().data(), "TEST"));
// //////////////////////////////////////////////////////////////////////////
//         std::string     filename_param = sickKoala.get_name() + ".report";

//         cr_assert(not(zero(str, filename_param)));
//         cr_assert(not(eq(str, filename_param, "")));        
//         cr_assert(ne(str, filename_param.data(), ""));
//         cr_assert(eq(str, filename_param.data(), "TEST.report"));
// //////////////////////////////////////////////////////////////////////////
//         int             id = 1;
//         KoalaNurse      koalaNurse(id);

//         cr_assert(id);
//         cr_assert(eq(int, koalaNurse.getID(), 1));
//         cr_assert(eq(int, koalaNurse.getID(), id));
// //////////////////////////////////////////////////////////////////////////
//         std::string     my_line;

//         cr_assert(zero(str, my_line));
//         cr_assert(eq(str, my_line, ""));
//         cr_assert_str_empty(my_line.data());
// //////////////////////////////////////////////////////////////////////////
//         std::string     return_value;

//         cr_assert(zero(str, return_value));
//         cr_assert(eq(str, return_value, ""));
//         cr_assert_str_empty(return_value.data());
// //////////////////////////////////////////////////////////////////////////
//         std::fstream    f_stream;

//         f_stream.open(filename_param.data(), std::ios::in);
//         cr_assert(f_stream.is_open() == false);
// }

// Test(readReport, test_readReport_readFile_and_stdout, .signal=SIGPIPE, .init=redirect_all_stdout) {
//         SickKoala       sickKoala;

//         cr_assert(ne(str, sickKoala.get_name().data(), ""));
//         cr_assert(eq(str, sickKoala.get_name().data(), "SickKoala"));
// //////////////////////////////////////////////////////////////////////////
//         std::string     filename_param = sickKoala.get_name() + ".report";

//         cr_assert(not(zero(str, filename_param)));
//         cr_assert(not(eq(str, filename_param, "")));        
//         cr_assert(ne(str, filename_param.data(), ""));
//         cr_assert(eq(str, filename_param.data(), "SickKoala.report"));
// //////////////////////////////////////////////////////////////////////////
//         int             id = 1;
//         KoalaNurse      koalaNurse(id);

//         cr_assert(id);
//         cr_assert(eq(int, koalaNurse.getID(), 1));
//         cr_assert(eq(int, koalaNurse.getID(), id));
// //////////////////////////////////////////////////////////////////////////
//         std::string     my_line;

//         cr_assert(zero(str, my_line));
//         cr_assert(eq(str, my_line, ""));
//         cr_assert_str_empty(my_line.data());
// //////////////////////////////////////////////////////////////////////////
//         std::string     return_value;

//         cr_assert(zero(str, return_value));
//         cr_assert(eq(str, return_value, ""));
//         cr_assert_str_empty(return_value.data());
// //////////////////////////////////////////////////////////////////////////
//         std::fstream    f_stream;

//         f_stream.open(filename_param.data(), std::ios::in);
//         cr_assert(f_stream.is_open() == true);
// //////////////////////////////////////////////////////////////////////////
//         if (f_stream.is_open()) {
//                 while (std::getline (f_stream, my_line, '\0')) {
//                         std::cout << "Nurse " << koalaNurse.getID() 
//                         << ": Kreog! Mr." << sickKoala.get_name() 
//                         << " needs a " << my_line << "!" << std::endl;
//                         return_value = "Nurse " + std::to_string(koalaNurse.getID()) 
//                         + ": Kreog! Mr." + sickKoala.get_name() + " needs a " + my_line + "!\n";
//                         cr_assert_stdout_eq_str("Nurse 1: Kreog! Mr.SickKoala needs a DRUG!\n");
//                         cr_assert(not(eq(str,return_value, "")));
//                         cr_assert(eq(str, return_value, "Nurse " + std::to_string(koalaNurse.getID()) 
//                         + ": Kreog! Mr." + sickKoala.get_name() + " needs a " + my_line + "!\n"));
//                 }
//         } else {
//                 return_value = "";
//                 cr_assert(zero(str, return_value));
//                 cr_assert(eq(str, return_value, ""));
//                 cr_assert_str_empty(return_value.data());
//         }
//         // f_stream.close();
// }

// Test(readReport, test_readReport_NotReadFile_and_stdout, .signal=SIGPIPE,  .init=redirect_all_stdout) {
//         SickKoala       sickKoala("TEST");

//         cr_assert(ne(str, sickKoala.get_name().data(), ""));
//         cr_assert(eq(str, sickKoala.get_name().data(), "TEST"));
// //////////////////////////////////////////////////////////////////////////
//         std::string     filename_param = sickKoala.get_name() + ".report";

//         cr_assert(not(zero(str, filename_param)));
//         cr_assert(not(eq(str, filename_param, "")));        
//         cr_assert(ne(str, filename_param.data(), ""));
//         cr_assert(eq(str, filename_param.data(), "TEST.report"));
// //////////////////////////////////////////////////////////////////////////
//         int             id = 1;
//         KoalaNurse      koalaNurse(id);

//         cr_assert(id);
//         cr_assert(eq(int, koalaNurse.getID(), 1));
//         cr_assert(eq(int, koalaNurse.getID(), id));
// //////////////////////////////////////////////////////////////////////////
//         std::string     my_line;

//         cr_assert(zero(str, my_line));
//         cr_assert(eq(str, my_line, ""));
//         cr_assert_str_empty(my_line.data());
// //////////////////////////////////////////////////////////////////////////
//         std::string     return_value;

//         cr_assert(zero(str, return_value));
//         cr_assert(eq(str, return_value, ""));
//         cr_assert_str_empty(return_value.data());
// //////////////////////////////////////////////////////////////////////////
//         std::fstream    f_stream;

//         f_stream.open(filename_param.data(), std::ios::in);
//         cr_assert(f_stream.is_open() == false);
// //////////////////////////////////////////////////////////////////////////
//         if (f_stream.is_open()) {
//                 while (std::getline (f_stream, my_line, '\0')) {
//                         std::cout << "Nurse " << koalaNurse.getID() 
//                         << ": Kreog! Mr." << sickKoala.get_name() 
//                         << " needs a " << my_line << "!" << std::endl;
//                         return_value = "Nurse " + std::to_string(koalaNurse.getID()) 
//                         + ": Kreog! Mr." + sickKoala.get_name() + " needs a " + my_line + "!\n";
//                         cr_assert_stdout_eq_str("Nurse 1: Kreog! Mr.SickKoala needs a DRUG!\n");
//                         cr_assert(not(eq(str,return_value, "")));
//                         cr_assert(eq(str, return_value, "Nurse " + std::to_string(koalaNurse.getID()) 
//                         + ": Kreog! Mr." + sickKoala.get_name() + " needs a " + my_line + "!\n"));
//                 }
//         } else {
//                 std::cout << "" << std::flush;
//                 return_value = "";
//                 cr_assert(zero(str, return_value));
//                 cr_assert(eq(str, return_value, ""));
//                 cr_assert_str_empty(return_value.data());
//                 cr_assert_stdout_eq_str("");
//         }
//         // f_stream.close();
// }

// Test(readReport, test_readReport_closeFile, .signal=SIGPIPE,  .init=redirect_all_stdout) {
//         SickKoala       sickKoala;

//         cr_assert(ne(str, sickKoala.get_name().data(), ""));
//         cr_assert(eq(str, sickKoala.get_name().data(), "SickKoala"));
// //////////////////////////////////////////////////////////////////////////
//         std::string     filename_param = sickKoala.get_name() + ".report";

//         cr_assert(not(zero(str, filename_param)));
//         cr_assert(not(eq(str, filename_param, "")));        
//         cr_assert(ne(str, filename_param.data(), ""));
//         cr_assert(eq(str, filename_param.data(), "SickKoala.report"));
// //////////////////////////////////////////////////////////////////////////
//         int             id = 1;
//         KoalaNurse      koalaNurse(id);

//         cr_assert(id);
//         cr_assert(eq(int, koalaNurse.getID(), 1));
//         cr_assert(eq(int, koalaNurse.getID(), id));
// //////////////////////////////////////////////////////////////////////////
//         std::string     my_line;

//         cr_assert(zero(str, my_line));
//         cr_assert(eq(str, my_line, ""));
//         cr_assert_str_empty(my_line.data());
// //////////////////////////////////////////////////////////////////////////
//         std::string     return_value;

//         cr_assert(zero(str, return_value));
//         cr_assert(eq(str, return_value, ""));
//         cr_assert_str_empty(return_value.data());
// //////////////////////////////////////////////////////////////////////////
//         std::fstream    f_stream;

//         f_stream.open(filename_param.data(), std::ios::in);
//         cr_assert(f_stream.is_open() == true);
// //////////////////////////////////////////////////////////////////////////
//         if (f_stream.is_open()) {
//                 while (std::getline (f_stream, my_line, '\0')) {
//                         std::cout << "Nurse " << koalaNurse.getID() 
//                         << ": Kreog! Mr." << sickKoala.get_name() 
//                         << " needs a " << my_line << "!" << std::endl;
//                         return_value = "Nurse " + std::to_string(koalaNurse.getID()) 
//                         + ": Kreog! Mr." + sickKoala.get_name() + " needs a " + my_line + "!\n";
//                         cr_assert_stdout_eq_str("Nurse 1: Kreog! Mr.SickKoala needs a DRUG!\n");
//                         cr_assert(not(eq(str,return_value, "")));
//                         cr_assert(eq(str, return_value, "Nurse " + std::to_string(koalaNurse.getID()) 
//                         + ": Kreog! Mr." + sickKoala.get_name() + " needs a " + my_line + "!\n"));
//                 }
//         } else {
//                 std::cout << "" << std::flush;
//                 return_value = "";
//                 cr_assert(zero(str, return_value));
//                 cr_assert(eq(str, return_value, ""));
//                 cr_assert_str_empty(return_value.data());
//                 cr_assert_stdout_eq_str("");
//         }
//         f_stream.close();
//         cr_assert(f_stream.is_open() == false);
// }

// Test(readReport, test_readReport_NotCloseFile, .signal=SIGPIPE,  .init=redirect_all_stdout) {
//         SickKoala       sickKoala;

//         cr_assert(ne(str, sickKoala.get_name().data(), ""));
//         cr_assert(eq(str, sickKoala.get_name().data(), "SickKoala"));
// //////////////////////////////////////////////////////////////////////////
//         std::string     filename_param = sickKoala.get_name() + ".report";

//         cr_assert(not(zero(str, filename_param)));
//         cr_assert(not(eq(str, filename_param, "")));        
//         cr_assert(ne(str, filename_param.data(), ""));
//         cr_assert(eq(str, filename_param.data(), "SickKoala.report"));
// //////////////////////////////////////////////////////////////////////////
//         int             id = 1;
//         KoalaNurse      koalaNurse(id);

//         cr_assert(id);
//         cr_assert(eq(int, koalaNurse.getID(), 1));
//         cr_assert(eq(int, koalaNurse.getID(), id));
// //////////////////////////////////////////////////////////////////////////
//         std::string     my_line;

//         cr_assert(zero(str, my_line));
//         cr_assert(eq(str, my_line, ""));
//         cr_assert_str_empty(my_line.data());
// //////////////////////////////////////////////////////////////////////////
//         std::string     return_value;

//         cr_assert(zero(str, return_value));
//         cr_assert(eq(str, return_value, ""));
//         cr_assert_str_empty(return_value.data());
// //////////////////////////////////////////////////////////////////////////
//         std::fstream    f_stream;

//         f_stream.open(filename_param.data(), std::ios::in);
//         cr_assert(f_stream.is_open() == true);
// //////////////////////////////////////////////////////////////////////////
//         if (f_stream.is_open()) {
//                 while (std::getline (f_stream, my_line, '\0')) {
//                         std::cout << "Nurse " << koalaNurse.getID() 
//                         << ": Kreog! Mr." << sickKoala.get_name() 
//                         << " needs a " << my_line << "!" << std::endl;
//                         return_value = "Nurse " + std::to_string(koalaNurse.getID()) 
//                         + ": Kreog! Mr." + sickKoala.get_name() + " needs a " + my_line + "!\n";
//                         cr_assert_stdout_eq_str("Nurse 1: Kreog! Mr.SickKoala needs a DRUG!\n");
//                         cr_assert(not(eq(str,return_value, "")));
//                         cr_assert(eq(str, return_value, "Nurse " + std::to_string(koalaNurse.getID()) 
//                         + ": Kreog! Mr." + sickKoala.get_name() + " needs a " + my_line + "!\n"));
//                 }
//         } else {
//                 std::cout << "" << std::flush;
//                 return_value = "";
//                 cr_assert(zero(str, return_value));
//                 cr_assert(eq(str, return_value, ""));
//                 cr_assert_str_empty(return_value.data());
//                 cr_assert_stdout_eq_str("");
//         }
//         cr_assert(f_stream.is_open() == true);
// }

// Test(readReport, test_readReport, .signal=SIGPIPE,  .init=redirect_all_stdout) {
//         SickKoala       sickKoala;

//         cr_assert(ne(str, sickKoala.get_name().data(), ""));
//         cr_assert(eq(str, sickKoala.get_name().data(), "SickKoala"));
// //////////////////////////////////////////////////////////////////////////
//         std::string     filename_param = sickKoala.get_name() + ".report";

//         cr_assert(not(zero(str, filename_param)));
//         cr_assert(not(eq(str, filename_param, "")));        
//         cr_assert(ne(str, filename_param.data(), ""));
//         cr_assert(eq(str, filename_param.data(), "SickKoala.report"));
// //////////////////////////////////////////////////////////////////////////
//         int             id = 1;
//         KoalaNurse      koalaNurse(id);

//         cr_assert(id);
//         cr_assert(eq(int, koalaNurse.getID(), 1));
//         cr_assert(eq(int, koalaNurse.getID(), id));
// //////////////////////////////////////////////////////////////////////////
//         std::string     my_line;

//         cr_assert(zero(str, my_line));
//         cr_assert(eq(str, my_line, ""));
//         cr_assert_str_empty(my_line.data());
// //////////////////////////////////////////////////////////////////////////
//         std::string     return_value;

//         cr_assert(zero(str, return_value));
//         cr_assert(eq(str, return_value, ""));
//         cr_assert_str_empty(return_value.data());
// //////////////////////////////////////////////////////////////////////////
//         std::fstream    f_stream;

//         f_stream.open(filename_param.data(), std::ios::in);
//         cr_assert(f_stream.is_open() == true);
// //////////////////////////////////////////////////////////////////////////
//         if (f_stream.is_open()) {
//                 while (std::getline (f_stream, my_line, '\0')) {
//                         std::cout << "Nurse " << koalaNurse.getID() 
//                         << ": Kreog! Mr." << sickKoala.get_name() 
//                         << " needs a " << my_line << "!" << std::endl;
//                         return_value = "Nurse " + std::to_string(koalaNurse.getID()) 
//                         + ": Kreog! Mr." + sickKoala.get_name() + " needs a " + my_line + "!\n";
//                         cr_assert_stdout_eq_str("Nurse 1: Kreog! Mr.SickKoala needs a DRUG!\n");
//                         cr_assert(not(eq(str,return_value, "")));
//                         cr_assert(eq(str, return_value, "Nurse " + std::to_string(koalaNurse.getID()) 
//                         + ": Kreog! Mr." + sickKoala.get_name() + " needs a " + my_line + "!\n"));
//                 }
//         } else {
//                 std::cout << "" << std::flush;
//                 return_value = "";
//                 cr_assert(zero(str, return_value));
//                 cr_assert(eq(str, return_value, ""));
//                 cr_assert_str_empty(return_value.data());
//                 cr_assert_stdout_eq_str("");
//         }
//         f_stream.close();
//         cr_assert(f_stream.is_open() == false);
// }

// Test(readReport, test_readReport_memberFunction_with_fileName, .signal=SIGPIPE,  .init=redirect_all_stdout) {

//         int             id = 1;
//         KoalaNurse      koalaNurse(id);
//         std::string     return_value;

//         return_value = koalaNurse.readReport("SickKoala");
//         cr_assert(id);
//         cr_assert(eq(int, koalaNurse.getID(), 1));
//         cr_assert(eq(int, koalaNurse.getID(), id));
//         cr_assert_stdout_eq_str("Nurse 1: Kreog! Mr.SickKoala needs a DRUG!\n");
//         cr_assert(not(eq(str,return_value, "")));
//         cr_assert(eq(str, return_value, "Nurse " + std::to_string(koalaNurse.getID()) 
//                         + ": Kreog! Mr.SickKoala needs a DRUG!\n"));
// }

// Test(readReport, test_readReport_memberFunction_without_fileName, .signal=SIGPIPE,  .init=redirect_all_stdout) {

//         int             id = 1;
//         KoalaNurse      koalaNurse(id);
//         std::string     return_value;

//         return_value = koalaNurse.readReport("");
//         cr_assert(id);
//         cr_assert(eq(int, koalaNurse.getID(), 1));
//         cr_assert(eq(int, koalaNurse.getID(), id));
//         cr_assert_stdout_eq_str("");
//         cr_assert(eq(str,return_value, ""));
// }

// Test(timeCheck, test_timeCheck_nurse_notWorking, .init=redirect_all_stdout) {
//         bool            _isWorking = false;
//         int             id = 1;

//         cr_assert(_isWorking == false);
//         cr_assert(id);
//         cr_assert(eq(int, id, 1));

//         if(_isWorking == true) {
//                 std::cout << "Nurse " << id << ": Time to get to work!" << std::endl;
//                 cr_assert_stdout_eq_str("Nurse 1: Time to get to work!\n");
//         }
//         else {
//                 std::cout << "Nurse " << id << ": Time to go home to my eucalyptus forest!" << std::endl;
//                 cr_assert_stdout_eq_str("Nurse 1: Time to go home to my eucalyptus forest!\n");
//         }
// }

// Test(timeCheck, test_timeCheck_nurse_Working, .init=redirect_all_stdout) {
//         bool            _isWorking = false;
//         int             id = 1;

//         _isWorking = !_isWorking;
//         cr_assert(_isWorking == true);
//         cr_assert(id);
//         cr_assert(eq(int, id, 1));

//         if(_isWorking == true) {
//                 std::cout << "Nurse " << id << ": Time to get to work!" << std::endl;
//                 cr_assert_stdout_eq_str("Nurse 1: Time to get to work!\n");
//         }
//         else {
//                 std::cout << "Nurse " << id << ": Time to go home to my eucalyptus forest!" << std::endl;
//                 cr_assert_stdout_eq_str("Nurse 1: Time to go home to my eucalyptus forest!\n");
//         }
// }

// Test(timeCheck, test_timeCheck_memberFunction_working, .signal=SIGPIPE, .init=redirect_all_stdout) {
//         KoalaNurse      koalaNurse(1);

//         cr_assert(koalaNurse.get_isWorking() == false);
//         koalaNurse.timeCheck();
//         cr_assert(koalaNurse.get_isWorking() == true);
//         cr_assert_stdout_eq_str("Nurse 1: Time to get to work!\n");
// }

// Test(timeCheck, test_timeCheck_memberFunction_NotWorking, .signal=SIGPIPE, .init=redirect_all_stdout) {
//         KoalaNurse      koalaNurse(1);

//         cr_assert(koalaNurse.get_isWorking() == false);
//         koalaNurse.set_isWorking(true);
//         cr_assert(koalaNurse.get_isWorking() == true);
//         koalaNurse.timeCheck();
//         cr_assert(koalaNurse.get_isWorking() == false);
//         cr_assert_stdout_eq_str("Nurse 1: Time to go home to my eucalyptus forest!\n");
// }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// END //


// Test(poke, stdcout_poke_function, .signal=SIGPIPE, .init=redirect_all_stdout) {
//         SickKoala sickKoala("SickKoala");

//         sickKoala.poke();
//         cr_assert_stdout_eq_str("Mr.SickKoala: Gooeeeeerrk!!\n");
// }

// Test(takeDrug, strParameter_eq_MarsStrings_and_stdcout_caught,
//         .init=redirect_all_stdout)
// {
//         std::string     _name("SickKoala");
//         std::string     string = "Mars";
//         std::string     s_mars("Mars");
//         bool            return_value;

//         cr_assert(eq(str,string, s_mars));
//         if (string == s_mars)
//         {
//                 return_value = true;
//                 cr_assert(return_value == true);
//                 std::cout << "Mr." << _name << ": Mars, and it kreogs!" << std::endl;
//                 cr_assert_stdout_eq_str("Mr.SickKoala: Mars, and it kreogs!\n");

//         }


// }

// Test(takeDrug, strParameter_notEq_MarsStrings_and_stdcout_caught,
//         .init=redirect_all_stdout)
// {
//         std::string     _name("SickKoala");
//         std::string     string = "Buronzand";
//         std::string     s_mars("Mars");
//         bool            return_value;

//         cr_assert(not(eq(str,string, s_mars)));
//         if (string == s_mars)
//         {
//                 return_value = true;
//                 cr_assert(return_value == true);
//                 std::cout << "Mr." << _name << ": Mars, and it kreogs!" << std::endl;
//                 cr_assert_stdout_eq_str("Mr.SickKoala: Mars, and it kreogs!\n");

//         } else
//         {
//                 return_value = false;
//                 cr_assert(return_value == false);
//                 std::cout << "Mr." << _name << ": Goerkreog!" << std::endl;
//                 cr_assert_stdout_eq_str("Mr.SickKoala: Goerkreog!\n");                
//         }
// }

// Test(takeDrug, strParameter_eq_BuronzandStrings_and_stdcout_caught,
//         .init=redirect_all_stdout)
// {
//         std::string     _name("SickKoala");
//         std::string     string = "Buronzand";
//         std::string     s_buronzand("Buronzand");
//         bool            return_value;

//         cr_assert(eq(str,string, s_buronzand));
//         if (string == s_buronzand)
//         {
//                 return_value = true;
//                 cr_assert(return_value == true);
//                 std::cout << "Mr." << _name << ": And you'll sleep right away!" << std::endl;
//                 cr_assert_stdout_eq_str("Mr.SickKoala: And you'll sleep right away!\n");

//         } else {
//                 cr_log_error("FAIL");
//                 cr_fail();

//         }
// }

// Test(takeDrug, strParameter_notEq_BuronzandStrings_and_stdcout_caught,
//         .init=redirect_all_stdout)
// {
//         std::string     _name("SickKoala");
//         std::string     string = "BuronzanD";
//         std::string     s_buronzand("Buronzand");
//         bool            return_value;

//         cr_assert(not(eq(str,string, s_buronzand)));
//         if (string == s_buronzand)
//         {
//                 return_value = true;
//                 cr_assert(return_value == true);
//                 std::cout << "Mr." << _name << ": And you'll sleep right away!" << std::endl;
//                 cr_assert_stdout_eq_str("Mr.SickKoala: : And you'll sleep right away!\n");

//         } else {
//                 return_value = false;
//                 cr_assert(return_value == false);
//                 std::cout << "Mr." << _name << ": Goerkreog!" << std::endl;
//                 cr_assert_stdout_eq_str("Mr.SickKoala: Goerkreog!\n");
//         }
// }

// Test(takeDrug, strParameter_notEq_strings_and_stdcout_caught2,
//         .init=redirect_all_stdout)
// {
//         std::string     _name("SickKoala");
//         std::string     string = "randomString";
//         std::string     s_buronzand("Buronzand");
//         std::string     s_mars("Mars");
//         bool            return_value;

//         cr_assert(not(eq(str,string, s_buronzand)));
//         cr_assert(not(eq(str,string, s_mars)));
//         if (string == s_buronzand )
//         {
//                 return_value = true;
//                 cr_assert(return_value == true);
//                 std::cout << "Mr." << _name << ": And you'll sleep right away!" << std::endl;
//                 cr_assert_stdout_eq_str("Mr.SickKoala: And you'll sleep right away!\n");
//         } else if (string == s_mars)
//         {
//                 return_value = true;
//                 cr_assert(return_value == true);
//                 std::cout << "Mr." << _name << ": Mars, and it kreogs!" << std::endl;
//                 cr_assert_stdout_eq_str("Mr.SickKoala: Mars, and it kreogs!\n");
//         } else
//         {
//                 return_value = false;
//                 cr_assert(return_value == false);
//                 std::cout << "Mr." << _name << ": Goerkreog!" << std::endl;
//                 cr_assert_stdout_eq_str("Mr.SickKoala: Goerkreog!\n");
//         }
// }

// Test(takeDrug, takeDrug_randomString, .signal=SIGPIPE,
//         .init=redirect_all_stdout)
// {
//         SickKoala sickKoala;

//         cr_assert(sickKoala.takeDrug("random") == false);
//         cr_assert_stdout_eq_str("Mr.SickKoala: Goerkreog!\n");
// }

// Test(takeDrug, takeDrug_marsString, .signal=SIGPIPE,
//         .init=redirect_all_stdout)
// {
//         SickKoala sickKoala;

//         cr_assert(sickKoala.takeDrug("Mars") == true);
//         cr_assert_stdout_eq_str("Mr.SickKoala: Mars, and it kreogs!\n");
// }

// Test(takeDrug, takeDrug_buronzandString, .signal=SIGPIPE,
//         .init=redirect_all_stdout)
// {
//         SickKoala sickKoala;
        
//         cr_assert(sickKoala.takeDrug("Buronzand") == true);
//         cr_assert_stdout_eq_str("Mr.SickKoala: And you'll sleep right away!\n");
// }

// Test(overDrive, strParameter_test)
// {
//         SickKoala sickKoala;
//         std::string instance;

//         cr_assert(zero(str, instance));
//         cr_assert(eq(str, instance, ""));
//         cr_assert_str_empty(instance.data());
//         instance = "Kreog! How's it going?";
//         cr_assert(not(zero(str, instance)));
//         cr_assert(not(eq(str, instance, "")));
//         cr_assert(eq(str, instance, "Kreog! How's it going?"));
//         cr_assert(ne(str, sickKoala.get_name().data(), ""));
//         cr_assert(eq(str, sickKoala.get_name().data(), "SickKoala"));
// }

// Test(overDrive, find_and_replace_test)
// {
//         SickKoala sickKoala;
//         std::string instance;

//         cr_assert(zero(str, instance));
//         cr_assert(eq(str, instance, ""));
//         cr_assert_str_empty(instance.data());
//         instance = "Kreog! How's it going?";
//         cr_assert(not(zero(str, instance)));
//         cr_assert(not(eq(str, instance, "")));
//         cr_assert(eq(str, instance, "Kreog! How's it going?"));
//         cr_assert(ne(str, sickKoala.get_name().data(), ""));
//         cr_assert(eq(str, sickKoala.get_name().data(), "SickKoala"));
//         instance.replace(instance.find("Kreog!"), sizeof(instance.find("Kreog!")) - 2, "1337!");
// }

// Test(overDrive, stdout_test, .signal=SIGPIPE, .init=redirect_all_stdout)
// {
//         SickKoala sickKoala;
//         std::string instance;

//         cr_assert(zero(str, instance));
//         cr_assert(eq(str, instance, ""));
//         cr_assert_str_empty(instance.data());
//         instance = "Kreog! How's it going?";
//         cr_assert(not(zero(str, instance)));
//         cr_assert(not(eq(str, instance, "")));
//         cr_assert(eq(str, instance, "Kreog! How's it going?"));
//         cr_assert(ne(str, sickKoala.get_name().data(), ""));
//         cr_assert(eq(str, sickKoala.get_name().data(), "SickKoala"));
//         instance.replace(instance.find("Kreog!"), sizeof(instance.find("Kreog!")) - 2, "1337!");
//         std::cout << "Mr." << sickKoala.get_name() << ": " << instance << std::endl << std::flush;
//         cr_assert_stdout_eq_str("Mr.SickKoala: 1337! How's it going?\n");
// }

// Test(overDrive, test_overDrive_memberFunction,
//         .signal=SIGPIPE, .init=redirect_all_stdout)
// {
//         SickKoala sickKoala;

//         sickKoala.overDrive("Kreog! How's it going?");
//         cr_assert_stdout_eq_str("Mr.SickKoala: 1337! How's it going?\n");
// }