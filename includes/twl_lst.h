/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 19:33:34 by yyang             #+#    #+#             */
/*   Updated: 2015/03/07 14:50:47 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWL_LST_H
# define TWL_LST_H

# include <stddef.h>
# include "twl_string.h"
# include "twl_sort.h"

typedef struct				s_lst_elem
{
	void					*data;
	struct s_lst_elem		*next;
	struct s_lst_elem		*prev;
	char					*key;
}							t_lst_elem;

typedef struct				s_lst
{
	t_lst_elem				*head;
}							t_lst;

/*
** Basics
*/

t_lst						*twl_lst_new(void);
void						*twl_lst_get(t_lst *lst, int index);
void						*twl_lst_get_rand(t_lst *lst);
size_t						twl_lst_len(t_lst *lst);
void						twl_lst_del(t_lst *lst, void (*delfn)());

/*
** Aggregate
*/

size_t						twl_lst_count(t_lst *lst, void *(*f)(void *));

/*
** Search
*/

int							twl_lst_indexof(t_lst *lst, void *target,
														int (*cmp_fn)());
void						*twl_lst_find(t_lst *lst,
						bool (*f)(void *data, void *context), void *context);

/*
** Move
*/

void						*twl_lst_pop(t_lst *lst);
void						*twl_lst_popi(t_lst *lst, int index);
void						twl_lst_push(t_lst *lst, void *data);
void						*twl_lst_shift(t_lst *lst);
void						twl_lst_unshift(t_lst *lst, void *data);
void						twl_lst_swap(t_lst *lst, int i, int j);

/*
** Collection
*/

void						twl_lst_iter(t_lst *lst,
	void (*f)(void *data, void *context), void *context);
void						twl_lst_iteri(t_lst *lst,
	void (*iter_fn)(void *data, int index, void *context), void *context);

void						twl_lst_filter(t_lst *lst,
	bool (*filter_fn)(void *data, void *context),
	void *context, void (*delfn)(void *));
t_lst						*twl_lst_map(t_lst *lst, void *(*f)(void *data));
void						*twl_lst_reduce(t_lst *lst,
						void *(*fn)(void *data, void *memo), void *context);
int							twl_lst_reducei(t_lst *lst,
								int (*fn)(void *data, int memo), int memo);

/*
** Misc
*/

void						twl_lst_sort(t_lst *lst,
									t_sort_cmp_fn *cmp_fn, void *context);
void						twl_lst_rev(t_lst *lst);

/*
** Convert
*/

void						**twl_lst_to_arr(t_lst *lst);
void						*twl_lst_to_arr2(t_lst *lst, int cols);

/*
** Private
*/

t_lst_elem					*twl_lst_get_elem__(t_lst *lst, int index);
t_lst_elem					*twl_lst_create_elem__(void *data);
void						twl_lst_del_elem__(t_lst *lst,
									t_lst_elem *elem,
														void (*delfn)());
void						twl_lst_iter_elem__(t_lst *lst,
			void (*f)(t_lst_elem *elem, void *context), void *context);
void						twl_lst_link__(t_lst_elem *elem1,
													t_lst_elem *elem2);

void						twl_lst_clear__(t_lst *lst, void (*delfn)());

#endif
