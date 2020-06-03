#include <iostream>
#include  "graph.h"
#include "binary_heap.h"
#include "priority_queue.h"


void graph_interface(int root)
{
	Graph<int> graph(root);
	
	int choice = 0;
	int key = 0;
	while (true) {
		
		printf("%s",
			"1. Add element.\n"
			"2. Erase element.\n"
			"3. Exist element.\n"
			"4. Show minimum.\n"
			"5. Show maximum.\n"
			"6. Show graph.\n"
			"7. exit\n");
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			if (!(std::cin >> key)) { std::cout << "\nINCORRECT INPUT!\n";  exit(1); }

			graph.add(key);
			break;
			
		case 2:
			if (!(std::cin >> key)) { std::cout << "\nINCORRECT INPUT!\n";  exit(1); }

			graph.erase(key);
			break;

		case 3:
			if (!(std::cin >> key)) { std::cout << "\nINCORRECT INPUT!\n";  exit(1); }

			std::cout << graph.exist(key);
			break;
		case 4:
			std::cout << graph.minimum();
			break;

		case 5:
			std::cout << graph.maximum();
			break;
			
		case 6:
			graph.dfs();
			break;

		case 7:
			std::cout << "Time to say goodbye.";
			exit(1);
			
		default:
			std::cout << "wrong :'|";
		}
		std::cout << "\n";
	}
}

void bheap_interface(int root)

{
	Binary_heap<int> bheap(root);

	int choice = 0;
	int key = 0;
	int old_key = 0, new_key = 0;
	while (true) {

		printf("%s",
			"1. Add element.\n"
			"2. Extract minimum.\n"
			"3. Exist element.\n"
			"4. Change key.\n"
			"5. Show minimum.\n"
			"6. Show binary heap.\n"
			"7. exit\n");
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			if (!(std::cin >> key)) { std::cout << "\nINCORRECT INPUT!\n";  exit(1); }

			bheap.add(key);
			break;

		case 2:
			std::cout << bheap.extract_min();
			break;

		case 3:
			if (!(std::cin >> key)) { std::cout << "\nINCORRECT INPUT!\n";  exit(1); }

			std::cout << bheap.exist(key);
			break;
			
		case 4:
			std::cout << "\nOLD KEY: ";
			
			if (!(std::cin >> old_key)) { std::cout << "\nINCORRECT INPUT!\n";  exit(1); }

			std::cout << "\nNEW KEY: ";
			if (!(std::cin >> new_key)) { std::cout << "\nINCORRECT INPUT!\n";  exit(1); }

			bheap.change_key(old_key, new_key);
			break;

		case 5:
			std::cout << bheap.get_min();
			break;

		case 6:
			bheap.show();
			break;

		case 7:
			std::cout << "Time to say goodbye.";
			exit(1);

		default:
			std::cout << "wrong!";
		}
		std::cout << "\n";
	}
}

void pqueue_interface(int first_key, int first_value)

{
	Priority_queue<int> pqueue(first_key, first_value);

	int choice = 0;
	int key = 0, value = 0;
	while (true) {

		printf("%s",
			"1. Add element.\n"
			"2. Extract element.\n"
			"3. Exist element.\n"
			"4. exit\n");
		
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			std::cout << "\nInput key and then value: \n";
			if (!(std::cin >> key)) { std::cout << "\nINCORRECT INPUT!\n";  exit(1); }
			if (!(std::cin >> value)) { std::cout << "\nINCORRECT INPUT!\n";  exit(1); }

			pqueue.add(key, value);
			break;

		case 2:
			std::cout << pqueue.extract();
			break;

		case 3:
			std::cout << "\nInput key and then value: \n";
			
			if (!(std::cin >> key)) { std::cout << "\nINCORRECT INPUT!\n";  exit(1); }
			if (!(std::cin >> value)) { std::cout << "\nINCORRECT INPUT!\n";  exit(1); }
			
			std::cout << pqueue.exist(key, value);
			break;

		case 4:
			std::cout << "Time to say goodbye.";
			exit(1);

		default:
			std::cout << "wrong!";
		}
		std::cout << "\n";
	}
}

int main()
{

	int choice = 0;
	int key = 0, value = 0;
	std::cout << "Graph is 1.\nBinary heap is 2.\nPriority queue is 3.\n";
	std::cout << "Choose type of data structure: ";
	std::cin >> choice;
	std::cout << "\nInput first element of structure: \n";
	std::cout << "Input key: \n";
	if (!(std::cin >> key)) { std::cout << "\nINCORRECT INPUT!\n";  exit(1); }

	
	switch (choice)
	{
	case 1:
		graph_interface(key);
		break;
		
	case 2:
		bheap_interface(key);
		break;
		
	case 3:
		std::cout << "Input value: \n";
		
		if (!(std::cin >> value)) { std::cout << "\nINCORRECT INPUT!\n";  exit(1); }

		pqueue_interface(key, value);
		break;
		
	default:
		std::cout << "Bye.";
	}
	
	return 0;
}