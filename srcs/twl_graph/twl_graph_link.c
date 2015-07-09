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

#include "twl_graph.h"

#include "twl_xstdlib.h"

#include "twl_xstdio.h"

void				twl_graph_link(t_graph *this, t_graph_node *node1,
														t_graph_node *node2)
{
	if (!twl_graph_node_mgr_find_by_id(this->nodes_, node1->id_)
		|| !twl_graph_node_mgr_find_by_id(this->nodes_, node2->id_))
	{
		twl_xprintf("twl_graph_link required nodes belonging to current graph");
	}
	if (!twl_graph_node_mgr_find_by_id(node1->links_, node2->id_))
	{
		twl_lst_push(node1->links_, node2);
	}
	if (!twl_graph_node_mgr_find_by_id(node2->links_, node1->id_))
	{
		twl_lst_push(node2->links_, node1);
	}
	(void)this;
}
