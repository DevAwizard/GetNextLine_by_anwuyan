* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:41:34 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/03/17 18:57:12 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		index_s1;
	int		index_s2;
	char	*new_string;

	if (!s1 && !s2)
		return (NULL);
	new_string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen (s2)) + 1);
	if (!new_string)
		return (NULL);
	index_s1 = 0;
	while (s1 && s1[index_s1] != '\0')
	{
		new_string[index_s1] = s1[index_s1];
		index_s1++;
	}
	index_s2 = 0;
	while (s2 && s2[index_s2] != '\0')
		new_string[index_s1++] = s2[index_s2++];
	new_string[index_s1] = '\0';
	if (s1)
		free(s1);
	return (new_string);
}

char	*ft_return_line_after_cheking_linefeed(char *old_line)
{
	int			index;
	char		*new_line;

	if (!old_line || old_line[0] == '\0')
		return (NULL);
	index = 0;
	while (old_line[index] != '\0' && old_line [index] != '\n')
		index++;
	new_line = malloc(sizeof(char) * (index + 2));
	index = 0;
	while (old_line[index] != '\n' && old_line[index] != '\0')
	{
		new_line[index] = old_line[index];
		index++;
	}
	if (old_line[index] == '\n')
		new_line[index++] = '\n';
	new_line[index] = '\0';
	return (new_line);
}

char	*ft_return_new_line_after_cleaning(char *string)
{
	int		index;
	int		index1;
	char	*after_cleaning_str;

	if (!string)
		return (NULL);
	index = 0;
	while (string[index] != '\n' && string[index] != '\0')
		index++;
	if (string[index] != '\n')
		return (free(string), NULL);
	index++;
	after_cleaning_str = malloc(sizeof(char) * (ft_strlen(string) - index + 1));
	if (!after_cleaning_str)
		return (NULL);
	index1 = 0;
	while (string[index] != '\0')
		after_cleaning_str[index1++] = string[index++];
	after_cleaning_str[index1] = '\0';
	free(string);
	return (after_cleaning_str);
}

char	*get_next_line(int fd)
{
	static char		*store_string = NULL;
	int				read_bytes;
	char			buffer[BUFFER_SIZE + 1];
	char			*return_next_line;

	while (1)
	{
		read_bytes = read (fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			if (store_string)
				return (free(store_string), store_string = NULL);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		if (read_bytes == 0 || read_bytes < BUFFER_SIZE)
			break ;
		if (ft_check_line_jump(buffer))
			break ;
		store_string = ft_strjoin(store_string, buffer);
	}
	store_string = ft_strjoin(store_string, buffer);
	return_next_line = ft_return_line_after_cheking_linefeed(store_string);
	store_string = ft_return_new_line_after_cleaning(store_string);
	return (return_next_line);
}
