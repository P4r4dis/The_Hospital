#include "../includes/my_hospital.hpp"
#include "./tests_includes/test_my_hospital.hpp"

Test(SickKoala, ctorDefault) {

        std::string     name;
        SickKoala       sickKoala;

        cr_assert(zero(str, name));
        cr_assert(eq(str, name, ""));
        cr_assert_str_empty(name.data());
        cr_assert(ne(str, sickKoala.get_name().data(), ""));
        cr_assert(eq(str, sickKoala.get_name().data(), "SickKoala"));
}

Test(SickKoala, ctorCustom) {

        SickKoala       sickKoala("SickKoala");

        cr_assert(ne(str, sickKoala.get_name().data(), ""));
        cr_assert(eq(str, sickKoala.get_name().data(), "SickKoala"));
}

Test(SickKoala, ctorDefault_and_dtor,  .signal=SIGPIPE, .init=redirect_all_stdout) {
        SickKoala sickKoala;
        sickKoala.~SickKoala();
        cr_assert_stdout_eq_str("Mr.SickKoala: Kreooogg!! I'm cuuuured!\n");
}

Test(SickKoala, ctorCustom_and_dtor,  .signal=SIGPIPE, .init=redirect_all_stdout) {
        SickKoala sickKoala("SickKoala");
        sickKoala.~SickKoala();
        cr_assert_stdout_eq_str("Mr.SickKoala: Kreooogg!! I'm cuuuured!\n");
}

Test(poke, stdcout_poke_function, .signal=SIGPIPE, .init=redirect_all_stdout) {
        SickKoala sickKoala("SickKoala");

        sickKoala.poke();
        cr_assert_stdout_eq_str("Mr.SickKoala: Gooeeeeerrk!!\n");
}

Test(takeDrug, strParameter_eq_MarsStrings_and_stdcout_caught,
        .init=redirect_all_stdout)
{
        std::string     _name("SickKoala");
        std::string     string = "Mars";
        std::string     s_mars("Mars");
        bool            return_value;

        cr_assert(eq(str,string, s_mars));
        if (string == s_mars)
        {
                return_value = true;
                cr_assert(return_value == true);
                std::cout << "Mr." << _name << ": Mars, and it kreogs!" << std::endl;
                cr_assert_stdout_eq_str("Mr.SickKoala: Mars, and it kreogs!\n");

        }
}

Test(takeDrug, strParameter_notEq_MarsStrings_and_stdcout_caught,
        .init=redirect_all_stdout)
{
        std::string     _name("SickKoala");
        std::string     string = "Buronzand";
        std::string     s_mars("Mars");
        bool            return_value;

        cr_assert(not(eq(str,string, s_mars)));
        if (string == s_mars)
        {
                return_value = true;
                cr_assert(return_value == true);
                std::cout << "Mr." << _name << ": Mars, and it kreogs!" << std::endl;
                cr_assert_stdout_eq_str("Mr.SickKoala: Mars, and it kreogs!\n");

        } else
        {
                return_value = false;
                cr_assert(return_value == false);
                std::cout << "Mr." << _name << ": Goerkreog!" << std::endl;
                cr_assert_stdout_eq_str("Mr.SickKoala: Goerkreog!\n");                
        }
}

Test(takeDrug, strParameter_eq_BuronzandStrings_and_stdcout_caught,
        .init=redirect_all_stdout)
{
        std::string     _name("SickKoala");
        std::string     string = "Buronzand";
        std::string     s_buronzand("Buronzand");
        bool            return_value;

        cr_assert(eq(str,string, s_buronzand));
        if (string == s_buronzand)
        {
                return_value = true;
                cr_assert(return_value == true);
                std::cout << "Mr." << _name << ": And you 'll sleep right away!" << std::endl;
                cr_assert_stdout_eq_str("Mr.SickKoala: And you 'll sleep right away!\n");

        } else {
                cr_log_error("FAIL");
                cr_fail();

        }
}

Test(takeDrug, strParameter_notEq_BuronzandStrings_and_stdcout_caught,
        .init=redirect_all_stdout)
{
        std::string     _name("SickKoala");
        std::string     string = "BuronzanD";
        std::string     s_buronzand("Buronzand");
        bool            return_value;

        cr_assert(not(eq(str,string, s_buronzand)));
        if (string == s_buronzand)
        {
                return_value = true;
                cr_assert(return_value == true);
                std::cout << "Mr." << _name << ": And you 'll sleep right away!" << std::endl;
                cr_assert_stdout_eq_str("Mr.SickKoala: : And you 'll sleep right away!\n");

        } else {
                return_value = false;
                cr_assert(return_value == false);
                std::cout << "Mr." << _name << ": Goerkreog !" << std::endl;
                cr_assert_stdout_eq_str("Mr.SickKoala: Goerkreog !\n");
        }
}

Test(takeDrug, strParameter_notEq_strings_and_stdcout_caught2,
        .init=redirect_all_stdout)
{
        std::string     _name("SickKoala");
        std::string     string = "randomString";
        std::string     s_buronzand("Buronzand");
        std::string     s_mars("Mars");
        bool            return_value;

        cr_assert(not(eq(str,string, s_buronzand)));
        cr_assert(not(eq(str,string, s_mars)));
        if (string == s_buronzand )
        {
                return_value = true;
                cr_assert(return_value == true);
                std::cout << "Mr." << _name << ": And you 'll sleep right away!" << std::endl;
                cr_assert_stdout_eq_str("Mr.SickKoala: : And you 'll sleep right away!\n");
        } else if (string == s_mars)
        {
                return_value = true;
                cr_assert(return_value == true);
                std::cout << "Mr." << _name << ": Mars, and it kreogs!" << std::endl;
                cr_assert_stdout_eq_str("Mr.SickKoala: Mars, and it kreogs!\n");
        } else
        {
                return_value = false;
                cr_assert(return_value == false);
                std::cout << "Mr." << _name << ": Goerkreog !" << std::endl;
                cr_assert_stdout_eq_str("Mr.SickKoala: Goerkreog !\n");
        }
}

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
