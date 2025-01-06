#include "PhoneBook.hpp"
#include <iostream>

bool isInteger(const std::string& str)
{
	for (size_t i = 1; i < str.size(); i++)
	{
		char c = str[i];
		if (!std::isdigit(c))
			return (false);
	}
	return (true);
}

bool isPhoneNumber(const std::string& str)
{
	if (str.empty())
		return (false);
	if (!(str[0] == '+' || std::isdigit(str[0])))
		return (false);
	if (!isInteger(str))
		return (false);
	return (true);
}

void	clearAndIgnoreInput()
{
	std::cin.clear();
	std::cin.ignore(1000, '\n');
}

int main() {
	PhoneBook phoneBook;
	std::string command;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::cin >> command;
		if (!std::cin)
			return(1);
		//clearAndIgnoreInput();
		if (command == "ADD")
		{
			Contact contact;
			std::string input;
			std::cout << "First Name: ";
			std::getline(std::cin >> std::ws, input);
			if (!std::cin)
				return(1);
			contact.setFirstName(input);
			std::cout << "Last Name: ";
			std::getline(std::cin >> std::ws, input);
			if (!std::cin)
				return(1);
			contact.setLastName(input);
			std::cout << "Phone Number: ";
			std::cin >> input;
			if (!std::cin)
				return(1);
			while (!isPhoneNumber(input))
			{
				std::cout << "Please enter a valid number !" << std::endl;
				clearAndIgnoreInput();
				std::cin >> input;
				if (!std::cin)
					return(1);
			}
			contact.setPhoneNumber(input);
			clearAndIgnoreInput();
			std::cout << "Darkest Secret: ";
			if (!std::getline(std::cin >> std::ws, input))
				return(1);
			contact.setDarkestSecret(input);
			phoneBook.addContact(contact);
		}
		else if (command == "SEARCH")
		{
			if (!(phoneBook.searchContact()))
				return (1);
		}
		else if (command == "EXIT")
		{
			std::cout << "Goodbye !" << std::endl;
			return (0);
		}
	}

	return (0);
}
