# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svaccaro <svaccaro@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 17:30:08 by svaccaro          #+#    #+#              #
#    Updated: 2023/11/10 13:54:21 by svaccaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#####################################ALIAS#####################################

# Compiler #
CC = cc

# Compilation flags #
CFLAGS = -Wall -Wextra -Werror

# No ask to remove #
CLEAR = rm -f

# Program's name #
NAME = libftprintf.a

# Source files to compile #
SRC = ft_printf.c ft_printf_utils.c
SRC_LIB = libft/libft.a

# Objects derived from source files #
OBJS = $(SRC:.c=.o)

#####################################RULES#####################################

# Default rule: Complies the program #
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME)$(OBJS)

# Rule to clean objects files #
clean:
	$(CLEAR) $(OBJS)

# Rule to clean everything (clean + library) #
fclean: clean
	$(CLEAR) $(NAME)

# Rule to clean and recompile all #
re: flclean all

# Patern rule to compile any .c file into its corresponding .o file #
%.o: %.c
	$(CC) $(CFLAGS) libft.a -c $< -o $@ 

# Tells to command make that these names aren't files #
.PHONY: all clean fclean re bonus
