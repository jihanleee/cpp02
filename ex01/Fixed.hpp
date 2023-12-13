#ifndef FIXED_HPP
# define FIXED_HPP
# include <string>
# include <iostream>

class Fixed{
	private:
		int _fixedPointNumber;
		static const int _fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &a);
		Fixed(const float fNumber);
		Fixed(const int iNumber);
		~Fixed();
		void operator=(const Fixed &oprand);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat(void) const;
		int toInt(void) const;
};
std::ostream& operator <<(std::ostream& os, const Fixed &oprand);
#endif
