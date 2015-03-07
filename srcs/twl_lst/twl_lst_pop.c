/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:41:52 by yyang             #+#    #+#             */
/*   Updated: 2015/03/06 21:39:49 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <assert.h>
#include "twl_lst.h"

void	*twl_lst_pop(t_lst *lst)
{
	t_lst_elem	*elem;
	void			*data;

	elem = lst->head;
	while (elem->next)
		elem = elem->next;
	data = elem->data;
	twl_lst_del_elem__(lst, elem, NULL);
	if (lst->head == elem)
		lst->head = NULL;
	return (data);
}
