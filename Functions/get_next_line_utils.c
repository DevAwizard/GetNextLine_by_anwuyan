/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:54:13 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/03/15 19:34:43 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *string)
{
	size_t	index;

	if (!string)
		return (0);
	index = 0;
	while (string[index] != '\0')
		index++;
	return (index);
}

int	ft_check_line_jump(char *new_string)
{
	int	index;

	if (!new_string)
		return (0);
	index = 0;
	while (new_string[index] != '\0')
	{
		if (new_string[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}
