#include "push_swap.h"

int			main(int ac, char **av)
{
    t_massive   *s;
    int         max_i;

    
    if (!(s = (t_massive *)ft_memalloc(sizeof(t_massive))))
		exit_error();
	if (ac >= 2)
    {
        init_stack_a(s, av, ac);
        s->b = NULL;
        //s->bottom = 0;
        //s->top = s->size / 2 + 1;
        s->message = ft_strdup("");
        max_i = (s->size > 100 ? 11 : 5);
        new_sort(s, max_i);
        ft_printf("%s", s->message);
	    free(s->message);
       //sorting_algorithm(s);
        //print_stacks(s);
        /*printf("s->a\n");
        print_stack(s->a);
        printf("\n");
        printf("s->b\n");
        print_stack(s->b);*/
    }
}