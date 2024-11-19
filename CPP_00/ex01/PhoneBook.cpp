#include "include.hpp"

bool	validate_option(std::string string);

void PhoneBook::AddContact(void)
{
	static int index = 0;
	std::string FirstName, LastName, NickName;

	while (true)
	{
		std::cout << "   Type the" YELLOW " first " RESET "name → ";
		if (!std::getline(std::cin, FirstName))
			return ;
		if (validateOption(FirstName))
			break;
		printRetry();
	}
	if (FirstName.length() > 10)
		FirstName = FirstName.substr(0, 9) + ".";

	clearScreen();
	printOptions("    Adding a contact", -1);

	// Input loop for last name
	while (true)
	{
		std::cout << "   Type the" YELLOW " last " RESET "name → ";
		if (!std::getline(std::cin, LastName))
			return;
		if (validateOption(LastName))
			break;
		printRetry();
	}
	if (LastName.length() > 10)
		LastName = LastName.substr(0, 9) + ".";

	clearScreen();
	printOptions("    Adding a contact", -1);

	// Input loop for nick name
	while (true)
	{
		std::cout << "   Choose the" YELLOW " nick " RESET "name → ";
		if (!std::getline(std::cin, NickName))
			return;
		if (validateOption(NickName))
			break;
		printRetry();
	}
	if (NickName.length() > 10)
		NickName = NickName.substr(0, 9) + ".";

	if (index < LIST_SIZE)
	{
		_contacts[index] = Contact(index, FirstName, LastName, NickName);
	}
	else
	{
		for (int i = 0; i < LIST_SIZE - 1; i++)
		{
			_contacts[i] = _contacts[i + 1]; // Shift contacts left
			_contacts[i].ReduceIndex(i);   // Update indices
		}
		_contacts[LIST_SIZE - 1] = Contact(LIST_SIZE - 1, FirstName, LastName, NickName);
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
		if (!_contacts[digit].PrintContact(digit))
			std::cout << RED "             Contact not found" RESET << std::endl;
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
		if (!found)
			std::cout << RED "             Contact not found" RESET << std::endl;
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
