# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/23 19:51:56 by oavelar           #+#    #+#              #
#    Updated: 2021/05/20 19:47:47 by oavelar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= miniRT

OS		:= $(shell uname)

CC		= gcc 

CFLAGS		= -Wall -Wextra -Werror -Imlx

INCLUDES	= -Iincludes/ -I$(MINILIBX_DIR)

LIBFT_DIR	= libft/

LIBFT_A		= libft/libft.a

SRC_DIR		= srcs/

SRC_FILES	= 	main/minirt.c \
			main/bmp.c \
			main/cast_shadows.c \
			main/check_args.c \
			main/errors.c \
 			main/load_utils.c \
			main/move_elem.c \
			main/scene.c \
			main/shadows.c \
 			main/surface_data.c \
			main/vectors_1.c \
 			main/vectors_2.c \
 			main/vectors.c \
			utils/read_camera.c \
			utils/read_cy.c \
			utils/read_elem.c \
			utils/read_light.c \
			utils/read_plane.c \
			utils/read_scene.c \
			utils/read_sphere.c \
			utils/read_square.c \
			utils/read_triangle.c \
			utils/render_cy.c \
  			utils/render_plane.c \
			utils/render_scene.c \
	 		utils/render_sphere.c \
		 	utils/render_square.c \
			utils/render_triangle.c		

SRC		= $(addprefix $(SRC_DIR), $(SRC_FILES))

GREEN		= \033[1;32m
BLUE		= \033[0;34m
RED		= \033[1;31m
COLOR_OFF	= \033[0m

ifeq ($(OS), Linux)
	MINILIBX_DIR = mlx_linux
	MLXFLAG = -lm -lbsd -lX11 -lXext
endif

ifeq ($(OS), Darwin)
	MINILIBX_DIR = minilibx_mac
	MLXFLAG = -lmlx -framework OpenGL -framework AppKit
endif

MINILIBX_A	= $(MINILIBX_DIR)/libmlx.a

all: libraries $(NAME)

$(NAME): $(OBJ)
	@echo "$(BLUE)Building miniRT$(COLOR_OFF)"
	$(CC) $(CFLAGS) $(SRC) $(INCLUDES) $(LIBFT_A) $(MINILIBX_A) $(MLXFLAG) -o $(NAME)
	@echo "$(GREEN)miniRT done!$(COLOR_OFF)"

libraries:
	@echo "$(BLUE)Building libraries....$(COLOR_OFF)"
	make -C $(LIBFT_DIR)
	make -C $(MINILIBX_DIR)
	@echo "$(GREEN)Libraries built$(COLOR_OFF)"

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MINILIBX_DIR)

fclean:
	@rm -f $(NAME) 
	@make fclean -C $(LIBFT_DIR)
	@echo "\033[0;31m ---- all cleared! ---- \033[0m"

re: fclean all

.PHONY: all clean fclean re libraries bonus
