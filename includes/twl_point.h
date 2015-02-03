/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_point.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 14:35:02 by yyang             #+#    #+#             */
/*   Updated: 2015/02/02 20:25:27 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWL_POINT_H
# define TWL_POINT_H

# define T_FT_POINT(x, y)	((t_twl_point){(x), (y)})

typedef struct	s_twl_point
{
	int x;
	int y;
}				t_twl_point;

typedef struct	s_twl_dpoint
{
	double x;
	double y;
}				t_twl_dpoint;


t_twl_point		*twl_point_init(int x, int y);
t_twl_dpoint	*twl_dpoint_init(double x, double y);

#endif
