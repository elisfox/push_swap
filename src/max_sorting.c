#include "push_swap.h"

static void b_to_bottom(t_massive *s)
{
    push_a(s);
    s->message = ft_strjoin_f(s->message, "pa\n", 1);
    s->a = rotate_a_b(s->a);
    s->message = ft_strjoin_f(s->message, "ra\n", 1);
    s->bottom++;
}

static void b_to_top(t_massive *s)
{
    push_a(s);
    s->message = ft_strjoin_f(s->message, "pa\n", 1);
    s->top--;
}

static void a_to_bottom(t_massive *s)
{
    s->a = rotate_a_b(s->a);
    s->message = ft_strjoin_f(s->message, "ra\n", 1);
    s->bottom++;
}
static void half_a_to_b(t_massive *s, int flag)
{
    while (flag <= s->size)
    {
        if (s->a->index == s->bottom + 1 && s->a->index >= s->size / 2)
        {
            a_to_bottom(s);
            flag++;
        }
        if(s->a->index <= s->middle)
        {
            push_b(s);
            s->message = ft_strjoin_f(s->message, "pb\n", 1);
        }
        else
        {
            s->a = rotate_a_b(s->a);
            s->message = ft_strjoin_f(s->message, "ra\n", 1);
        }
        flag++;
    }  
}

static void quater_a_to_b(t_massive *s, int flag)
{
    //int flag;

    //flag = s->bottom < s->size / 4 ? (s->size / 4 - s->bottom) : (s->size - s->bottom);
    while(flag--) 
    {
        if (s->a->index == s->bottom + 1)
            a_to_bottom(s);
        else
        {
            push_b(s);
            s->message = ft_strjoin_f(s->message, "pb\n", 1);
        }   
    }
}

static void    sort(t_massive *s)
{
    while(s->b)
    {
        if(s->b->index == s->bottom + 1)
            b_to_bottom(s);
        else if(s->b->index == s->top - 1)
            b_to_top(s);
        else
        {
            s->b = rotate_a_b(s->b);
            s->message = ft_strjoin_f(s->message, "rb\n", 1);
        }
        while (s->a->index == s->bottom + 1) //кинуть вниз а отсортированные
            a_to_bottom(s); 
    }
}

static void half_b_to_a(t_massive *s)
{
    if (s->b->index <= s->middle)
    {
        s->b = rotate_a_b(s->b);
        s->message = ft_strjoin_f(s->message, "rb\n", 1);
    }
    else
    {
        push_a(s);
        s->message = ft_strjoin_f(s->message, "pa\n", 1);
        //if (s->a->index == s->bottom + 1)
            //a_to_bottom(s);
    }
}

void    max_sort(t_massive *s)
{
    int flag;
    int quarter; 

    flag = 1;
    s->middle = s->size / 2;
    half_a_to_b(s, flag); //перекинуть половину в б
    print_stack(s->a, s->b);
    printf("\n");
    getchar();
    flag = s->middle;
    quarter = s->middle /= 2;
    printf("flag1 = %d\n", flag);
    while (flag--)
        half_b_to_a(s); //перекинуть четверть обратно
    print_stack(s->a, s->b);
    printf("\n");
    getchar();
    flag = s->middle;
    s->middle = s->middle / 2;
    while (flag--)
        half_b_to_a(s); //перекинуть 1/8 обратно
        print_stack(s->a, s->b);
    printf("\n");
    getchar();
    sort(s); //отсортировать 1/8
    flag = s->size / 4 - s->size / 8;
    flag = s->size / 4 - s->bottom;
    quater_a_to_b(s, flag); //перекинуть вторую 1/8
        print_stack(s->a, s->b);
    printf("\n");
    getchar();
    
    sort(s); //отсортировали 1/4
    
    print_stack(s->a, s->b);
    printf("\n");
    getchar();
    printf("flag = %d\n", flag);
    printf("mid = %d\n", s->middle);
    flag = s->size / 2 - s->bottom;
    quater_a_to_b(s, flag); //перекинуть вторую четверть

    print_stack(s->a, s->b);
    printf("\n");
    getchar();

    flag = s->size / 2 - s->bottom;
    printf("flag = %d\n", flag);
    s->middle = s->size / 8 + s->size /4;
    printf("s->middle = %d\n", s->middle);
    while (flag--)
        half_b_to_a(s); //перекинуть 1/8 обратно
    sort(s); // отсортировали 1/4 + 1/8
    flag = s->size / 2 - s->bottom;
    printf("flag = %d\n", flag);
    quater_a_to_b(s, flag); //перекинуть третью 1/8
    sort(s); // отсортировали половину

    


        
    print_stack(s->a, s->b);
    printf("\n");
    getchar();
}
