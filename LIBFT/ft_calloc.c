/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:04:44 by jmanson           #+#    #+#             */
/*   Updated: 2022/09/17 11:04:49 by jmanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*ptr;

	if (number == 0 || size == 0)
	{
		number = 1;
		size = 1;
	}
	ptr = malloc(number * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, number * size);
	return (ptr);
}
