# include <string>
# include <iostream>
# include <cmath>
# include "Fixed.hpp"

Fixed::Fixed() {
	/* std::cout << "Default constructor called\n"; */
	_fixedPointNumber = 0;
}

Fixed::~Fixed() {
	/* std::cout << "Destructor called\n"; */
}

Fixed::Fixed(const Fixed &a) {
	/* std::cout << "Copy constructor called\n"; */
	*this = a;
}

Fixed::Fixed(const float fNumber) {
	float	absNumber;
	int		sign;
	float decimalPart;
	unsigned int mantissa;
	int intPart;

	/* std::cout << "Float constructor called\n"; */
	absNumber = fNumber;
	sign = 1;
	if (fNumber < 0) {
		absNumber *= -1;
		sign = -1;
	}
	intPart = (int)absNumber;
	decimalPart = absNumber - intPart;
	decimalPart = decimalPart + 1;
	mantissa = (*(unsigned int *)(&decimalPart) - 0x3f800000);
	*(unsigned int *)(&decimalPart) = (unsigned int)((mantissa) + 0x3f800000);
	_fixedPointNumber = ((intPart << 8) + (mantissa >> 15)) + 1;
	if (sign == -1)
		_fixedPointNumber = ~_fixedPointNumber + 1;
}

Fixed::Fixed(const int iNumber) {
	int absNumber;
	int sign;

	/* std::cout << "Int constructor called\n"; */
	absNumber = iNumber;
	sign = 1;
	if (iNumber < 0) {
		absNumber *= -1;
		sign = -1;
	}
	_fixedPointNumber = (absNumber << 8);
	if (sign == -1)
		_fixedPointNumber = ~_fixedPointNumber + 1;
}

float Fixed::toFloat(void) const {
	float result;

	*(unsigned int *)(&result) = ((_fixedPointNumber << 15) & 0x7fffff) + 0x3f800000;
	result += (_fixedPointNumber >> 8) - 1;
	return (result);
}

int Fixed::toInt(void) const {
	int result;

	result = (_fixedPointNumber >> 8);
	return (result);
}

std::ostream& operator<<(std::ostream& os, const Fixed &oprand) {
	os << oprand.toFloat();
	return (os);
}

void Fixed::operator=(const Fixed &oprand) {
	/* std::cout << "Copy assignment operator called\n"; */
	_fixedPointNumber = oprand._fixedPointNumber;
}

bool Fixed::operator==(const Fixed &oprand) {
	return (_fixedPointNumber == oprand._fixedPointNumber);
}

bool Fixed::operator!=(const Fixed &oprand) {
	return (_fixedPointNumber != oprand._fixedPointNumber);
}

bool Fixed::operator<(const Fixed &oprand) {
	return (_fixedPointNumber < oprand._fixedPointNumber);
}

bool Fixed::operator<=(const Fixed &oprand) {
	return (_fixedPointNumber <= oprand._fixedPointNumber);
}

bool Fixed::operator>(const Fixed &oprand) {
	return (_fixedPointNumber > oprand._fixedPointNumber);
}

bool Fixed::operator>=(const Fixed &oprand) {
	return (_fixedPointNumber >= oprand._fixedPointNumber);
}

Fixed &Fixed::operator++() {
	(this->_fixedPointNumber)++;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed copy(*this);
	++(*this);
	return (copy);
}

Fixed Fixed::operator+(Fixed const &oprand){
	Fixed result;
	result._fixedPointNumber = _fixedPointNumber + oprand._fixedPointNumber;
	return (result);
}

Fixed Fixed::operator-(Fixed const &oprand){
	Fixed result;
	result._fixedPointNumber = _fixedPointNumber - oprand._fixedPointNumber;
	return (result);
}

Fixed Fixed::operator*(Fixed const &oprand){
	Fixed result;
	long	temp;

	temp = ((long)_fixedPointNumber * (long)oprand._fixedPointNumber);
	temp = (temp >> 8);
	result._fixedPointNumber = (int)temp;
	return (result);
}

Fixed Fixed::operator/(Fixed const &oprand){
	Fixed result;
	long	temp;
	long	temp1;

	temp1 = ((long)_fixedPointNumber << 8);
	temp = temp1 / oprand._fixedPointNumber;
	result._fixedPointNumber = (int)temp;
	return (result);
}

Fixed &Fixed::min(Fixed &fNumber1, Fixed &fNumber2){
	if (fNumber1 <= fNumber2)
		return (fNumber1);
	else
		return (fNumber2);
}

const Fixed &Fixed::min(const Fixed &fNumber1, const Fixed &fNumber2){
	Fixed tmp1(fNumber1);
	Fixed tmp2(fNumber2);

	if (tmp1 <= tmp2)
		return (fNumber1);
	else
		return (fNumber2);
}
Fixed &Fixed::max(Fixed &fNumber1, Fixed &fNumber2){
	if (fNumber1 >= fNumber2)
		return (fNumber1);
	else
		return (fNumber2);
}
const Fixed &Fixed::max(const Fixed &fNumber1, const Fixed &fNumber2){
	Fixed tmp1(fNumber1);
	Fixed tmp2(fNumber2);

	if (tmp1 <= tmp2)
		return (fNumber1);
	else
		return (fNumber2);
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return (_fixedPointNumber);
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called\n";
	_fixedPointNumber = raw;
}
