#include	"Point.hpp"

int	main()
{
	//std::cout << "Entrer 3 points A B et C en argument, puis un dernier point P " << std::endl;
	//std::cout << "Le programme va devoir verifier si P est dans le triangle (segments non inclus)" << std::endl;
	//std::cout << std::endl;

	//float x;
	//float y;
	//std::cout << "Point A(x,y) : " << std::endl;
	//std::cin >> x >> y;
	//Point a(x,y);
	//std::cout << "Point B(x,y) : " << std::endl;
	//std::cin >> x >> y;
	//Point b(x,y);
	//std::cout << "Point C(x,y) : " << std::endl;
	//std::cin >> x >> y;
	//Point c(x,y);
	//std::cout << "Point P(x,y) : " << std::endl;
	//std::cin >> x >> y;
	//Point pointIn(x,y);
	//std::cout << std::endl;

	//if (bsp(a, b, c, pointIn) == false)
	//	std::cout << "Le point n'est pas dans le triangle" << std::endl;
	//else
	//	std::cout << "Le point est dans le triangle" << std::endl;

    Point a(0, 0), b(5, 0), c(2.5, 5);
    Point pointIn(2.5, 2);
	Point	pointInSegment(1, 2);
	Point	pointOut(5, 5);


	std::cout << "pointin(" <<  pointIn.getPointValueX() << "," << pointIn.getPointValueY() << ")" << std::endl;
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