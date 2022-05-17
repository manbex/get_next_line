/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:59:37 by mbenicho          #+#    #+#             */
/*   Updated: 2022/05/17 19:59:39 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_have_newline(char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i] && str[i] != '\n')
			i++;
		if (str[i] == '\n')
			return (1);
	}
	return (0);
}

char	*get_line(char *stash)
{
	char	*str;
	int		size;
	int		i;

	i = 0;
	size = 0;
	if (!stash)
		return (NULL);
	while (stash[size] && stash[size] != '\n')
		size++;
	if (stash[size] == '\n')
		size++;
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = stash[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*get_stash(char *stash)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = 0;
	size = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	while (stash[i + size])
		size++;
	if (!size)
		return (free(stash), NULL);
	str = malloc((size + 1) * sizeof(char));
	while (stash[i])
		str[j++] = stash[i++];
	str[j] = 0;
	return (free(stash), str);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stash[1024];
	int			readed;
	char		*str;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	readed = 1;
	while (!ft_have_newline(stash[fd]) && readed)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed < 0)
			return (free(buf), NULL);
		buf[readed] = 0;
		if (readed)
			stash[fd] = ft_strjoin(stash[fd], buf);
	}
	str = get_line(stash[fd]);
	stash[fd] = get_stash(stash[fd]);
	return (free(buf), str);
}
