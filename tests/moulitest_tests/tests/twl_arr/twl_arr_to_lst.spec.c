#include "twl_arr.h"
#include "project.h"
#include "twl_lst.h"

static void simple_test(t_test *test)
{
	char **arr;
	t_lst *lst;

	arr = twl_arr_new(99);
	twl_arr_push(arr, strdup("zaa"));
	twl_arr_push(arr, strdup("zbb"));
	twl_arr_push(arr, strdup("zcc"));

	lst = twl_arr_to_lst(arr);

	mt_assert(strcmp(twl_lst_get_elem__(lst, 0)->data, "zaa") == 0);
	mt_assert(strcmp(twl_lst_get_elem__(lst, 1)->data, "zbb") == 0);
	mt_assert(strcmp(twl_lst_get_elem__(lst, 2)->data, "zcc") == 0);
	mt_assert(twl_lst_get_elem__(lst, 3) == NULL);
}

void	suite_twl_arr_to_lst(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}