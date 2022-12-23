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
    if(newNode == NULL)
    {
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

SickKoala         *SickKoalaList::getFromName(std::string name)
{
    if (this->_content && this->_content->get_name() == name)
    {
		return this->_content;
	}
	else if (this->_next)
    {
		return this->_next->getFromName(name);
	}
	return nullptr;


}

SickKoalaList           *SickKoalaList::remove(SickKoalaList *newElement)
{
    SickKoalaList       *prev;
    SickKoalaList       *current;

    prev = nullptr;
    current = this;
    while (current != nullptr)
    {
        if (current->_content == newElement->_content)
        {
            if(current == this)
                current = this->_next;
            else
            {
                prev->_next = current->_next;
                current = prev->_next;
            }
        }
        else
        { 
            prev = current;
            current = current->_next;
        }
    }
    if (current == nullptr)
        return nullptr;
    return this;
}

SickKoalaList *SickKoalaList::removeFromName(std::string name)
{
    SickKoalaList* prev;
    SickKoalaList* current;

    prev = this;
    current = this;
    while (current != nullptr)
    {
        if (current->_content->get_name() == name)
        {
            if(current == this)
            {
                current->_content = nullptr;
                current = this->_next;
            }
            else
            {
                prev->_next = current->_next;
                current = prev->_next;
            }
        }
        else
        { 
            prev = current;
            current = current->_next;
        }
    }
    if (current == nullptr)
        return nullptr;
    return this;
}

void SickKoalaList::dump()
{
	SickKoalaList *current;

    current = this;
	std::cout << "Patients: " << std::flush;
	while (current) 
    {
		if (current->_content)
			std::cout << current->_content->get_name() << std::flush;
		else
			std::cout << "[nullptr]" << std::flush;
		if (current->_next)
			std::cout << ", " << std::flush;
		else
			std::cout << ".\n"  << std::flush;
		current = current->_next;
	}
}

KoalaNurseList::KoalaNurseList(KoalaNurse     *nurse) : _nurse(nurse), _next(nullptr)
{} 

KoalaNurseList::~KoalaNurseList()
{}

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
    KoalaNurseList  *newNode;
    KoalaNurseList  *temp;
    
    newNode = new KoalaNurseList(koalaNurseList->_nurse);
    temp = this;
    newNode->_nurse = koalaNurseList->_nurse;
    if(newNode == NULL)
        newNode = koalaNurseList;
    else
    {
        while(temp->_next != NULL)
            temp = temp->_next;
        temp->_next = newNode;
        newNode->_prev = temp;
    }
}

KoalaNurse              *KoalaNurseList::getFromId(int id)
{
    if (this->_nurse && this->_nurse->getID() == id)
		return this->_nurse;
	else if (this->_next)
		return this->_next->getFromId(id);
	return nullptr;
}

KoalaNurseList          *KoalaNurseList::remove(KoalaNurseList *newElement)
{
    KoalaNurseList      *prev;
    KoalaNurseList      *current;

    prev = nullptr;
    current = this;
    while (current != nullptr)
    {
        if (current->_nurse == newElement->_nurse)
        {
            if(current == this)
            {
                current = this->_next;
            }
            else
            {
                prev->_next = current->_next;
                current = prev->_next;
            }
        }
        else
        { 
            prev = current;
            current = current->_next;
        }
    }
    if (current == nullptr)
        return nullptr;
    return this;
}

KoalaNurseList          *KoalaNurseList::removeFromId(int id)
{
    KoalaNurseList      *prev;
    KoalaNurseList      *current;

    prev = this;
    current = this;
    while (current != nullptr)
    {
        if (current->_nurse->getID() == id)
        {
            if(current == this)
            {
                current->_nurse = nullptr;
                current = this->_next;
            }
            else
            {
                prev->_next = current->_next;
                current = prev->_next;
            }
        }
        else
        { 
            prev = current;
            current = current->_next;
        }
    }
    if (current == nullptr)
        return nullptr;
    return this;
}

void    KoalaNurseList::dump()
{
	std::cout << "Nurses: " << std::flush;
	KoalaNurseList      *current;
    
    current = this;
	while (current) 
    {
		if (current->_nurse)
			std::cout << "id" << current->_nurse->getID() << std::flush;
		else
			std::cout << "[nullptr]" << std::flush;
		if (current->_next)
			std::cout << ", " << std::flush;
		else
			std::cout << ".\n"  << std::flush;
		current = current->_next;
	}
}



KoalaDoctorList::KoalaDoctorList(KoalaDoctor     *doctor) : _doctor(doctor), _next(nullptr)
{} 

KoalaDoctorList::~KoalaDoctorList()
{}

KoalaDoctor *KoalaDoctorList::getDoctor(void){
    return _doctor;
}

KoalaDoctorList    *KoalaDoctorList::getNext(void)
{
    return _next;
}

void KoalaDoctorList::setNext(KoalaDoctorList *next)
{
    _next = next;
}

bool                KoalaDoctorList::isEnd(void)
{
    if(_next == nullptr)
        return true;
    else
        return false; 
}

void                KoalaDoctorList::append(KoalaDoctorList       *koalaDoctorList)
{

    // Check if the list is empty
    // if (this->_doctor == nullptr)
    // {
    //     this->_doctor = koalaDoctorList->_doctor;
    //     this->_next = koalaDoctorList;
    // //    return;
    // }

    // // Find the last node in the list
    // KoalaDoctorList *current = this;
    // while (current->_next != nullptr)
    // {
    //     current = current->_next;
    // }

    // // Append the new node to the end of the list
    // current->_next = koalaDoctorList;
///////////////////////////////////////////////////////
    //recursive
    // Check if the list is empty
    if (this->_doctor == nullptr)
    {
        this->_doctor = koalaDoctorList->_doctor;
        this->_next = koalaDoctorList;
        // return;
    }

    // Append the new node to the end of the list using recursion
    if (this->_next == nullptr)
        this->_next = koalaDoctorList;
    else
        this->_next->append(koalaDoctorList);
}

KoalaDoctor              *KoalaDoctorList::getFromName(std::string name)
{
    if (this->_doctor && this->_doctor->getName() == name)
		return this->_doctor;
	else if (this->_next)
		return this->_next->getFromName(name);
	return nullptr;
}

KoalaDoctorList          *KoalaDoctorList::remove(KoalaDoctorList *newElement)
{
    // Check if the list is empty
    if (this->_doctor == nullptr)
        return this;

    // Check if the node to be removed is the first node in the list
    if (this == newElement)
    {
        KoalaDoctorList *newHead;
        newHead = this->_next;
        this->_doctor = nullptr;
        this->_next = nullptr;
        return newHead;
    }

    // Iterate through the list and remove the matching node
    KoalaDoctorList *current = this;
    while (current->_next != nullptr)
    {
        if (current->_next == newElement)
        {
            current->_next = newElement->_next;
            newElement->_doctor = nullptr;
            newElement->_next = nullptr;
            // break;
        }
        current = current->_next;
    }
    // Return a pointer to the first node of the list
    return this;  
}

KoalaDoctorList          *KoalaDoctorList::removeFromName(std::string name)
{
    // Check if the list is empty
    if (this->_doctor == nullptr)
        return this;

    // Check if the first node in the list has the matching name
    if (this->_doctor->getName() == name)
    {
        KoalaDoctorList *newHead = this->_next;
        this->_doctor = nullptr;
        this->_next = nullptr;
        return newHead;
    }

    // Iterate through the list and remove the first node with the matching name
    KoalaDoctorList     *current;
    current = this;
    
    while (current->_next != nullptr)
    {
        if (current->_next->_doctor->getName() == name)
        {
            KoalaDoctorList *nodeToRemove = current->_next;
            current->_next = nodeToRemove->_next;
            nodeToRemove->_doctor = nullptr;
            nodeToRemove->_next = nullptr;
            break;
        }
        current = current->_next;
    }

    // Return a pointer to the first node of the list
    return this;
}

void    KoalaDoctorList::dump()
{
	KoalaDoctorList      *current;
    
    current = this;
	std::cout << "Doctors: " << std::flush;
	while (current) 
    {
		if (current->_doctor)
			std::cout << "Dr." << current->_doctor->getName() << std::flush;
		else
			std::cout << "[nullptr]" << std::flush;
		if (current->_next)
			std::cout << ", " << std::flush;
		else
			std::cout << ".\n"  << std::flush;
		current = current->_next;
	}
}