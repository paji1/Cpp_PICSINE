/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:21:18 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/12/02 12:30:40 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>
namespace std
{
	extern ostream cout;
	ios_base::Init __foo;
}

int main(int argc, char const *argv[])
{
	for (int i = 1; i < argc; i++)
		for (int j = 0; argv[i][j] ; j++)
			std::cout << (char)toupper(argv[i][j]);
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return 0;
}
