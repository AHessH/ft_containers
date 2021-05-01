#include "Vector.hpp"
#include <iostream>
#include <vector>
#include <string>

class Fixed
{
	private:
		int		c_fixed_poind_value;

	public:
		Fixed(int value);
		Fixed(const Fixed &);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		Fixed &operator=(const Fixed &);
};

Fixed::Fixed(int value):c_fixed_poind_value(value)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &d)
{
	std::cout << "Copy constructor called" << std::endl;
	this->c_fixed_poind_value = d.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (c_fixed_poind_value);
}

void Fixed::setRawBits(int const raw)
{
	c_fixed_poind_value = raw;
}

Fixed &Fixed::operator=(const Fixed &d)
{
	std::cout << "Assignation operator called" << std::endl;
	c_fixed_poind_value = d.getRawBits();
	return (*this);
}

int		main(void){

	ft::vector<std::string> vec;
	vec.push_back("hello");
	vec.push_back("eduard");

	std::cout << "hi" << std::endl;
	// ft::vector<std::string>::iterator it1 = vec.begin();
	// ft::vector<std::string>::iterator it2 = it1 + 1;
	// std::cout << it2->size() << std::endl;
	return (0);
}