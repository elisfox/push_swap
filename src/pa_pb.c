#include "push_swap.h"

void push_b(t_massive *s)
{
    t_stack *tmp;

    tmp = s->a;
    if (s->a->next)
    {
        s->a = s->a->next;
        s->a->prev = NULL;
    }
    else
        s->a = NULL;
    if (tmp == NULL)
        return;
    else if (s->b == NULL)
    {   
        s->b = tmp;
        s->b->prev = NULL;
        s->b->next = NULL;
    }    
    else
    {
        
        tmp->next = s->b;
        s->b->prev = tmp;
        s->b = tmp;
    }
}   

void push_a(t_massive *s)
{
    t_stack *tmp;

    tmp = s->b;
    if (s->b->next)
    {
        s->b = s->b->next;
        s->b->prev = NULL;
    }
    else
        s->b = NULL;    
    if (tmp == NULL)
        return;
    else if (s->a == NULL)
    {   
        s->a = tmp;
        s->a->prev = NULL;
        s->a->next = NULL;
    }    
    else
    {
        tmp->next = s->a;
        s->a->prev = tmp;
        s->a = tmp;
    }
}