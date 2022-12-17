#include "../includes/my_list_hospital.hpp"
//CTOR
SickKoalaList::     SickKoalaList(SickKoala     *content) : 
    _content(content), _next(nullptr) 
{}
//DTOR
SickKoalaList::     ~SickKoalaList()
{}
//MEMBER FUNCTION
bool                SickKoalaList::isEnd(void)
{
        if(_next == nullptr)
            return true;
        else
            return false;
        
}
////ACCESSORS / GETTER
SickKoala           *SickKoalaList::getContent(void)
{
    return _content;
}

SickKoalaList       *SickKoalaList::getNext(void)
{
    return _next;
}

SickKoalaList       *SickKoalaList::getThis(void)
{
    return _this;
}
////MUTATORS / SETTER
void                SickKoalaList::setNext(SickKoalaList *next)
{
    this->_next = next;
}

void                SickKoalaList::setContent(SickKoala       *content)
{
    this->_content = content;
}

void                SickKoalaList::append(SickKoalaList       *sickKoalaList)
{
  SickKoalaList* newNode = new SickKoalaList(sickKoalaList->_content);
  SickKoalaList* temp = this;

  newNode->_content = sickKoalaList->_content;
  if(newNode == NULL) {
    newNode = sickKoalaList;
  }
  else
  {
    while(temp->_next != NULL)
      temp = temp->_next;
    temp->_next = newNode;
    newNode->_prev = temp;
    }
}

SickKoala         *SickKoalaList::getFromName(std::string name){
    SickKoalaList* current = this;
 
    while (current != NULL)
    {
        if (current->_content->get_name() == name)
        {
            return (current->_content);
        }
        current = current->_next;
    }
    return nullptr;
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *newElement)
{
    SickKoalaList* prev = this;
    SickKoalaList* current = this; //this
    
    while (current != nullptr)
    {
        if (current->_content == newElement->_content)
        {
            if(current == this)
            {
                // this->_next;
                delete current;
                current = this->_next;
            }
            else
            {
                prev->_next = current->_next;
                delete current;
                current = prev->_next;
            }
        }
        else
        { 
            prev = current;
            current = current->_next;
        }
    }
    // key not found in list
    if (current == nullptr)
    {
        return this; //this
    }
    return this; //this
}

SickKoalaList *SickKoalaList::removeFromName(std::string name)
{
    SickKoalaList* prev = nullptr;
    SickKoalaList* current = this; //this
    
    while (current != nullptr)
    {
        if (current->_content->get_name() == name)
        {
            if(current == this)
            {
                // current->setNext(nullptr);
                delete current; //can be comment
                current = this->_next;
            }
            else
            {
                prev->_next = current->_next;
                delete current; // can be comment
                current = prev->_next;
            }
        }
        else
        { 
            prev = current;
            current = current->_next;
        }
    }
  // key not found in list
    if (current == nullptr)
        return this; // this
    return this;// this
}

void SickKoalaList::dump()
{
    SickKoalaList* temp = this;  
    
    std::cout<<"Patients: ";
    while(temp)
    {
        std::cout << (temp == this ? "" : ", ");
        std::cout << (temp->getContent() ? temp->getContent()->get_name() : "[nullptr]");
        temp = temp->_next;
    }
    std::cout<< "." << std::endl;
}
// void            SickKoalaList::append(SickKoalaList *  sick1)
// {



//     // if (this->isEnd())
//     //     this->setNext(sick1);
//     // else
//     //     this->_next->append(sick1);
//     SickKoalaList *tmp;

//   tmp = this;
//   if (tmp == NULL)
//     {
//         // this->_content = sick1->_content;
//         tmp->setContent(sick1->_content);
//         // this->_next = sick1->_next;
//         tmp->setNext(sick1->_next);

//     }
// //   while (tmp != NULL && tmp->_next != NULL)
//   while (tmp->isEnd() != true && tmp->getNext() != NULL)
//   {
//     // tmp = tmp->_next;
//     tmp = tmp->getNext();
//   }
// //   tmp->_next = sick1;
//     tmp->setNext(sick1);
// }



KoalaNurseList::KoalaNurseList(KoalaNurse     *nurse) : _nurse(nurse), _next(nullptr)
{} 

KoalaNurseList::~KoalaNurseList()
{
}

KoalaNurse *KoalaNurseList::getNurse(void){
    return _nurse;
}

KoalaNurseList    *KoalaNurseList::getNext(void)
{
    return _next;
}

void KoalaNurseList::setNext(KoalaNurseList *next)
{
    _next = next;
}

bool                KoalaNurseList::isEnd(void)
{
        if(_next == nullptr)
            return true;
        else
            return false;
        
}

void                KoalaNurseList::append(KoalaNurseList       *koalaNurseList)
{
  KoalaNurseList* newNode = new KoalaNurseList(koalaNurseList->_nurse);
  KoalaNurseList* temp = this;

  newNode->_nurse = koalaNurseList->_nurse;
  if(newNode == NULL) {
    newNode = koalaNurseList;
  }
  else
  {
    while(temp->_next != NULL)
      temp = temp->_next;
    temp->_next = newNode;
    newNode->_prev = temp;
    }
}