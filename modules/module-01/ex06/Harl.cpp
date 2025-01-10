#include	"Harl.hpp"

Harl::Harl()
{
	std::cout << "Constructor call" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Destructor call" << std::endl;
}

enum	levelNber{
	DEBUG,
	INFOS,
	WARNING,
	ERROR
};

const std::string	levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

static int	getLevelId(std::string level)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			return (i);
		}
	}
	return (-1);
}

void Harl::complain( std::string level )
{
	switch (getLevelId(level))
	{
		case DEBUG:
			std::cout << "DEBUG" << std::endl;
			std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
			break;
		case INFOS:
			std::cout << "INFOS" << std::endl;
			std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
			break;
		case WARNING:
			std::cout << "WARNING" << std::endl;
			std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month." << std::endl;
			break;
		case ERROR:
			std::cout << "ERROR" << std::endl;
			std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
			break;
		default:
			std::cout << "Unknown level: " << level << std::endl;
			break;
	}
}

void	Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}