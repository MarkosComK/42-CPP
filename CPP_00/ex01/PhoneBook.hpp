#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "include.hpp"


class PhoneBook
{
	private:
		Contact _contacts[LIST_SIZE + 1];

	public:
		PhoneBook()
		{
		}
		void AddContact();
		void ShowContacts();
};

#endif
