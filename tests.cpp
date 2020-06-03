#include  <iostream>
#include  "graph.h"
#include  "binary_heap.h"
#include "priority_queue.h"

int main()
{

	bool* is_passed = new bool[18];

	for (int i = 0; i < 18; ++i) is_passed[i] = true;
	
	Graph<int>check_graph_1(100);
	Graph<int>check_graph_2(40);

	Binary_heap<int>check_bheap_1(100);
	Binary_heap<int>check_bheap_2(40);

	Priority_queue<int>check_pqueue_1(100, 100);
	Priority_queue<int>check_pqueue_2(40,40);

	const int test_array_1_size = 15;
	const int test_array_2_size = 3;
	
	int test_array_1[test_array_1_size] = { 50, 150, 25, 60, 125, 200, 10, 35, 5, 15, 28, 40, 30, 41, 32 };
	int test_array_2[test_array_2_size] = { 30, 41, 32 };
	
	int test_index_doesnt_exist_1_1 = 2;
	int test_index_doesnt_exist_1_2 = 10;

	int test_index_doesnt_exist_2_1 = 0;
	int test_index_doesnt_exist_2_2 = 2;


	int test_minimum_1 = 5;
	int test_minimum_2 = 30;

	int test_minimum_1_2 = 10;
	int test_minimum_2_2 = 32;

	int test_maximum_1 = 200;
	int test_maximum_2 = 41;

	for (auto i : test_array_1) check_graph_1.add(i);
	for (auto i : test_array_2) check_graph_2.add(i);

	for (auto i : test_array_1) check_bheap_1.add(i);
	for (auto i : test_array_2) check_bheap_2.add(i);

	for (int i = 0; i < test_array_1_size; ++i) check_pqueue_1.add(test_array_1[i], test_array_1[i]);
	for (int i = 0; i < test_array_2_size; ++i) check_pqueue_2.add(test_array_2[i], test_array_2[i]);

	for (auto i : test_array_1) if (check_graph_1.exist(i) != true) is_passed[0] = false;
	for (auto i : test_array_2) if (check_graph_2.exist(i) != true) is_passed[1] = false;

	for (auto i : test_array_1) if (check_bheap_1.exist(i) != true) is_passed[2] = false;
	for (auto i : test_array_2) if (check_bheap_2.exist(i) != true) is_passed[3] = false;

	if (check_graph_1.minimum() != test_minimum_1) is_passed[4] = false;
	if (check_graph_2.minimum() != test_minimum_2)  is_passed[5] = false;

	if (check_graph_1.maximum() != test_maximum_1) is_passed[6] = false;
	if (check_graph_2.maximum() != test_maximum_2)  is_passed[7] = false;

	if (check_bheap_1.get_min() != test_minimum_1) is_passed[8] = false;
	if (check_bheap_2.get_min() != test_minimum_2)  is_passed[9] = false;

	if (check_pqueue_1.extract() != test_minimum_1) is_passed[10] = false;
	if (check_pqueue_2.extract() != test_minimum_2)  is_passed[11] = false;

	if (check_pqueue_1.extract() != test_minimum_1_2) is_passed[12] = false;
	if (check_pqueue_2.extract() != test_minimum_2_2)  is_passed[13] = false;
	
	check_graph_1.erase(test_array_1[test_index_doesnt_exist_1_1]);
	if (check_graph_1.exist(test_array_1[test_index_doesnt_exist_1_1]) == true) is_passed[14] = false;

	check_graph_1.erase(test_array_1[test_index_doesnt_exist_1_2]);
	if (check_graph_1.exist(test_array_1[test_index_doesnt_exist_1_2]) == true) is_passed[15] = false;

	check_graph_2.erase(test_array_2[test_index_doesnt_exist_2_1]);
	if (check_graph_2.exist(test_array_2[test_index_doesnt_exist_2_1]) == true) is_passed[16] = false;

	check_graph_2.erase(test_array_2[test_index_doesnt_exist_2_2]);
	if (check_graph_2.exist(test_array_2[test_index_doesnt_exist_2_2]) == true) is_passed[17] = false;

	for (int i = 0; i < 18; ++i)
	{
		std::cout << "TEST #" << i +1;

		if (is_passed[i]) std::cout << " PASSED!";
		else std::cout << " FAILED!";

		std::cout << "\n";
	}

	return 0;
}