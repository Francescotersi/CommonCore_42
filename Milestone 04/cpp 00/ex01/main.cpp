#include "header.h"

int main()
{
	PhoneBook phonebook;
	std::string input;

	otacon_calls_in();
	phonebook.setContactCount();
	phonebook.setNumberOfSavedContacts();
	while (input != "EXIT")
	{
		codec_instructions();
		std::getline(std::cin, input);
		if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else if (input != "EXIT")
			otacon_gets_angry();
	}
	otacon_calls_out();
	return (0);
}
