/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:02:15 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/18 18:05:46 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

void PrintOptions()
{
	std::cout << " -------------------------------------" << std::endl;
	std::cout << "| ADD    " << ":    save a new contact      |" << std::endl;
	std::cout << "| SEARCH " << ": display a specific contact |" << std::endl;
	std::cout << "| EXIT   " << ":     quit the program       |" << std::endl;
	std::cout << " -------------------------------------" << std::endl;
}

void clearScreen() {
	for (int i = 0; i < 50; i++)
		std::cout << std::endl;
}

std::string toUpper(std::string option)
{
	for (int i = 0; option[i]; i++)
	{
		option[i] = (char )toupper(option[i]);
	}
	return (option);
}

enum options
{
	ADD,
	SEARCH,
	EXIT,
};

int	main(void)
{
	std::string	option;
	std::string	contact1 = "contact1";
	PhoneBook	phonebook;

	PrintOptions();
	std::cout
		<< "  Chose a option: ";
	std::cin >> option;
	option= toUpper(option);
	std::cout
		<< "  You entered: " << option <<
	std::endl;
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	while (1)
	{
		if (option.compare("ADD") == 0)
		{
			std::cout
				<< "Type the first name: ";
			std::cin >> FirstName;
			std::cout
				<< "Type the last name: ";
			std::cin >> LastName;
			std::cout
				<< "Chose the nick name: ";
			std::cin >> NickName;
			phonebook.AddContact(FirstName, LastName, NickName);
		}
		if (option.compare("SHOW") == 0)
		{
			phonebook.ShowContacts();
		}
		if (option.compare("EXIT"))
			break;
	}
}
