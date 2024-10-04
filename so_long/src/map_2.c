/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:45:43 by fzayani           #+#    #+#             */
/*   Updated: 2024/09/13 11:19:29 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_exit(const char *message)
{
	ft_printf("%s\n", message);
	exit(EXIT_FAILURE);
}

void	print_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		ft_printf("Map line %d: %s\n", i, map[i]);
		i++;
	}
}

char	*remove_newline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

void	read_map(int fd, t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line = remove_newline(line);
		validate_line_length(fd, line, i, data);
		data->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	free(line);
}
