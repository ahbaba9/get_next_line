/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:42:52 by amine             #+#    #+#             */
/*   Updated: 2022/12/08 16:35:58 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	llen(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

char	*reading_(int fd, char *stash)
{
	char	*buffer;
	int		readed;

	buffer = malloc (sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	readed = 1;
	while (!ft_strchr(stash, '\n') && readed)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[readed] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free (buffer);
	return (stash);
}

char	*fline(char *stash)
{
	char	*str;
	int		i;
	int		linel;

	i = 0;
	linel = llen(stash);
	if (!ft_strlen(stash))
		return (NULL);
	if (stash[linel] == '\n')
		str = malloc(sizeof(char) * (linel + 2));
	else
		str = malloc(sizeof(char) * (linel +1));
	if (!str)
		return (NULL);
	while (stash[i] && i <= linel)
	{
		str[i] = stash[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*next(char *stash)
{
	char	*str;
	int		i;
	int		linel;

	linel = llen(stash);
	i = 0;
	str = malloc (sizeof(char) * (ft_strlen(stash) - llen(stash) + 1));
	linel++;
	while (stash[linel])
	{
		str[i++] = stash[linel++];
	}
	str[i] = '\0';
	free (stash);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stash[514];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 514)
		return (NULL);
	stash[fd] = reading_(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = fline(stash[fd]);
	stash[fd] = next(stash[fd]);
	return (line);
}
