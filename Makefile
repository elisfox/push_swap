# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/30 19:01:08 by rrhaenys          #+#    #+#              #
#    Updated: 2019/02/20 17:23:15 by rrhaenys         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME_checker = checker

### PATH ###
SRCS_PATH = src/
OBJ_PATH  = obj/
LIBFT_PATH = libft/

FLAGS = #-Wall -Werror -Wextra
INC = -I ./includes/ -I ./$(LIBFT_PATH)includes/

SRCS_NAME = checker.c \
            pa_pb.c \
            ra_rb_rr.c \
            read_instructions.c \
            sa_sb_ss.c \
            selection_sort.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS_NAME:.c=.o))

all: $(NAME_checker)

$(NAME_checker): $(OBJ)
	@make -w -C $(LIBFT_PATH)
	@echo "\033[92m$(LIBFT_PATH)\033[0m compiled."
	@gcc $(FLAGS) $(OBJ) $(INC) -L $(LIBFT_PATH) -lft -o $(NAME_checker)
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