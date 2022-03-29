#include "../includes/so_long.h"

int	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}