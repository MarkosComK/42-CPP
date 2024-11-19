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

int	main(void)
{
	int			LastOption = 0;
	std::string	option;
	std::string	FirstName;
	std::string	LastName;
	std::string	NickName;
	PhoneBook	phonebook;

	clearScreen();
	while (true)
	{
		printOptions("", LastOption);
		if (!std::getline(std::cin, option))
		{
			option = "EXIT";
		}
		option= toUpper(option);
		if (option.compare("ADD") == 0)
		{
			clearScreen();
			printOptions("    Adding a contact", -1);
			phonebook.AddContact();
			LastOption = 1;
			clearScreen();
		}
		else if (option.compare("SHOW") == 0)
		{
			clearScreen();
			printOptions("    Contacts List:", -1);
			phonebook.ShowContacts();
			std::cout << "    Press Enter to continue...";
			std::cin.get();
			clearScreen();
		}
		else if (option.compare("EXIT") == 0)
		{
			clearScreen();
			printOptions("", 4);
			std::cout <<
			std::endl <<
			std::endl;
			break;
		}
		else
		{
			clearScreen();
			LastOption = 3;
		}
	}
}


//utilitary functions
void printOptions(std::string value, int LastOption)
{
	std::string message;

	switch (LastOption)
	{
		case (-1):
			message = "";
			break;
		case (0):
			message = "   Type your choice → ";
			break;
		case (1):
			value = "    Contact Succefully added";
			message = "   Type your choice → ";
			break;
		case (2):
			message = "  in progress";
			break;
		case (3):
			value = RED "    Invalid option, try again!" RESET;
			message = "   Type your choice → ";
			break;
		case (4):
			message = MAGENTA "               Bye, bye! 🥹" RESET;
			break;
	}
	std::cout << "     Welcome to 90s digital phonebook  " << std::endl;
	std::cout << GREEN;
	std::cout << "   --------------------------------------" << std::endl;
	std::cout << "  |  ADD    " << ":    save a new contact      |" << std::endl;
	std::cout << "  |  SEARCH " << ": display a specific contact |" << std::endl;
	std::cout << "  |  EXIT   " << ":     quit the program       |" << std::endl;
	std::cout << "   --------------------------------------" << std::endl;
	std::cout << value << std::endl;
	std::cout << RESET;
	std::cout
		<< message;
}

void clearScreen(std::string str, int lines)
{
	std::cout << "\033[2J\033[1;1H"; //<-clean the screen
	std::cout << str;
	for (int i = 0; i != lines; i++)
		std::cout << std::endl;
}

void	printRetry()
{
	clearScreen();
	std::cout
		<< RED "   Invalid Name," YELLOW "try again! " RESET <<
	std::endl;
}

std::string toUpper(std::string option)
{
	for (int i = 0; option[i]; i++)
	{
		option[i] = (char )toupper(option[i]);
	}
	return (option);
}

bool	validateOption(std::string string)
{
	for (int i = 0; string[i]; i++)
	{
		if (!isalpha(string[i]))
		{
			return (false);
		}
	}
	return (true);
}
