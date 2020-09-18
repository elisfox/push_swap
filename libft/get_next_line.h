/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcolossu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:08:12 by bcolossu          #+#    #+#             */
/*   Updated: 2019/10/16 19:30:08 by bcolossu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include "libft.h"
# include <fcntl.h>
# define BUFF_SIZE 838860

typedef	struct	s_gnl
{
	int				fd;
	char			*segment;
	struct s_gnl	*next;
}				t_gnl;

#endif
