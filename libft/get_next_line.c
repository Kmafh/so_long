/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anherrer <anherrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:07:42 by anherrer          #+#    #+#             */
/*   Updated: 2022/06/14 12:48:47 by anherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_to_line(int fd, char *src)
{
	char	*buff;
	int		result;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	result = 1;
	while (!ft_strcompr(src, '\n') && result != 0)
	{
		result = read(fd, buff, BUFFER_SIZE);
		if (result < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[result] = '\0';
		src = ft_strjoin(src, buff);
	}
	free(buff);
	return (src);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*src;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (0);
	src = read_to_line(fd, src);
	if (!src)
		return (NULL);
	line = get_line(src);
	src = ft_new_left_str(src);
	return (line);
}

/*int	main(void)
{
	
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("test/test1.txt", O_RDONLY);

	i = 1;
	
	while (i < 9)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s\n", i, line);
		free(line);
		i++;
	}
	close(fd1);
	return (0);
}*/
