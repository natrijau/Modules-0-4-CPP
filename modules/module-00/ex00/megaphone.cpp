#include <iostream>
#include <string>

int main(int ac, char **av)
{
	if(ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (size_t i = 1; i < ac; i++)
	{
		std::string str = av[i];
		for (size_t j = 0; str[j]; j++)
			std::cout << (char)toupper(str[j])  ;
	}
	std::cout << std::endl;
	return (0);
}