#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook() : current_index(0), old_index(0) {}

void PhoneBook::addContact(const Contact& contact)
{
	contacts[current_index] = contact;
	current_index = (current_index + 1) % 8;
	if (current_index == old_index)
		old_index = (old_index + 1) % 8;
}

std::string checkSize(std::string str)
{
	if (str.size() > 10 )
	{
		std::string str_resize = str;
		str_resize.resize(9);
		std::string result = str_resize + ".";
		return (result);
	}
	return (str);
}

bool PhoneBook::searchContact() const
{
	if (contacts[0].getFirstName().empty())
	{
		std::cout << "You have no contact. Please add a contact before searching"
		<< std::endl;
		return (true);
	}
	
	std::cout << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Phone Number" << "|"
			<< std::endl;
	for (int i = 0; i < 8; ++i)
	{
		std::cout << std::setw(10) << i << "|"
				<< std::setw(10) << checkSize(contacts[i].getFirstName()) << "|"
				<< std::setw(10) << checkSize(contacts[i].getLastName()) << "|"
				<< std::setw(10) << checkSize(contacts[i].getPhoneNumber()) << "|"
				<< std::endl;
	}
	int index;
	std::cout << "Enter the index of the contact: ";
	while (true)
	{
		if (!(std::cin >> index)) 
		{
			if (std::cin.eof())
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				return (false);
			}
			std::cout << "Invalid input. Please enter a valid index (0 to 7): ";
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		} 
		else if (index < 0 || index >= 8) 
		{
			std::cout << "Invalid index. Please enter a valid index (0 to 7): ";
		} 
		else 
			break;
	}
	if (index >= 0 && index < 8)
	{
		std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
		std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
		std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
	}
	return (true);
}
