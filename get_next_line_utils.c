/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:22:34 by mbenicho          #+#    #+#             */
/*   Updated: 2022/05/10 22:22:35 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup_cat(char *dest, char *src)
{
	char	*str;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(src) + ft_strlen(dest);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (free(dest), NULL);
	while (dest[i])
	{
		str[i] = dest[i];
		i++;
	}
	while (*src)
		str[i++] = *src++;
	str[i] = 0;
	free(dest);
	return (str);
}
