/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:38:06 by fzayani           #+#    #+#             */
/*   Updated: 2024/09/12 17:06:56 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

int	ber_extension(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	return (len > 4 && ft_strcmp(filename + len - 4, ".ber") == 0);
}

int	check_arguments(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("Error: Wrong number of arguments.\n");
		ft_printf("Usage: ./so_long map.ber\n");
		return (0);
	}
	if (!ber_extension(av[1]))
	{
		ft_printf("Error: The map file must have a .ber extension.\n");
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (!check_arguments(ac, av))
		return (1);
	ft_memset(&data, 0, sizeof(data));
	load_map(av[1], &data);
	check_map(&data);
	find_p_position(&data);
	load_map_copie(&data);
	if (!check_valid_path(&data))
	{
		ft_printf("Invalid map: not all collectibles\
                or the exit are reachable.\n");
		free_map(&data);
		return (1);
	}
	init_mlx(&data);
	load_images(&data);
	draw_map(&data);
	setup_hooks(&data);
	end_game(&data);
	return (0);
}
