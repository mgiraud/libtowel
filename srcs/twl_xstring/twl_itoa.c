/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2015/01/24 20:36:30 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_stdlib.h"
#include "twl_string.h"
#include "twl_xstring.h"

char	*twl_itoa(int n)
{
	return (twl_lltoa(n));
}
