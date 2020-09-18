/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_longlong.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcolossu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:26:13 by bcolossu          #+#    #+#             */
/*   Updated: 2019/09/16 18:26:43 by bcolossu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_longlong(long long nbr)
{
	if (nbr < 0)
		return (ft_strjoin("-", ft_itoa_unsigned(-nbr)));
	else
		return (ft_itoa_unsigned(nbr));
}
