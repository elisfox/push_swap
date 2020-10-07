#include "push_swap.h"

int main(int ac, char **av)
{
    t_massive *s;

    if (!(s = (t_massive *)ft_memalloc(sizeof(t_massive))))
		exit_error();
	if (ac >= 2)
    {
        init_stack_a(s, av, ac);
        s->b = NULL;
        s->a = rr_a_b(s->a);
        print_stack(s->a, s->b);
        //s->a = rotate_a_b(s->a);
        s->a = rr_a_b(s->a);
        print_stack(s->a, s->b);
        //read_instructions(s);
    }
    return(0);
}