/* ************************************************************************** */
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

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*string;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	string = get_next_line(fd);
	printf("Primera llamada %s", string);
	free(string);
	string = get_next_line(fd);
	printf("Segunda llamada %s", string);
	free(string);
	string = get_next_line(fd);
	printf("Tercera llamada %s", string);
	free(string);
	string = get_next_line(fd);
	printf("Cuarta llamada %s", string);
	free(string);
	close(fd);
	return (0);
}

int	main(void)
{
	int		fd;
	char	*string;

	fd = open ("test.txt", O_RDONLY);
	string = get_next_line(fd);
	while (string != NULL)
	{
		printf("%s", string);
		free(string);
		string = get_next_line(fd);
	}
	close(fd);
	return (0);
}
