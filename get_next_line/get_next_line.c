/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:17:06 by emarles           #+#    #+#             */
/*   Updated: 2025/01/13 19:56:27 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *str, int search_str, int pos);
char	*get_line(char *s);

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char		*line;
	static char	*storage;
	char		*tmp;

	storage = NULL;
	if (fd < 0)
		return (NULL);
	while ((read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (!storage)
			storage = ft_strdup("");
		tmp = ft_strdup(storage);
		free(storage);
		storage = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_strchr(storage, '\n', 0))
			break ;
	}
	if (!storage)
		return (NULL);
	line = get_line(storage); // this line here causes memory leaks // maybe separate function needed for getting the line
	// free(storage);
	storage = ft_strchr(storage, '\n', 0) + 1; //problem with mem leaks also possibly hier
	// free(storage);
	return (line);
}
