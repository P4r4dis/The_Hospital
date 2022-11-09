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
        std::string     get_name(void);
        void            poke(void);        

    private:
        std::string     _name;
        
    protected:
};


#endif  // !__MY_HOSPITAL__