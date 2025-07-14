#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "header.h"
// #include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int contactCount; // Current index for adding new contacts
	int numberOfSavedContacts; // Number of contacts saved in the phonebook

	void addContactCount();
	void addNumberOfSavedContacts();

public:
	PhoneBook(void);
	~PhoneBook(void);

	void setNumberOfSavedContacts();
	void setContactCount();
	void setContact(Contact contact);
	void add();
	void search();

	int getNumberOfSavedContacts() const;
	Contact getContact(int i) const;
	int getContactCount() const;
};

#endif
