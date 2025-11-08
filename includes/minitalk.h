/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:10:05 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/11/08 10:48:19 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"
# define BUSY 0
# define READY 1

int		ft_bintoi(const char *string);
char	*ft_itobin(int n);

#endif