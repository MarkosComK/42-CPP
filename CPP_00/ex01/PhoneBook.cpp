#include "PhoneBook.hpp"


void PhoneBook::addContact(std::string FName, std::string LName, std::string NName)
{
	contacts[0] = Contact(FName, LName, NName);
}

void PhoneBook::showContact()
{
	contacts[0].PrintContact();
}
