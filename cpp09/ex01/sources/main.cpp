#include "RPN.hpp"
#include <exception>
#include <iostream>

int	main( int ac, char **av )
{
	( void )ac;
	( void )av;
	if ( ac != 2 )
	{
		std::cerr << RED "Usage: ./RPN [arg]" RESET << std::endl;
	}
	try
	{
		RPN rpn( ( std::string( av[1] ) ) );
		/* int result = rpn.calculate( std::string( av[1] ); */

	}
	catch ( std::exception & e )
	{
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	return ( 0 );
}
