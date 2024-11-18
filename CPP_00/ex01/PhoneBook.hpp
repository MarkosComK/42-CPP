#include <iostream>
#include "./Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[9];

	public:
		PhoneBook()
		{
		}

		void addContact(std::string FName, std::string LName, std::string NName)
		{
			contacts[0] = Contact(FName, LName, NName);
		}

		void showContact()
		{
			contacts[0].printContact();
		}
};
