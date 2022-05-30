/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrei <jocorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:48:31 by jocorrei          #+#    #+#             */
/*   Updated: 2022/05/30 22:12:27 by jocorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

int	ft_atol(const char *str)
{
	long    res;
	int     joker;

	res = 0;
	joker = 1;
	while (*str != '\0' && ft_strchr("\t\n\v\f\r ", *str) != NULL)
		str++;
	if (*str != '\0' && ft_strchr("+-", *str) != NULL)
	{
		if (*str == '-')
			joker *= -1;
		str++;
	}
	while (*str != '\0' && ft_strchr("0123456789", *str) != NULL)
	{
		res *= 10;
		res += *str - '0';
		str++;
	}
	return (res * joker);
}