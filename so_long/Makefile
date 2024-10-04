# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/21 14:58:23 by fzayani           #+#    #+#              #
#    Updated: 2024/09/13 13:11:31 by fzayani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRCS_FILES	=	utils.c flood_fill.c\
				find_position.c check_map.c map.c map_2.c\
				main.c check_map_utils.c\
				fenetre.c pixel.c textures.c destroy.c \
				
SRCS_PATH	=	src/
OBJS_PATH	=	.objs/
INC_PATH	=	include/

LIBFT_PATH	=	./libft/
LIBFT_LIB	=	$(LIBFT_PATH)libft.a

MLX_PATH	=	./mlx/
MLX_LIB		=	$(MLX_PATH)libmlx_Linux.a

SRCS		=	$(addprefix $(SRCS_PATH), $(SRCS_FILES))
OBJS		=	$(addprefix $(OBJS_PATH), $(SRCS:.c=.o))
INC			=	$(addprefix $(INC_PATH), $(INC_FILE))

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -I$(INC_PATH) -I$(LIBFT_PATH) -I$(MLX_PATH)
LFLAGS		=	-L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx_Linux -lXext -lX11 -lm
RM			=	rm -rf

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

$(OBJS_PATH)%.o:	%.c
	mkdir -p ${@D}
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_LIB):
	@make -C $(LIBFT_PATH) --silent

$(MLX_LIB):
	@make -C $(MLX_PATH) --silent

clean:
	$(RM) $(OBJS_PATH)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MLX_PATH)
	@echo "[DONE] Objects files deletion..."

fclean:	clean
	$(RM) $(NAME) $(NAMEB)
	@make fclean -C $(LIBFT_PATH)
	@echo "[DONE] so_long deletion..."

re:	fclean all
	@echo "[DONE] so_long recompiled..."

.PHONY:	all clean fclean re