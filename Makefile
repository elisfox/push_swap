#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcolossu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/11 20:49:09 by jojoseph          #+#    #+#              #
#    Updated: 2020/05/21 19:42:55 by jojoseph         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME_push = push_swap
NAME_checker = checker

ifndef VERBOSE
MAKEFLAGS += --no-print-directory
endif

### PATH ###
SRCS_PATH = src/
OBJ_PATH  = obj/
LIBFT_PATH = libft/

FLAGS = -Wall -Werror -Wextra
INC = -I ./includes/ -I ./$(LIBFT_PATH)includes/

SRCS_NAME = pa_pb.c \
            ra_rb_rr.c \
            read_instructions.c \
            sa_sb_ss.c \
            selection_sort.c \
			help_functions.c \
			init_stack.c \
			new_sort.c \
			push_for_sort.c \
			push_for_sort2.c \
			valid.c \
			small_sort.c \
			delete_stack.c

SRCS_CHECKER = checker.c $(SRCS_NAME)

SRCS_PUSH = push_swap.c $(SRCS_NAME)

SRCS_CHECKER_FULL = $(addprefix $(SRCS_PATH), $(SRCS_CHECKER))
SRCS_PUSH_FULL = $(addprefix $(SRCS_PATH), $(SRCS_PUSH))
OBJ_CHECKER = $(addprefix $(OBJ_PATH), $(SRCS_CHECKER:.c=.o))
OBJ_PUSH = $(addprefix $(OBJ_PATH), $(SRCS_PUSH:.c=.o))

all: $(NAME_checker) $(NAME_push)

$(NAME_push) : $(OBJ_PUSH)
	@make -w -C $(LIBFT_PATH)
	@echo "\033[92m$(LIBFT_PATH)\033[0m compiled."
	@gcc $(FLAGS) $(OBJ_PUSH) $(INC) -L $(LIBFT_PATH) -lft -o $(NAME_push)
	@echo "\033[35m$(NAME_push)\033[0m created."

$(NAME_checker): $(OBJ_CHECKER)
	@make -w -C $(LIBFT_PATH)
	@echo "\033[92m$(LIBFT_PATH)\033[0m compiled."
	@gcc $(FLAGS) $(OBJ_CHECKER) $(INC) -L $(LIBFT_PATH) -lft -o $(NAME_checker)
	@echo "\033[35m$(NAME_checker)\033[0m created."

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	@gcc -c $(FLAGS) $(INC) $< -o $@
	@echo "\033[33m$<\033[0m compiled."

clean:
	@make -w -C $(LIBFT_PATH)/ clean
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@make -w -C $(LIBFT_PATH)/ fclean
	@/bin/rm -rf $(NAME_checker)

re: fclean all

.PHONY: all, clean, fclean, re
