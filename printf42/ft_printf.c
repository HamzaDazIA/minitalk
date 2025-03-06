#include "ft_printf.h"

int	fail_check(int i)
{
	if (i < 0)
		return (-1);
	return (i);
}

int	ft_check_conversions(const char c, va_list p)
{
	int	how_mprint;

	how_mprint = 0;
	if (c == 'c')
		how_mprint += ft_putchar(va_arg(p, int));
	else if (c == 's')
		how_mprint += ft_putstr(va_arg(p, char *));
	else if (c == 'd' || c == 'i')
		how_mprint += ft_putnbr(va_arg(p, int));
	else if (c == 'u')
		how_mprint += ft_putnbr_unsignd(va_arg(p, unsigned int));
	else if (c == '%')
		how_mprint += ft_putchar('%');
	else if (c == 'X' || c == 'x')
		how_mprint += ft_printhex(va_arg(p, int), c);
	else if (c == 'p')
		how_mprint += ft_printp(va_arg(p, void *));
	return (how_mprint);
}

int	ft_printf(const char *counst, ...)
{
	va_list	p;
	int		i;
	int		how_mprint;

	if (write(1, 0, 0) == -1)
		return (-1);
	how_mprint = 0;
	i = 0;
	va_start(p, counst);
	while (counst[i] != '\0')
	{
		if (counst[i] == '%')
		{
			how_mprint += ft_check_conversions(counst[i + 1], p);
			i++;
		}
		else
			how_mprint += ft_putchar(counst[i]);
		i++;
	}
	va_end(p);
	how_mprint = fail_check(how_mprint);
	return (how_mprint);
}
