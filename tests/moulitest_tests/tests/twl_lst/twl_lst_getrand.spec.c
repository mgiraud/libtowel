#include <project.h>

static void simple_test(t_test *test)
{
	t_lst *lst;
	char *coucou;

	lst = twl_lst_new();

	twl_lst_push(lst, strdup("tata"));
	twl_lst_push(lst, strdup("tata"));
	twl_lst_push(lst, strdup("tata"));
	coucou = twl_lst_get_rand(lst);
	mt_assert(!!coucou);

}

void	suite_twl_lst_getrand(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
