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

#include <stdlib.h>

#include "twl_json.h"

#include "twl_xstring.h"

#include "twl_stdio.h"
#include "twl_xstdio.h"
#include "twl_stdlib.h"

static t_jnode		*twl_json_parse_do(char *json_str, int *len_ptr);

int					twl_json_parse_array(t_jnode *arr_node, char *json_str)
{
	char			*json_str_sav;
	int				len;
	t_jnode			*node;

	json_str_sav = json_str;
	json_str++;
	while (twl_strchr(JSON_WHITE_SPACE_CHARS, *json_str))
		json_str++;
	if (*json_str != ']')
	{
		while (true)
		{
			node = twl_json_parse_do(json_str, &len);
			if (!node)
			{
				twl_lprintf("[syntax error] array elem: %s\n", json_str);
				return -1;
			}
			twl_jnode_array_push(arr_node, node);
			json_str += len;
			while (twl_strchr(JSON_WHITE_SPACE_CHARS, *json_str))
				json_str++;
			if (*json_str == ']')
				break ;
			if (*json_str != ',')
			{
				twl_lprintf("[syntax error] expect: ']'\n");
				return -1;
			}
			json_str++;
		}
	}
	json_str++;
	return (json_str - json_str_sav);
}

static char			*twl_json_parse_get_obj_key(char *json_str, int *len_ptr)
{
	char			*key;

	key = twl_str_before_any_char(json_str, ":");
	if (key == NULL)
		return (NULL);
	*len_ptr = twl_strlen(key) + 1;
	key = twl_strtrim_chars_free(key, JSON_WHITE_SPACE_CHARS);
	if (*key != '\"' || key[twl_strlen(key) - 1] != '\"')
	{
		free(key);
		return (NULL);
	}
	key = twl_strtrim_chars_free(key, "\"");
	if (twl_strchr(key, '\"') || *key == '\0')
	{
		free(key);
		return (NULL);
	}
	return (key);
}

int					twl_json_parse_object(t_jnode *obj_node, char *json_str)
{
	char			*json_str_sav;
	int				len;
	t_jnode			*node;
	char			*key;

	json_str_sav = json_str;
	json_str++;
	while (twl_strchr(JSON_WHITE_SPACE_CHARS, *json_str))
		json_str++;
	if (*json_str != '}')
	{
		while (true)
		{
			key = twl_json_parse_get_obj_key(json_str, &len);
			if (key == NULL)
				return (-1);
			json_str += len;
			node = twl_json_parse_do(json_str, &len);
			if (!node)
				twl_xprintf("object syntax error: %s\n", json_str);
			twl_jnode_object_add(obj_node, node, key);
			json_str += len;
			while (twl_strchr(JSON_WHITE_SPACE_CHARS, *json_str))
				json_str++;
			if (*json_str == '}')
				break ;
			if (*json_str != ',')
				twl_xprintf("object syntax error: %s\n", json_str);
			json_str++;
		}
	}
	json_str++;
	return (json_str - json_str_sav);
}

t_jnode				*twl_json_parse_string(char *json_str, int *len_ptr)
{
	char			*str_sav;
	char			*the_string;
	t_jnode			*node;

	json_str++;
	str_sav = json_str;

	while (*json_str)
	{
		if (*json_str == '"' && *(json_str - 1) != '\\')
			break;
		json_str++;
	}
	the_string = twl_strndup(str_sav, json_str - str_sav);
	*len_ptr = json_str - str_sav + 2;
	node = twl_jnode_new_string(the_string);
	return (node);
}

static char			*get_primitive_token(char *json_str)
{
	char			*result;
	size_t			len;
	char			*token;

	result = twl_strchr_any(json_str, JSON_STR_END_OF_PRIMITIVE);
	if (result == NULL)
		return (twl_strdup(json_str));
	len = result - json_str;
	token = twl_strnew(len);
	twl_strncpy(token, json_str, len);
	token = twl_strtrim_chars_free(token, JSON_WHITE_SPACE_CHARS);
	return (token);
}

static t_jnode		*twl_json_parse_primitive(char *json_str, int *len_ptr)
{
	t_jnode			*node;
	char			*token;

	node = NULL;
	token = get_primitive_token(json_str);
	if (twl_strequ(token, JSON_STR_TRUE))
	{
		node = twl_jnode_new_primitive(JSON_BOOL, true);
		*len_ptr = JSON_STR_TRUE_LEN;
	}
	else if (twl_strequ(token, JSON_STR_FALSE))
	{
		node = twl_jnode_new_primitive(JSON_BOOL, false);
		*len_ptr = JSON_STR_FALSE_LEN;
	}
	else if (twl_strequ(token, JSON_STR_NULL))
	{
		node = twl_jnode_new_null();
		*len_ptr = JSON_STR_NULL_LEN;
	}
	else if (twl_str_contains_only(token, JSON_NUMBER_CHARS))
	{
		node = twl_jnode_new_primitive(JSON_NUMBER, twl_atoi(token));
		*len_ptr = twl_strlen(token);
	}
	free(token);
	return node;
}

static t_jnode		*twl_json_parse_do(char *json_str, int *len_ptr)
{
	t_jnode			*node;
	int				skiped;

	skiped = 0;
	node = NULL;
	while (twl_strchr(JSON_WHITE_SPACE_CHARS, *json_str))
	{
		skiped++;
		json_str++;
	}
	if (*json_str == '[')
	{
		node = twl_jnode_new_array();
		*len_ptr = twl_json_parse_array(node, json_str);
	}
	else if (*json_str == '{')
	{
		node = twl_jnode_new_object();
		*len_ptr = twl_json_parse_object(node, json_str);
	}
	else if (*json_str == '"')
	{
		node = twl_json_parse_string(json_str, len_ptr);
	}
	else if (twl_strchr(JSON_PRIM_START_CHARS, *json_str))
	{
		node = twl_json_parse_primitive(json_str, len_ptr);
	}
	if (*len_ptr == -1)
		return (NULL);
	*len_ptr += skiped;

	return node;
}

t_jnode				*twl_json_parse(char *json_str)
{
	int				len;
	t_jnode			*node;

	node = twl_json_parse_do(json_str, &len);
	if (!node)
		return (NULL);
	while (json_str[len] && twl_strchr(JSON_WHITE_SPACE_CHARS, json_str[len]))
		len++;
	if (twl_strlen(json_str) != (size_t)len)
		return (NULL);
	return node;
}
