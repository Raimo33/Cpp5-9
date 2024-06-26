/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:23:59 by craimond          #+#    #+#             */
/*   Updated: 2024/05/11 14:06:51 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>

template <typename T>
size_t	easyfind(const T &container, const int target)
{
	typename T::const_iterator it;

	it = std::find(container.begin(), container.end(), target);
	if (it == container.end())
		throw NotFoundException();
	return distance(container.begin(), it);
}

const char* NotFoundException::what() const throw()
{
	return "Element not found";
}