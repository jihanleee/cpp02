# include <string>
# include <iostream>
# include <cmath>
# include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called\n";
	_fixedPointNumber = 0;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

Fixed::Fixed(Fixed &a) {
	std::cout << "Copy constructor called\n";
	_fixedPointNumber = a.getRawBits();
}

Fixed::Fixed(const float fNumber) {
	float	absNumber;
/* 	int		sign; */
	float decimalPart;
	unsigned int mantissa;
	int intPart;
	float result;

	absNumber = fNumber;
/* 	sign = 1; */
	if (fNumber < 0) {
		absNumber *= -1;
/* 		sign = -1; */
	}
	intPart = (int)absNumber;
	decimalPart = absNumber - intPart;

	decimalPart = decimalPart + 1;
	std::cout <<"int part"<< intPart << std::endl;
	std::cout <<"decimal part"<< decimalPart << std::endl;
	mantissa = (*(unsigned int *)(&decimalPart) - 0x3f800000);
	*(unsigned int *)(&decimalPart) = (unsigned int)((mantissa) + 0x3f800000);
	std::cout <<"mantissa"<< mantissa << std::endl;
	std::cout << intPart << std::endl;
	std::cout << decimalPart << std::endl;
	std::cout << *(unsigned int *)(&decimalPart) << std::endl;
	_fixedPointNumber = ((intPart << 8) + (mantissa >> 15));
	*(unsigned int *)(&result) = ((_fixedPointNumber << 15) & 0x7fffff) + 0x3f800000;
	std::cout << result << std::endl;
	result += (_fixedPointNumber >> 8) - 1;
	std::cout << result << std::endl;
	std::cout << std::hex << _fixedPointNumber << std::endl;
}
/*
Fixed::Fixed(const int &iNumber) {

} */

void Fixed::operator=(const Fixed &oprand) {
	std::cout << "Copy assignment operator called\n";
	_fixedPointNumber = oprand._fixedPointNumber;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return (_fixedPointNumber);
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called\n";
	_fixedPointNumber = raw;
}