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

};

std::ostream& operator<<(std::ostream& output, const Fixed& a);

#endif