# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/03 01:12:30 by obouftou          #+#    #+#              #
#    Updated: 2025/01/05 14:47:58 by obouftou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap


BONUS_NAME = checker

CC = cc

MAKE = make

CFLAGS =  -Wall -Wextra -Werror -g

INCLUDE = include/

HEADER = $(INCLUDE)push_swap.h

HEADER_BONUS = $(INCLUDE)push_swap_bonus.h

SRC_DIR = src/

BONUS_SRC_DIR = bonus/

SRC = 	$(SRC_DIR)duplic_check.c \
		$(SRC_DIR)push_swap.c \
		$(SRC_DIR)ft_atoi.c \
		$(SRC_DIR)ft_fill.c \
		$(SRC_DIR)ft_free.c \
		$(SRC_DIR)ft_putstr.c $(SRC_DIR)ft_split.c \
		$(SRC_DIR)ft_strcmp.c $(SRC_DIR)ft_strdup.c $(SRC_DIR)ft_strjoin.c $(SRC_DIR)ft_strlen.c $(SRC_DIR)get_input.c $(SRC_DIR)lst_utils.c \
		$(SRC_DIR)lst_utils2.c $(SRC_DIR)algo_utils3.c $(SRC_DIR)parcing.c $(SRC_DIR)push_moves.c \
		$(SRC_DIR)rev_rotate_moves.c \
		$(SRC_DIR)rotate_orders.c \
		$(SRC_DIR)sort.c \
		$(SRC_DIR)swap_orders.c\
		 $(SRC_DIR)algo_utils.c \
		$(SRC_DIR)algo_utils2.c \
		$(SRC_DIR)ft_itoa.c


BONUS_SRC = $(BONUS_SRC_DIR)duplic_check_bonus.c \
			$(BONUS_SRC_DIR)ft_atoi_bonus.c \
			$(BONUS_SRC_DIR)ft_fill_bonus.c \
			$(BONUS_SRC_DIR)ft_free_bonus.c \
			$(BONUS_SRC_DIR)ft_putstr_bonus.c $(BONUS_SRC_DIR)ft_split_bonus.c \
			$(BONUS_SRC_DIR)ft_strcmp_bonus.c $(BONUS_SRC_DIR)ft_strdup_bonus.c $(BONUS_SRC_DIR)ft_strjoin_bonus.c $(BONUS_SRC_DIR)ft_strlen_bonus.c $(BONUS_SRC_DIR)get_input_bonus.c $(BONUS_SRC_DIR)lst_utils_bonus.c \
			$(BONUS_SRC_DIR)lst_utils2_bonus.c $(BONUS_SRC_DIR)algo_utils3_bonus.c $(BONUS_SRC_DIR)parcing_bonus.c $(BONUS_SRC_DIR)push_moves_bonus.c \
			$(BONUS_SRC_DIR)rev_rotate_moves_bonus.c \
			$(BONUS_SRC_DIR)rotate_orders_bonus.c \
			$(BONUS_SRC_DIR)sort_bonus.c \
			$(BONUS_SRC_DIR)swap_orders_bonus.c \
			$(BONUS_SRC_DIR)algo_utils_bonus.c \
			$(BONUS_SRC_DIR)algo_utils2_bonus.c \
			$(BONUS_SRC_DIR)ft_itoa_bonus.c $(BONUS_SRC_DIR)checker_bonus.c $(BONUS_SRC_DIR)get_next_line_bonus.c $(BONUS_SRC_DIR)get_next_line_utils_bonus.c  
			

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)	

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $^ -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(BONUS_OBJ) -o $(BONUS_NAME)

%.o : %.c $(HEADER) $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) -f $(OBJ) $(BONUS_OBJ)

fclean : clean
	rm -f $(NAME) $(BONUS_NAME)

re : fclean all

.PHONY : all clean fclean re 