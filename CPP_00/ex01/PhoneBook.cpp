#include "include.hpp"

void PhoneBook::AddContact(void)
{
	static int index = 0;
	std::string FirstName;
	std::string LastName;
	std::string NickName;

	std::cout
		<< "  Type the first name: ";
	std::cin >> FirstName;
	ClearScreen();
	PrintOptions("    Adding a contact", -1);
	std::cout
		<< "  Type the last name:  ";
	std::cin >> LastName;
	ClearScreen();
	PrintOptions("    Adding a contact", -1);
	std::cout
		<< "  Chose the nick name:  ";
	std::cin >> NickName;
	if (index < 2)
		_contacts[index] = Contact(index, FirstName, LastName, NickName);
	else
	{
		int i = 0;
		_contacts[0] = Contact();
		for (i = 0; i < LIST_SIZE; i++)
		{
			_contacts[i + 1].ReduceIndex(i);
			_contacts[i] = _contacts[i + 1];
		}
		i--;
		_contacts[i] = Contact(i, FirstName, LastName, NickName);
	}
	index++;
}

void PhoneBook::ShowContacts()
{
	std::cout
		<< "  --------------------------------------"
		<< std::endl
		<< "  index|first-name|last--name|nick--name"
		<< std::endl;
	for (int i = 0; i < LIST_SIZE; i++)
	{
		_contacts[i].PrintContact(i);
	}
	std::cout
		<< "  --------------------------------------"
		<< std::endl
		<< std::endl;
}
