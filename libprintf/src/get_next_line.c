/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:28:23 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 12:01:43 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

int		ft_str_not_empty(char **str, char **line)
{
	int		ret;
	char	*tmp;

	ret = (int)ft_strlen(*str);
	if ((tmp = ft_strchr(*str, '\n')))
		*tmp = '\0';
	if ((int)ft_strlen(*str) < ret)
	{
		*line = ft_strdup(*str);
		if ((int)ft_strlen(*line) < ret - 1)
			*str = ft_strcpy(*str, *str + (int)ft_strlen(*line) + 1);
		else
			ft_strdel(str);
		return (1);
	}
	return (0);
}

int		ft_read_gnl(int fd, char **line, char **str)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if ((tmp = ft_strchr(buf, '\n')))
			*tmp = '\0';
		tmp = ft_strjoin(*str, buf);
		ft_strdel(str);
		*str = ft_strdup(tmp);
		ft_strdel(&tmp);
		if ((int)ft_strlen(buf) < ret)
		{
			*line = ft_strdup(*str);
			free(*str);
			if ((int)ft_strlen(buf) < ret - 1)
				*str = ft_strdup(buf + (int)ft_strlen(buf) + 1);
			else
				*str = NULL;
			return (1);
		}
	}
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str;
	int			ret;

	if (fd < 0 || BUFF_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (-1);
	if (str)
		if (ft_str_not_empty(&str, line))
			return (1);
	if (!(str))
		if (!(str = ft_strnew(0)))
			return (-1);
	if ((ret = ft_read_gnl(fd, line, &str)))
		return (1);
	if (ret == 0 && ft_strlen(str) > 0)
	{
		*line = ft_strdup(str);
		ft_strdel(&str);
		return (1);
	}
	ft_strdel(&str);
	return (ret);
}
