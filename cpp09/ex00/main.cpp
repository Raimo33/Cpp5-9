/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:15:45 by craimond          #+#    #+#             */
/*   Updated: 2024/05/11 15:19:38 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static int8_t	check_args(int argc, char **argv);

int main(int argc, char **argv)
{
	try
	{
		if (check_args(argc, argv) == 1)
			return 1;
		BitcoinExchange exchange(DATA_FILE);
		exchange.convertToValues(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

static int8_t	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
		return 1;
	}
	if (std::string(argv[1]).find(".csv") == std::string::npos)
	{
		std::cerr << "Error: input file must be a .csv file" << std::endl;
		return 1;
	}
	return 0;
}