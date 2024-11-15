# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 01:52:16 by tbarret           #+#    #+#              #
#    Updated: 2024/03/02 12:28:47 by tbarret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	so_long
CC 			=	cc
CFLAGS 		=	-Wall -Wextra -Werror
SRCS_PATH	= 	./src
SRCS_PRINTF = 	$(SRCS_PATH)/functions/printf/ft_printchar.c \
				$(SRCS_PATH)/functions/printf/ft_printf.c \
				$(SRCS_PATH)/functions/printf/ft_printhex.c \
				$(SRCS_PATH)/functions/printf/ft_printnbr.c \
				$(SRCS_PATH)/functions/printf/ft_printptr.c \
				$(SRCS_PATH)/functions/printf/ft_printstr.c \
				$(SRCS_PATH)/functions/printf/ft_printunbr.c 
				
SRCS_GNL	= 	$(SRCS_PATH)/functions/gnl/get_next_line.c \
				$(SRCS_PATH)/functions/gnl/get_next_line_utils.c 	

SRCS_LIBFT	= 	$(SRCS_PATH)/functions/libft/ft_bzero.c \
				$(SRCS_PATH)/functions/libft/ft_calloc.c \
				$(SRCS_PATH)/functions/libft/ft_split.c \
				$(SRCS_PATH)/functions/libft/ft_strstr.c \
				$(SRCS_PATH)/functions/libft/ft_substr.c
SRCS_FILE 	= 	$(SRCS_PRINTF) \
				$(SRCS_GNL) \
				$(SRCS_LIBFT) \
				$(SRCS_PATH)/functions/so_long.c \
				$(SRCS_PATH)/functions/file.c \
				$(SRCS_PATH)/functions/map.c \
				$(SRCS_PATH)/functions/map_utils.c \
				$(SRCS_PATH)/functions/image.c \
				$(SRCS_PATH)/functions/player.c \
				$(SRCS_PATH)/functions/hook.c \
				$(SRCS_PATH)/functions/event.c \
				$(SRCS_PATH)/functions/path_find.c 
OBJS_FILE	=	$(SRCS_FILE:.c=.o)

all: $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -g3

$(NAME) : $(OBJS_FILE)
	@make -C ./libs/mlx
	$(CC) -g3 $^ -o $@ -L./libs/mlx -lmlx -lXext -lX11 -lz -lm ./libs/mlx/libmlx.a
clean:
	@make clean -C ./libs/mlx
	rm -f $(OBJS_FILE)

fclean: clean
	rm -f $(NAME)

re: fclean all
