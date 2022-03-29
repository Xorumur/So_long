#include "../includes/so_long.h"

static void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	n;

	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	n = (unsigned int)nb;
	if (n / 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}