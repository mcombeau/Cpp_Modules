/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:13:40 by mcombeau          #+#    #+#             */
/*   Updated: 2022/11/27 15:20:41 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <iostream>
#include <fstream>

void	printUsage( const char *name )
{
	std::cout << "Usage: " << name << " <filename> <string_to_replace>"
		<< " <replacement_string>" << std::endl;
	return ;
}

int	openSteams( std::ifstream *ifs, std::ofstream *ofs, std::string infile, std::string outfile )
{
	ifs->open( infile.c_str(), std::ifstream::in );
	if ( !ifs->good() )
	{
		std::cerr << "Error: " << infile << ": "
			<< strerror( errno ) << std::endl;
		return ( -1 );
	}
	ofs->open( outfile.c_str(), std::ofstream::out | std::ofstream::trunc );
	if ( !ofs->good() )
	{
		ifs->close();
		std::cerr << "Error: " << outfile << ": "
			<< strerror( errno ) << std::endl;
		return ( -1 );
	}
	return ( 0 );
}

void	replaceBuffer( std::string *buffer, std::string const target, std::string const subst )
{
	size_t	pos;

	pos = 0;
	if ( target.empty() )
		return ;
	while ( pos != std::string::npos )
	{
		pos = buffer->find( target.c_str(), 0, target.length() );
		if ( pos == std::string::npos )
			break ;
		buffer->erase( pos, target.length() );
		if ( !subst.empty() )
			buffer->insert(pos, subst);
	}
}

int	copyContents( std::ifstream *ifs, std::ofstream *ofs,
				std::string const target, std::string const subst )
{
	std::string	buffer;
	
	while ( std::getline( *ifs, buffer ) )
	{
		if (ifs->fail())
			return ( -1 );
		replaceBuffer( &buffer, target, subst );
		*ofs << buffer;
		if (!ifs->eof())
			*ofs << std::endl;
	}
	return ( 0 );
}

int	main( int ac, char **av )
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		infile,
					outfile,
					target,
					subst;
	if ( ac != 4 )
	{
		printUsage( av[0] );
		return ( 1 );
	}
	infile = av[1];
	outfile = infile;
	outfile.append(".replace");
	target = av[2];
	subst = av[3];

	if ( openSteams(&ifs, &ofs, infile, outfile) == -1 )
		return ( 1 );
	if ( copyContents(&ifs, &ofs, target, subst) == -1 )
	{
		ifs.close();
		ofs.close();
		return ( 1 );
	}
	ifs.close();
	ofs.close();
	return ( 0 );
}