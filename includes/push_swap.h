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
	t_stack			*a;
	t_stack			*b;
}					t_massive;

typedef struct s_instr
{
    int     sa;
    int     sb;
    int     ss;
    int     pa;
    int     pb;
    int     ra;
    int     rb;
    int     rr;
    int     rra;
    int     rrb;
    int     rrr;
}              t_instr;

int *sort_tab(int *arr, int size);
void rotate_a_b(t_stack *stack, t_massive *s);
void swap_a_b(t_stack *stack);

#endif