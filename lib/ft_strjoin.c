/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:57:47 by mlecherb          #+#    #+#             */
/*   Updated: 2022/03/29 18:57:49 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strjoin_g(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	free(s1);
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
