#include "../includes/push_swap.h"

static int check_instr(t_massive *s, char *line, t_instr *instr)
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
	else if(!ft_strcmp(line, "rrb"))
		instr->rrb = 1;
	else if(!ft_strcmp(line, "rrr"))
		instr->rrr = 1;
	else if(!ft_strcmp(line, "rr"))
		instr->rr = 1;
	else if(!ft_strcmp(line, "rra"))
		instr->rra = 1;
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


void    read_instructions(t_massive *s)
{
    char	*line;
    t_instr *instr;
    size_t fd;

    fd = 0;
    if(s->size = 1)
    {
		ft_printf("OK\n");
		return ;
	}
    while (get_next_line(fd, &line) == 1)
    {
        zero_instr(instr);
        if (!check_instr(s, line, instr))
		{
			free(line);
			error_stack();
        }
        free(line);
        make_instr(s, rule)

    }
    free(line);
    close(fd);




}
