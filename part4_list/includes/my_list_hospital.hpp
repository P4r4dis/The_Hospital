#ifndef __MY_LIST_HOSPITAL__
#   define __MY_LIST_HOSPITAL__

#include <iostream>
#include <iomanip>
#include <fstream>
#include "../../part1_patient/includes/my_patient_hospital.hpp"
#include "../../part2_nurse/includes/my_nurse_hospital.hpp"

class SickKoalaList
{
    private:
        SickKoala       *_content;
        SickKoalaList   *_next;
        SickKoalaList   *_prev;
        SickKoalaList   *_this = this;

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
        SickKoala       *getContent(void);
        SickKoalaList   *getNext(void);
        SickKoalaList   *getThis(void);
    //Setter
        void            setNext(SickKoalaList           *next);
        void            setContent(SickKoala            *content);
};

class KoalaNurseList
{
    private:
        KoalaNurse          *_nurse;
        KoalaNurseList      *_next;
        KoalaNurseList      *_prev;

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

#endif  // !__MY_LIST_HOSPITAL__