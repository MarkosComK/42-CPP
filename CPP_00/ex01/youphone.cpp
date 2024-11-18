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

void PrintOptions(std::string value = "")
{
	std::cout << "   Welcome to 90s digital phonebook  " << std::endl;
	std::cout << GREEN;
	std::cout << " -------------------------------------" << std::endl;
	std::cout << "| ADD    " << ":    save a new contact      |" << std::endl;
	std::cout << "| SEARCH " << ": display a specific contact |" << std::endl;
	std::cout << "| EXIT   " << ":     quit the program       |" << std::endl;
	std::cout << " -------------------------------------" << std::endl;
	std::cout << value << std::endl;
	std::cout << RESET << std::endl;
}

void ClearScreen(std::string str = "", int lines = 2)
{
	std::cout << "\033[2J\033[1;1H"; //<-clean the screen
	std::cout << str;
	for (int i = 0; i != lines; i++)
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

int	main(void)
{
	std::string	option;
	std::string	contact1 = "contact1";
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	PhoneBook	phonebook;

	ClearScreen();
	PrintOptions();
	std::cout
		<< "  Type your choice: ";
	while (1)
	{
		std::cin >> option;
		option= toUpper(option);
		ClearScreen();
		if (option.compare("ADD") == 0)
		{
			PrintOptions("Adding a contact");
			phonebook.AddContact();
		}
		else if (option.compare("SHOW") == 0)
		{
			phonebook.ShowContacts();
		}
		else if (option.compare("EXIT") == 0)
			break;
		else
			std::cout << "Invalid option, try again!" << std::endl;
	}
}
