/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 10:00:30 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2021/10/22 15:00:31 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdarg.h>

int	ft_check_flag(const char flag, va_list ap, int count)
{	
	if (flag == 'c')
		count += ft_put_c(va_arg(ap, int));
	else if (flag == 'd' || flag == 'i')
		count += ft_put_i(ap);
	else if (flag == 'p')
		count = ft_put_p(ap, count);
	else if (flag == 's')
		count = ft_put_s(ap, count);
	else if (flag == 'u')
		count = ft_put_u(ap, count);
	else if (flag == 'x')
		count = ft_put_h(ap, count);
	else if (flag == 'X')
		count = ft_put_upperh(ap, count);
	else if (flag == '%')
	{
		write (1, "%", 1);
		count++;
	}
	return (count);
}
