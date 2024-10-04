/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:56:58 by fzayani           #+#    #+#             */
/*   Updated: 2024/09/13 13:28:05 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define SUCCESS 0
# define ERROR -1

# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

# ifdef __linux__
#  define ESC_KEY 65307
# endif

typedef struct s_img
{
	int			img_width;
	int			img_height;
	void		*img_wall;
	void		*img_player;
	void		*img_collectible;
	void		*img_exit;
	void		*img_sol;
}				t_img;

// Structure pour le joueur
typedef struct s_player
{
	int			x;
	int			y;
	int			cc;
	int			count;
}				t_player;

// Structure pour les données du jeu
typedef struct s_data
{
	t_img		*img;
	t_player	player;
	void		*mlx;
	void		*win;
	char		**map;
	char		**copie_map;
	int			map_width;
	int			map_height;
	void		*texture;
	int			exit_f;
}				t_data;

////textures//

void			load_images(t_data *data);
int				allocate_img_memory(t_data *data);
void			*load_single_image(void *mlx, char *file_path, int *img_width,
					int *img_height);
void			check_img_loaded(t_data *data);

// flood_fill

char			**copy_map(char **map, int height);
void			load_map_copie(t_data *data);
void			flood_fill(t_data *data, t_player *player,
					int *reachable_items);
int				count_collectibles(t_data *data);
int				check_valid_path(t_data *data);

// map //

void			calculate_map_size(const char *file_path, int *width,
					int *height);
void			allocate_map_memory(t_data *data);
int				open_map_file(const char *file_path);
void			validate_line_length(int fd, char *line, int line_number,
					t_data *data);
void			load_map(const char *file_path, t_data *data);

// map_2//

void			print_map(char **map, int height);
char			*remove_newline(char *line);
void			error_exit(const char *message);
void			read_map(int fd, t_data *data);

/// check map////

int				check_map_rectangular(t_data *data);
void			count_map_elements(t_data *data, int *exit_count,
					int *start_count, int *collectible_count);
int				check_map_elements(t_data *data);
int				check_map_walls(t_data *data);
void			check_map(t_data *data);

/// check_map_utils////

void			print_line_lengths(t_data *data);
void			check_invalid_characters(t_data *data, char element);
void			check_map_line_length(t_data *data);

/////utils/////

int				end_game(t_data *data);

////destroy///

void			free_map(t_data *data);

/// find_position ///

void			find_p_position(t_data *data);

////fenetre////

void			init_mlx(t_data *data);
void			move_player(t_data *data, int new_x, int new_y);
int				handle_keypress(int keycode, t_data *data);
void			setup_hooks(t_data *data);
int				close_window(t_data *data);

/////pixel////

void			draw_tile(t_data *data, int x, int y);
void			draw_map(t_data *data);

#endif