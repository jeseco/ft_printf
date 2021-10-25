/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JEAN-SEBA <jcourtem@student.42quebec>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 10:04:09 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2021/10/13 10:39:27 by JEAN-SEBA        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_put_s(va_list ap, int count)
{
	char	*s;
	int		i;

	s = va_arg(ap, char *);
	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			write (1, &s[i++], 1);
			count++;
		}
	}
	else
	{
		s = "(null)";
		while (s[i])
		{
			write (1, &s[i++], 1);
			count++;
		}
	}
	return (count);
}
