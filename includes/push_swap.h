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
}					t_stack;

typedef struct		s_massive
{
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
void print_stack(t_stack *a);
void    read_instructions(t_massive *s);
long long	ft_atoi_ps(const char *str);
#endif