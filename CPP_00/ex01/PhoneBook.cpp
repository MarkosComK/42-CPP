#include "include.hpp"

bool	validate_option(std::string string);

void PhoneBook::AddContact(void)
{
	static int index = 0;
	std::string FirstName;
	std::string LastName;
	std::string NickName;

	std::cout
		<< "   Type the" YELLOW " first " RESET "name → ";
	std::getline(std::cin, FirstName);
	if (!validate_option(FirstName)) {print_retry(); AddContact(); }
	ClearScreen();
	PrintOptions("    Adding a contact", -1);
	std::cout
		<< "   Type the last name → ";
	std::getline(std::cin, LastName);
	if (!validate_option(FirstName)) {print_retry(); AddContact(); }
	ClearScreen();
	PrintOptions("    Adding a contact", -1);
	std::cout
		<< "   Chose the nick name → ";
	std::getline(std::cin, NickName);
	if (!validate_option(FirstName)) {print_retry(); AddContact(); }
	if (index < LIST_SIZE)
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
		<<
		CYAN
		<< "   --------------------------------------"
		<< std::endl
		<<
		RESET
		<< "   index|first-name|last--name|nick--name"
		<< std::endl;
	for (int i = 0; i < LIST_SIZE; i++)
	{
		_contacts[i].PrintContact(i);
	}
	std::cout
		<<
		CYAN
		<< "   --------------------------------------"
		<< std::endl
		<<
		RESET
		<< std::endl;
}
