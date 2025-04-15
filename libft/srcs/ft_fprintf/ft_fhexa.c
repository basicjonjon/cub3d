/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fhexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:54:57 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/04/15 16:48:17 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	ft_fhexa(unsigned int n, int i, int fd)
{
	char	*hex;
	int		count;

	count = 0;
	if (i == 0)
		hex = "0123456789abcdef";
	else if (i == 1)
		hex = "0123456789ABCDEF";
	if (n > 15)
	{
		count += ft_fhexa(n / 16, i, fd);
		count += ft_fhexa(n % 16, i, fd);
	}
	else
		count += ft_fputchar_ct(hex[n], fd);
	return (count);
}

int	ft_fhexa_llong(unsigned long long n, int fd)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (n > 15)
	{
		count += ft_fhexa_llong(n / 16, fd);
		count += ft_fhexa_llong(n % 16, fd);
	}
	else
		count += ft_fputchar_ct(hex[n], fd);
	return (count);
}
