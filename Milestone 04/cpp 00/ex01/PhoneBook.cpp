#include "header.h"

PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::setContact(Contact contact)
{
	this->contacts[this->contactCount] = contact;
}

Contact PhoneBook::getContact(int i) const
{
	return (this->contacts[i]);
}

void PhoneBook::addContactCount()
{
	if (this->contactCount >= 7)
		this->contactCount = 0;
	else
		this->contactCount += 1;
}

void PhoneBook::setContactCount()
{
	this->contactCount = 0;
}

int PhoneBook::getContactCount() const
{
	return (this->contactCount);
}

void PhoneBook::addNumberOfSavedContacts()
{
	if (numberOfSavedContacts < 8)
		this->numberOfSavedContacts += 1;
}

void PhoneBook::setNumberOfSavedContacts()
{
	this->numberOfSavedContacts = 0;
}

int PhoneBook::getNumberOfSavedContacts() const
{
	return (this->numberOfSavedContacts);
}

void	print_per_column(std::string str)
{
	if (str.length() >= 10)
		std::cout << std::setw(10) << std::right << str.substr(0,9) + '.';
	else	
		std::cout << std::setw(10) << std::right << str;
	std::cout << "|";
}

void	print_contacts(Contact contacts)
{
	print_per_column(contacts.getFirstName());
	print_per_column(contacts.getLastName());
	print_per_column(contacts.getNickname());

	std::cout << std::endl;
}

void	PhoneBook::search()
{
	int j = 0;
	std::string input;

	while (j < this->numberOfSavedContacts)
	{
		print_per_column(std::to_string(j + 1));
		print_contacts(this->contacts[j]);
		j++;
	}
	otacon_asks_for_index();
	std::getline(std::cin, input);
	if (input == "EXIT")
		return ;
	if (input != "1" && input != "2" && input != "3" &&
		input != "4" && input != "5" && input != "6" &&
		input != "7" && input != "8")
		return ;
	int index = std::stoi(input);
	if (index >= 1 && index <= this->numberOfSavedContacts)
	{
		index -= 1; // Adjust for 0 based index
	
		std::cout << "First Name: " << this->contacts[index].getFirstName() << std::endl;
		std::cout << "Last Name: " << this->contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << this->contacts[index].getNickname() << std::endl;
		std::cout << "Phone Number: " << this->contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << this->contacts[index].getDarkestSecret() << std::endl;
	}
	if (this->contacts[index].getFirstName() == "Liquid" &&
		this->contacts[index].getLastName() == "Snake")
		otacon_easter_egg();
}

int	check_if_empty(std::string str)
{
	if (str.empty())
		return (1);
	for (int i = 0; i < str.length(); i++)
	{
		if ((str[i]) != ' ' && str[i] != '\t')
			return (0);
	}
	return (1);
}

void	PhoneBook::add()
{
	Contact		contact;
	std::string	input;

	slowPrint("Insert first name", 10);
	std::getline(std::cin, input);
	if (check_if_empty(input) == 1)
	{
		otacon_makes_snake_feel_bad();
		return ;
	}
	contact.setFirstName(input);

	slowPrint("Insert last name", 10);
	std::getline(std::cin, input);
	if (check_if_empty(input) == 1)
	{
		otacon_makes_snake_feel_bad();
		return ;
	}
	contact.setLastName(input);

	slowPrint("Insert Nickname", 10);
	std::getline(std::cin, input);
	if (check_if_empty(input) == 1)
	{
		otacon_makes_snake_feel_bad();
		return ;
	}
	contact.setNickname(input);

	slowPrint("Insert Codec frequency", 10);
	std::getline(std::cin, input);
	if (check_if_empty(input) == 1)
	{
		otacon_makes_snake_feel_bad();
		return ;
	}
	contact.setPhoneNumber(input);

	slowPrint("Finally enter his darkest secret", 10);
	std::getline(std::cin, input);
	if (check_if_empty(input) == 1)
	{
		otacon_makes_snake_feel_bad();
		return ;
	}
	contact.setDarkestSecret(input);

	setContact(contact);
	addContactCount();
	addNumberOfSavedContacts();

	slowPrint("-Contact frequency saved-", 20);

	// std::cout << contact.getFirstName() << " "
	// 	  << contact.getLastName() << " "
	// 	  << contact.getNickname() << " "
	// 	  << contact.getPhoneNumber() << " "
	// 	  << contact.getDarkestSecret() << std::endl;
}
