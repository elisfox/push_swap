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

void half_b_to_a(t_massive *s)
{
    if (s->b->index <= s->middle)
        s->b = rotate_a_b(s->b);
    else
        push_a(s); 
}

void half_a_to_b(t_massive *s, int flag)
{
    while (flag <= s->size)
    {
        if(s->a->index <= s->middle)
            push_b(s);
        else
            s->a = rotate_a_b(s->a);
        flag++;
    }  
}

void quater_a_to_b(t_massive *s, int flag)
{
    while(flag - s->middle--) 
    {
        if (s->a->index == s->bottom + 1)
            a_to_bottom(s);
        else
            push_b(s);        
    }
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
            s->b = rotate_a_b(s->b);
        while (s->a->index == s->bottom + 1) //кинуть вниз а отсортированные
            a_to_bottom(s);
       /* print_stack(s->a, s->b);
        printf("\n");
        getchar();     */   
    }
}

void    quarter_sort(t_massive *s)
{
    int flag;

    flag = 1;
    s->middle = s->size / 2;
        half_a_to_b(s, flag); //перекинуть половину в б
    print_stack(s->a, s->b);
    printf("\n");
    getchar();
    flag = s->middle;
    s->middle /= 2;
    printf("mid = %d\n", s->middle);
    while (flag--)
        half_b_to_a(s); //перекинуть четверть обратно
    sort(s); //отсортировали четверть

    print_stack(s->a, s->b);
    printf("\n");
    getchar();
    printf("mid = %d\n", s->middle);

    quater_a_to_b(s, flag); //перекинуть вторую четверть
    
    print_stack(s->a, s->b);
    printf("\n");
    getchar();

    sort(s);

    print_stack(s->a, s->b);
    printf("\n");
    getchar();






}

void    half_sort(t_massive *s)
{
    int flag;

    flag = 1;
    s->middle = s->size / 2;
    while (flag <= s->size) //перекинуть половину в б
    {
        if(s->a->index <= s->middle)
            push_b(s);
        else
            s->a = rotate_a_b(s->a);
        flag++;        
    }
    sort(s); //отсортировать б
    s->top = s->size + 1;
    while(s->a->index != 1) //кинуть вторую половину в б
    {
        if (s->a->index == s->bottom + 1)
            a_to_bottom(s);
        else
            push_b(s);
    }
    sort(s); //отсортировать вторую половину б
}

void    sorting_algorithm(t_massive *s)
{
   /* print_stack(s->a, s->b);
    printf("\n");
    getchar();*/
    if (s->size >= 50)
        quarter_sort(s);
    if (s->size < 50)
        half_sort(s);
    print_stack(s->a, s->b);
    printf("\n");
    getchar();
}