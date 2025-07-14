#include "header.h"

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

void Contact::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}

std::string Contact::getFirstName() const
{
	return (this->firstName);
}

void Contact::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

std::string Contact::getLastName() const
{
	return (this->lastName);
}

void Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

std::string Contact::getNickname() const
{
	return (this->nickname);
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

std::string Contact::getPhoneNumber() const
{
	return (this->phoneNumber);
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

std::string Contact::getDarkestSecret() const
{
	return (this->darkestSecret);
}
