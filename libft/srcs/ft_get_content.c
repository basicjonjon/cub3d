/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:47:56 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/01/20 18:49:16 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_get_content(char *start, char *end)
{
	char	*content;
	size_t	size;
	size_t	i;

	size = end - start;
	content = (char *)malloc(sizeof(char) * (size + 1));
	if (!content)
		return (NULL);
	i = 0;
	while (start != end && i < size)
	{
		content[i] = *start;
		start++;
		i++;
	}
	content[i] = '\0';
	return (content);
}
