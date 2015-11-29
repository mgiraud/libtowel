/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_jnode.h"

#include "twl_xstdlib.h"

t_jnode				*twl_jnode_new_array(void)
{
	t_jnode	*node;

	node = twl_jnode_new();
	node->type = JSON_ARRAY;
	node->value.array = twl_lst_new();
	return (node);
}