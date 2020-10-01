#include "push_swap.h"

int			main(int ac, char **av)
{
    t_massive *s;

    if (!(s = (t_massive *)ft_memalloc(sizeof(t_massive))))
		exit_error();
	if (ac >= 2)
    {
        init_stack_a(s, av, ac);
        s->b = NULL;
        s->bottom = 0;
        s->top = s->size / 2 + 1;
        sorting_algorithm(s);
    }
}