/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 21:12:52 by annguyen          #+#    #+#             */
/*   Updated: 2015/03/07 14:36:58 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWL_XSYS_STAT_H
# define TWL_XSYS_STAT_H

int			twl_isdir(char *path);
int			twl_isexec(char *path);
int			twl_isblock(char *path);
int			twl_issocket(char *path);
int			twl_isfifo(char *path);
int			twl_isspec_char(char *path);
int			twl_islink(char *path);
int			twl_isdir(char *path);

#endif
