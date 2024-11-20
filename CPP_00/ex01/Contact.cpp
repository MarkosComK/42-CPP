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
	bool		found = false;
	std::string	trunc;

	if (this->_FirstName.compare("") != 0)
	{
		std::cout << "   ";
		std::cout <<  std::setw(5) << index;
		std::cout << "|";
		found = true;
	}
	if (this->_FirstName.compare("") != 0)
	{
		if (_FirstName.length() > 10)
			std::cout << std::setw(10) << this->_FirstName.substr(0, 9) + ".";
		else
			std::cout << std::setw(10) << this->_FirstName;
		std::cout << "|";
		found = true;
	}
	if (this->_LastName.compare("") != 0)
	{
		if (_LastName.length() > 10)
			std::cout << std::setw(10) << this->_LastName.substr(0, 9) + ".";
		else
			std::cout << std::setw(10) << this->_LastName;
		std::cout << "|";
		found = true;
	}
	if (this->_NickName.compare("") != 0)
	{
		if (_NickName.length() > 10)
			std::cout << std::setw(10) << this->_NickName.substr(0, 9) + ".";
		else
			std::cout << std::setw(10) << this->_NickName;
		found = true;
	}
	else
		found = false;
	return (found);
}

bool Contact::PrintContactInfo(int index)
{
	bool	found = false;

	if (this->_FirstName.compare("") != 0)
	{
		std::cout << GREEN << "    Index:        " << RESET << index << std::endl;
		found = true;
	}
	if (this->_FirstName.compare("") != 0)
	{
		std::cout << GREEN << "    First name:   " << RESET  << this->_FirstName << std::endl;
		found = true;
	}
	if (this->_LastName.compare("") != 0)
	{
		std::cout << GREEN << "    Last name:    " << RESET  << this->_LastName << std::endl;
		found = true;
	}
	if (this->_NickName.compare("") != 0)
	{
		std::cout << GREEN << "    Nick name:    " << RESET  << this->_NickName << std::endl;
		found = true;
	}
	if (this->_PhoneNumber.compare("") != 0)
	{
		std::cout << GREEN << "    Phone number: " << RESET  << this->_PhoneNumber << std::endl;
		found = true;
	}
	if (this->_DarkSecret.compare("") != 0)
	{
		std::cout << GREEN << "    Dark Secret:  " << RESET  << this->_DarkSecret
			<< std::endl
			<< std::endl;
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
