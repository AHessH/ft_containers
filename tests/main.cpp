#include "Vector.hpp"
#include <iostream>
#include <vector>
#include <string>

int		main(void){
	std::string hello = "helloo";
	std::string hello1 = "hello1";
	std::string hello2 = "helloo2";
	std::string hello3 = "helloo3";
	std::string hello4 = "helloo4";

	std::cout << "size " << sizeof(hello1) << std::endl;
	ft::vector<std::string> vec;
	std::vector<std::string> vec1;
	vec.push_back(hello);
	vec.push_back(hello1);
	// vec.push_back("helloo2");
	// vec.push_back("helloo3");
	// vec.push_back("helloo4");

	ft::vector<std::string>::iterator it1 = vec.begin();
	ft::vector<std::string>::iterator it2 = it1 + 1;
	std::cout << it2->size() << std::endl;
	return (0);
}