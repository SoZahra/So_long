/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:30:35 by fzayani           #+#    #+#             */
/*   Updated: 2024/09/13 11:36:10 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	allocate_img_memory(t_data *data)
{
	data->img = ft_calloc(1, sizeof(t_img));
	if (!data->img)
	{
		ft_printf("Error allocating memory for images.\n");
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (0);
	}
	return (1);
}

void	*load_single_image(void *mlx, char *file_path, int *img_width,
		int *img_height)
{
	return (mlx_xpm_file_to_image(mlx, file_path, img_width, img_height));
}

void	check_img_loaded(t_data *data)
{
	if (!data->img->img_wall || !data->img->img_sol || !data->img->img_player
		|| !data->img->img_collectible || !data->img->img_exit)
	{
		end_game(data);
		perror("Failed to load images");
		exit(EXIT_FAILURE);
	}
}

void	load_images(t_data *data)
{
	if (!allocate_img_memory(data))
		return ;
	data->img->img_wall = mlx_xpm_file_to_image(data->mlx,
			"./textures/wall1.xpm", &data->img->img_width,
			&data->img->img_height);
	data->img->img_player = mlx_xpm_file_to_image(data->mlx,
			"./textures/player.xpm", &data->img->img_width,
			&data->img->img_height);
	data->img->img_collectible = mlx_xpm_file_to_image(data->mlx,
			"./textures/collectible1.xpm", &data->img->img_width,
			&data->img->img_height);
	data->img->img_exit = mlx_xpm_file_to_image(data->mlx,
			"./textures/exit1.xpm", &data->img->img_width,
			&data->img->img_height);
	data->img->img_sol = mlx_xpm_file_to_image(data->mlx,
			"./textures/sol1.xpm", &data->img->img_width,
			&data->img->img_height);
	check_img_loaded(data);
}
