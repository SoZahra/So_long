/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:36:42 by fzayani           #+#    #+#             */
/*   Updated: 2024/09/13 11:16:45 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**copy_map(char **map, int height)
{
	int		i;
	char	**map_copy;

	i = 0;
	map_copy = malloc((height + 1) * sizeof(char *));
	if (!map_copy)
		return (NULL);
	while (i < height)
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			while (i--)
				free(map_copy[i]);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[height] = NULL;
	return (map_copy);
}

void	load_map_copie(t_data *data)
{
	data->copie_map = copy_map(data->map, data->map_height);
	if (!data->copie_map)
	{
		ft_printf("Error: Failed to allocate memory for map copy.\n");
		free_map(data);
		exit(1);
	}
}

void	flood_fill(t_data *data, t_player *player, int *reachable_items)
{
	t_player	n_player;

	if (player->x < 0 || player->x >= data->map_height || player->y < 0
		|| player->y >= data->map_width)
		return ;
	else if (data->copie_map[player->x][player->y] == '1'
		|| data->copie_map[player->x][player->y] == 'V')
		return ;
	if (data->copie_map[player->x][player->y] == 'C')
		(*reachable_items)++;
	else if (data->copie_map[player->x][player->y] == 'E' && data->exit_f == 0)
	{
		(*reachable_items)++;
		data->exit_f = 1;
		return ;
	}
	data->copie_map[player->x][player->y] = 'V';
	n_player = (t_player){player->x + 1, player->y, player->cc, player->count};
	flood_fill(data, &n_player, reachable_items);
	n_player = (t_player){player->x - 1, player->y, player->cc, player->count};
	flood_fill(data, &n_player, reachable_items);
	n_player = (t_player){player->x, player->y + 1, player->cc, player->count};
	flood_fill(data, &n_player, reachable_items);
	n_player = (t_player){player->x, player->y - 1, player->cc, player->count};
	flood_fill(data, &n_player, reachable_items);
}

int	count_collectibles(t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = ((j = count = 0));
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	data->player.cc = count;
	return (count);
}

int	check_valid_path(t_data *data)
{
	int			reachable_items;
	int			collectibles_to_be_collected;
	int			expected_items;
	t_player	start_player;

	reachable_items = 0;
	collectibles_to_be_collected = count_collectibles(data);
	expected_items = collectibles_to_be_collected + 1;
	start_player.x = data->player.x;
	start_player.y = data->player.y;
	flood_fill(data, &start_player, &reachable_items);
	if (reachable_items != expected_items)
	{
		ft_printf("Error: Not all items and the exit are reachable.\n");
		return (0);
	}
	return (1);
}
