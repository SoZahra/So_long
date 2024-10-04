/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:14:19 by fzayani           #+#    #+#             */
/*   Updated: 2024/09/13 13:33:38 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_line_lengths(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_height)
	{
		ft_printf("Length of line %d: %zu\n", i, ft_strlen(data->map[i]));
		i++;
	}
}

void	check_map_line_length(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_height)
	{
		if (ft_strlen(data->map[i]) != (size_t)data->map_width)
		{
			free_map(data);
			error_exit("Error: map lines are not of consistent length.");
		}
		i++;
	}
}

void	check_invalid_characters(t_data *data, char element)
{
	if (element != 'E' && element != 'P' && element != 'C' && element != '1'
		&& element != '0')
	{
		free_map(data);
		error_exit("Error: map contains invalid characters.");
	}
}
