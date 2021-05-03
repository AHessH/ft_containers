#include "../includes/Vector.hpp"
#include <iostream>
#include <vector>
#include <string>
// void stuff(const ft::vector<std::string>& myvector )
// {
//     ft::vector<std::string>::const_iterator it = myvector.begin(); //const version will be called
// 	std::cout << *it << std::endl;

// }
// int		main(void){

// 	ft::vector<std::string> vec;
// 	vec.push_back("hello");
// 	vec.push_back("eduard");
// 	vec.push_back("hello11");
// 	vec.push_back("hello20");

// 	std::cout << "hi" << std::endl;

// 	// stuff( vec );
// 	ft::vector<std::string>::reverse_iterator it1 = vec.rbegin();
// 	ft::vector<std::string>::reverse_iterator it2 = it1 - 1;
// 	// it2++;
	
// 	for (ft::vector<std::string>::reverse_iterator it1 = vec.rbegin(); it1 != vec.rend(); it1++)
// 		std::cout << *it1 << std::endl;
// 	return (0);
// }

int	main(void){

	// ft::vector<char> cp;
	// cp.push_back('d');
	// cp.push_back('f');
	ft::vector<char> ch1;
	ch1.push_back('a');
	ch1.push_back('b');
	ch1.push_back('c');
	ch1.push_back('d');
	ch1.push_back('f');

	ft::vector<char> ch;
	ch.push_back('a');
	ch.push_back('b');
	ch.push_back('c');
	ch.push_back('d');
	ch.push_back('f');

	ft::vector<char>::iterator it = ch.begin();
	//it -= 3;
	ch.erase(ch.begin(), it);

	for (ft::vector<char>::iterator it = ch.begin(); it < ch.end(); it++){
		std::cout << "|" << *it << "|" << " ";
	}
	std::cout << std::endl;
	std::cout << ch.size() << ch.back() << std::endl;
}