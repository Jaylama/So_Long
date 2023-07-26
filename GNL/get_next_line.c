/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanson <jmanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:11:24 by jmanson           #+#    #+#             */
/*   Updated: 2023/07/05 15:21:33 by jmanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_newline(char *str, char *newline)
{
	size_t	i;

	i = 0;
	if (*newline != 0 && str != newline)
		ft_memcpy(newline, 0, ft_strlen(newline));
	while (str[i] != '\n' && str[i++])
		;
	if (str[i] == '\n' && str[i + 1])
	{			
		i++;
		ft_memcpy(newline, &str[i], ft_strlen(&str[i]) + 1);
		if (str != newline)
			str[--i] = '\0';
	}
	else if (str[i] == '\n')
		ft_memcpy(newline, 0, ft_strlen(newline));
	return (str);
}

char	*ft_read_buff(int fd, char *line, char *newline)
{
	int		ret;
	char	*buff;

	ret = BUFFER_SIZE;
	buff = ft_calloc(1, BUFFER_SIZE + 1);
	while (ret == BUFFER_SIZE && !ft_strnewl(buff))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		buff[ret] = '\0';
		if (ret < 1)
			break ;
		buff = ft_newline(buff, newline);
		line = ft_strjoin(line, buff);
	}
	free(buff);
	buff = NULL;
	return (line);
}

char	*check_nl(char *line, char *newline)
{
	int	i;

	i = 0;
	while (newline[i] != '\n' && newline[i++])
		;
	line = ft_calloc(1, i + 2);
	ft_memcpy(line, newline, i + 1);
	ft_newline(newline, newline);
	return (line);
}

char	*get_next_line(int fd, char *line)
{
	static char	newline[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (*newline == 0)
		line = ft_calloc(1, 1);
	else
	{
		line = 0;
		line = check_nl(line, newline);
		if (ft_strnewl(line))
		{
			line[ft_strnewl(line)] = '\0';
			goto end;
		}
	}
	line = ft_read_buff(fd, line, newline);
	end:
	if (!line || !*line)
	{
		free(line);
		return (0);
	}
	printf("%s\n", line);
	return (line);
}
/*
int	main(void)
{
	int	fd;
	int	i;
	char	*line;

	i = 0;
	line = NULL;
	fd = open("testfile.txt", O_RDONLY);
	if (fd < 1)
		return (-1);
	while (i++ < 10)
	{		
		printf("%d:\n%s\n", i, get_next_line(fd, line));
		printf("================\n");
	}
	close (fd);
	return (0);
}
*/
