/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:58:39 by jojoseph          #+#    #+#             */
/*   Updated: 2020/06/11 20:25:25 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

# define TYPE			"cCsSpdDiouUxXfFybk%"
# define FLAGS			"#-+ .*0123456789hLljz"
# define ALLSYMBOLS		"cCsSpdDiouUxXfFyb#-+% .*0123456789hLljzk"
# define NUMBERS		"0123456789"

typedef struct	s_flags
{
	int			char_null;
	int			pf_return;
	int			step;
	int			negative;
	int			trash;
	int			plus;
	int			zero;
	int			space;
	int			hash;
	int			width;
	int			prec;
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			j;
	int			l_cap;
	int			error;
	int			minus;
	int			dot;
	int			z;
	int			pointer;
	va_list		copy;
}				t_flags;

char			*b_space_int(char *string, char *s, int width, t_flags *t);
int				if_minus(char *s);
int				max(int a, int b, int c);
void			pointer_arg_start(t_flags *t, va_list ap);
void			iso_output(va_list ap, t_flags *t);
void			in_persent_text(const char *f, t_flags *t, va_list ap);
void			format_step(va_list ap, const char *f, t_flags *t);
char			*str_left_cpy(char *string, char *s, int precision, t_flags *t);
void			b_space(char *string, int width, t_flags *t);
char			*str_right_cpy(char *string, char *s, int precision);
void			convertion(char *s);
void			int_output3(char *s, t_flags *t, char *string);
void			put_null_char(char *string);
void			star_bonus(const char *format, t_flags *t, va_list ap);
void			p_processing(t_flags *t, va_list ap, int base,\
const char *format);
void			oxb_processing(t_flags *t, va_list ap, int base,\
const char *format);
void			f_process(t_flags *t, va_list ap, const char *format);
void			char_or_string(t_flags *t, va_list ap, const char *format,\
char c);
void			int_output(char *s, t_flags *t, const char *format, int zero);
void			reset_struct(t_flags *t);
void			plus_minus(const char *format, t_flags *t);
void			numbers(const char *format, t_flags *t);
void			len_analysis(const char *s, t_flags *t);
int				ft_printf(const char *format, ...);
void			bzero_struct(t_flags *t);
void			text(const char *format, t_flags *t);
void			analysis(const char *f, t_flags *t, va_list ap);
void			int_processing(t_flags *t, va_list ap, const char *format);
void			unsigned_n_process(t_flags *t, va_list ap, const char *format);

#endif
