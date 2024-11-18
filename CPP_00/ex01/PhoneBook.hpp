#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "include.hpp"


class PhoneBook
{
	private:
		Contact _contacts[9];

	public:
		PhoneBook()
		{
		}
		void AddContact(std::string FName, std::string LName, std::string NName);
		void ShowContacts();
};

#endif
