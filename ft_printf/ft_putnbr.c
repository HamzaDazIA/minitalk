#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nb;
	int		how_mprint;

	how_mprint = 0;
	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		how_mprint += 1;
		nb *= -1;
	}
	if (nb > 9)
	{
		how_mprint += ft_putnbr(nb / 10);
		how_mprint += ft_putchar((nb % 10) + '0');
	}
	else
		how_mprint += ft_putchar(nb + '0');
	return (how_mprint);
}
