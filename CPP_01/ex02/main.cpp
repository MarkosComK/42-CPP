#include <iostream>

/*
	Write a program that contains:
	• A string variable initialized to "HI THIS IS BRAIN".
	• stringPTR: A pointer to the string.
	• stringREF: A reference to the string.

	Your program has to print:
	• The memory address of the string variable.
	• The memory address held by stringPTR.
	• The memory address held by stringREF.

	And then:
	• The value of the string variable.
	• The value pointed to by stringPTR.
	• The value pointed to by stringREF.

	That’s all, no tricks. The goal of this exercise is to demystify references which can
	seem completely new. Although there are some little differences, this is another syntax
	for something you already do: address manipulation.
*/

int	main(void)
{
	//Write a program that contains:
	std::string		string = "HI THIS IS BRAIN";//<- A string variable initialized to "HI THIS IS BRAIN".
	std::string*	stringPTR = &string;//        <- stringPTR: A pointer to the string.
	std::string&	stringREF = string;//         <- stringREF: A reference to the string.
	
	std::cout << std::endl;
	//Your program has to print:
	//The memory address of the string variable.
	std::cout << "Memory address of the string:     " << &string << std::endl;
	//The memory address held by stringPTR.
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
	//The memory address held by stringREF.
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

	std::cout << std::endl;
	//And then:
	//The value of the string variable.
	std::cout << "The value of the string variable:  " << string << std::endl;
	//The value pointed to by stringPTR.
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	//The value pointed to by stringREF.
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
	std::cout << std::endl;
}
