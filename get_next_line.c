/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:15:24 by vradchen          #+#    #+#             */
/*   Updated: 2017/12/12 14:15:25 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char			*ft_strjoin2(char *s1, char *s2)
{
	int			len;
	int			i;
	int			i2;
	char		*s3;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = (char*)malloc(sizeof(char) * len + 1);
	if (s3 == NULL)
		return (NULL);
	i = 0;
	i2 = 0;
	while (s1[i2])
		s3[i++] = s1[i2++];
	i2 = 0;
	while (s2[i2])
		s3[i++] = s2[i2++];
	s3[i] = '\0';
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (s3);
}

static char		*ft_trim(char *s)
{
	int			i;
	char		*s2;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (NULL);
	if (!(s2 = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

static int		ft_w2(char **line, char **buffer)
{
	char		*buffer2;
	char		*str;

	buffer2 = ft_strdup(*buffer);
	str = buffer2;
	if (*buffer2 == '\0')
		return (0);
	*line = ft_trim(buffer2);
	if (*line == NULL)
	{
		*line = ft_strdup(buffer2);
		while (*buffer2)
			buffer2++;
		*buffer = ft_strdup(buffer2);
		return (1);
	}
	while (*buffer2 != '\n')
		buffer2++;
	buffer2++;
	*buffer = ft_strdup(buffer2);
	free(str);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*buffer[45000];
	int			n;
	char		*tmp;

	n = 1;
	if (fd < 0 || fd == 2)
		return (-1);
	if (buffer[fd] == NULL)
		buffer[fd] = ft_strnew(0);
	while (n != 0)
	{
		tmp = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
		n = read(fd, tmp, BUFF_SIZE);
		if (n == -1)
			return (-1);
		tmp[n] = '\0';
		buffer[fd] = ft_strjoin2(buffer[fd], tmp);
	}
	return (ft_w2(line, &buffer[fd]));
}
