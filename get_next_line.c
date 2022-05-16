/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:32:20 by mbenicho          #+#    #+#             */
/*   Updated: 2022/05/16 17:32:21 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	size;
	int		i;

	i = -1;
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		*s1 = 0;
	}
	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s1[++i])
		str[i] = s1[i];
	while (*s2)
		str[i++] = *s2++;
	str[i] = 0;
	return (free(s1), str);
}

int		ft_have_newline(char *stash)
{
	size_t	i;

	i = 0;
	if (stash)
	{
		while (stash[i] && stash[i] != '\n')
			i++;
		if (stash[i] == '\n')	
			return (1);
	}
	return (0);
}

char	*get_line(char *stash)
{
	size_t	i;
	size_t	size;
	char	*str;

	size = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[size] && stash[size] != '\n')
		size++;
	str = malloc((size + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		str[i] = stash[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*get_stash(char *stash, int readed)
{
	size_t	i;
	char	*str;

	i = 0;
	while (*stash && *stash != '\n')
		stash++;
	if (!*stash && readed)
		return (free(stash), NULL);
	while (stash[i])
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (free(stash), NULL);
	i = 0;
	while (*stash)
		str[i++] = *stash++;
	str[i] = 0;
	return (free(stash), str);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stash;
	int			readed;
	char		*str;

	if (BUFFER_SIZE < 1)
		return (NULL);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	readed = 1;
	while (!ft_have_newline(stash) && readed)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed < 0)
			return (free(buf), NULL);
		buf[readed] = 0;
		stash = ft_strjoin(stash, buf);
	}
	str = get_line(stash);
	stash = get_stash(stash, readed);
	return (free(buf), str);
}


#include <fcntl.h>
int	main()
{
	int		fd;
	char	*str;

	fd = open("txt", O_RDONLY);

	str = get_next_line(fd);
	printf("%s", str);
	free(str);

	/*str = get_next_line(fd);
	printf("%s", str);
	free(str);

	str = get_next_line(fd);
	printf("%s", str);
	free(str);

	str = get_next_line(fd);
	printf("%s", str);
	free(str);*/

	close(fd);
	return (0);
}
