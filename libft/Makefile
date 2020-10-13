#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcolossu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/11 20:49:09 by bcolossu          #+#    #+#              #
#    Updated: 2020/05/21 19:42:55 by bcolossu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: $(NAME) all compile fclean clean re

NAME = libft.a

FLAGS = -Wall -Werror -Wextra -c -g -O2

HEADERS_LIST = libft.h ft_printf.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./
SOURCES_LIST = ft_strjoin_f.c\
		ft_itoa_base.c\
		ft_ftoa.c\
		ft_ftoa_long.c\
		ft_itoa_long.c\
		ft_itoa_longlong.c\
		ft_getnbr.c\
		ft_free_array.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstnew.c\
		ft_atoi.c\
		ft_bzero.c\
		ft_end_word.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_isspace.c\
		ft_itoa.c\
		ft_memalloc.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memdel.c\
		ft_memmove.c\
		ft_memset.c\
		ft_push_tab.c\
		ft_putchar.c\
		ft_putchar_fd.c\
		ft_putendl.c\
		ft_putendl_fd.c\
		ft_putnbr.c\
		ft_putnbr_fd.c\
		ft_putstr.c\
		ft_putstr_fd.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strclr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdel.c\
		ft_strdup.c\
		ft_strequ.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlen.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strnequ.c\
		ft_strnew.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strsplit.c\
		ft_strstr.c\
		ft_strsub.c\
		ft_strtrim.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_word_count.c\
		get_next_line.c\
		ft_itoa_unsigned.c \
    ft_printf/ft_printf.c \
    ft_printf/bzero_struct.c \
    ft_printf/digit_p.c \
    ft_printf/digit_p2.c \
    ft_printf/output.c \
    ft_printf/analysis.c \
    ft_printf/char.c \
    ft_printf/unsigned_n.c \
    ft_printf/modifers.c \
    ft_printf/oxb.c \
    ft_printf/char2.c \
    ft_printf/bonus.c 

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
OBJECTS_DIRECTORY_PRINTF = objects/ft_printf
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# COLORS
GREEN = \033[0;32m
BOLD_GREEN = \033[1;32m
RED = \033[0;31m
BOLD_RED = \033[1;31m
YELLOW = \033[0;33m
BOLD_YELLOW = \033[1;33m
BLUE = \033[0;34m
BOLD_BLUE = \033[1;34m
MAGENTA = \033[0;35m
BOLD_MAGENTA = \033[1;35m
CYAN = \033[0;36m
BOLD_CYAN = \033[1;36m
RESET = \033[0m
CLEAR_LINE = \033[2K
BEGIN_LINE = \033[A

PWD = $(shell pwd)

TOTAL_FILES := $(shell echo $(SOURCES_LIST) | wc -w | sed -e 's/ //g')
CURRENT_FILES = $(shell find $(PWD)/objects/ -type f | wc -l | sed -e 's/ //g')

all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
		@ar rc $(NAME) $(OBJECTS)
		@ranlib $(NAME)
		@echo "\n$(CLEAR_LINE)$(BOLD_YELLOW)$(NAME)$(RESET):$(BOLD_BLUE) ready to use!$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@mkdir -p $(OBJECTS_DIRECTORY_PRINTF)
	@echo "$(BOLD_YELLOW)$(NAME)$(RESET): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@gcc $(FLAGS) -I $(HEADERS_DIRECTORY) $< -o $@
	@echo "$(CLEAR_LINE)$(GREEN)Compiling file [$(CYAN)$<$(GREEN)]. ($(CURRENT_FILES) / $(TOTAL_FILES))$(RESET)$(BEGIN_LINE)"



clean:
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(BOLD_YELLOW)$(NAME)$(RESET): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(BOLD_YELLOW)$(NAME)$(RESET): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BOLD_RED)$(NAME) deleted$(RESET)"


re:
	@$(MAKE) fclean
	@$(MAKE) all
