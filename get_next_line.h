/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:34:29 by mbenicho          #+#    #+#             */
/*   Updated: 2022/05/17 19:36:41 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*get_stash(char *stash);
char	*get_line(char *stash);
int		ft_have_newline(char *str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);

#endif
