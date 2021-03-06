#include "RBTree.hpp"
#include <iostream>
#include <cstdlib>
#include <csignal>
#include "print_tree.hpp"
#include "functions.hpp"

#define TRUE 1
#define FALSE 0

#define NB_MAX 250
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
	Tree<int, std::string> RB_tree;
	Node<int, std::string> * head = NULL;
	std::string command;
	int nb;
	while (true)
	{
		std::cout << "ENTER COMMAND A(DD), D(ELETE), E(XIT) FOLLOWED BY NUMBER (0 <= NB <= 99)" << std::endl;
		std::getline(std::cin, command);
		if (command.size() <= 0){
			std::cin.get();
			std::cin.clear();
			break;
			fflush(stdin);
			}                                        
		else if (command[0] == 'A')
		{
			if (str_is_number(&command[1]))
			{
				nb = atoi(&command[1]);
				if (nb >= NB_MIN && nb <= NB_MAX)
				{
					head = RB_tree.insert_new_node(nb, "NULL");
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
		else if (command[0] == 'D')
		{
			if (str_is_number(&command[1]))
			{
				nb = atoi(&command[1]);
				if (nb >= NB_MIN && nb <= NB_MAX)
				{
					RB_tree.delete_node(RB_tree.find_node(nb));;
						
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

		else if (command == "E")
		{
			std::cout << "Exit" << std::endl;
			break;
		}
		print_tree(RB_tree.getRoot());
	}
}