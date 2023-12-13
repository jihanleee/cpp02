# include <string>
# include <iostream>
# include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called\n";
	_fixedPointNumber = 0;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &a) {
	std::cout << "Copy constructor called\n";
	*this = a;
}

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