/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:16:37 by fzayani           #+#    #+#             */
/*   Updated: 2024/09/12 15:34:19 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_tile(t_data *data, int x, int y)
{
	if (data->map[x][y] == '1' && data->img->img_wall)
		mlx_put_image_to_window(data->mlx, data->win, data->img->img_wall, y
			* 64, x * 64);
	else if (data->map[x][y] == '0' && data->img->img_sol)
		mlx_put_image_to_window(data->mlx, data->win, data->img->img_sol, y
			* 64, x * 64);
	else if (data->map[x][y] == 'P' && data->img->img_player)
		mlx_put_image_to_window(data->mlx, data->win, data->img->img_player, y
			* 64, x * 64);
	else if (data->map[x][y] == 'E' && data->img->img_exit)
		mlx_put_image_to_window(data->mlx, data->win, data->img->img_exit, y
			* 64, x * 64);
	else if (data->map[x][y] == 'C' && data->img->img_collectible)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->img_collectible, y * 64, x * 64);
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->map_height)
	{
		y = 0;
		while (y < data->map_width)
		{
			draw_tile(data, x, y);
			y++;
		}
		x++;
	}
}
