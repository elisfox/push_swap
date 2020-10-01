#include "push_swap.h"

void print_stack(t_stack *a, t_stack *b)
{
    ft_printf("_   _\na   b\n");
    while(a || b)
    {
        if (a)
        {
            printf("%d", a->index);
            a = a->next;
        }
        else
            printf("#");
        
        printf("   ");
        if(b)
        {
            printf("%d", b->index);
            b = b->next;
        }
        else
            printf("#");
        printf("\n");
    }
}

void exit_error(void)
{
    ft_printf("%s\n", "Error");
    exit(1);
}

long long	ft_atoi_ps(const char *str)
{
	int                 nv;
	long long           nb;
	int                 i;

	i = 0;
	nb = 0;
	nv = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			nv *= -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		if (nb * 10 + (str[i] - 48) < nb)
			return (nv < 0 ? 0 : -1);
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	nb *= nv;
    if (nb > INT32_MAX || nb < INT32_MIN)
        exit_error();
	return (nb);
}