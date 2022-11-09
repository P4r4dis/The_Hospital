#ifndef __MY_HOSPITAL__
#   define __MY_HOSPITAL__

#include <iostream>
#include <iomanip>

class SickKoala {
    public:
        //CTOR
        SickKoala();
        //CTOR CUSTOM
        SickKoala(std::string name);
        //DTOR
        ~SickKoala();
        //Member Function
        void            poke(void);
        bool            takeDrug(std::string str);
        //Getter
        std::string     get_name(void);


    private:
        std::string     _name;
        
    protected:
};


#endif  // !__MY_HOSPITAL__