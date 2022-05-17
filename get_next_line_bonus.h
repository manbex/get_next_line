/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:00:28 by mbenicho          #+#    #+#             */
/*   Updated: 2022/05/17 20:00:30 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*get_stash(char *stash);
char	*get_line(char *stash);
int		ft_have_newline(char *str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);

#endif
