#include "PhoneBook.hpp"
#include <iostream>

bool isInteger(const std::string& str) {
	if (str.empty())
		return (false);
	for (size_t i = 0; i < str.size(); i++)
	{
		char c = str[i];
		if (!std::isdigit(c))
			return (false);
	}
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
		clearAndIgnoreInput();
		if (command == "ADD")
		{
			Contact contact;
			std::string input;
			std::cout << "First Name: ";
			std::cin >> input;
			if (!std::cin)
				return(1);
			contact.setFirstName(input);
			clearAndIgnoreInput();
			std::cout << "Last Name: ";
			std::cin >> input;
			if (!std::cin)
				return(1);
			contact.setLastName(input);
			clearAndIgnoreInput();
			std::cout << "Phone Number: ";
			std::cin >> input;
			while (!isInteger(input))
			{
				std::cout << "Please enter a valid number !" << std::endl;
				clearAndIgnoreInput();
				std::cin >> input;
			}
			if (!std::cin)
				return(1);
			contact.setPhoneNumber(input);
			clearAndIgnoreInput();
			std::cout << "Darkest Secret: ";
			std::getline(std::cin, input);
			if (!std::cin)
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
