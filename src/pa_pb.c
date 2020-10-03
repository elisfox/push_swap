#include "push_swap.h"

void push_b(t_massive *s)
{
    t_stack *tmp;

    tmp = s->a;
    s->a = s->a->next;
    if (tmp == NULL)
        return;
    else if (s->b == NULL)
    {   
        s->b = tmp;
        s->b->next = NULL;
    }    
    else
    {
        tmp->next = s->b;
        s->b = tmp;
    }
    printf("1\n");
}

void push_a(t_massive *s)
{
    t_stack *tmp;

    tmp = s->b;
    s->b = s->b->next;
    if (tmp == NULL)
        return;
    else if (s->a == NULL)
    {   
        s->a = tmp;
        s->a->next = NULL;
    }    
    else
    {
        tmp->next = s->a;
        s->a = tmp;
    }
    printf("1\n");
}