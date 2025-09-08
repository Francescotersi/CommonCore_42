#ifndef	FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{	
	private:
		int fixed_value;
		static const int bits = 8;
	
	public:
		Fixed();
		Fixed(const int number);
		Fixed(const float number);
		Fixed( const Fixed& other );
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int toInt( void ) const;
		float toFloat( void ) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw );

		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		Fixed operator+(const Fixed& other);
		Fixed operator-(const Fixed& other);
		Fixed operator*(const Fixed& other);
		Fixed operator/(const Fixed& other);

		Fixed& operator++();
		Fixed operator++(int other);
		Fixed& operator--();
		Fixed operator--(int);

		static Fixed& min(Fixed& other1, Fixed& other2);
		static const Fixed& min(const Fixed& other1, const Fixed& other2);
		static Fixed& max(Fixed& other1, Fixed& other2);
		static const Fixed& max(const Fixed& other1, const Fixed& other2);
};

std::ostream& operator<<(std::ostream& output, const Fixed& a);

#endif