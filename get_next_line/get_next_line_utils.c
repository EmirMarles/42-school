/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:21:52 by emarles           #+#    #+#             */
/*   Updated: 2025/01/12 15:14:54 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s);

char	*ft_strdup(char *s)
{
	size_t	i;
	size_t	size;
	char	*new_str;

	i = 0;
	size = ft_strlen(s);
	new_str = malloc((size + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	k;
	char	*new_str;
	
	i = 0;
	k = 0;
	// free(new_str);
	new_str = malloc(((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char)));
	if (new_str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		new_str[i] = s2[k];
		i++;
		k++;
	}
	new_str[i] = '\0';
	return (new_str);
}

size_t	ft_strlen(char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

char	*ft_strchr(char *str, int search_str, int pos)
{
	int		i;

	i = 0;
	i = pos;
	while (str[i] != '\0')
	{
		if (str[i] == (char)search_str)
			return ((char *)&str[i]);
		i++;
	}
	if (search_str == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
