/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:42:27 by mmarpaul          #+#    #+#             */
/*   Updated: 2024/12/11 19:52:00 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_print_tab_fd(char **tab, int fd)
{
	int	i;

	if (!tab || !(*tab))
		return ;
	i = 0;
	while (tab[i])
	{
		ft_putstr_fd(tab[i], fd);
		write(fd, "\n", 1);
		i++;
	}
}
