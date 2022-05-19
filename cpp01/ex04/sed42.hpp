/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sed42.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 23:30:14 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 01:17:24 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <fstream>

#define BUFFER_SIZE 128

bool			open_file(std::ifstream* stream, std::string path);
bool			create_file(std::ofstream* stream, std::string path);
bool			file_exists(std::string path);
std::string*	read_entire_file(std::ifstream* input_stream);
void			close_file(std::ifstream* stream);
void			close_file(std::ofstream* stream);
