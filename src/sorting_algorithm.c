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
    while (i <= s->size)
    {
        if(s->a->index <= s->middle)
            push_b(s);
        else
            s->a = rotate_a_b(s->a);
        i++;        
    }
    sort(s);
    while (s->a->index == s->bottom + 1)
        a_to_bottom(s);
    s->top = s->size + 1;
    while(s->a->index != 1)
    {
        if (s->a->index == s->bottom + 1)
            a_to_bottom(s);
        else
            push_b(s);
    }
    sort(s);
    a_to_bottom(s);
}

void    sorting_algorithm(t_massive *s)
{
    if (s->size < 50)
        half_sort(s);
}