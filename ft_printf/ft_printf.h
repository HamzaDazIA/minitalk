/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 03:51:06 by hdazia            #+#    #+#             */
/*   Updated: 2025/03/07 03:51:07 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *counst, ...);
int	ft_putnbr(int n);
int	ft_putchar(char c);
int	ft_putnbr_unsignd(unsigned int n);
int	ft_printhex(unsigned int nb, char c);
int	fail_check(int i);
int	ft_putstr(char *s);
int	ft_printp(void *p);

#endif
