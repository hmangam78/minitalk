/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:54:26 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/11/08 10:46:47 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/*Receives a string containing a binary integer and returns its integer value*/
int	ft_bintoi(const char *string)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (i <= 7)
	{
		num = (2 * num) + (string[i] - '0');
		i++;
	}
	return (num);
}

/*Receives an integer and returns a string with its binary code*/
char	*ft_itobin(int n)
{
	char	*str;
	long	num;
	int		i;

	num = n;
	i = 0;
	str = malloc(sizeof(char) * 9);
	if (!str)
		return (NULL);
	while (i < 9)
		str[i++] = '\0';
	i = 7;
	while (i >= 0)
	{
		str[i--] = (num % 2) + '0';
		num = num / 2;
	}
	return (str);
}
