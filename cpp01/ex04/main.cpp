#include <errno.h>
#include <string.h>
#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
	std::ifstream	ifs,
					ofs;
	std::string		infile,
					outfile,
					target,
					replace;
	if (ac != 4)
	{
		std::cout << "Usage: " << av[0] << " <filename> <string_to_replace>"
			<< " <replacement_string>" << std::endl;
		return (1);
	}
	infile = av[1];
	outfile = infile;
	outfile.append(".replace");
	target = av[2];
	replace = av[3];

	std::cout << "infile = " << infile << "\noutfile = " << outfile << std::endl;

	ifs.open(infile.c_str(), std::ifstream::in);
	if (!ifs.good())
	{
		std::cerr << "Error: " << infile << ": "
			<< strerror(errno) << std::endl;
		return (1);
	}
	ofs.open(outfile.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (!ofs.good())
	{
		std::cerr << "Error: " << outfile << ": "
			<< strerror(errno) << std::endl;
		return (1);
	}

	ifs.close();
	ofs.close();
	return (0);
}