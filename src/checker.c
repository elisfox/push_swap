#include "../includes/push_swap.h"

void error_stack(void)
{
    ft_printf("%s\n", "Error");
    exit(1);
}

void check_numbers(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (i < ac)
    {
        j = 0;
        while(av[i][j])
        {
            while (ft_isspace(av[i][j]))
				j++;
            
            if((av[i][j] == '-' || av[i][j] == '+' || av[i][j] == ' ') && ft_isdigit(av[i][j + 1]))
                j++;
            if (!ft_isdigit(av[i][j]) && av[i][j] != '\0')
				error_stack();
            while (ft_isdigit(av[i][j]))
				j++;
            if(!ft_isspace(av[i][j]) && av[i][j] != '\0')
                error_stack();
       }
       i++;
    }
}

int *create_array(int count, char ***args)
{
    int *tab;
    int i;
    int j;

    i = 0;
    j = 0;
    if(!(tab = (int *)malloc(sizeof(int) * count)))
        return (NULL);
    count = 0;
    while(args[i])
    {
        j = 0;
        while(args[i][j])
        {
            tab[count] = (int)(ft_atoi(args[i][j]));
            printf("tab = %d\n", tab[count]);
            j++;
            count++;
        }
        i++;
    }
    return (tab);            
}

char ***extract_numbers(int ac, char **av)
{
    char ***args;
    int i;
    int j;
    
    i = 1;
    j = 0;
    args = (char ***)malloc(sizeof(char **) * (ac));
    while (i < ac)
        args[j++] = ft_strsplit(av[i++], ' '); 
    args[j] = NULL;
    return (args);
}

int count_numbers(char ***args)
{
    int count;
    int i;
    int j;

    count = 0;
    i = 0;
    j = 0;
    while (args[i])
    {
        j = 0;
        while(args[i][j++])
            count++;
        i++;
    }
    return (count);
}

void check_doubles(int *tab)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while(tab[i++])
    {
        j = 0;
        while(tab[j++])
        {
            if(tab[i] == tab[j] && i != j)
                error_stack();
        }
        i++;
    }
}

void valid_args(t_massive *s, int ac, char **av)
{
    char ***args;

    check_numbers(ac, av);
    args = extract_numbers(ac, av);
    s->size = count_numbers(args);
    s->tab = create_array(s->size, args);
    check_doubles(s->tab);
    
}

t_stack *add_elem(t_stack *first, int i)
{
    t_stack *new;

    if(!(new = (t_stack *)ft_memalloc(sizeof(t_stack))))
        error_stack();
    first->next = new;
    new->val = i;
    return(new);    
}
void print_stack(t_stack *a)
{
    while(a)
    {
        printf("elem=%d, index=%d\n", a->val, a->index);
        a = a->next;
    }
}

void get_index(t_stack *a, int *new_tab)
{
    int j;

    j = 0;
    while(a != NULL)
    {
        j = 0;
        while(a->val != new_tab[j])
            j++;
        a->index = j + 1;
        //printf("elem=%d, index=%d\n", a->val, a->index);
        a = a->next;
    }
}

t_stack *init_stack_a(t_massive *s, char **av, int ac)
{
    t_stack *head;
    int i;
    int *new_tab;

    i = 0;
    valid_args(s, ac, av);
    if(!(s->a = (t_stack *)ft_memalloc(sizeof(t_stack))))
        error_stack();
    head = s->a;
    s->a->val = s->tab[i++];
    while(i < s->size)
        s->a = add_elem(s->a, s->tab[i++]);
    s->a->next = NULL;
    new_tab = sort_tab(s->tab, s->size);
    s->a = head;
    get_index(s->a, new_tab);
    return(head);
}

/*t_stack *init_stack_a(t_massive *s)
{
    if(!(s->b = (t_stack *)ft_memalloc(sizeof(t_stack))))
        error_stack();
    s->b->index = 0;
    s->b->val = 0;
    s->b->next = NULL;
    return(s->b);    
}*/

int main(int ac, char **av)
{
    t_massive *s;

    if (!(s = (t_massive *)ft_memalloc(sizeof(t_massive))))
		error_stack();
	if (ac >= 2)
    {
        s->a = init_stack_a(s, av, ac);
        //s->b = init_stack_b(s);
        if(!(s->b = (t_stack *)ft_memalloc(sizeof(t_stack))))
            error_stack();
        print_stack(s->a);
        //read_instructions(s);
        rotate_a_b(s->a, s);
        printf("\n");
        print_stack(s->a);

    }
    return(0);
}