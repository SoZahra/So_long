/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:08:15 by fzayani           #+#    #+#             */
/*   Updated: 2024/09/10 14:17:49 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	end_game(t_data *data)
{
	int	i;

	i = 0;
	if (data->img)
	{
		if (data->img->img_wall)
			mlx_destroy_image(data->mlx, data->img->img_wall);
		if (data->img->img_player)
			mlx_destroy_image(data->mlx, data->img->img_player);
		if (data->img->img_collectible)
			mlx_destroy_image(data->mlx, data->img->img_collectible);
		if (data->img->img_exit)
			mlx_destroy_image(data->mlx, data->img->img_exit);
		if (data->img->img_sol)
			mlx_destroy_image(data->mlx, data->img->img_sol);
		free(data->img);
	}
	mlx_destroy_window(data->mlx, data->win);
	mlx_loop_end(data->mlx);
	mlx_destroy_display(data->mlx);
	free_map(data);
	free(data->mlx);
	exit(0);
}
