#include "include.hpp"

Contact::Contact(int Index, std::string FName, std::string LName, std::string NName, std::string PNumber, std::string DSecret)
{
	this->_Index = Index;
	this->_FirstName = FName;
	this->_LastName = LName;
	this->_NickName = NName;
	this->_PhoneNumber = PNumber;
	this->_DarkSecret = DSecret;
}

bool Contact::PrintContact(int index)
{
	bool	found = false;

	if (this->_FirstName.compare("") != 0)
	{
		std::cout << "   ";
		std::cout <<  std::setw(5) << index;
		std::cout << "|";
		found = true;
	}
	if (this->_FirstName.compare("") != 0)
	{
		std::cout << std::setw(10) << this->_FirstName;
		std::cout << "|";
		found = true;
	}
	if (this->_LastName.compare("") != 0)
	{
		std::cout << std::setw(10) << this->_LastName;
		std::cout << "|";
		found = true;
	}
	if (this->_NickName.compare("") != 0)
	{
		std::cout << std::setw(10) << this->_NickName << std::endl;
		found = true;
	}
	else
		found = false;
	return (found);
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
