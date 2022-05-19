/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 23:23:47 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 01:15:50 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <iostream>
#include <fstream>
#include "sed42.hpp"

static bool replacer(std::ifstream* input_stream, std::ofstream* output_stream, std::string& find, std::string& replace)
{
	size_t			find_len = find.length();
	size_t			replace_len = replace.length();
	size_t			index = 0;
	std::string*	contents;

	contents = read_entire_file(input_stream);
	if (!contents)
		return (false);
	if (find_len > 0)
	{
		while ((index = contents->find(find, index)) != std::string::npos)
		{
			contents->erase(index, find_len);
			contents->insert(index, replace);
			index += replace_len;
		}
	}
	*output_stream << *contents;
	delete contents;
	return (true);
}

int		main(int argc, char **argv)
{
	std::string		replace_file;
	std::ifstream	input_stream;
	std::ofstream	output_stream;

	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <find> <replace>" << std::endl;
		exit(1);
	}

	replace_file = std::string(argv[1]) + ".replace";
	if (file_exists(replace_file))
	{
		std::string		overwrite;
		std::cout << "Warning: output file already exists. Overwrite '" << replace_file << "'? ";
		std::getline(std::cin, overwrite);
		if (std::cin.eof() || overwrite.size() == 0 || (overwrite.at(0) != 'y' && overwrite.at(0) != 'Y'))
			exit(1);
	}

	if (!open_file(&input_stream, argv[1]))
	{
		std::cerr << "Error: could not open input file" << std::endl;
		exit(1);
	}

	if (!create_file(&output_stream, replace_file))
	{
		std::cerr << "Error: could not create output file" << std::endl;
		exit(1);
	}

	std::string		find = std::string(argv[2]);
	std::string		replace = std::string(argv[3]);
	if (!replacer(&input_stream, &output_stream, find, replace))
		std::cerr << "Error: could not fully read input file" << std::endl;

	close_file(&input_stream);
	close_file(&output_stream);
}
