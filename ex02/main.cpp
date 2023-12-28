#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed numA(256.256f);
	Fixed numB(-256.256f);

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << "max(a,b):" << Fixed::max( a, b ) << std::endl;
	std::cout << "min(a,b):"<< Fixed::min(a, b) << std::endl;
	std::cout << std::endl;

	std::cout << "numA:" << numA;
	std::cout << " numB:" << numB << std::endl;

	if (numA < numB)
		std::cout << "numA < numB is true\n";
	else
		std::cout << "numA < numB is false\n";
	if (numA <= numB)
		std::cout << "numA <= numB is true\n";
	else
		std::cout << "numA <= numB is false\n";
	if (numA > numB)
		std::cout << "numA > numB is true\n";
	else
		std::cout << "numA > numB is false\n";
	if (numA >= numB)
		std::cout << "numA >= numB is true\n";
	else
		std::cout << "numA >= numB is false\n";
	if (numA == numB)
		std::cout << "numA == numB is true\n";
	else
		std::cout << "numA == numB is false\n";
	if (numA != numB)
		std::cout << "numA != numB is true\n";
	else
		std::cout << "numA != numB is false\n";
	std::cout << std::endl;

	std::cout << "numA + numB is " << numA + numB << std::endl; 
	std::cout << "numA - numB is " << numA - numB << std::endl;
	std::cout << "numA * numB is " << numA * numB << std::endl;
	std::cout << "numA / numB is " << numA / numB << std::endl;
	std::cout << std::endl;

	return 0;
}
