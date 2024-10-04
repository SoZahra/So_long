/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fenetre.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:45:03 by fzayani           #+#    #+#             */
/*   Updated: 2024/09/12 18:14:35 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free_map(data);
		perror("Failed to initialize MLX");
		exit(EXIT_FAILURE);
	}
	data->win = mlx_new_window(data->mlx, data->map_width * 64, data->map_height
			* 64, "miaou");
	if (!data->win)
	{
		perror("Failed to create window");
		exit(EXIT_FAILURE);
	}
}

void	move_player(t_data *data, int new_x, int new_y)
{
	if (data->map[new_x][new_y] != '1')
	{
		ft_printf("Step : %d\n", data->player.count++);
		if (data->map[new_x][new_y] == 'C')
			data->player.cc--;
		if (data->map[new_x][new_y] == 'E')
		{
			if (data->player.cc == 0)
			{
				ft_printf("You reached the exit ! BRAVO !!\n");
				end_game(data);
			}
			else
			{
				ft_printf("You can't exit yet! Collect all items first.\n");
				return ;
			}
		}
		data->map[data->player.x][data->player.y] = '0';
		data->player.x = new_x;
		data->player.y = new_y;
		data->map[new_x][new_y] = 'P';
		draw_map(data);
	}
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		end_game(data);
	else if (keycode == W_KEY)
		move_player(data, data->player.x - 1, data->player.y);
	else if (keycode == A_KEY)
		move_player(data, data->player.x, data->player.y - 1);
	else if (keycode == S_KEY)
		move_player(data, data->player.x + 1, data->player.y);
	else if (keycode == D_KEY)
		move_player(data, data->player.x, data->player.y + 1);
	return (0);
}

void	setup_hooks(t_data *data)
{
	mlx_key_hook(data->win, handle_keypress, data);
	mlx_hook(data->win, 17, 0, end_game, data);
	mlx_loop(data->mlx);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}
