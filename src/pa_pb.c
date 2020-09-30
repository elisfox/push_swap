#include "../includes/push_swap.h"

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

/*void push_a(t_massive *s)
{
    t_stack *tmp;

    if (s->b == NULL)
        return;
    tmp = s->b;
    s->b = s->b->next;
    if (s->a == NULL)
    {   
        s->a = s->b;
        s->a->next = NULL;
    }
    else if (s->a->index == 0)
    {
        s->a = NULL;
        tmp->next = s->a;
        s->a = tmp;
    }
    else
    {    
        tmp->next = s->a;
        s->a = tmp;
    }
}*/