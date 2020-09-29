#include "../includes/push_swap.h"

void	make_instr(t_massive *s, t_instr *instr)
{
	if (instr->sa)
		swap_a_b(s->a);
	else if (instr->sb)
		swap_a_b(s->b);
	else if (instr->ss)
		swap_ss(s->a,s->b);
	else if (instr->pa)
		push_a(s);
	else if (instr->pb)
		push_b(s);
	else if (instr->ra)
		s->a = rotate_a_b(s->a);
	else if (instr->rb)
		s->b = rotate_a_b(s->b);
	else if (instr->rr)
		rr(s->a, s->b);
	else if (instr->rra)
		s->a = rr_a_b(s->a);
	else if (instr->rrb)
		s->b = rr_a_b(s->b);
	else if (instr->rrr)
		rrr(s->a, s->b);	
}

static int check_instr(char *line, t_instr *instr)
{
    if(!ft_strcmp(line, "sa"))
		instr->sa = 1;
	else if(!ft_strcmp(line, "sb"))
		instr->sb = 1;
	else if(!ft_strcmp(line, "ss"))
		instr->ss = 1;
	else if(!ft_strcmp(line, "pa"))
		instr->pa = 1;
	else if(!ft_strcmp(line, "pb"))
		instr->pb = 1;
	else if(!ft_strcmp(line, "ra"))
		instr->ra = 1;
	else if(!ft_strcmp(line, "rb"))
		instr->rb = 1;
	else if(!ft_strcmp(line, "rr"))
		instr->rr = 1;
	else if(!ft_strcmp(line, "rra"))
		instr->rra = 1;
	else if(!ft_strcmp(line, "rrb"))
		instr->rrb = 1;
	else if(!ft_strcmp(line, "rrr"))
		instr->rrr = 1;
    else
        return (0);
    return(1);
    
}

void zero_instr(t_instr *instr)
{
	instr->sa = 0;
	instr->sb = 0;
	instr->ss = 0;
	instr->pa = 0;
	instr->pb = 0;
	instr->ra = 0;
	instr->rb = 0;
	instr->rr = 0;
	instr->rra = 0;
	instr->rrb = 0;
	instr->rrr = 0;
}

void check_sort_stacks(t_massive *s)
{
	int flag_a;
	int flag_b;

	flag_a = 1;
	flag_b = 1;
	while (s->a->next)
	{
		if	(s->a->val > s->a->next->val)
			flag_a *= 0;
		s->a = s->a->next;
	}
	if (s->b)
		flag_b = 0;
	if (flag_a == 1 && flag_b == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void    read_instructions(t_massive *s)
{
    char	*line;
    t_instr *instr;
    size_t fd;

	if (!(instr = (t_instr *)ft_memalloc(sizeof(t_instr))))
		error_stack();
    fd = 0;
    if(s->size == 1)
    {
		ft_printf("OK\n");
		return ;
	}
    while (get_next_line(fd, &line) == 1)
    {
        zero_instr(instr);
        if (!check_instr(line, instr))
		{
			free(line);
			error_stack();
        }
		free(line);
    }
    close(fd);
	check_sort_stacks(s);
}
