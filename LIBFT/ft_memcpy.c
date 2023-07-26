/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanson <jmanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:13:17 by jmanson           #+#    #+#             */
/*   Updated: 2023/07/19 14:55:52 by jmanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(char *dst, const char *src, size_t n)
{
	char		*srce;
	size_t		i;

	srce = (char *)src;
	i = 0;
	if ((!dst && !src) || !n)
		return (dst);
	while (srce && i < n)
	{
		dst[i] = srce[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
