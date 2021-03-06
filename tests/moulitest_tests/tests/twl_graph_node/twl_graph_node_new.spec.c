#include <project.h>
#include "twl_graph.h"

static void simple_test(t_test *test)
{
	t_graph_node			*node0;
	t_graph_node			*node1;
	t_graph_node			*node2;
	t_graph_node			*node3;

	node0 = twl_graph_node_new(0, "A");
	node1 = twl_graph_node_new(1, "B");
	node2 = twl_graph_node_new(2, "C");
	node3 = twl_graph_node_new(3, "D");

	mt_assert(strcmp(node0->data_, "A") == 0);
	mt_assert(strcmp(node1->data_, "B") == 0);
	mt_assert(strcmp(node2->data_, "C") == 0);
	mt_assert(strcmp(node3->data_, "D") == 0);
	mt_assert(twl_lst_len(node0->edges_) == 0);
	mt_assert(twl_lst_len(node1->edges_) == 0);
	mt_assert(twl_lst_len(node2->edges_) == 0);
	mt_assert(twl_lst_len(node3->edges_) == 0);
	mt_assert(!node0->is_visited_);
	mt_assert(!node1->is_visited_);
	mt_assert(!node2->is_visited_);
	mt_assert(!node3->is_visited_);
}

static void simple_test_set_id(t_test *test)
{
	mt_assert(twl_graph_node_new(42, "A")->id_ == 42);
}

void	suite_twl_graph_node_new(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, simple_test_set_id);
}
