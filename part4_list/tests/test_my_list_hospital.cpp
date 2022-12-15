#include "../includes/my_list_hospital.hpp"
#include "../../part3_doctor/includes/my_doctor_hospital.hpp"
#include "../../part2_nurse/includes/my_nurse_hospital.hpp"
#include "../../part1_patient/includes/my_patient_hospital.hpp"
#include "./tests_includes/test_my_list_hospital.hpp"



///////////////////////////////////////////////////////////////////////////////

Test(SickKoalaList, test_ctor_init_params) {
        SickKoala               cancer;
        SickKoalaList           sick1(&cancer);

        cr_assert(not(zero(ptr,sick1.getContent())));
        cr_assert_eq(sick1.getContent(), &cancer);
        cr_assert(zero(ptr,sick1.getNext()));
        cr_assert_eq(sick1.getNext(), nullptr);
}

Test(SickKoalaList, test_isEnd) {
        SickKoala               cancer;
        SickKoalaList           sick1(&cancer);
        bool                    return_value;

        cr_assert(not(zero(ptr,sick1.getContent())));
        cr_assert_eq(sick1.getContent(), &cancer);
        cr_assert(zero(ptr,sick1.getNext()));
        cr_assert_eq(sick1.getNext(), nullptr);

        if(sick1.getNext() == nullptr)
        {
                return_value = true;
                cr_assert(return_value == true);
        }
        sick1.setNext(&sick1);
        if(sick1.getNext() != nullptr)
        {
                return_value = false;
                cr_assert(return_value == false);
        }
}

Test(SickKoalaList, test_isEnd_memberFunction) {
        SickKoala               cancer;
        SickKoalaList           sick1(&cancer);

        cr_assert(not(zero(ptr,sick1.getContent())));
        cr_assert_eq(sick1.getContent(), &cancer);
        cr_assert(zero(ptr,sick1.getNext()));
        cr_assert_eq(sick1.getNext(), nullptr);

        cr_assert(sick1.isEnd() == true);
        sick1.setNext(&sick1);
        cr_assert(sick1.isEnd() == false);
}



// SickKoala *SickKoalaList::getFromName(std::string name) {
//   if (this->_content && this->_content->get_name().compare(name) == 0)
//     return this->_content;
//   else if (this->_next)
//     return this->_next->getFromName(name);
//   return NULL;

// //   SickKoalaList *tmp;

// //   tmp = this;
// //   while (tmp != NULL && ((tmp->_content != NULL && tmp->_content->get_name() != name) || tmp->_content == NULL))
// //     tmp = tmp->_next;
// //   return (tmp != NULL && tmp->_content != NULL ? tmp->_content : NULL);
// }


    void SickKoalaList::dump() {
      SickKoalaList* temp = getThis();
        std::cout<<"Patients : ";
        while(temp) {
            std::cout << temp->_content->get_name() <<" ";
                    temp = temp->_next;
        }
        std::cout<<std::endl;
    }


Test(SickKoalaList, test_append, .signal=SIGPIPE, .init=redirect_all_stdout) { //avoid signal

        cr_log_warn("Start Test APPEND : This test is not complete");

        SickKoala k1("Hibiki");
        cr_assert(not(zero(ptr,&k1)));
        cr_assert(not(zero(str,k1.get_name())));
        cr_assert_eq(k1.get_name(), "Hibiki");

        SickKoala k2("Satsuki");
        cr_assert(not(zero(ptr,&k2)));
        cr_assert(not(zero(str,k2.get_name())));
        cr_assert_eq(k2.get_name(), "Satsuki");

        SickKoala k3("Hibana");
        cr_assert(not(zero(ptr,&k3)));
        cr_assert(not(zero(str,k3.get_name())));
        cr_assert_eq(k3.get_name(), "Hibana");

        SickKoala k4("Sayori");
        cr_assert(not(zero(ptr,&k4)));
        cr_assert(not(zero(str,k4.get_name())));
        cr_assert_eq(k4.get_name(), "Sayori");

        SickKoala k5("Hanaki");
        cr_assert(not(zero(ptr,&k5)));
        cr_assert(not(zero(str,k5.get_name())));
        cr_assert_eq(k5.get_name(), "Hanaki");

        SickKoalaList sick1(&k1);
        cr_assert(not(zero(ptr,&sick1)));
        cr_assert(not(zero(ptr, sick1.getContent())));
        cr_assert(zero(ptr, sick1.getNext()));
        cr_assert_eq(sick1.getContent(), &k1);

        SickKoalaList sick2(&k2);
        cr_assert(not(zero(ptr,&sick2)));
        cr_assert(not(zero(ptr, sick2.getContent())));
        cr_assert(zero(ptr, sick2.getNext()));
        cr_assert_eq(sick2.getContent(), &k2);

        SickKoalaList sick3(&k3);
        cr_assert(not(zero(ptr,&sick3)));
        cr_assert(not(zero(ptr, sick3.getContent())));
        cr_assert(zero(ptr, sick3.getNext()));
        cr_assert_eq(sick3.getContent(), &k3);

        SickKoalaList sick4(&k4);
        cr_assert(not(zero(ptr,&sick4)));
        cr_assert(not(zero(ptr, sick4.getContent())));
        cr_assert(zero(ptr, sick4.getNext()));
        cr_assert_eq(sick4.getContent(), &k4);

        SickKoalaList sick5(&k5);
        cr_assert(not(zero(ptr,&sick5)));
        cr_assert(not(zero(ptr, sick5.getContent())));
        cr_assert(zero(ptr, sick5.getNext()));
        cr_assert_eq(sick5.getContent(), &k5);

        sick1.append(&sick2);
        cr_assert(not(zero(ptr, sick1.getNext())));

        sick1.append(&sick3);
        cr_assert(not(zero(ptr, sick1.getNext())));

        sick1.append(&sick4);
        cr_assert(not(zero(ptr, sick1.getNext())));

        sick1.append(&sick5);
        cr_assert(not(zero(ptr, sick1.getNext())));

        sick1.dump();
        cr_assert_stdout_eq_str("Patients : Hibiki Satsuki Hibana Sayori Hanaki \n");
}

Test(SickKoalaList, test_getFromName, .signal=SIGPIPE, .init=redirect_all_stdout) 
{
        SickKoala k1("Hibiki");
        cr_assert(not(zero(ptr,&k1)));
        cr_assert(not(zero(str,k1.get_name())));
        cr_assert_eq(k1.get_name(), "Hibiki");

        SickKoala k2("Satsuki");
        cr_assert(not(zero(ptr,&k2)));
        cr_assert(not(zero(str,k2.get_name())));
        cr_assert_eq(k2.get_name(), "Satsuki");

        SickKoala k3("Hibana");
        cr_assert(not(zero(ptr,&k3)));
        cr_assert(not(zero(str,k3.get_name())));
        cr_assert_eq(k3.get_name(), "Hibana");

        SickKoala k4("Sayori");
        cr_assert(not(zero(ptr,&k4)));
        cr_assert(not(zero(str,k4.get_name())));
        cr_assert_eq(k4.get_name(), "Sayori");

        SickKoala k5("Hanaki");
        cr_assert(not(zero(ptr,&k5)));
        cr_assert(not(zero(str,k5.get_name())));
        cr_assert_eq(k5.get_name(), "Hanaki");

        SickKoalaList sick1(&k1);
        cr_assert(not(zero(ptr,&sick1)));
        cr_assert(not(zero(ptr, sick1.getContent())));
        cr_assert(zero(ptr, sick1.getNext()));
        cr_assert_eq(sick1.getContent(), &k1);

        SickKoalaList sick2(&k2);
        cr_assert(not(zero(ptr,&sick2)));
        cr_assert(not(zero(ptr, sick2.getContent())));
        cr_assert(zero(ptr, sick2.getNext()));
        cr_assert_eq(sick2.getContent(), &k2);

        SickKoalaList sick3(&k3);
        cr_assert(not(zero(ptr,&sick3)));
        cr_assert(not(zero(ptr, sick3.getContent())));
        cr_assert(zero(ptr, sick3.getNext()));
        cr_assert_eq(sick3.getContent(), &k3);

        SickKoalaList sick4(&k4);
        cr_assert(not(zero(ptr,&sick4)));
        cr_assert(not(zero(ptr, sick4.getContent())));
        cr_assert(zero(ptr, sick4.getNext()));
        cr_assert_eq(sick4.getContent(), &k4);

        SickKoalaList sick5(&k5);
        cr_assert(not(zero(ptr,&sick5)));
        cr_assert(not(zero(ptr, sick5.getContent())));
        cr_assert(zero(ptr, sick5.getNext()));
        cr_assert_eq(sick5.getContent(), &k5);

        sick1.append(&sick2);
        cr_assert(not(zero(ptr, sick1.getNext())));

        sick1.append(&sick3);
        cr_assert(not(zero(ptr, sick1.getNext())));

        sick1.append(&sick4);
        cr_assert(not(zero(ptr, sick1.getNext())));

        sick1.append(&sick5);
        cr_assert(not(zero(ptr, sick1.getNext())));

        // sick1.dump();

	SickKoala *koala = sick1.getFromName("Sayori");

	if (koala == nullptr)
                std::cout << "ERROR nullptr" << std::endl;
        else if (koala->get_name().compare("Sayori") == 0)
        {
                cr_assert(koala != nullptr);
                cr_assert(koala->get_name() == "Sayori");
		std::cout << "Sayori founded" << std::endl;
        }
	else
		std::cout << "ERROR " << koala->get_name() << " found instead of Sayori" << std::endl;
        cr_assert_stdout_eq_str("Sayori founded\n");
}


SickKoalaList *SickKoalaList::remove(SickKoalaList *newElement)
{
    // SickKoalaList* cur, * prev;
    // if (newElement == NULL)
    //     return newElement;
    
    // if (newElement->_content) {
    //     cur = newElement->_next;
    //     // delete newElement;
    //     newElement = cur;
    //     return newElement; //nullptr
    // }
    // cur = newElement;
    // prev = NULL;
    // while ( cur != NULL && cur->_content != NULL ) {
    //     prev = cur;
    //     cur = cur->_next;
    // }
    // if (cur == NULL) {
    //     return newElement;
    // }
    // prev->_next = cur->_next;
    // delete cur;
    // return newElement;

    // else call the recursive method
 ////////////////////////////////////////////////////////////////////

// OK
  SickKoalaList* prev = this;
  SickKoalaList* current = this; //this

  while (current != nullptr) {
    if (current->_content == newElement->_content) {

      if(current == this){
        //   this->_next;
          delete current;
          current = this->_next;
        }
      else{
        prev->_next = current->_next;
        delete current;
        current = prev->_next;
      }
    }
   else{ 
      prev = current;
      current = current->_next;
     }
  }

  // key not found in list
  if (current == nullptr) {
    return nullptr; //this
  }
  
  return nullptr; //this
}

Test(SickKoalaList, test_remove,) // .signal=SIGPIPE, .init=redirect_all_stdout
{
        SickKoala k1("Hibiki");
        cr_assert(not(zero(ptr,&k1)));
        cr_assert(not(zero(str,k1.get_name())));
        cr_assert_eq(k1.get_name(), "Hibiki");

        SickKoala k2("Satsuki");
        cr_assert(not(zero(ptr,&k2)));
        cr_assert(not(zero(str,k2.get_name())));
        cr_assert_eq(k2.get_name(), "Satsuki");

        SickKoala k3("Hibana");
        cr_assert(not(zero(ptr,&k3)));
        cr_assert(not(zero(str,k3.get_name())));
        cr_assert_eq(k3.get_name(), "Hibana");

        SickKoala k4("Sayori");
        cr_assert(not(zero(ptr,&k4)));
        cr_assert(not(zero(str,k4.get_name())));
        cr_assert_eq(k4.get_name(), "Sayori");

        SickKoala k5("Hanaki");
        cr_assert(not(zero(ptr,&k5)));
        cr_assert(not(zero(str,k5.get_name())));
        cr_assert_eq(k5.get_name(), "Hanaki");

        SickKoalaList sick1(&k1);
        cr_assert(not(zero(ptr,&sick1)));
        cr_assert(not(zero(ptr, sick1.getContent())));
        cr_assert(zero(ptr, sick1.getNext()));
        cr_assert_eq(sick1.getContent(), &k1);

        SickKoalaList sick2(&k2);
        cr_assert(not(zero(ptr,&sick2)));
        cr_assert(not(zero(ptr, sick2.getContent())));
        cr_assert(zero(ptr, sick2.getNext()));
        cr_assert_eq(sick2.getContent(), &k2);

        SickKoalaList sick3(&k3);
        cr_assert(not(zero(ptr,&sick3)));
        cr_assert(not(zero(ptr, sick3.getContent())));
        cr_assert(zero(ptr, sick3.getNext()));
        cr_assert_eq(sick3.getContent(), &k3);

        SickKoalaList sick4(&k4);
        cr_assert(not(zero(ptr,&sick4)));
        cr_assert(not(zero(ptr, sick4.getContent())));
        cr_assert(zero(ptr, sick4.getNext()));
        cr_assert_eq(sick4.getContent(), &k4);

        SickKoalaList sick5(&k5);
        cr_assert(not(zero(ptr,&sick5)));
        cr_assert(not(zero(ptr, sick5.getContent())));
        cr_assert(zero(ptr, sick5.getNext()));
        cr_assert_eq(sick5.getContent(), &k5);

        sick1.append(&sick2);
        cr_assert(not(zero(ptr, sick1.getNext())));

        sick1.append(&sick3);
        cr_assert(not(zero(ptr, sick1.getNext())));

        sick1.append(&sick4);
        cr_assert(not(zero(ptr, sick1.getNext())));

        sick1.append(&sick5);
        cr_assert(not(zero(ptr, sick1.getNext())));

        // sick1.dump();

	SickKoala *koala = sick1.getFromName("Sayori");
	if (koala == nullptr)
                std::cout << "ERROR nullptr" << std::endl;
        else if (koala->get_name().compare("Sayori") == 0)
        {
                cr_assert(koala != nullptr);
                cr_assert(koala->get_name() == "Sayori");
		std::cout << "Sayori founded" << std::endl;
        }
	else
		std::cout << "ERROR " << koala->get_name() << " found instead of Sayori" << std::endl;
        sick1.remove(&sick4);
        sick1.dump();

        koala = sick1.getFromName("Sayori");
	if (koala == nullptr){
                std::cout << "ERROR nullptr" << std::endl;
                cr_assert(koala == nullptr);
        }
        else if (koala->get_name().compare("Sayori") == 0)
        {
                cr_assert(koala != nullptr);
                cr_assert(koala->get_name() == "Sayori");
		std::cout << "Sayori founded2" << std::endl;
        }
	else
		std::cout << "ERROR " << koala->get_name() << " found instead of Sayori" << std::endl;
}

// Test(SickKoalaList, test_removeFromName,) // .signal=SIGPIPE, .init=redirect_all_stdout
// {
//         SickKoala k1("Hibiki");
//         cr_assert(not(zero(ptr,&k1)));
//         cr_assert(not(zero(str,k1.get_name())));
//         cr_assert_eq(k1.get_name(), "Hibiki");

//         SickKoala k2("Satsuki");
//         cr_assert(not(zero(ptr,&k2)));
//         cr_assert(not(zero(str,k2.get_name())));
//         cr_assert_eq(k2.get_name(), "Satsuki");

//         SickKoala k3("Hibana");
//         cr_assert(not(zero(ptr,&k3)));
//         cr_assert(not(zero(str,k3.get_name())));
//         cr_assert_eq(k3.get_name(), "Hibana");

//         SickKoala k4("Sayori");
//         cr_assert(not(zero(ptr,&k4)));
//         cr_assert(not(zero(str,k4.get_name())));
//         cr_assert_eq(k4.get_name(), "Sayori");

//         SickKoala k5("Hanaki");
//         cr_assert(not(zero(ptr,&k5)));
//         cr_assert(not(zero(str,k5.get_name())));
//         cr_assert_eq(k5.get_name(), "Hanaki");

//         SickKoalaList sick1(&k1);
//         cr_assert(not(zero(ptr,&sick1)));
//         cr_assert(not(zero(ptr, sick1.getContent())));
//         cr_assert(zero(ptr, sick1.getNext()));
//         cr_assert_eq(sick1.getContent(), &k1);

//         SickKoalaList sick2(&k2);
//         cr_assert(not(zero(ptr,&sick2)));
//         cr_assert(not(zero(ptr, sick2.getContent())));
//         cr_assert(zero(ptr, sick2.getNext()));
//         cr_assert_eq(sick2.getContent(), &k2);

//         SickKoalaList sick3(&k3);
//         cr_assert(not(zero(ptr,&sick3)));
//         cr_assert(not(zero(ptr, sick3.getContent())));
//         cr_assert(zero(ptr, sick3.getNext()));
//         cr_assert_eq(sick3.getContent(), &k3);

//         SickKoalaList sick4(&k4);
//         cr_assert(not(zero(ptr,&sick4)));
//         cr_assert(not(zero(ptr, sick4.getContent())));
//         cr_assert(zero(ptr, sick4.getNext()));
//         cr_assert_eq(sick4.getContent(), &k4);

//         SickKoalaList sick5(&k5);
//         cr_assert(not(zero(ptr,&sick5)));
//         cr_assert(not(zero(ptr, sick5.getContent())));
//         cr_assert(zero(ptr, sick5.getNext()));
//         cr_assert_eq(sick5.getContent(), &k5);

//         sick1.append(&sick2);
//         cr_assert(not(zero(ptr, sick1.getNext())));

//         sick1.append(&sick3);
//         cr_assert(not(zero(ptr, sick1.getNext())));

//         sick1.append(&sick4);
//         cr_assert(not(zero(ptr, sick1.getNext())));

//         sick1.append(&sick5);
//         cr_assert(not(zero(ptr, sick1.getNext())));

//         // sick1.dump();

// 	SickKoala *koala = sick1.getFromName("Sayori");
// 	if (koala == nullptr)
//                 std::cout << "ERROR nullptr" << std::endl;
//         else if (koala->get_name().compare("Sayori") == 0)
//         {
//                 cr_assert(koala != nullptr);
//                 cr_assert(koala->get_name() == "Sayori");
// 		std::cout << "Sayori founded" << std::endl;
//         }
// 	else
// 		std::cout << "ERROR " << koala->get_name() << " found instead of Sayori" << std::endl;
//         sick1.remove(&sick4);
//         sick1.dump();

//         koala = sick1.getFromName("Sayori");
// 	if (koala == nullptr){
//                 std::cout << "ERROR nullptr" << std::endl;
//                 cr_assert(koala == nullptr);
//         }
//         else if (koala->get_name().compare("Sayori") == 0)
//         {
//                 cr_assert(koala != nullptr);
//                 cr_assert(koala->get_name() == "Sayori");
// 		std::cout << "Sayori founded2" << std::endl;
//         }
// 	else
// 		std::cout << "ERROR " << koala->get_name() << " found instead of Sayori" << std::endl;

//         sick1.removeFromName("Sayori");
// 	if (koala == nullptr){
//                 std::cout << "ERROR nullptr" << std::endl;
//                 cr_assert(koala == nullptr);
//         }
//         else if (koala->get_name().compare("Sayori") == 0)
//         {
//                 cr_assert(koala != nullptr);
//                 cr_assert(koala->get_name() == "Sayori");
// 		std::cout << "Sayori founded2" << std::endl;
//         }
// 	else
// 		std::cout << "ERROR " << koala->get_name() << " found instead of Sayori" << std::endl;
//         // cr_assert_stdout_eq_str("Sayori founded\n");
// }

///////////////////////////////////////////////////////////////////////////////
// Test(KoalaDoctor, test_ctor_stdout, .init=redirect_all_stdout) {
//     KoalaDoctor     cox("Cox");

//     cr_assert_stdout_eq_str("Dr.Cox: I'm Dr.Cox! How do you kreog?\n");
// }

// Test(KoalaDoctor, test_getName) {
//     KoalaDoctor     cox("Cox");

//     cr_assert(not(zero(str, cox.getName())));
//     cr_assert(not(eq(str, cox.getName(), "")));
//     cr_assert(eq(str, cox.getName(), "Cox"));
// }

// Test(KoalaDoctor, test_diagnose_parameters,.init=redirect_all_stdout)//, .signal=SIGPIPE, .init=redirect_all_stdout)
// {
//     KoalaDoctor     cox("Cox");
//     cr_assert_stdout_eq_str("Dr.Cox: I'm Dr.Cox! How do you kreog?\n");
// ///////////////////////////////////////////////////////////////////////
//     SickKoala       *sickKoala = new SickKoala;
//     std::string     name;
//     cr_assert(zero(str, name));
//     cr_assert(eq(str, name, ""));
//     cr_assert_str_empty(name.data());
//     cr_assert(ne(str, sickKoala->get_name().data(), ""));
//     cr_assert(eq(str, sickKoala->get_name().data(), "SickKoala"));
// //////////////////////////////////////////////////////////////////////
//     std::string     file_nameReport = sickKoala->get_name() + ".report";
//     cr_assert(not(zero(str, file_nameReport)));
//     cr_assert(not(eq(str, file_nameReport, "")));        
//     cr_assert(ne(str, file_nameReport.data(), ""));
//     cr_assert(eq(str, file_nameReport.data(), "SickKoala.report"));
// //////////////////////////////////////////////////////////////////////
//     std::ofstream   file_drReport;

//     file_drReport.open(file_nameReport.data());
//     cr_assert(file_drReport.is_open() == true);
//     file_drReport.close();
//     cr_assert(file_drReport.is_open() == false);
// /////////////////////////////////////////////////////////////////////
//     std::string     drug[5] = {"Mars", "Buronzand", "Viagra", "Extasy", "Eucalyptus leaf"};
//     std::string     drug2[5] = {"Mars", "Buronzand", "Viagra", "Extasy", "Eucalyptus leaf"};

//     cr_assert(eq(str[5], drug, drug2));
// //////////////////////////////////////////////////////////////////////
//     long            number_random = random() % 5;
//     cr_assert(number_random != 0);
//     cr_assert(number_random == 3);


//     // std::cout << "Dr." << cox.getName() 
//     // << ": So what's goerking you Mr." 
//     // << sickKoala->get_name() << "?" << std::endl;
//     // sickKoala->poke();

//     // file_drReport.open(file_nameReport);
//     // file_drReport << drug[number_random];
//     // file_drReport.close();
//     // cr_assert_stdout_eq_str("Dr.Cox: I'm Dr.Cox! How do you kreog?\nDr.Cox: So what's goerking you Mr.SickKoala?\nMr.SickKoala: Gooeeeeerrk!!\n");



//     // std::cout << "Dr." << cox.getName() 
//     // << ": So what's goerking you Mr." 
//     // << sickKoala->get_name() << "?" << std::endl;
//     // sickKoala->poke();

//     // file_nameReport = sickKoala->get_name() + ".report";
//     // file_drReport.open(file_nameReport);
//     // file_drReport << drug[number_random];
//     // file_drReport.close();
//     // cr_assert_stdout_eq_str("Dr.Cox: I'm Dr.Cox! How do you kreog?\nDr.Cox: So what's goerking you Mr.SickKoala?\nMr.SickKoala: Gooeeeeerrk!!\n");
// }

// Test(KoalaDoctor, test_diagnose_KoalaDoctor_stdout,.init=redirect_all_stdout)//, .signal=SIGPIPE, .init=redirect_all_stdout)
// {
//     KoalaDoctor     cox("Cox");
// ///////////////////////////////////////////////////////////////////////
//     SickKoala       *sickKoala = new SickKoala;
//     std::string     name;
//     cr_assert(zero(str, name));
//     cr_assert(eq(str, name, ""));
//     cr_assert_str_empty(name.data());
//     cr_assert(ne(str, sickKoala->get_name().data(), ""));
//     cr_assert(eq(str, sickKoala->get_name().data(), "SickKoala"));
// //////////////////////////////////////////////////////////////////////
//     std::string     file_nameReport = sickKoala->get_name() + ".report";
//     cr_assert(not(zero(str, file_nameReport)));
//     cr_assert(not(eq(str, file_nameReport, "")));        
//     cr_assert(ne(str, file_nameReport.data(), ""));
//     cr_assert(eq(str, file_nameReport.data(), "SickKoala.report"));
// //////////////////////////////////////////////////////////////////////
//     std::ofstream   file_drReport;

//     file_drReport.open(file_nameReport.data());
//     cr_assert(file_drReport.is_open() == true);
//     file_drReport.close();
//     cr_assert(file_drReport.is_open() == false);
// /////////////////////////////////////////////////////////////////////
//     std::string     drug[5] = {"Mars", "Buronzand", "Viagra", "Extasy", "Eucalyptus leaf"};
//     std::string     drug2[5] = {"Mars", "Buronzand", "Viagra", "Extasy", "Eucalyptus leaf"};

//     cr_assert(eq(str[5], drug, drug2));
// //////////////////////////////////////////////////////////////////////
//     long            number_random = random() % 5;
//     cr_assert(number_random != 0);
//     cr_assert(number_random == 3);
// //////////////////////////////////////////////////////////////////////
//     std::cout << "Dr." << cox.getName() 
//     << ": So what's goerking you Mr." 
//     << sickKoala->get_name() << "?" << std::endl;
//     cr_assert_stdout_eq_str("Dr.Cox: I'm Dr.Cox! How do you kreog?\nDr.Cox: So what's goerking you Mr.SickKoala?\n");
// //////////////////////////////////////////////////////////////////////
//     // sickKoala->poke();

//     // file_drReport.open(file_nameReport);
//     // file_drReport << drug[number_random];
//     // file_drReport.close();
//     // cr_assert_stdout_eq_str("Dr.Cox: I'm Dr.Cox! How do you kreog?\nDr.Cox: So what's goerking you Mr.SickKoala?\nMr.SickKoala: Gooeeeeerrk!!\n");



//     // std::cout << "Dr." << cox.getName() 
//     // << ": So what's goerking you Mr." 
//     // << sickKoala->get_name() << "?" << std::endl;
//     // sickKoala->poke();

//     // file_nameReport = sickKoala->get_name() + ".report";
//     // file_drReport.open(file_nameReport);
//     // file_drReport << drug[number_random];
//     // file_drReport.close();
//     // cr_assert_stdout_eq_str("Dr.Cox: I'm Dr.Cox! How do you kreog?\nDr.Cox: So what's goerking you Mr.SickKoala?\nMr.SickKoala: Gooeeeeerrk!!\n");
// }

// Test(KoalaDoctor, test_diagnose_Sickkoala_poke_memberFunction,.init=redirect_all_stdout)//, .signal=SIGPIPE, .init=redirect_all_stdout)
// {
//     KoalaDoctor     cox("Cox");
// ///////////////////////////////////////////////////////////////////////
//     SickKoala       *sickKoala = new SickKoala;
//     std::string     name;
//     cr_assert(zero(str, name));
//     cr_assert(eq(str, name, ""));
//     cr_assert_str_empty(name.data());
//     cr_assert(ne(str, sickKoala->get_name().data(), ""));
//     cr_assert(eq(str, sickKoala->get_name().data(), "SickKoala"));
// //////////////////////////////////////////////////////////////////////
//     std::string     file_nameReport = sickKoala->get_name() + ".report";
//     cr_assert(not(zero(str, file_nameReport)));
//     cr_assert(not(eq(str, file_nameReport, "")));        
//     cr_assert(ne(str, file_nameReport.data(), ""));
//     cr_assert(eq(str, file_nameReport.data(), "SickKoala.report"));
// //////////////////////////////////////////////////////////////////////
//     std::ofstream   file_drReport;

//     file_drReport.open(file_nameReport.data());
//     cr_assert(file_drReport.is_open() == true);
//     file_drReport.close();
//     cr_assert(file_drReport.is_open() == false);
// /////////////////////////////////////////////////////////////////////
//     std::string     drug[5] = {"Mars", "Buronzand", "Viagra", "Extasy", "Eucalyptus leaf"};
//     std::string     drug2[5] = {"Mars", "Buronzand", "Viagra", "Extasy", "Eucalyptus leaf"};

//     cr_assert(eq(str[5], drug, drug2));
// //////////////////////////////////////////////////////////////////////
//     long            number_random = random() % 5;
//     cr_assert(number_random != 0);
//     cr_assert(number_random == 3);
// //////////////////////////////////////////////////////////////////////
//     std::cout << "Dr." << cox.getName() 
//     << ": So what's goerking you Mr." 
//     << sickKoala->get_name() << "?" << std::endl;
// //////////////////////////////////////////////////////////////////////
//     sickKoala->poke();
//     cr_assert_stdout_eq_str("Dr.Cox: I'm Dr.Cox! How do you kreog?\nDr.Cox: So what's goerking you Mr.SickKoala?\nMr.SickKoala: Gooeeeeerrk!!\n");
// //////////////////////////////////////////////////////////////////////
//     // file_drReport.open(file_nameReport);
//     // file_drReport << drug[number_random];
//     // file_drReport.close();
//     // cr_assert_stdout_eq_str("Dr.Cox: I'm Dr.Cox! How do you kreog?\nDr.Cox: So what's goerking you Mr.SickKoala?\nMr.SickKoala: Gooeeeeerrk!!\n");



//     // std::cout << "Dr." << cox.getName() 
//     // << ": So what's goerking you Mr." 
//     // << sickKoala->get_name() << "?" << std::endl;
//     // sickKoala->poke();

//     // file_nameReport = sickKoala->get_name() + ".report";
//     // file_drReport.open(file_nameReport);
//     // file_drReport << drug[number_random];
//     // file_drReport.close();
//     // cr_assert_stdout_eq_str("Dr.Cox: I'm Dr.Cox! How do you kreog?\nDr.Cox: So what's goerking you Mr.SickKoala?\nMr.SickKoala: Gooeeeeerrk!!\n");
// }

// Test(KoalaDoctor, test_diagnose_writeReport, .init=redirect_all_stdout)//, .signal=SIGPIPE, .init=redirect_all_stdout)
// {
//     KoalaDoctor     cox("Cox");
// ///////////////////////////////////////////////////////////////////////
//     SickKoala       *sickKoala = new SickKoala;
//     std::string     name;
//     cr_assert(zero(str, name));
//     cr_assert(eq(str, name, ""));
//     cr_assert_str_empty(name.data());
//     cr_assert(ne(str, sickKoala->get_name().data(), ""));
//     cr_assert(eq(str, sickKoala->get_name().data(), "SickKoala"));
// //////////////////////////////////////////////////////////////////////
//     std::string     file_nameReport = sickKoala->get_name() + ".report";
//     cr_assert(not(zero(str, file_nameReport)));
//     cr_assert(not(eq(str, file_nameReport, "")));        
//     cr_assert(ne(str, file_nameReport.data(), ""));
//     cr_assert(eq(str, file_nameReport.data(), "SickKoala.report"));
// //////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////
//     std::string     drug[5] = {"Mars", "Buronzand", "Viagra", "Extasy", "Eucalyptus leaf"};
//     std::string     drug2[5] = {"Mars", "Buronzand", "Viagra", "Extasy", "Eucalyptus leaf"};

//     cr_assert(eq(str[5], drug, drug2));
// //////////////////////////////////////////////////////////////////////
//     long            number_random = random() % 5;
//     cr_assert(number_random != 0);
//     cr_assert(number_random == 3);
// //////////////////////////////////////////////////////////////////////
//     std::cout << "Dr." << cox.getName() 
//     << ": So what's goerking you Mr." 
//     << sickKoala->get_name() << "?" << std::endl;
// //////////////////////////////////////////////////////////////////////
//     sickKoala->poke();
//     // cr_assert_stdout_eq_str("Dr.Cox: I'm Dr.Cox! How do you kreog?\nDr.Cox: So what's goerking you Mr.SickKoala?\nMr.SickKoala: Gooeeeeerrk!!\n");
// //////////////////////////////////////////////////////////////////////
//     std::ofstream   file_drReport;

//     file_drReport.open(file_nameReport.data());
//     cr_assert(file_drReport.is_open() == true);
//     file_drReport << drug[number_random];
//     file_drReport.close();
//     cr_assert(file_drReport.is_open() == false);

//     std::string line;
//     std::ifstream myfile("SickKoala.report");

//     if (myfile.is_open())
//     {
//         while ( getline (myfile,line) )
//         {
//             std::cout << line << std::endl;
//         }
//         myfile.close();
//         cr_assert(myfile.is_open() == false);
//     }
//     cr_assert_stdout_eq_str("Dr.Cox: I'm Dr.Cox! How do you kreog?\nDr.Cox: So what's goerking you Mr.SickKoala?\nMr.SickKoala: Gooeeeeerrk!!\nExtasy\n");
// }


// Test(KoalaDoctor, test_diagnose,.init=redirect_all_stdout)//, .signal=SIGPIPE, .init=redirect_all_stdout)
// {
//     KoalaDoctor     cox("Cox");
//     SickKoala       *sickKoala = new SickKoala;
//     std::ofstream   file_drReport;
//     std::string     file_nameReport;

//     std::string     drug[5] = {"Mars", "Buronzand", "Viagra", "Extasy", "Eucalyptus leaf"};
//     long            number_random = random() % 5;

//     std::cout << "Dr." << cox.getName() 
//     << ": So what's goerking you Mr." 
//     << sickKoala->get_name() << "?" << std::endl;
//     sickKoala->poke();

//     file_nameReport = sickKoala->get_name() + ".report";
//     file_drReport.open(file_nameReport);
//     file_drReport << drug[number_random];
//     file_drReport.close();
//     cr_assert_stdout_eq_str("Dr.Cox: I'm Dr.Cox! How do you kreog?\nDr.Cox: So what's goerking you Mr.SickKoala?\nMr.SickKoala: Gooeeeeerrk!!\n");
// }

// Test(diagnose, test_diagnose_memberfunction,.init=redirect_all_stdout)//, .signal=SIGPIPE, .init=redirect_all_stdout)
// {
//     KoalaDoctor     cox("Cox");
//     SickKoala       *sickKoala = new SickKoala;

//     cox.diagnose(sickKoala);
//     cr_assert_stdout_eq_str("Dr.Cox: I'm Dr.Cox! How do you kreog?\nDr.Cox: So what's goerking you Mr.SickKoala?\nMr.SickKoala: Gooeeeeerrk!!\n");
// }


// Test(timeCheck, test_timeCheck_doctor_notWorking, .init=redirect_all_stdout)
// {
//         KoalaDoctor     cox("Cox");
//         bool            _isWorking = false;

//         cr_assert(_isWorking == false);
//         cr_assert(eq(str, cox.getName().data(), "Cox"));

//         if(_isWorking == true)
//         {
//                 std::cout << "Dr." << cox.getName() << ": Time to get to work!" << std::endl;
//                 cr_assert_stdout_eq_str("Dr.Cox: Time to get to work!\n");
//         }
//         else
//         {
//                 std::cout << "Dr." << cox.getName() << ": Time to go home to my eucalyptus forest!" << std::endl;
//                 cr_assert_stdout_eq_str("Dr.Cox: I'm Dr.Cox! How do you kreog?\nDr.Cox: Time to go home to my eucalyptus forest!\n");
//         }
// }

// Test(timeCheck, test_timeCheck_doctor_Working, .init=redirect_all_stdout) {
//         KoalaDoctor     cox("Cox");
//         bool            _isWorking = false;

//         cr_assert(_isWorking == false);
//         _isWorking = !_isWorking;
//         cr_assert(_isWorking == true);
//         cr_assert(eq(str, cox.getName().data(), "Cox"));

//         if(_isWorking == true) {
//                 std::cout << "Dr." << cox.getName() << ": Time to get to work!" << std::endl;
//                 cr_assert_stdout_eq_str("Dr.Cox: I'm Dr.Cox! How do you kreog?\nDr.Cox: Time to get to work!\n");
//         }
//         else {
//                 std::cout << "Dr." << cox.getName() << ": Time to go home to my eucalyptus forest!" << std::endl;
//                 cr_assert_stdout_eq_str("Dr.Cox: I'm Dr.Cox! How do you kreog?\nDr.Cox: Time to go home to my eucalyptus forest!\n");
//         }
// }

// Test(timeCheck, test_timeCheck_memberFunction_working, .init=redirect_all_stdout) {
//         KoalaDoctor      cox("Cox");

//         cr_assert(cox.getIsWorking() == false);
//         cox.timeCheck();
//         cr_assert(cox.getIsWorking() == true);
//         cr_assert_stdout_eq_str("Dr.Cox: I'm Dr.Cox! How do you kreog?\nDr.Cox: Time to get to work!\n");
// }

// Test(timeCheck, test_timeCheck_memberFunction_NotWorking, .init=redirect_all_stdout) {
//         KoalaDoctor      cox("Cox");

//         cr_assert(cox.getIsWorking() == false);
//         cox.setIsWorking(true);
//         cr_assert(cox.getIsWorking() == true);
//         cox.timeCheck();
//         cr_assert(cox.getIsWorking() == false);
//         cr_assert_stdout_eq_str("Dr.Cox: I'm Dr.Cox! How do you kreog?\nDr.Cox: Time to go home to my eucalyptus forest!\n");
// }

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