#include "../includes/my_list_hospital.hpp"
//CTOR
SickKoalaList::     SickKoalaList(SickKoala     *patient) : 
    _patient(patient), _next(nullptr) 
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
SickKoala           *SickKoalaList::getPatient(void)
{
    return _patient;
}

SickKoalaList       *SickKoalaList::getNext(void)
{
    return _next;
}

////MUTATORS / SETTER
void                SickKoalaList::setNext(SickKoalaList *next)
{
    this->_next = next;
}

void                SickKoalaList::setPatient(SickKoala       *patient)
{
    this->_patient = patient;
}

void                SickKoalaList::append(SickKoalaList       *sickKoalaList)
{
    // Check if the list is empty
    if (this->_patient == nullptr)
    {
        this->_patient = sickKoalaList->_patient;
        this->_next = sickKoalaList;
    }

    // Find the last node in the list
    SickKoalaList *current = this;
    while (current->_next != nullptr)
    {
        current = current->_next;
    }

    // Append the new node to the end of the list
    current->_next = sickKoalaList;
}

SickKoala         *SickKoalaList::getFromName(std::string name)
{
    if (this->_patient && this->_patient->get_name() == name)
		return this->_patient;
	else if (this->_next)
		return this->_next->getFromName(name);
	return nullptr;
}

SickKoalaList           *SickKoalaList::remove(SickKoalaList *newElement)
{
    if (this->_patient == nullptr)
        return this;

    // Check if the node to be removed is the first node in the list
    if (this == newElement)
    {
        SickKoalaList *newHead;
        newHead = this->_next;
        this->_patient = nullptr;
        this->_next = nullptr;
        return newHead;
    }

    // Iterate through the list and remove the matching node
    SickKoalaList *current = this;
    while (current->_next != nullptr)
    {
        if (current->_next == newElement)
        {
            current->_next = newElement->_next;
            newElement->_patient = nullptr;
            newElement->_next = nullptr;
            break;
        }
        current = current->_next;
    }
    // Return a pointer to the first node of the list
    return this;  
}

SickKoalaList *SickKoalaList::removeFromName(std::string name)
{
    // Check if the list is empty
    if (this->_patient == nullptr)
        return this;

    // Check if the first node in the list has the matching name
    if (this->_patient->get_name() == name)
    {
        SickKoalaList *newHead = this->_next;
        this->_patient = nullptr;
        this->_next = nullptr;
        return newHead;
    }

    // Iterate through the list and remove the first node with the matching name
    SickKoalaList     *current;
    current = this;
    
    while (current->_next != nullptr)
    {
        if (current->_next->_patient->get_name() == name)
        {
            SickKoalaList *nodeToRemove = current->_next;
            current->_next = nodeToRemove->_next;
            nodeToRemove->_patient = nullptr;
            nodeToRemove->_next = nullptr;
            break;
        }
        current = current->_next;
    }

    // Return a pointer to the first node of the list
    return this;
}

void SickKoalaList::dump()
{
	SickKoalaList *current;

    current = this;
	std::cout << "Patients: " << std::flush;
	while (current) 
    {
		if (current->_patient)
			std::cout << current->_patient->get_name() << std::flush;
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
    // Check if the list is empty
    if (this->_nurse == nullptr)
    {
        this->_nurse = koalaNurseList->_nurse;
        this->_next = koalaNurseList;
    }

    // Find the last node in the list
    KoalaNurseList *current = this;
    while (current->_next != nullptr)
        current = current->_next;

    // Append the new node to the end of the list
    current->_next = koalaNurseList;
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
    // Check if the list is empty
    if (this->_nurse == nullptr)
        return this;

    // Check if the node to be removed is the first node in the list
    if (this == newElement)
    {
        KoalaNurseList *newHead;
        newHead = this->_next;
        this->_nurse = nullptr;
        this->_next = nullptr;
        return newHead;
    }

    // Iterate through the list and remove the matching node
    KoalaNurseList *current = this;
    while (current->_next != nullptr)
    {
        if (current->_next == newElement)
        {
            current->_next = newElement->_next;
            newElement->_nurse = nullptr;
            newElement->_next = nullptr;
            break;
        }
        current = current->_next;
    }
    // Return a pointer to the first node of the list
    return this;  
}

KoalaNurseList          *KoalaNurseList::removeFromId(int id)
{
    // Check if the list is empty
    if (this->_nurse == nullptr)
        return this;

    // Check if the first node in the list has the matching name
    if (this->_nurse->getID() == id)
    {
        KoalaNurseList *newHead = this->_next;
        this->_nurse = nullptr;
        this->_next = nullptr;
        return newHead;
    }

    // Iterate through the list and remove the first node with the matching name
    KoalaNurseList     *current;
    current = this;
    
    while (current->_next != nullptr)
    {
        if (current->_next->_nurse->getID() == id)
        {
            KoalaNurseList *nodeToRemove = current->_next;
            current->_next = nodeToRemove->_next;
            nodeToRemove->_nurse = nullptr;
            nodeToRemove->_next = nullptr;
            break;
        }
        current = current->_next;
    }
    // Return a pointer to the first node of the list
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
			std::cout << current->_nurse->getID() << std::flush;
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

    // //Check if the list is empty
    // if (this->_doctor == nullptr)
    // {
    //     this->_doctor = koalaDoctorList->_doctor;
    //     this->_next = koalaDoctorList;
    // //    return;
    // }

    // // Find the last node in the list
    // KoalaDoctorList *current = this;
    // while (current->_next != nullptr)
    //     current = current->_next;

    // // Append the new node to the end of the list
    // current->_next = koalaDoctorList;
///////////////////////////////////////////////////////
    //recursive
    // Check if the list is empty
    if (this->_doctor == nullptr)
    {
        this->_doctor = koalaDoctorList->_doctor;
        this->_next = koalaDoctorList;
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
			std::cout << current->_doctor->getName() << std::flush;
		else
			std::cout << "[nullptr]" << std::flush;
		if (current->_next)
			std::cout << ", " << std::flush;
		else
			std::cout << ".\n"  << std::flush;
		current = current->_next;
	}
}