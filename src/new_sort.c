#include "push_swap.h"

void    first_up(t_massive *s, int count_first)
{
    while (count_first)
    {
        s->a = rotate_a_b(s->a);
        s->message = ft_strjoin_f(s->message, "ra\n", 1);
        count_first--;
    }
    //push_b(s);
    //s->message = ft_strjoin_f(s->message, "pb\n", 1);
}

void    first_b_up(t_massive *s, int count_low)
{
    while (count_low)
    {
        s->b = rotate_a_b(s->b);
        s->message = ft_strjoin_f(s->message, "rb\n", 1);
        count_low--;
    }
}



void    second_up(t_massive *s, int count_second)
{
    while (count_second)
    {
        s->a = rr_a_b(s->a);
        s->message = ft_strjoin_f(s->message, "rra\n", 1);
        count_second--;    
    }
    s->a = rr_a_b(s->a);
    s->message = ft_strjoin_f(s->message, "rra\n", 1);
    //push_b(s);
    //s->message = ft_strjoin_f(s->message, "pb\n", 1);
}

void    second_b_up(t_massive *s, int count_high)
{
    while (count_high)
    {
        s->a = rr_a_b(s->a);
        s->message = ft_strjoin_f(s->message, "rra\n", 1);
        count_high--;    
    }
    s->a = rr_a_b(s->a);
    s->message = ft_strjoin_f(s->message, "rra\n", 1);
}


void    push_to_b(t_massive *s)
{
    t_stack *tmp;
    int count;
    int count_low;
    int count_high;

    tmp = s->b;
    count_low = 0;
    count_high = 0;
    if (tmp == NULL)
    {
        push_b(s);
        s->message = ft_strjoin_f(s->message, "pb\n", 1);
    }
    else if (tmp->next == NULL)
    {
        if(s->a->index > tmp->index)
        {
            push_b(s);
            s->message = ft_strjoin_f(s->message, "pb\n", 1);
        }    
        else
        {
            push_b(s);
            s->message = ft_strjoin_f(s->message, "pb\n", 1);
            s->b = rotate_a_b(s->b);
            s->message = ft_strjoin_f(s->message, "rb\n", 1);
        }   
    }
    else
    {    
        while(s->a->index < tmp->index)
        {
            tmp = tmp->next;
            count_low++;
        }
        count = count_low;
        
        while(tmp->next != NULL)
            tmp = tmp->next;
        
        while(s->a->index > tmp->index && tmp->prev)
        {
            tmp = tmp->prev;
            count_high++;
        }
        printf("!\n");
        if (count_low <= count_high)
            first_b_up(s, count_low);
        else
            second_b_up(s, count_high);
        push_b(s);
        if (count_low <= count_high)
            second_b_up(s, count_low);
        else
            first_b_up(s, count_high);
    }
}

void    five_sort(t_massive *s, int size_chunk)
{
    int count_first;
    int count_second;
    t_stack *first;
    t_stack *second;
    t_stack *tmp;
    
    count_first = 0;
    count_second = 0;
    tmp = s->a;
    while(tmp->index > size_chunk)
    {
        tmp = tmp->next;
        count_first++;
    }
    printf("count_first = %d\n", count_first);
    first = tmp;
    printf("first = %d\n", first->index);
    while(tmp->next != NULL)
        tmp = tmp->next;
    printf("last = %d\n", s->a->index);
    while(tmp->index > size_chunk)
    {
        tmp = tmp->prev;
        count_second++;
    }
    printf("count_second = %d\n", count_second);
    second = tmp;
    printf("second = %d\n", second->index);
    if(count_first <= count_second)
        first_up(s, count_first);
    else
        second_up(s, count_second);
    push_to_b(s);
    
    print_stack(s->a,s->b);
}

/*static void ft_clearstr_stack(t_massive *s)
{
    char *ptr;

    ptr = s->message;
 char *str;
    while (*ptr != '\0')
    {
        if (ft_strncmp(ptr, "pa\npb\n", 6) == 0)
        {
            ft_strcpy(ptr, (ptr + 6));
            ptr = s->message;
        }
        else if (ft_strncmp(ptr, "pb\npa\n", 6) == 0)
        {
            ft_strcpy(ptr, (ptr + 6));
            ptr = s->message;
        }
        else if (ft_strncmp(ptr, "\nrb\nrrb", 7) == 0)
        {
            ft_strcpy(ptr, (ptr + 7));
            ptr = s->message;
        }
        else if (ft_strncmp(ptr, "ra\nrb\n", 4) == 0)
        {
            str = ft_strdup(ptr + 6);
            ft_strcpy(ptr, "rr\n");
            ptr = s->message;
            ptr = ft_strjoin_f(ptr, str, 1);
            s->message = ptr;
        }
        else
            ptr++;
    }
}*/

void    new_sort(t_massive *s)
{
    int size_chunk;
    int count;
    
    size_chunk = s->size;
    count = 0;
    printf("!\n");
    if (s->size >= 100)
    {
        //size_chunk = s->size / 5;
        size_chunk = 5;
        printf("size_chunk = %d\n", size_chunk);
        while(count < size_chunk)
        {
            five_sort(s, size_chunk);
            count++;
        }
        print_stack(s->a,s->b);
    }
    //ft_clearstr_stack(s);
    ft_printf("%s", s->message);
	free(s->message);
}