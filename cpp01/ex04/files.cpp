/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   files.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 23:30:01 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 01:17:28 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sed42.hpp"
#include <iostream>
#include <fstream>

bool	open_file(std::ifstream* stream, std::string path)
{
	stream->open(path, std::ifstream::in);
	return (stream->is_open());
}

bool	create_file(std::ofstream* stream, std::string path)
{
	stream->open(path, std::ofstream::out);
	return (stream->is_open());
}

bool	file_exists(std::string path)
{
	std::ifstream	stream;
	bool			exists;

	stream.open(path, std::ifstream::in);
	exists = stream.good();
	stream.close();
	return (exists);
}

void	close_file(std::ifstream* stream)
{
	stream->close();
}

void	close_file(std::ofstream* stream)
{
	stream->close();
}

std::string*	read_entire_file(std::ifstream* input_stream)
{
	std::string*	contents = new std::string("");
	char			buffer[BUFFER_SIZE + 1];

	while (true)
	{
		try
		{
			bzero(buffer, BUFFER_SIZE + 1);
			input_stream->read(buffer, BUFFER_SIZE);
			contents->append(buffer);
			if (input_stream->eof())
				break;
		}
		catch ( ... )
		{
			delete contents;
			return (NULL);
		}
	}
	return (contents);
}
