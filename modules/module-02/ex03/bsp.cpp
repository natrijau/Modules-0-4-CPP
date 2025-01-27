#include	"Point.hpp"

/*
Concept of Surface with the Vector Product
The vector product allows to calculate the surface of a triangle from two of its vectors.

For two points 𝐴 ( 𝑥 1 , 𝑦 1 ) A(x 1 ​ ,y 1 ​ ) and 𝐵 ( 𝑥 2 , 𝑦 2 ) B(x 2 ​ ,y 2 ​ ), the vector 𝐴𝐵 ⃗ is:
𝐴𝐵 ⃗ = ( 𝑥 2 − 𝑥 1 , 𝑦 2 − 𝑦 1 )

The surface area is proportional to the norm of the vector product between 𝐴𝐵 ⃗ and 𝐴𝐶 ⃗ :
Surface area = 1/2 × ∣ 𝐴 𝐵 ⃗ × 𝐴 𝐶 ⃗ ∣

In 2D, the norm of a vector product is given by:
𝑢 ⃗ × 𝑣 ⃗ = 𝑢𝑥 * 𝑣𝑦 − 𝑢𝑦 * 𝑣 𝑥 u × v = ux ​ * vy ​ − uy ​* vx ​

Thus, the surface area of ​​a triangle formed by 𝐴 A, 𝐵 B, and 𝐶 C is:
𝑆urface𝐴𝐵𝐶 = 1/2 ⋅ ∣ ( 𝑥 𝐵 − 𝑥 𝐴 ) * ( 𝑦 𝐶 − 𝑦 𝐴 ) − ( 𝑦 𝐵 − 𝑦 𝐴 ) * ( 𝑥 𝐶 − 𝑥 𝐴 ) ∣
*/

void	allPos(Fixed &abVectorX, Fixed &abVectorY, Fixed &acVectorX, Fixed &acVectorY)
{
	if (abVectorX < 0)
		abVectorX = abVectorX * -1;
	if (abVectorY < 0)
		abVectorY = abVectorY * -1;
	if (acVectorX < 0)
		acVectorX = acVectorX * -1;
	if (acVectorY < 0)
		acVectorY = acVectorY * -1;	
}

Fixed	surface(Point a, Point b, Point c)
{
	Fixed	abVectorX = b.getPointValueX() - a.getPointValueX();
	Fixed	abVectorY = b.getPointValueY() - a.getPointValueY();
	Fixed	acVectorX = c.getPointValueX() - a.getPointValueX();
	Fixed	acVectorY = c.getPointValueY() - a.getPointValueY();	

	return (((abVectorX * acVectorY) - (abVectorY * acVectorX)) / 2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{	
	Fixed	surfaceAbc = surface(a, b, c);
	Fixed	surfacePab = surface(point, a, b);
	Fixed	surfacePac = surface(point, a, c);
	Fixed	surfacePbc = surface(point, b, c);
	
	allPos(surfaceAbc, surfacePab, surfacePac, surfacePbc);
	
	std::cout << std::endl;
	std::cout << "Le principe est de calculer la somme des surfaces des triangles qui ont en communs le point P.";
	std::cout << "Ici PAB, PBC et PCA." << std::endl;
	std::cout << "On peut ensuite comparer cette somme avec la surface du triangle principale ABC." << std::endl;
	std::cout << "Si la somme des triangles(P...) >= ABC le point n'est pas dans le triangle" << std::endl;
	std::cout << "Si la somme des triangles(P...) < ABC le point est pas dans le triangle" << std::endl;
	std::cout << std::endl;

	std::cout << "La surface du triangle PAB : " <<surfacePab << std::endl;
	std::cout << "La surface du triangle PAC : " <<surfacePac << std::endl;
	std::cout << "La surface du triangle PBC : " <<surfacePbc << std::endl;
	std::cout << "La somme des triangles(P...) : " << (surfacePab + surfacePac + surfacePbc) << std::endl;
	std::cout << "La surface du triangle ABC : " << surfaceAbc << std::endl;
	std::cout << std::endl;

	if (surfacePab == 0 || surfacePac == 0 || surfacePbc == 0)
	{
		std::cout << "Le point est sur un des segments du triangle" << std::endl;
		return (false);
	}	
	if (surfaceAbc != (surfacePab + surfacePac + surfacePbc))
		return (false);
	return (true);
}