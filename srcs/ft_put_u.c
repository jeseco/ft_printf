/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 10:06:02 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2021/10/25 16:15:09 by JEAN-SEBA        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_put_u(va_list ap, int count)
{
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	if (u >= 10)
	{
		ft_putnbr(u / 10);
		ft_putnbr(u % 10);
	}
	else
	{
		count += ft_put_c(u + '0');
		return (count);
	}
	return (count += ft_uintlen(u));
}
