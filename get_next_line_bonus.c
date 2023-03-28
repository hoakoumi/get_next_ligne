/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoakoumi <hoakoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:37:06 by hoakoumi          #+#    #+#             */
/*   Updated: 2022/12/26 20:08:44 by hoakoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*reading(int fd, char *s)
{
	char	*buffer;
	int		nbr;

	nbr = 1;
	buffer = malloc (sizeof (char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!search(s) && nbr != 0)
	{
		nbr = read (fd, buffer, BUFFER_SIZE);
		if (nbr == -1)
		{
			free (buffer);
			free (s);
			return (NULL);
		}
		buffer[nbr] = '\0';
		s = join (s, buffer);
	}
	free (buffer);
	return (s);
}

char	*checking(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s[i])
		return (NULL);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	str = (char *)malloc (sizeof (char) * (i + 2));
	if (!str)
		return (NULL);
	while (s[j] != '\0' && s[j] != '\n')
	{
		str[j] = s[j];
		j++;
	}
	if (s[j] == '\n')
	{
		str[j] = s[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*testing(char *s)
{
	int		i;
	char	*str;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free (s);
		return (NULL);
	}
	str = (char *)malloc (sizeof (char) * (ft_strlen(s) - i));
	if (!str)
		return (NULL);
	i++;
	while (s[i] != '\0')
		str[j++] = s[i++];
	str[j] = '\0';
	free (s);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*h[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	h[fd] = reading (fd, h[fd]);
	if (!h[fd])
		return (NULL);
	line = checking (h[fd]);
	h[fd] = testing (h[fd]);
	return (line);
}
