# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oavelar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/23 19:51:56 by oavelar           #+#    #+#              #
#    Updated: 2021/04/10 23:34:56 by oavelar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	miniRT

OS			:= $(shell uname)

CC			= gcc -g -fsanitize=address

CFLAGS		= -Wall -Wextra -Werror

INCLUDES	= -Iincludes/ -Ilibft/libft.h -I$(MINILIBX_DIR)

LIBFT_DIR	= libft/

LIBFT_A		= libft/libft.a

SRC_FILES	= 	main/minirt.c \
							main/move_elem \
							main/bmp.c \
							main/scene.c \
							main/check_args.c \
 					 		main/surface_data.c \
							main/shadows.c \
							main/cast_shadows_2.c \
							main/load_utils.c \
 							main/vectors.c \
						  main/vectors_1.c \
 							main/vectors_2.c \
 							main/errors.c \
 							utils/render_scene.c \
  						utils/render_sphere.c \
							utils/render_plane.c \
	 						utils/render_cy.c \
						  utils/render_square.c \
						  utils/render_triangle.c	\	
							utils/read_scene.c \
 							utils/read_elements.c \ 
 							utils/read_camera.c \
 							utils/read_light.c \
 							utils/read_sphere.c \
 							utils/read_plane.c \
 							utils/read_cy.c \
 							utils/read_square.c \
 							utils/read_triangle.c  
						 
SRC_DIR		= srcs/

SRC			= $(addprefix $(SRC_DIR), $(SRC_FILES))

GREEN		= \033[1;32m

BLUE		= \033[0;34m

RED			= \033[1;31m

COLOR_OFF	= \033[0m

ifeq ($(OS), Linux)
	MINILIBX_DIR = mlx_linux
	MLXFLAG = -lm -lbsd -lX11 -lXext
endif
ifeq ($(OS), Darwin)
	MINILIBX_DIR = minilibx_mac
	MLXFLAG = -lz -framework OpenGL -framework AppKit
endif

MINILIBX_A	= $(MINILIBX_DIR)/libmlx.a

all: libraries $(NAME)

$(NAME): $(OBJ)
	@echo "$(BLUE)Building miniRT$(COLOR_OFF)"
	$(CC) $(CFLAGS) $(SRC) $(INCLUDES) $(LIBFT_A) $(MINILIBX_A) $(MLXFLAG) -o $(NAME)
	@echo "$(GREEN)miniRT done!$(COLOR_OFF)"

libraries:
	@echo "$(BLUE)Building libraries...$(COLOR_OFF)"
	make plus -C $(LIBFT_DIR)
	make -C $(MINILIBX_DIR)
	@echo "$(GREEN)Libraries built$(COLOR_OFF)"

clean:
	@make clean -C $(LIBFT_DIR)

fclean:
	@rm -f $(NAME) 
	@make fclean -C $(LIBFT_DIR)
	@echo "\033[0;31m ---- all cleared! ---- \033[0m"

re: fclean all

.PHONY: all clean fclean re libraries bonus
