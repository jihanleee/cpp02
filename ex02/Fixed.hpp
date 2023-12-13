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
		bool operator==(const Fixed &oprand);
		bool operator!=(const Fixed &oprand);
		bool operator <(const Fixed &oprand);
		bool operator <=(const Fixed &oprand);
		bool operator >(const Fixed &oprand);
		bool operator >=(const Fixed &oprand);
		Fixed operator+(const Fixed &oprand);
		Fixed operator-(const Fixed &oprand);
		Fixed operator*(const Fixed &oprand);
		Fixed operator/(const Fixed &oprand);
		Fixed &operator++();
		Fixed operator++(int);
		static Fixed &min(Fixed &fNumber1, Fixed &fNumber2);
		static const Fixed &min(const Fixed &fNumber1, const Fixed &fNumber2);
		static Fixed &max(Fixed &fNumber1, Fixed &fNumber2);
		static const Fixed &max(const Fixed &fNumber1, const Fixed &fNumber2);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat(void) const;
		int toInt(void) const;
};
std::ostream& operator <<(std::ostream& os, const Fixed &oprand);
#endif
