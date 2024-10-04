/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:05:55 by fzayani           #+#    #+#             */
/*   Updated: 2024/09/13 11:40:07 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	calculate_map_size(const char *file_path, int *width, int *height)
{
	int		fd;
	char	*line;
	int		line_length;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening map file");
		exit(EXIT_FAILURE);
	}
	*width = 0;
	*height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line = remove_newline(line);
		line_length = ft_strlen(line);
		if (line_length > *width)
			*width = line_length;
		(*height)++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	allocate_map_memory(t_data *data)
{
	data->map = ft_calloc(sizeof(char *), data->map_height);
	if (!data->map || data->map_height <= 1)
	{
		free(data->map);
		perror("Failed to allocate memory for map");
		exit(EXIT_FAILURE);
	}
}

int	open_map_file(const char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening map file");
		close(fd);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	validate_line_length(int fd, char *line, int line_number,
		t_data *data)
{
	if ((int)ft_strlen(line) != data->map_width)
	{
		ft_printf("Length mismatch at line %d: expected %d, got %d\n", \
			line_number, data->map_width, ft_strlen(line));
		free(line);
		free_map(data);
		get_next_line(-1);
		close(fd);
		exit(EXIT_FAILURE);
	}
}

void	load_map(const char *file_path, t_data *data)
{
	int	fd;

	calculate_map_size(file_path, &data->map_width, &data->map_height);
	allocate_map_memory(data);
	fd = open_map_file(file_path);
	read_map(fd, data);
	close(fd);
}
