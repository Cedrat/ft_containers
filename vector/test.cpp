#include "vector.hpp"
#include <vector>
#include <iostream>
#include <chrono>
#include <iostream>
#include <sys/time.h>
#include <ctime>
#include <poll.h>
#include <list>
#include <string>


int main()
{

std::cout << "\nINSERT\n";
	ft::vector<std::string>	insert_in_me;
	for (size_t i = 0; i < 15; i++)
		insert_in_me.push_back("I love pomme\n");
	std::cout << "after push_back, before at\n";
	for (size_t i = 0; i < insert_in_me.size(); i++)
		std::cout << insert_in_me.at(i) << ' ';
	std::cout << '\n';

	ft::vector<std::string>::iterator	tmp;
	tmp = insert_in_me.begin() + 4;
	insert_in_me.insert(tmp, 8, "Norminet");
	for (size_t i = 0; i < insert_in_me.size(); i++)
		std::cout << insert_in_me.at(i) << ' ';
	std::cout << '\n';


	// std::cout << "\nINSERT RANGE\n";
	ft::vector<std::string>	insert_bis;
	for (size_t i = 0; i < 7; i++)
		insert_bis.push_back("oeoeoe");
	// for (size_t i = 0; i < insert_bis.size(); i++)
	// 	std::cout << insert_bis[i] << ' ';
	// std::cout << '\n';

	insert_bis.insert(insert_bis.begin() + 5, insert_in_me.begin(), insert_in_me.end());
	// for (size_t i = 0; i < insert_bis.size(); i++)
	// 	std::cout << insert_bis[i] << ' ';
	// std::cout << '\n';
	ft::vector<std::string>	insert_in_you;

	insert_in_you = insert_in_me;

  return 0;
}