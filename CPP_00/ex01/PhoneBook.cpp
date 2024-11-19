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
	if (!validateOption(FirstName)) {printRetry(); AddContact(); }
	clearScreen();
	printOptions("    Adding a contact", -1);
	std::cout
		<< "   Type the last name → ";
	std::getline(std::cin, LastName);
	if (!validateOption(FirstName)) {printRetry(); AddContact(); }
	clearScreen();
	printOptions("    Adding a contact", -1);
	std::cout
		<< "   Chose the nick name → ";
	std::getline(std::cin, NickName);
	if (!validateOption(FirstName)) {printRetry(); AddContact(); }
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

bool	PhoneBook::SearchContact()
{
	bool		found = false;
	std::string value;
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::cout
		<< "   Type your search → ";
	std::getline(std::cin, value);
	if (std::isdigit(value[0]))
	{
		int	digit = value[0] - '0';
		clearScreen();
		printOptions("    Found: ", -1);
		std::cout << std::endl;
		std::cout
			<<
			CYAN
			<< "   --------------------------------------"
			<< std::endl
			<<
			RESET
			<< "   index|first-name|last--name|nick--name"
			<< std::endl;
		_contacts[digit].PrintContact(digit);
		std::cout
			<<
			CYAN
			<< "   --------------------------------------"
			<< std::endl
			<<
			RESET
			<< std::endl;
		return (found);
	}
	else
	{
		clearScreen();
		printOptions("    Found: ", -1);
		std::cout << std::endl;
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
			firstName = _contacts[i].GetName(FIRSTNAME);
			lastName = _contacts[i].GetName(LASTNAME);
			nickName = _contacts[i].GetName(NICKNAME);
			if (value.compare(firstName) == 0)
			{
				found = true;
			}
			if (value.compare(lastName) == 0)
			{
				found = true;
			}
			if (value.compare(nickName) == 0)
			{
				found = true;
			}
			if (found)
			{
				_contacts[i].PrintContact(i);
				found = false;
			}
		}
		std::cout
			<<
			CYAN
			<< "   --------------------------------------"
			<< std::endl
			<<
			RESET
			<< std::endl;
		return (found);
	}
	return (found);
}
