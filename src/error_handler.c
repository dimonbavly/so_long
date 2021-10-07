/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 11:04:17 by                   #+#    #+#             */
/*   Updated: 2021/10/07 09:40:56 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_so_long.h"

void	error_n_xit(char *str, int num)
{
	printf("Error\n>>>%s\n", str);
	exit (num);
}

void	*check_null_ptr(void *ptr)
{
	if (ptr == NULL)
		error_n_xit(strerror(errno), EXIT_FAILURE);
	else
		return (ptr);
}
