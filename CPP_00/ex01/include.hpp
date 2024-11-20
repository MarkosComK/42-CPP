#ifndef INCLUDE_H
#define INCLUDE_H

#define LIST_SIZE 8

#define RESET      "\033[0m"

// Basic Colors
#define BLACK      "\033[30m"
#define RED        "\033[31m"
#define GREEN      "\033[32m"
#define YELLOW     "\033[33m"
#define BLUE       "\033[34m"
#define MAGENTA    "\033[35m"
#define CYAN       "\033[36m"
#define WHITE      "\033[37m"

#include <cstring>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"
#include "PhoneBook.hpp"

enum
{
	FIRSTNAME,
	LASTNAME,
	NICKNAME,
};

void		clearScreen(std::string str = "", int lines = 2);
void		printRetry();
void		printOptions(std::string value = "", int LastOption = 0);
std::string	toUpper(std::string option);
bool		validateOption(std::string string);
bool		validateNumber(std::string string);

#endif
