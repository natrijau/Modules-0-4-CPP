#include	"Point.hpp"

/*
	2. Notion de Surface avec le Produit Vectoriel
	Le produit vectoriel permet de calculer la surface d’un triangle à partir de deux de ses vecteurs.
	
	Pour deux points 𝐴 ( 𝑥 1 , 𝑦 1 ) A(x 1 ​ ,y 1 ​ ) et 𝐵 ( 𝑥 2 , 𝑦 2 ) B(x 2 ​ ,y 2 ​ ), le vecteur 𝐴𝐵 ⃗ est : 
		𝐴𝐵 ⃗ = ( 𝑥 2 − 𝑥 1 , 𝑦 2 − 𝑦 1 )
	
	La surface est proportionnelle à la norme du produit vectoriel entre 𝐴𝐵 ⃗ et 𝐴𝐶 ⃗ : 
		Surface = 1/2 × ∣ 𝐴 𝐵 ⃗ × 𝐴 𝐶 ⃗ ∣
		
	En 2D, la norme d’un produit vectoriel est donnée par : 
		𝑢 ⃗ × 𝑣 ⃗ = 𝑢𝑥 * 𝑣𝑦 − 𝑢𝑦 * 𝑣 𝑥 u × v = ux ​ * vy ​ − uy ​* vx ​ 
	
	Ainsi, la surface d’un triangle formé par 𝐴 A, 𝐵 B, et 𝐶 C est :
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
	//std::cout << surfaceAbc << std::endl;
	//std::cout << surfacePab << std::endl;
	//std::cout << surfacePac << std::endl;
	//std::cout << surfacePbc << std::endl;
	if (surfacePab == 0 || surfacePac == 0 || surfacePbc == 0)
	{
		std::cout << "Le point est sur un des segments du triangle" << std::endl;
		return (false);
	}	
	if (surfaceAbc != (surfacePab + surfacePac + surfacePbc))
		return (false);
	return (true);
}