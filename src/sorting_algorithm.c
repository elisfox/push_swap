#include "push_swap.h"

void to_bottom(t_massive *s)
{
    push_a(s);
    s->a = rotate_a_b(s->a);
    s->bottom++;
}

void to_top(t_massive *s)
{
    push_a(s);
    s->top--;
}

void    back_half(t_massive *s)
{
    while(s->b)
    {
        if(s->b->index == s->bottom +1)
            to_bottom(s);
        else if(s->b->index == s->top - 1)
            to_top(s);
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
    back_half(s);
    while (s->a->index == s->bottom + 1)
    {
        
    }

}

void    sorting_algorithm(t_massive *s)
{
    if (s->size < 50)
        half_sort(s);
}