#ifndef	__CURE_HPP__
#define	__CURE_HPP__

class Cure
{
	private:
		/* data */
	public:
		Cure();
		Cure(const Cure& copy);
		~Cure();

		Cure	&operator=(const Cure& fix);
};


#endif
