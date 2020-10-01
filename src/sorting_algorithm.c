#include "push_swap.h"

void b_to_bottom(t_massive *s)
{
    push_a(s);
    s->a = rotate_a_b(s->a);
    s->bottom++;
}

void b_to_top(t_massive *s)
{
    push_a(s);
    s->top--;
}

void a_to_bottom(t_massive *s)
{
    s->a = rotate_a_b(s->a);
    s->bottom++;
}

void    sort(t_massive *s)
{
    while(s->b)
    {
        if(s->b->index == s->bottom + 1)
            b_to_bottom(s);
        else if(s->b->index == s->top - 1)
            b_to_top(s);
        else
            s->b = rr_a_b(s->b);
    }
}

void    half_sort(t_massive *s)
{
    int i;

    i = 1;
    s->middle = s->size / 2;
    while (i <= s->size) //перекинуть половину в б
    {
        if(s->a->index <= s->middle)
            push_b(s);
        else
            s->a = rotate_a_b(s->a);
        i++;        
    }
        print_stack(s->a, s->b);
        printf("\n");
        getchar();
    sort(s); //отсортировать б
    while (s->a->index == s->bottom + 1) //кинуть вниз а отсортированные
        a_to_bottom(s);
        /*printf("s->a\n");
        print_stack(s->a);
        printf("\n");
        printf("s->b\n");
        print_stack(s->b);
        getchar();*/
    s->top = s->size + 1;
    while(s->a->index != 1) //кинуть вторую половину в б
    {
        if (s->a->index == s->bottom + 1)
            a_to_bottom(s);
        else
            push_b(s);
    }
       /* printf("s->a\n");
        print_stack(s->a);
        printf("\n");
        printf("s->b\n");
        print_stack(s->b);
        getchar();*/
    sort(s); //отсортировать вторую половину б
        /*printf("s->a\n");
        print_stack(s->a);
        printf("\n");
        printf("s->b\n");
        print_stack(s->b);
        getchar();*/
    a_to_bottom(s); //кинуть вниз а отсортированные
        /*printf("s->a\n");
        print_stack(s->a);
        printf("\n");
        printf("s->b\n");
        print_stack(s->b);
        getchar();*/
}

void    sorting_algorithm(t_massive *s)
{
    print_stack(s->a, s->b);
    printf("\n");
    getchar();
    if (s->size < 50)
        half_sort(s);
    print_stack(s->a, s->b);
    printf("\n");
    getchar();
}