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
        s->message = ft_strdup("");
        sorting_algorithm(s);
        //print_stacks(s);
        /*printf("s->a\n");
        print_stack(s->a);
        printf("\n");
        printf("s->b\n");
        print_stack(s->b);*/
    }
}