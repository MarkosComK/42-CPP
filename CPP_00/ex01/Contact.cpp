#include <iostream>
#include "PhoneBook.hpp"

Contact::Contact(std::string FName, std::string LName, std::string NName)
{
	this->_FirstName = FName;
	this->_LastName = LName;
	this->_NickName = NName;
}

void Contact::PrintContact(void)
{
	std::cout << this->_FirstName << std::endl;
	std::cout << this->_LastName << std::endl;
	std::cout << this->_NickName << std::endl;
}
