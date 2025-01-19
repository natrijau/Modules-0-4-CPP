#include	"Point.hpp"

int	main( void )
{
	Point	a(0, 0);
	Point	b(4, 0);
	Point	c(2, 4);
	Point	pointIn(2, 2);
	Point	pointInSegment(1, 2);
	Point	pointOut(5, 5);


	std::cout << "Pour le point (2,2)" << std::endl;
	if (bsp(a, b, c, pointIn) == false)
		std::cout << "Le point n'est pas dans le triangle" << std::endl;
	else
		std::cout << "Le point est dans le triangle" << std::endl;
	std::cout << "Pour le point (1,2)" << std::endl;
	if (bsp(a, b, c, pointInSegment) == false)
		std::cout << "Le point n'est pas dans le triangle" << std::endl;
	else
		std::cout << "Le point est dans le triangle" << std::endl;
	std::cout << "Pour le point (5,5)" << std::endl;
	if (bsp(a, b, c, pointOut) == false)
		std::cout << "Le point n'est pas dans le triangle" << std::endl;
	else
		std::cout << "Le point est dans le triangle" << std::endl;
	return (0);
}