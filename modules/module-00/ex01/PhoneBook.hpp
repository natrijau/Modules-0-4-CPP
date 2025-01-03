#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int current_index;
		int old_index;

	public:
		PhoneBook();
		void addContact(const Contact& contact);
		bool searchContact() const;
};

#endif
