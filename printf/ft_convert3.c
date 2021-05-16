/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:47:57 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/04/17 11:47:05 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_estim(long n)
{
	size_t	estim;
	int		isneg;

	estim = 0;
	isneg = 0;
	if (n < 0)
	{
		estim++;
		isneg++;
		n = -n;
	}
	while (n >= 1)
	{
		estim++;
		n /= 10;
	}
	return (estim);
}

static char		*ft_gen(char *rtn, long nbr, int len, int isneg)
{
	if (nbr != 0)
		rtn = malloc(sizeof(char) * (len + 1));
	else
		return (rtn = ft_strdup("0"));
	if (!rtn)
		return (0);
	isneg = 0;
	if (nbr < 0)
	{
		isneg++;
		nbr = -nbr;
	}
	rtn[len] = '\0';
	while (--len)
	{
		rtn[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (isneg == 1)
		rtn[0] = '-';
	else
		rtn[0] = (nbr % 10) + '0';
	return (rtn);
}

char			*ft_u_itoa(unsigned int n)
{
	int		len;
	char	*rtn;
	long	nbr;
	int		isneg;

	nbr = n;
	len = ft_estim(nbr);
	rtn = 0;
	isneg = 0;
	if (!(rtn = ft_gen(rtn, nbr, len, isneg)))
		return (0);
	return (rtn);
}

int	  			conv_unint(va_list ap, t_struct *list)
{
	unsigned long long	arg;
	char	*conv;
	int size;
	int neg;
	
	neg = 0;
	conv = NULL;
	if (list->star > 0 && list->width == 0)
		list->width = va_arg(ap, int);
	if (list->star > 0 && list->precisionlen == 0)
		list->precisionlen = va_arg(ap, int);
	arg = va_arg(ap, unsigned int);
	if (arg == 0 && list->precision > 0 && list->precisionlen == 0)
		return (-1);
	conv = ft_u_itoa(arg);
	size = ft_strlen(conv);
	print_int(list, conv, neg, size);
	free(conv);
		return (1);
}







