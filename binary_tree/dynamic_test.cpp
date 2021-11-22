#include "RBTree.hpp"
#include <iostream>
#include <cstdlib>
#include <csignal>

#define TRUE 1
#define FALSE 0

#define NB_MAX 99
#define NB_MIN 0

bool str_is_number(std::string str)
{
	std::string::iterator it_begin = str.begin();

	while (it_begin != str.end())
	{
		std::cerr << it_begin[0] << std::endl;
		if (it_begin[0] > '9' || it_begin[0] < '0')
			return (FALSE);
		it_begin++;
	}
	return (TRUE);

}

int main()
{
	Node<int> *tree = NULL;
	std::string command;
	int nb;
	while (true)
	{
		std::cout << "ENTER COMMAND A(DD), D(ELETE), E(XIT)" << std::endl;
		std::getline(std::cin, command);
		if (command == "A")
		{
			std::cout << "ENTER NUMBER BETWEEN 0 AND 100" << std::endl;
			std::getline(std::cin, command);
			if (str_is_number(command))
			{
				nb = atoi(command.c_str());
				if (nb >= NB_MIN && nb <= NB_MAX)
				{
					std::cerr << "nb" << std::endl;
					tree = insert_new_node(tree, nb);
				}
				else 
				{
					std::cout << "BAD VALUE" << std::endl;
				}
			}
			else
			{
				std::cout << "BAD INPUT" << std::endl;
			}
		}
		else if (command == "D")
		{
			std::cout << "not implemented" << std::endl;
		}

		else if (command == "E")
		{
			std::cout << "Exit" << std::endl;
			break;
		}
		system("clear");
		print_tree(tree);
	}
}