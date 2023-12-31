/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:37:43 by jmanson           #+#    #+#             */
/*   Updated: 2023/07/05 14:37:47 by jmanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(char *message)
{
	printf("\033[0;31m" " Error\n    %s\n" "\033[0m", message);
	return (0);
}

void	*null_error(char *message)
{
	printf("\033[0;31m" " Error\n %s\n" "\033[0m", message);
	return (0);
}

void	print_warning(char *message)
{
	printf("\033[0;33m" " Warning\n %s\n" "\033[0m", message);
}
