/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanson <jmanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:16:14 by jmanson           #+#    #+#             */
/*   Updated: 2023/05/11 16:06:37 by jmanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *str, char *str2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = malloc(ft_strlen(str) + ft_strlen(str2) + 1);
	if (!new)
		return (NULL);
	if (str)
		while (str[j])
			new[i++] = str[j++];
	j = 0;
	if (str2)
		while (str2[j])
			new[i++] = str2[j++];
	new[i] = '\0';
	if (str)
		free(str);
	return (new);
}
