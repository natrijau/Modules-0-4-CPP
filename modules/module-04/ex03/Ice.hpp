#ifndef	__ICE_HPP__
#define	__ICE_HPP__

class Ice
{
	private:
		/* data */
	public:
		Ice();
		Ice(const Ice& copy);
		~Ice();

		Ice	&operator=(const Ice& fix);
};

#endif
