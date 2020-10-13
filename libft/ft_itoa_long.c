/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:26:13 by jojoseph          #+#    #+#             */
/*   Updated: 2019/09/16 18:26:43 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_long(long nbr)
{
	if (nbr < 0)
		return (ft_strjoin("-", ft_itoa_unsigned(-nbr)));
	else
		return (ft_itoa_unsigned(nbr));
}
