#include "include.hpp"

Contact::Contact(std::string FName, std::string LName, std::string NName)
{
	this->_FirstName = FName;
	this->_LastName = LName;
	this->_NickName = NName;
}

void Contact::PrintContact(void)
{
	if (this->_FirstName != "")
		std::cout << this->_FirstName << std::endl;
	if (this->_LastName != "")
		std::cout << this->_LastName << std::endl;
	if (this->_NickName != "")
		std::cout << this->_NickName << std::endl;
}
