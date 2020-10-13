/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:58:39 by jojoseph          #+#    #+#             */
/*   Updated: 2020/06/11 20:25:25 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

typedef struct		s_stack
{
	int				val;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct		s_massive
{	
	char			*message;
	int				*tab;
	int				size;
    int             top;
    int             bottom;
    int             middle;
	t_stack			*a;
	t_stack			*b;
}					t_massive;

typedef enum e_command {SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR} command;

typedef struct s_instr
{
    command comm;
}              t_instr;

void init_stack_a(t_massive *s, char **av, int ac);
void exit_error(void);
int *sort_tab(int *arr, int size);
t_stack *rotate_a_b(t_stack *stack);
void swap_a_b(t_stack *stack);
void swap_ss(t_stack *stack_a, t_stack *stack_b);
t_stack *rr_a_b(t_stack *stack);
void rr(t_stack *stack_a, t_stack *stack_b);
void rrr(t_stack *stack_a, t_stack *stack_b);
void push_a(t_massive *s);
void push_b(t_massive *s);
void print_stack(t_stack *a, t_stack *b);
void    read_instructions(t_massive *s);
long long	ft_atoi_ps(const char *str);
void	new_sort(t_massive *s, int max_i);
void	pb_and_print(t_massive *s);
void	pa_and_print(t_massive *s);
void	second_or_first_up(t_massive *s, int count_first, int count_second);
void	second_or_first_b_up(t_massive *s, int count_first, int count_second);
void	first_up(t_massive *s, int count_first);
void	first_b_up(t_massive *s, int count_first);
void	second_up(t_massive *s, int count_second);
void	second_b_up(t_massive *s, int count_second);
void	push_to_b(t_massive *s, int size_chunk);
void	not_first_elem(t_massive *s, int size_chunk);
void	check_doubles(int *tab, int size);
void	check_numbers(int ac, char **av);
int		*create_array(int count, char ***args);
char	***extract_numbers(int ac, char **av);
int		count_numbers(char ***args);
void	small_sort(t_massive *s);
void	five_sort(t_massive *s, int size_chunk);
void	correct_order(t_massive *s, int size_chunk);
void	sa_and_print(t_massive *s);
void	first_smallest(t_massive *s);
void	first_not_smallest(t_massive *s);
void	delete_stack(t_stack *stack);

#endif