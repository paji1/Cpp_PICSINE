/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:05:58 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/01/06 22:38:11 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sstream>

int main(int argc, char **argv)
{
	if (argc != 4)
		return 1;
	if (std::string(argv[1]).empty())
		return 6;
	if (std::string(argv[2]).empty())
		return 7;

	std::fstream input(std::string(argv[1]).c_str(), std::fstream::in);
	if (access(std::string(argv[1]).c_str(), F_OK) == -1)
		return std::cerr << "file not exist" << std::endl, 3;
	if (!input.is_open())
		return std::cerr << "permession" << std::endl, 4;

	std::fstream output(std::string(argv[1]).append(".replace").c_str(), std::fstream::out | std::fstream::trunc);
	if (access(std::string(argv[1]).append(".replace").c_str(), F_OK) == -1)
		return std::cerr << "faild to open" << std::endl, 5;
	if (!output.is_open())
		return std::cerr << "permession" << std::endl, 6;
	std::stringstream sstr;
	std::string str;

	getline(input, str, '\0');
	size_t pos = str.npos;
	while ((pos = str.find(argv[2])) != str.npos)
	{
		output << str.substr(0, pos);
		output << argv[3];
		str.erase(0, pos + std::string(argv[2]).length());
	}
	if (!str.empty())
		output << str;

	return 0;
}
