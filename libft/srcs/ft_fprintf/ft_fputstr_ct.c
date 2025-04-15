/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputstr_ct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:45:12 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/04/15 16:50:16 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	ft_fputstr_ct(char *str, int fd)
{
	int	count;
	int	i;

	if (!str)
		return (ft_fputstr_ct("(null)", fd));
	count = 0;
	i = 0;
	while (str[i])
	{
		count += ft_fputchar_ct(str[i], fd);
		i++;
	}
	return (count);
}
