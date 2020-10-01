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
}

/*void push_b(t_massive *s)
{
    t_stack *tmp;
    
    if (s->a == NULL)
        return;
    tmp = s->a;
    s->a = s->a->next;
    if (s->b->index == 0)
    {
        s->b = NULL;
        tmp->next = s->b;
        s->b = tmp;
    }
    else
    {    
        tmp->next = s->b;
        s->b = tmp;
    }
}*/

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
}