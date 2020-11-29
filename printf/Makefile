# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 16:32:11 by bmarilli          #+#    #+#              #
#    Updated: 2020/11/27 01:10:49 by bmarilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PRINTF = libftprintf.a

LIB_DIR =  ./libft/
LIB_NAME =	libft/libft.a
LIBFT = libft.a

CC		= gcc

HEADER	= ./includes

FLAGS	= -Wall -Wextra -Werror -g

OBJS	= $(SRCS:.c=.o)

DIR		= ./SRC/

SRCS = $(DIR)ft_printf.c $(DIR)ft_decint.c $(DIR)ft_parse_str.c \
	   $(DIR)ft_types.c $(DIR)ft_char.c $(DIR)ft_string.c \
	   $(DIR)ft_func.c $(DIR)ft_decint2.c $(DIR)ft_undecint.c\
	   $(DIR)ft_unhexint.c $(DIR)ft_pointer.c $(DIR)ft_write_n.c\

AR		= ar rc

F_NONE		= \033[37m
F_BOLD		= \033[1m
F_RED		= \033[31m
F_ORANGE	= \033[38m
F_YELLOW	= \033[33m
F_GREEN		= \033[32m
F_CYAN		= \033[36m
F_BLUE		= \033[34m

.c.o:
	$(CC) $(FLAGS) -c  -I$(HEADER) $< -o $(<:.c=.o)

all: $(LIBFT) $(NAME_PRINTF)

bonus : $(LIBFT) $(NAME_PRINTF)

$(LIBFT):
		@echo "Compile libft.a"
		@$(MAKE) -C $(LIB_DIR)
		@echo "Compile OK"
$(NAME_PRINTF): $(OBJS) 
		@cp libft/libft.a $(NAME_PRINTF)
		@$(AR) $(NAME_PRINTF) $(OBJS)
		ranlib $(NAME_PRINTF)
clean:
	make clean -C $(LIB_DIR)
	rm $(OBJS)
fclean: clean
	make fclean -C $(LIB_DIR)
	rm -rf $(NAME_PRINTF)

re: fclean all

code:
	@echo " ~~~~~~~~~~~~~~~~"
	@echo "$(F_BOLD)  * Make code, *"
	@echo "$(F_BOLD)   * not war! *"
	@echo "$(F_RED)    ..10101.."
	@echo "$(F_ORANGE)  01   1   011"
	@echo "$(F_YELLOW) 10     0     00"
	@echo "$(F_GREEN) 11   .010.   11"
	@echo "$(F_CYAN) 00 .01 1 01. 10"
	@echo "$(F_BLUE) 010   1   110"
	@echo "$(F_BLUE)   11011010**$(F_NONE)"

.PHONY: all clean fclean re code bonus
