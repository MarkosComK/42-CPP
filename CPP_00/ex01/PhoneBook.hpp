#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "include.hpp"


class PhoneBook
{
	private:
		Contact _contacts[8];

	public:
		PhoneBook()
		{
		}
		void AddContact();
		void ShowContacts();
};

#endif
