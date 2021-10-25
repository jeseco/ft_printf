/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_h.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 10:08:19 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2021/10/22 14:48:44 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_put_upperh(va_list ap, int count)
{
	unsigned int	t[10];
	int				j;
	unsigned int	va;

	va = va_arg(ap, unsigned int);
	j = 0;
	while (va >= 16)
	{
		t[j++] = va % 16;
		va = va / 16;
	}
	if (va >= 10 && va <= 15)
		count += ft_put_c('A' + (va - 10));
	else
	{
		ft_putnbr(va);
		count++;
	}
	while (j-- != 0)
	{
		if (!(t[j] >= 10 && t[j] <= 15))
		{	
			ft_putnbr(t[j]);
			count++;
		}	
		else
			count += ft_put_c('A' + (t[j] - 10));
	}
	return (count);
}

int	ft_put_h(va_list ap, int count)
{
	unsigned int	t[10];
	int				j;
	unsigned int	va;

	va = va_arg(ap, unsigned int);
	j = 0;
	while (va >= 16)
	{
		t[j++] = va % 16;
		va = va / 16;
	}
	if (va >= 10 && va <= 15)
		count += ft_put_c('a' + (va - 10));
	else
	{
		ft_putnbr(va);
		count++;
	}
	while (j-- != 0)
	{
		if (!(t[j] >= 10 && t[j] <= 15))
		{	
			ft_putnbr(t[j]);
			count++;
		}	
		else
			count += ft_put_c('a' + (t[j] - 10));
	}
	return (count);
}
