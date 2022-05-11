/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:21:56 by mbenicho          #+#    #+#             */
/*   Updated: 2022/05/10 22:21:57 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buf, char *str)
{
	char	last;
	int		i;

	last = ' ';
	while (last != '\n')
	{
		i = 0;
		while (last != '\n' && i < BUFFER_SIZE)
		{
			if (read(fd, &buf[i], 1) <= 0)
				return (NULL);
			last = buf[i];
			i++;
		}
		buf[i] = 0;
		str = ft_strdup_cat(str, buf);
		if (!str)
			return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char	*buf;
	char	*str;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	str = malloc(1);
	if (!str)
		return (free(buf), NULL);
	str[0] = 0;
	str = ft_read(fd, buf, str);
	free(buf);
	if (!str)
		return (NULL);
	return (str);
}
