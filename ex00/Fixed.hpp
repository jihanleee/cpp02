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
		Fixed(const int &intNumber);
		Fixed(const float &floatNumber);
		Fixed(Fixed &a);
		~Fixed();
		float toFloat(void) const;
		int toInt(void) const;
		void operator=(const Fixed &oprand);
		int getRawBits(void) const;
		void setRawBits( int const raw );
};

#endif
