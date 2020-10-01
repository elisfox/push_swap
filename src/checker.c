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
       /* printf("s->a\n");
        print_stack(s->a);
        printf("s->b\n");
        print_stack(s->b);
        push_b(s);
        s->a = rotate_a_b(s->a);
        push_b(s);
        s->a = rotate_a_b(s->a);
        swap_a_b(s->a);
        s->a = rotate_a_b(s->a);
        push_a(s);
        push_a(s);
        printf("s->a\n");
        print_stack(s->a);
        printf("\n");
        printf("s->b\n");
        print_stack(s->b);*/
        read_instructions(s);
        printf("s->a\n");
        print_stack(s->a);
        printf("\n");
        printf("s->b\n");
        print_stack(s->b);
    }
    return(0);
}