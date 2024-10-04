/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:55:29 by fzayani           #+#    #+#             */
/*   Updated: 2024/09/13 13:33:23 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	count_map_elements(t_data *data, int *exit_count, int *start_count,
		int *collectible_count)
{
	int	i;
	int	j;

	i = ((j = 0));
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == 'E')
				(*exit_count)++;
			else if (data->map[i][j] == 'P')
				(*start_count)++;
			else if (data->map[i][j] == 'C')
				(*collectible_count)++;
			check_invalid_characters(data, data->map[i][j]);
			j++;
		}
		i++;
	}
}

int	check_map_elements(t_data *data)
{
	int	exit_count;
	int	start_count;
	int	collectible_count;

	exit_count = ((start_count = collectible_count = 0));
	count_map_elements(data, &exit_count, &start_count, &collectible_count);
	check_map_line_length(data);
	if (exit_count != 1 || start_count != 1 || collectible_count < 1)
		return (ft_printf("Error: Map need 1 exit, 1 collectible,\
				and 1 start position.\n"), 0);
	return (1);
}

int	check_map_rectangular(t_data *data)
{
	int	width;
	int	i;

	i = 1;
	width = ft_strlen(data->map[1]);
	while (i < data->map_height)
	{
		if (ft_strlen(data->map[i]) != (size_t)width)
		{
			print_line_lengths(data);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_map_walls(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_width)
	{
		if (data->map[0][i] != '1' || data->map[data->map_height - 1][i] != '1')
			return (ft_printf("Error: Map must be surrounded by walls.\n"), 0);
		i++;
	}
	i = 0;
	while (i < data->map_height)
	{
		if (data->map[i][0] != '1' || data->map[i][data->map_width - 1] != '1')
		{
			ft_printf("%d - %c\n", i, data->map[i][0]);
			ft_printf("%d %d - %c\n", i, data->map_width,
				data->map[i][data->map_width - 1]);
			ft_printf("Error: Map must be surrounded by walls.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	check_map(t_data *data)
{
	if (!check_map_rectangular(data))
	{
		free_map(data);
		error_exit("Error : Map is not rectangular !!!");
	}
	if (!check_map_elements(data))
	{
		free_map(data);
		error_exit("Error : Map doesn't have valid char !!!");
	}
	if (!check_map_walls(data))
	{
		free_map(data);
		error_exit("Error : Map doesn't have walls !!! wtf");
	}	
}
