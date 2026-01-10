/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcronin <jcronin@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:46:19 by jcronin           #+#    #+#             */
/*   Updated: 2026/01/10 17:46:20 by jcronin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stddef.h>

char	*ft_strchrnul(const char *s, int c);
int		ft_putnbr_base(char buf[], long long n, char *base_str, int base_len);
