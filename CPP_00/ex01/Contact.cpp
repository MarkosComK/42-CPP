#include "include.hpp"

Contact::Contact(int Index, std::string FName, std::string LName, std::string NName)
{
	this->_Index = Index;
	this->_FirstName = FName;
	this->_LastName = LName;
	this->_NickName = NName;
}

void Contact::PrintContact(int index)
{

	if (this->_FirstName.compare("") != 0)
	{
		std::cout << "   ";
		std::cout <<  std::setw(5) << index;
		std::cout << "|";
	}
	if (this->_FirstName.compare("") != 0)
	{
		std::cout << std::setw(10) << this->_FirstName;
		std::cout << "|";
	}
	if (this->_LastName.compare("") != 0)
	{
		std::cout << std::setw(10) << this->_LastName;
		std::cout << "|";
	}
	if (this->_NickName.compare("") != 0)
	{
		std::cout << std::setw(10) << this->_NickName << std::endl;
	}
}

void Contact::ReduceIndex(int index)
{
	this->_Index = index;
}

std::string Contact::GetName(int value)
{
	if (value == FIRSTNAME)
		return (this->_FirstName);
	if (value == LASTNAME)
		return (this->_LastName);
	if (value == NICKNAME)
		return (this->_NickName);
	else
		return ("Error");
}
