#include "include.hpp"

void PhoneBook::AddContact(std::string FName, std::string LName, std::string NName)
{
	static int index = 0;
	if (index < 9)
		_contacts[index] = Contact(FName, LName, NName);
	index++;
}

void PhoneBook::ShowContacts()
{
	for (int i = 0; i < 9; i++)
	{
		_contacts[i].PrintContact();
	}
}
