/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 10:00:58 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2021/10/27 18:49:48 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_put_p_helper(void *n)
{
	unsigned long	nb;
	unsigned int	t[100];
	int				j;
	int				i;

	nb = (unsigned long)n;
	j = 0;
	i = 0;
	while (nb >= 16)
	{
		t[j++] = nb % 16;
		nb = nb / 16;
	}
	if (nb >= 10 && nb <= 15)
		i += ft_put_c('a' + (nb - 10));
	if (!(nb >= 10 && nb <= 15))
	{
		ft_putnbr(nb);
		if (n > 0)
			i++;
	}
	while (j-- != 0)
	{
		if (!(t[j] >= 10 && t[j] <= 15))
		{
			ft_putnbr(t[j]);
			i++;
		}
		if (t[j] >= 10 && t[j] <= 15)
			i += ft_put_c('a' + (t[j] - 10));
	}
	return (i);
}

void	ft_put_p(va_list ap, int *pt_count)
{
	void	*p;

	p = va_arg(ap, void *);
	write (1, "0x", 2);
	*pt_count += 2;
	if (p == 0)
	{	
		*pt_count += ft_put_c('0');
		return ;
	}	
	*pt_count += ft_put_p_helper(p);
}
