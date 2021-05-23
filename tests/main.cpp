#include "../includes/Vector.hpp"
#include <iostream>
#include <vector>
#include <string>

template<typename T>
 bool compare_vec(ft::vector<T> &ft_vec, std::vector<T> &std_vec){
	if (ft_vec.size() != std_vec.size()){
		std::cerr << "\tError ft_vec.size != std_vec.size ft_vec.size() = |" << ft_vec.size() << "| std_vec.size() = |" << std_vec.size() << "|" << std::endl;
		return (false);
	}
	for (size_t i = 0; i < std_vec.size() && i < ft_vec.size(); i++)
		if (ft_vec[i] != std_vec[i]){
			std::cerr << "\tError ft_vec[i] != std_vec[i] i = |" << i << "| ft_vec[i] = " << ft_vec[i] << " std_vec[i] = |" << std_vec[i] << "|" << std::endl;
			return (false);
		}
	return (true);
}
template<typename T>
 void result_vec(const char *test_name, ft::vector<T> &ft_vec, std::vector<T> &std_vec){
	std::cout << test_name << ": ";
	if (compare_vec(ft_vec, std_vec)){
		std::cout << "\033[0;32;40mOK\033[0m";
	} else {
		std::cout << "\033[0;31;40mKO\033[0m";
	}
	std::cout << std::endl;
}

void	CheckVector(){


	ft::vector<int> ft_vec;
	std::vector<int> std_vec;

	{
		ft::vector<char> ft_vec;
		std::vector<char> std_vec;
		ft_vec.push_back('a');
		std_vec.push_back('a');
		result_vec("Push only 'a'", ft_vec, std_vec);
	}
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		for (int i = 0; i < 100000; i++){
			ft_vec.push_back(i);
			std_vec.push_back(i);
		}
		result_vec("Push 100000 ints", ft_vec, std_vec);
	}
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		for (int i = 0; i < 100000; i++){
			ft_vec.push_back(i);
			std_vec.push_back(i);
		}
		for (int i = 0; i < 10000; i++){
			ft_vec.pop_back();
			std_vec.pop_back();
		}
		result_vec("Push 100000 ints and pop 10000", ft_vec, std_vec);
	}
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		for (int i = 0; i < 3125; i ++){
			ft_vec.push_back(i);
			std_vec.push_back(i);
		}
		result_vec("Push 3125 ints check size", ft_vec, std_vec);
	}
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		std::cout << "Check max_size" << ": ";
		if (ft_vec.max_size() != 0){
			std::cout << "\033[0;32;40mOK\033[0m\n";
		} else {
			std::cout << "\033[0;31;40mKO\033[0m\n";
		}
	}
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		for (int i = 0; i < 12; i++){
			ft_vec.push_back(i);
			std_vec.push_back(i);
		}
		ft_vec.resize(100, 11);
		result_vec("Check resize with n > size", ft_vec, std_vec);
	}
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		for (int i = 0; i < 120; i++){
			ft_vec.push_back(i);
			std_vec.push_back(i);
		}
		ft_vec.resize(100, 11);
		result_vec("Check resize with n < size", ft_vec, std_vec);
	}
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		for (int i = 0; i < 120; i++){
			ft_vec.push_back(i);
			std_vec.push_back(i);
		}
		std::cout << "Check capacity" << ": ";
		if (ft_vec.capacity() != 0){
			std::cout << "\033[0;32;40mOK\033[0m\n";
		} else {
			std::cout << "\033[0;31;40mKO\033[0m\n";
		}
	}
		{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		for (int i = 0; i < 120; i++){
			ft_vec.push_back(i);
			std_vec.push_back(i);
		}
		std::cout << "Check empty() case 'false'" << ": ";
		if (ft_vec.empty() == ft_vec.empty()){
			std::cout << "\033[0;32;40mOK\033[0m\n";
		} else {
			std::cout << "\033[0;31;40mKO\033[0m\n";
		}
	}
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		std::cout << "Check empty() case 'true'" << ": ";

		if (ft_vec.empty() == ft_vec.empty()){
			std::cout << "\033[0;32;40mOK\033[0m\n";
		} else {
			std::cout << "\033[0;31;40mKO\033[0m\n";
		}
	}
	{
		ft::vector<int> ft_vec;
		uint capacity = 1200;
		for (int i = 0; i < 120; i++){
			ft_vec.push_back(i);
		}
		ft_vec.reserve(capacity);
		std::cout << "Check reserve() n > capacity()" << ": ";
		if (ft_vec.capacity() >= capacity){
			std::cout << "\033[0;32;40mOK\033[0m\n";
		} else {
			std::cout << "\033[0;31;40mKO\033[0m\n";
		}
	}
	{
		ft::vector<int> ft_vec;
		uint capacity = 2;
		for (int i = 0; i < 120; i++){
			ft_vec.push_back(i);
		}
		uint old_capacity = ft_vec.capacity();
		ft_vec.reserve(capacity);
		std::cout << "Check reserve() n < capacity()" << ": ";
		if (ft_vec.capacity() >= old_capacity){
			std::cout << "\033[0;32;40mOK\033[0m\n";
		} else {
			std::cout << "\033[0;31;40mKO\033[0m\n";
		}
	}
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		for (int i = 0; i < 120; i++){
			ft_vec.push_back(i);
			std_vec.push_back(i);
		}
		std::cout << "Check at() case1: ";
		if (ft_vec.at(19) == std_vec.at(19)){
			std::cout << "\033[0;32;40mOK\033[0m\n";
		} else {
			std::cout << "\033[0;31;40mKO\033[0m\n";
		}
	}
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		for (int i = 0; i < 120; i++){
			ft_vec.push_back(i);
			std_vec.push_back(i);
		}
		ft_vec.at(10) = 123124;
		std_vec.at(10) = 123124;
		std::cout << "Check at() case2: ";
		if (ft_vec.at(10) == std_vec.at(10)){
			std::cout << "\033[0;32;40mOK\033[0m\n";
		} else {
			std::cout << "\033[0;31;40mKO\033[0m\n";
		}
	}
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		for (int i = 34265; i < 34546; i++){
			ft_vec.push_back(i);
			std_vec.push_back(i);
		}
		std::cout << "Check front(): ";
		if (ft_vec.front() == std_vec.front()){
			std::cout << "\033[0;32;40mOK\033[0m\n";
		} else {
			std::cout << "\033[0;31;40mKO\033[0m\n";
		}
	}
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		for (int i = 34265; i < 34546; i++){
			ft_vec.push_back(i);
			std_vec.push_back(i);
		}
		std::cout << "Check back(): ";
		if (ft_vec.back() == std_vec.back()){
			std::cout << "\033[0;32;40mOK\033[0m\n";
		} else {
			std::cout << "\033[0;31;40mKO\033[0m\n";
		}
	}
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		for (int i = 34265; i < 34546; i++){
			std_vec.push_back(i);
		}
		ft_vec.assign(std_vec.begin(), std_vec.end());
		result_vec("Check assign() case1", ft_vec, std_vec);
	}
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		for (int i = 34265; i < 34546; i++){
			std_vec.push_back(123);
		}
		ft_vec.assign((unsigned int)34546 - 34265, 123);
		result_vec("Check assign() case2", ft_vec, std_vec);
	}
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		for (int i = 34265; i < 34546; i++){
			std_vec.push_back(i);
			ft_vec.push_back(i);
		}
		std::vector<int>::iterator std_it = std_vec.begin();
		ft::vector<int>::iterator ft_it = ft_vec.begin();
		std_it += 102;
		ft_it += 102;
		std_vec.insert(std_it, 12352345);
		ft_vec.insert(ft_it, 12352345);
		result_vec("Check insert1() case1", ft_vec, std_vec);
		ft_it++;
		std_it++;
	}
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		for (int i = 34265; i < 34546; i++){
			std_vec.push_back(i);
			ft_vec.push_back(i);
		}
		std::vector<int>::iterator std_it = std_vec.begin();
		ft::vector<int>::iterator ft_it = ft_vec.begin();
		std_vec.insert(std_it, 12352345);
		ft_vec.insert(ft_it, 12352345);
		result_vec("Check insert1() case2", ft_vec, std_vec);
	}
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		for (int i = 34265; i < 34546; i++){
			std_vec.push_back(i);
			ft_vec.push_back(i);
		}
		std::vector<int>::iterator std_it = std_vec.end();
		ft::vector<int>::iterator ft_it = ft_vec.end();
		std_vec.insert(std_it, 12352345);
		ft_vec.insert(ft_it, 12352345);
		result_vec("Check insert1() case3", ft_vec, std_vec);
	}
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		for (int i = 0; i < 100; i++){
			std_vec.push_back(i);
			ft_vec.push_back(i);
		}
		std::vector<int>::iterator std_it = std_vec.begin();
		ft::vector<int>::iterator ft_it = ft_vec.begin();
		std_it += 6;
		ft_it += 6;
		std_vec.insert(std_it, 2, (char)10);
		ft_vec.insert(ft_it, 2, (char)10);
		result_vec("Check insert2() case1", ft_vec, std_vec);
	}
//	{
//		ft::vector<int> ft_vec;
//		std::vector<int> std_vec;
//		for (int i = 34265; i < 34546; i++){
//			std_vec.push_back(i);
//			ft_vec.push_back(i);
//		}
//		std::vector<int>::iterator std_it = std_vec.begin();
//		ft::vector<int>::iterator ft_it = ft_vec.begin();
//		std_it += 6;
//		ft_it += 6;
//		std_vec.insert(std_it, (unsigned int)std_vec.size() + 100, (int)1);
//		ft_vec.insert(ft_it, (unsigned int)ft_vec.size() + 100, (int)1);
//		result_vec("Check insert() case2 n > size", ft_vec, std_vec);
//	}
}

int	main(void){
	CheckVector();
	return (0);
}