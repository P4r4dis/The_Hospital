#ifndef __MY_LIST_HOSPITAL__
#   define __MY_LIST_HOSPITAL__

#include <iostream>
#include <iomanip>
#include <fstream>
#include "../../part1_patient/includes/my_patient_hospital.hpp"
#include "../../part2_nurse/includes/my_nurse_hospital.hpp"
#include "../../part3_doctor/includes/my_doctor_hospital.hpp"


class SickKoalaList
{
    private:
        SickKoala       *_patient;
        SickKoalaList   *_next;

    public:
    //CTOR
        SickKoalaList(SickKoala                         *patient);
    //CCTOR
    //DTOR
        ~SickKoalaList();
    //Member Function
        bool            isEnd(void);
        void            append(SickKoalaList            *sickKoalaList);
        SickKoalaList   *remove(SickKoalaList           *sickKoalaList);
        SickKoalaList   *removeFromName(std::string     name);
        void            dump(void);

    //Getter
        SickKoala       *getFromName(std::string        name);
        SickKoala       *getPatient(void);
        SickKoalaList   *getNext(void);
    //Setter
        void            setNext(SickKoalaList           *next);
        void            setPatient(SickKoala            *patient);
};

class KoalaNurseList
{
    private:
        KoalaNurse          *_nurse;
        KoalaNurseList      *_next;

    public:
    //CTOR
        KoalaNurseList(KoalaNurse     *nurse);
    //CCTOR
    //DTOR
        ~KoalaNurseList();
    //Member Function
        bool            isEnd(void);
        void            append(KoalaNurseList       *koalaNurseList);

        KoalaNurseList  *remove(KoalaNurseList      *koalaNurseList);
        KoalaNurseList  *removeFromId(int           id);
        void            dump(void);

    //Getter
        KoalaNurse      *getNurse(void);
        KoalaNurse      *getFromId(int              id);
        // KoalaNurse      *getContent(void);
        KoalaNurseList  *getNext(void);
    //Setter
        void            setNext(KoalaNurseList      *next);
};

class KoalaDoctorList
{
    private:
        KoalaDoctor          *_doctor;
        KoalaDoctorList      *_next;

    public:
    //CTOR
        KoalaDoctorList(KoalaDoctor     *doctor);
    //CCTOR
    //DTOR
        ~KoalaDoctorList();
    //Member Function
        bool            isEnd(void);
        void            append(KoalaDoctorList       *koalaNurseList);

        KoalaDoctorList  *remove(KoalaDoctorList      *koalaNurseList);
        KoalaDoctorList  *removeFromName(std::string    name);
        void            dump(void);

    //Getter
        KoalaDoctor      *getDoctor(void);
        KoalaDoctor      *getFromName(std::string name);
        KoalaDoctorList  *getNext(void);
    //Setter
        void            setNext(KoalaDoctorList      *next);
};

#endif  // !__MY_LIST_HOSPITAL__