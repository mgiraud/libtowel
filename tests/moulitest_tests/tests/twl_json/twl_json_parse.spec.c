#include <project.h>
#include "twl_json.h"

static void test_array_of_bool(t_test *test)
{
	char			json_str[] = "[true,false]";
	t_jnode			*node;
	char			*json_dump_res;

	node = twl_json_parse(json_str);
	json_dump_res = twl_json_dump(node);
	mt_assert(node && twl_strcmp(json_dump_res, json_str) == 0);

	twl_jnode_del(node);
}

static void test_empty_array(t_test *test)
{
	char			json_str[] = "[]";
	t_jnode			*node;
	char			*json_dump_res;

	node = twl_json_parse(json_str);
	json_dump_res = twl_json_dump(node);
	mt_assert(node && twl_strcmp(json_dump_res, json_str) == 0);

	twl_jnode_del(node);
}

static void test_two_levels_array(t_test *test)
{
	char			json_str[] = "[[true],false]";
	t_jnode			*node;
	char			*json_dump_res;

	node = twl_json_parse(json_str);
	json_dump_res = twl_json_dump(node);
	mt_assert(node && twl_strcmp(json_dump_res, json_str) == 0);

	twl_jnode_del(node);
}

static void test_array_of_numbers(t_test *test)
{
	char			json_str[] = "[[21],42]";
	t_jnode			*node;
	char			*json_dump_res;

	node = twl_json_parse(json_str);
	json_dump_res = twl_json_dump(node);
	mt_assert(node && twl_strcmp(json_dump_res, json_str) == 0);

	twl_jnode_del(node);
}

static void test_null(t_test *test)
{
	char			json_str[] = "[null,42]";
	t_jnode			*node;
	char			*json_dump_res;

	node = twl_json_parse(json_str);
	json_dump_res = twl_json_dump(node);
	mt_assert(node && twl_strcmp(json_dump_res, json_str) == 0);

	twl_jnode_del(node);
}

static void test_object(t_test *test)
{
	char			json_str[] = "{\"key1\":21,\"key2\":42}";
	t_jnode			*node;
	char			*json_dump_res;

	node = twl_json_parse(json_str);
	json_dump_res = twl_json_dump(node);
	mt_assert(node && twl_strcmp(json_dump_res, json_str) == 0);

	twl_jnode_del(node);
}

static void test_object_empty(t_test *test)
{
	char			json_str[] = "{}";
	t_jnode			*node;
	char			*json_dump_res;

	node = twl_json_parse(json_str);
	json_dump_res = twl_json_dump(node);
	mt_assert(node && twl_strcmp(json_dump_res, json_str) == 0);

	twl_jnode_del(node);
}

static void test_object_complex(t_test *test)
{
	char			json_str[] = "{\"key1\":21,\"key2\":[1,2,{\"key3\":1}]}";
	t_jnode			*node;
	char			*json_dump_res;

	node = twl_json_parse(json_str);
	json_dump_res = twl_json_dump(node);
	mt_assert(node && twl_strcmp(json_dump_res, json_str) == 0);

	twl_jnode_del(node);
}

static void test_string(t_test *test)
{
	char			json_str[] = "[\"21\",\"42\",123]";
	t_jnode			*node;
	char			*json_dump_res;

	node = twl_json_parse(json_str);
	json_dump_res = twl_json_dump(node);
	mt_assert(node && twl_strcmp(json_dump_res, json_str) == 0);
	twl_jnode_del(node);
}

static void test_string_in_object(t_test *test)
{
	char			json_str[] = "{\"key\":{\"key\":{\"key\":{\"key\":{\"key\":\"value\"}}}}}";
	t_jnode			*node;
	char			*json_dump_res;

	node = twl_json_parse(json_str);
	json_dump_res = twl_json_dump(node);
	mt_assert(node && twl_strcmp(json_dump_res, json_str) == 0);
	twl_jnode_del(node);
}

static void test_white_space1(t_test *test)
{
	char			json_str[] = "\n [1, 2,3]";
	char			dump_expected[] = "[1,2,3]";
	t_jnode			*node;
	char			*json_dump_res;

	printf("===============\n");
	printf("str  '%s'\n", json_str);
	node = twl_json_parse(json_str);
	json_dump_res = twl_json_dump(node);

	printf("dump %s\n", json_dump_res);
	mt_assert(node && twl_strcmp(json_dump_res, dump_expected) == 0);
	twl_jnode_del(node);
}

static void test_white_space2(t_test *test)
{
	char			json_str[] = "\n [\t\n 1 , 2 , 3 ]\t\t\n";
	char			dump_expected[] = "[1,2,3]";
	t_jnode			*node;
	char			*json_dump_res;

	printf("===============\n");
	printf("str  '%s'\n", json_str);
	node = twl_json_parse(json_str);
	json_dump_res = twl_json_dump(node);

	printf("dump %s\n", json_dump_res);
	mt_assert(node && twl_strcmp(json_dump_res, dump_expected) == 0);
	twl_jnode_del(node);
}

static void test_white_space_object(t_test *test)
{
	char			json_str[] = "\n{ \"key\" : 123 }\n";
	char			dump_expected[] = "{\"key\":123}";
	t_jnode			*node;
	char			*json_dump_res;

	printf("===============\n");
	printf("str  '%s'\n", json_str);
	node = twl_json_parse(json_str);
	json_dump_res = twl_json_dump(node);

	printf("dump %s\n", json_dump_res);
	mt_assert(node && twl_strcmp(json_dump_res, dump_expected) == 0);
	twl_jnode_del(node);
}

static void test_white_space_complex(t_test *test)
{
	char			json_str[] = "{\"key\":[{},{ }, [], [ ],[{}],{\"key\":[1,2,3]}]}";
	char			dump_expected[] = "{\"key\":[{},{},[],[],[{}],{\"key\":[1,2,3]}]}";
	t_jnode			*node;
	char			*json_dump_res;

	printf("===============\n");
	printf("str  '%s'\n", json_str);
	node = twl_json_parse(json_str);
	json_dump_res = twl_json_dump(node);

	printf("dump %s\n", json_dump_res);
	mt_assert(node && twl_strcmp(json_dump_res, dump_expected) == 0);
	twl_jnode_del(node);
}

void	suite_twl_json_parse(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_array_of_bool);
	SUITE_ADD_TEST(suite, test_empty_array);
	SUITE_ADD_TEST(suite, test_two_levels_array);
	SUITE_ADD_TEST(suite, test_array_of_numbers);
	SUITE_ADD_TEST(suite, test_null);
	SUITE_ADD_TEST(suite, test_object);
	SUITE_ADD_TEST(suite, test_object_empty);
	SUITE_ADD_TEST(suite, test_object_complex);
	SUITE_ADD_TEST(suite, test_string);
	SUITE_ADD_TEST(suite, test_string_in_object);
	SUITE_ADD_TEST(suite, test_white_space1);
	SUITE_ADD_TEST(suite, test_white_space2);
	SUITE_ADD_TEST(suite, test_white_space_object);
	SUITE_ADD_TEST(suite, test_white_space_complex);
}