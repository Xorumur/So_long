/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:59:39 by mlecherb          #+#    #+#             */
/*   Updated: 2022/03/29 18:59:40 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_atoi(char *str)
{
	size_t				index;
	int					negative;
	unsigned long int	result;

	index = 0;
	negative = 1;
	result = 0;
	while (ft_iswspace(str[index]) == 1)
		index++;
	if (str[index] == '+' || str[index] == '-')
		if (str[index++] == '-')
			negative *= -1;
	while (ft_isdigit(str[index]))
	{
		result *= 10;
		result += str[index] - '0';
		index++;
	}
	return (result * negative);
}
