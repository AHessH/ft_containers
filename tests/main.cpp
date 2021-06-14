#include "../includes/Vector.hpp"
#include "../includes/List.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <string>

#define PRINT_DOUBLE_TAB (std::cout << "\t\t");

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
 void result_vec(const char *test_name, ft::vector<T> &ft_vec, std::vector<T> &std_vec, bool &result){
	std::cout << test_name << ": ";
	if (compare_vec(ft_vec, std_vec)){
		std::cout << "\033[0;32;40mOK\033[0m";
	} else {
		std::cout << "\033[0;31;40mKO\033[0m";
		result = false;
	}
	std::cout << std::endl;
}

bool	CheckVector(){
	bool result = true;
	// Push back
	{
		{
			PRINT_DOUBLE_TAB;
			ft::vector<char> ft_vec;
			std::vector<char> std_vec;
			ft_vec.push_back('a');
			std_vec.push_back('a');
			result_vec("Push only 'a'", ft_vec, std_vec, result);
		}
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft_vec;
			std::vector<int> std_vec;
			for (int i = 0; i < 100000; i++){
				ft_vec.push_back(i);
				std_vec.push_back(i);
			}
			result_vec("Push 100000 ints", ft_vec, std_vec, result);
		}
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft_vec;
			std::vector<int> std_vec;
			for (int i = 0; i < 3125; i ++){
				ft_vec.push_back(i);
				std_vec.push_back(i);
			}
			result_vec("Push 3125 ints check size", ft_vec, std_vec, result);
		}
	}
	// Push and pop
	{
		PRINT_DOUBLE_TAB;
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
		result_vec("Push 100000 ints and pop 10000", ft_vec, std_vec, result);
	}
	// Max_size
	{
		PRINT_DOUBLE_TAB;
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		std::cout << "Check max_size" << ": ";
		if (ft_vec.max_size() != 0){
			std::cout << "\033[0;32;40mOK\033[0m\n";
		} else {
			std::cout << "\033[0;31;40mKO\033[0m\n";
			result = false;
		}
	}
	// Capacity
	{
		PRINT_DOUBLE_TAB;
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
			result = false;
		}
	}
	// Empty
	{
		{
			PRINT_DOUBLE_TAB;
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
				result = false;
			}
		}
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft_vec;
			std::vector<int> std_vec;
			std::cout << "Check empty() case 'true'" << ": ";

			if (ft_vec.empty() == ft_vec.empty()){
				std::cout << "\033[0;32;40mOK\033[0m\n";
			} else {
				std::cout << "\033[0;31;40mKO\033[0m\n";
				result = false;
			}
		}
	}
	// Reserve
	{
		{
			PRINT_DOUBLE_TAB;
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
				result = false;
			}
		}
		{
			PRINT_DOUBLE_TAB;
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
				result = false;
			}
		}
	}
	// At
	{
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft_vec;
			std::vector<int> std_vec;
			for (int i = 0; i < 120; i++){
				ft_vec.push_back(i);
				std_vec.push_back(i);
			}
			std::cout << "Check at() case 1: ";
			if (ft_vec.at(19) == std_vec.at(19)){
				std::cout << "\033[0;32;40mOK\033[0m\n";
			} else {
				std::cout << "\033[0;31;40mKO\033[0m\n";
				result = false;
			}
		}
		{
			PRINT_DOUBLE_TAB;
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
				result = false;
			}
		}
	}
	// Front
	{
		PRINT_DOUBLE_TAB;
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
			result = false;
		}
	}
	// Back
	{
		PRINT_DOUBLE_TAB;
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
			result = false;
		}
	}
	// Begin
	{
		PRINT_DOUBLE_TAB;
		ft::vector<int> ft_vec;
		int i = 546523;
		ft_vec.push_back(i);
		std::cout << "Check begin(): ";
		if (*(ft_vec.begin()) == i){
			std::cout << "\033[0;32;40mOK\033[0m\n";
		} else {
			std::cout << "\033[0;31;40mKO\033[0m\n";
			result = false;
		}
	}
	// End
	{
		PRINT_DOUBLE_TAB;
		ft::vector<int> ft_vec;
		int i = 546523;
		ft_vec.push_back(i);
		std::cout << "Check end(): ";
		if (*(ft_vec.end() - 1) == i){
			std::cout << "\033[0;32;40mOK\033[0m\n";
		} else {
			std::cout << "\033[0;31;40mKO\033[0m\n";
			result = false;
		}
	}
	// RBegin
	{
		PRINT_DOUBLE_TAB;
		ft::vector<int> ft_vec;
		int i = 546523;
		ft_vec.push_back(i);
		std::cout << "Check rbegin(): ";
		if (*(ft_vec.rbegin()) == i){
			std::cout << "\033[0;32;40mOK\033[0m\n";
		} else {
			std::cout << "\033[0;31;40mKO\033[0m\n";
			result = false;
		}
	}
	// REnd
	{
		PRINT_DOUBLE_TAB;
		ft::vector<int> ft_vec;
		int i = 546523;
		ft_vec.push_back(i);
		std::cout << "Check rend(): ";
		if (*(ft_vec.rend() - 1) == i){
			std::cout << "\033[0;32;40mOK\033[0m\n";
		} else {
			std::cout << *(ft_vec.rend() - 1) << std::endl;
			std::cout << "\033[0;31;40mKO\033[0m\n";
			result = false;
		}
	}
	// Assign
	{	
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft_vec;
			std::vector<int> std_vec;
			for (int i = 34265; i < 34546; i++){
				std_vec.push_back(i);
			}
			ft_vec.assign(std_vec.begin(), std_vec.end());
			result_vec("Check assign() case1", ft_vec, std_vec, result);
		}
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft_vec;
			std::vector<int> std_vec;
			for (int i = 34265; i < 34546; i++){
				std_vec.push_back(123);
			}
			ft_vec.assign((unsigned int)34546 - 34265, 123);
			result_vec("Check assign() case2", ft_vec, std_vec, result);
		}
	}
	// Insert
	{
		{
			PRINT_DOUBLE_TAB;
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
			result_vec("Check insert1() case1", ft_vec, std_vec, result);
			ft_it++;
			std_it++;
		}
		{
			PRINT_DOUBLE_TAB;
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
			result_vec("Check insert1() case2", ft_vec, std_vec, result);
		}
		{
			PRINT_DOUBLE_TAB;
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
			result_vec("Check insert1() case3", ft_vec, std_vec, result);
		}
		{
			PRINT_DOUBLE_TAB;
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
			result_vec("Check insert2() case1 n < size", ft_vec, std_vec, result);
		}
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft_vec;
			std::vector<int> std_vec;
			for (int i = 34265; i < 34546; i++){
				std_vec.push_back(i);
				ft_vec.push_back(i);
			}
			std::vector<int>::iterator std_it = std_vec.begin();
			ft::vector<int>::iterator ft_it = ft_vec.begin();
			std_it += 6;
			ft_it += 6;
			std_vec.insert(std_it, (unsigned int)std_vec.size() + 100, (int)1);
			ft_vec.insert(ft_it, (unsigned int)ft_vec.size() + 100, (int)1);
			result_vec("Check insert2() case2 n > size", ft_vec, std_vec, result);
		}
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft_vec;
			std::vector<int> std_vec;
			for (int i = 0; i < 100; i++){
				std_vec.push_back(i);
				ft_vec.push_back(i);
			}
			std::vector<int>::iterator std_it = std_vec.begin();
			ft::vector<int>::iterator ft_it = ft_vec.begin();
			std_vec.insert(std_it, 2, (char)10);
			ft_vec.insert(ft_it, 2, (char)10);
			result_vec("Check insert2() case3 n < size", ft_vec, std_vec, result);
		}
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft_vec;
			std::vector<int> std_vec;
			for (int i = 34265; i < 34546; i++){
				std_vec.push_back(i);
				ft_vec.push_back(i);
			}
			std::vector<int>::iterator std_it = std_vec.begin();
			ft::vector<int>::iterator ft_it = ft_vec.begin();
			std_vec.insert(std_it, (unsigned int)std_vec.size() + 100, (int)1);
			ft_vec.insert(ft_it, (unsigned int)ft_vec.size() + 100, (int)1);
			result_vec("Check insert2() case4 n > size", ft_vec, std_vec, result);
		}
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft_vec;
			std::vector<int> std_vec;
			for (int i = 0; i < 100; i++){
				std_vec.push_back(i);
				ft_vec.push_back(i);
			}
			std::vector<int>::iterator std_it = std_vec.end();
			ft::vector<int>::iterator ft_it = ft_vec.end();
			std_vec.insert(std_it, 2, (char)10);
			ft_vec.insert(ft_it, 2, (char)10);
			result_vec("Check insert2() case5 n < size", ft_vec, std_vec, result);
		}
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft_vec;
			std::vector<int> std_vec;
			for (int i = 34265; i < 34546; i++){
				std_vec.push_back(i);
				ft_vec.push_back(i);
			}
			std::vector<int>::iterator std_it = std_vec.end();
			ft::vector<int>::iterator ft_it = ft_vec.end();
			std_vec.insert(std_it, (unsigned int)std_vec.size() + 100, (int)1);
			ft_vec.insert(ft_it, (unsigned int)ft_vec.size() + 100, (int)1);
			result_vec("Check insert2() case6 n > size", ft_vec, std_vec, result);
		}
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft_vec;
			std::vector<int> std_vec;
			ft::vector<int> ft_vec_new;
			std::vector<int> std_vec_new;

			for (int i = 34265; i < 34546; i++){
				std_vec.push_back(i);
				ft_vec.push_back(i);
			}
			for (int i = 1; i < 100; i++) {
				std_vec_new.push_back(i);
				ft_vec_new.push_back(i);
			}
			std::vector<int>::iterator std_it = std_vec.begin();
			ft::vector<int>::iterator ft_it = ft_vec.begin();
			std_it += 6;
			ft_it += 6;
			std_vec.insert(std_it, std_vec_new.begin(), std_vec_new.end());
			ft_vec.insert(ft_it, ft_vec_new.begin(), ft_vec_new.end());
			result_vec("Check insert3() case1 n < size", ft_vec, std_vec, result);
		}
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft_vec;
			std::vector<int> std_vec;
			ft::vector<int> ft_vec_new;
			std::vector<int> std_vec_new;

			for (int i = 34265; i < 34546; i++){
				std_vec.push_back(i);
				ft_vec.push_back(i);
			}
			for (int i = 1; i < 1000; i++) {
				std_vec_new.push_back(i);
				ft_vec_new.push_back(i);
			}
			std::vector<int>::iterator std_it = std_vec.begin();
			ft::vector<int>::iterator ft_it = ft_vec.begin();
			std_it += 6;
			ft_it += 6;
			std_vec.insert(std_it, std_vec_new.begin(), std_vec_new.end());
			ft_vec.insert(ft_it, ft_vec_new.begin(), ft_vec_new.end());
			result_vec("Check insert3() case2 n > size", ft_vec, std_vec, result);
		}
	}
	// Size
	{
		PRINT_DOUBLE_TAB;
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		for (int i = 0; i < 6542; i ++){
			ft_vec.push_back(i);
			std_vec.push_back(i);
		}
		result_vec("Check size()", ft_vec, std_vec, result);
	}
	// Clear
	{
		PRINT_DOUBLE_TAB;
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		for (int i = 0; i < 6542; i ++){
			ft_vec.push_back(i);
			std_vec.push_back(i);
		}
		ft_vec.clear();
		std_vec.clear();
		result_vec("Check clear()", ft_vec, std_vec, result);
	}
	// Erase
	{
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft_vec;
			std::vector<int> std_vec;
			for (int i = 0; i < 6542; i ++){
				ft_vec.push_back(i);
				std_vec.push_back(i);
			}
			ft_vec.erase((ft_vec.begin() + 233));
			std_vec.erase((std_vec.begin() + 233));
			result_vec("Check erase1()", ft_vec, std_vec, result);
		}
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft_vec;
			std::vector<int> std_vec;
			for (int i = 0; i < 6542; i ++){
				ft_vec.push_back(i);
				std_vec.push_back(i);
			}
			ft_vec.erase((ft_vec.begin() + 233), (ft_vec.begin() + 233));
			std_vec.erase((std_vec.begin() + 233), (std_vec.begin() + 233));
			result_vec("Check erase2() case1", ft_vec, std_vec, result);
		}
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft_vec;
			std::vector<int> std_vec;
			for (int i = 0; i < 6542; i ++){
				ft_vec.push_back(i);
				std_vec.push_back(i);
			}
			ft_vec.erase((ft_vec.begin() + 233), (ft_vec.begin() + 1235));
			std_vec.erase((std_vec.begin() + 233), (std_vec.begin() + 1235));
			result_vec("Check erase2() case2", ft_vec, std_vec, result);
		}
	}
	// Resize
	{
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft_vec;
			std::vector<int> std_vec;
			for (int i = 0; i < 12; i++){
				ft_vec.push_back(i);
				std_vec.push_back(i);
			}
			ft_vec.resize(100, 11);
			std_vec.resize(100, 11);
			result_vec("Check resize with n > size", ft_vec, std_vec, result);
		}
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft_vec;
			std::vector<int> std_vec;
			for (int i = 0; i < 120; i++){
				ft_vec.push_back(i);
				std_vec.push_back(i);
			}
			ft_vec.resize(100, 11);
			std_vec.resize(100, 11);
			result_vec("Check resize with n < size", ft_vec, std_vec, result);
		}
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft_vec;
			std::vector<int> std_vec;
			for (int i = 0; i < 120; i++){
				ft_vec.push_back(i);
				std_vec.push_back(i);
			}
			ft_vec.resize(100);
			std_vec.resize(100);
			result_vec("Check resize with n < size", ft_vec, std_vec, result);
		}
	}
	// Swap
	{
		PRINT_DOUBLE_TAB;
		ft::vector<int> ft1_vec;
		std::vector<int> std1_vec;
		ft::vector<int> ft2_vec;
		std::vector<int> std2_vec;
		for (int i = 0; i < 6542; i ++){
			ft1_vec.push_back(i);
			std1_vec.push_back(i);
			ft2_vec.push_back(i + 10000);
			std2_vec.push_back(i + 10000);
		}
		ft1_vec.swap(ft2_vec);
		std1_vec.swap(std2_vec);
		result_vec("Check swap() 1st vector", ft1_vec, std1_vec, result);
		PRINT_DOUBLE_TAB;
		result_vec("Check swap() 2nd vector", ft2_vec, std2_vec, result);
	}
	// == 
	{
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft1_vec;
			ft::vector<int> ft2_vec;
			for (int i = 0; i < 6542; i ++){
				ft1_vec.push_back(i);
				ft2_vec.push_back(i + 10000);
			}
			std::cout << "Check ==() case1: ";
			if (ft1_vec == ft2_vec) {
				std::cout << "\033[0;31;40mKO\033[0m\n";
				result = false;
			} else {
				std::cout << "\033[0;32;40mOK\033[0m\n";
			}
		}
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft1_vec;
			ft::vector<int> ft2_vec;
			for (int i = 0; i < 6542; i ++){
				ft1_vec.push_back(i);
				ft2_vec.push_back(i);
			}
			std::cout << "Check ==() case2: ";
			if (ft1_vec == ft2_vec) {
				std::cout << "\033[0;32;40mOK\033[0m\n";
			} else {
				std::cout << "\033[0;31;40mKO\033[0m\n";
				result = false;
			}
		}
	}
	// != 
	{
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft1_vec;
			ft::vector<int> ft2_vec;
			for (int i = 0; i < 6542; i ++){
				ft1_vec.push_back(i);
				ft2_vec.push_back(i + 10000);
			}
			std::cout << "Check !=() case1: ";
			if (ft1_vec != ft2_vec) {
				std::cout << "\033[0;32;40mOK\033[0m\n";
			} else {
				std::cout << "\033[0;31;40mKO\033[0m\n";
				result = false;
			}
		}
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft1_vec;
			ft::vector<int> ft2_vec;
			for (int i = 0; i < 6542; i ++){
				ft1_vec.push_back(i);
				ft2_vec.push_back(i);
			}
			std::cout << "Check !=() case2: ";
			if (ft1_vec != ft2_vec) {
				std::cout << "\033[0;31;40mKO\033[0m\n";
				result = false;
			} else {
				std::cout << "\033[0;32;40mOK\033[0m\n";
			}
		}
	}
	// > 
	{
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft1_vec;
			ft::vector<int> ft2_vec;
			for (int i = 0; i < 6542; i ++){
				ft1_vec.push_back(i);
				ft2_vec.push_back(i + 10000);
			}
			std::cout << "Check >() case1: ";
			if (ft2_vec > ft1_vec) {
				std::cout << "\033[0;32;40mOK\033[0m\n";
			} else {
				std::cout << "\033[0;31;40mKO\033[0m\n";
				result = false;
			}
		}
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft1_vec;
			ft::vector<int> ft2_vec;
			for (int i = 0; i < 6542; i ++){
				ft1_vec.push_back(i);
				ft2_vec.push_back(i);
			}
			std::cout << "Check >() case2: ";
			if (ft1_vec > ft2_vec) {
				std::cout << "\033[0;31;40mKO\033[0m\n";
				result = false;
			} else {
				std::cout << "\033[0;32;40mOK\033[0m\n";
			}
		}
	}
	// < 
	{
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft1_vec;
			ft::vector<int> ft2_vec;
			for (int i = 0; i < 6542; i ++){
				ft1_vec.push_back(i);
				ft2_vec.push_back(i + 10000);
			}
			std::cout << "Check <() case1: ";
			if (ft1_vec < ft2_vec) {
				std::cout << "\033[0;32;40mOK\033[0m\n";
			} else {
				std::cout << "\033[0;31;40mKO\033[0m\n";
				result = false;
			}
		}
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft1_vec;
			ft::vector<int> ft2_vec;
			for (int i = 0; i < 6542; i ++){
				ft1_vec.push_back(i);
				ft2_vec.push_back(i);
			}
			std::cout << "Check <() case2: ";
			if (ft1_vec < ft2_vec) {
				std::cout << "\033[0;31;40mKO\033[0m\n";
				result = false;
			} else {
				std::cout << "\033[0;32;40mOK\033[0m\n";
			}
		}
	}
	// >=
	{
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft1_vec;
			ft::vector<int> ft2_vec;
			for (int i = 0; i < 6542; i ++){
				ft1_vec.push_back(i);
				ft2_vec.push_back(i + 10000);
			}
			std::cout << "Check >=() case1: ";
			if (ft2_vec >= ft1_vec) {
				std::cout << "\033[0;32;40mOK\033[0m\n";
			} else {
				std::cout << "\033[0;31;40mKO\033[0m\n";
				result = false;
			}
		}
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft1_vec;
			ft::vector<int> ft2_vec;
			for (int i = 0; i < 6542; i ++){
				ft1_vec.push_back(i);
				ft2_vec.push_back(i);
			}
			std::cout << "Check >=() case2: ";
			if (ft1_vec >= ft2_vec) {
				std::cout << "\033[0;32;40mOK\033[0m\n";
			} else {
				std::cout << "\033[0;31;40mKO\033[0m\n";
				result = false;
			}
		}
	}
	// <= 
	{
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft1_vec;
			ft::vector<int> ft2_vec;
			for (int i = 0; i < 6542; i ++){
				ft1_vec.push_back(i);
				ft2_vec.push_back(i + 10000);
			}
			std::cout << "Check <=() case1: ";
			if (ft1_vec <= ft2_vec) {
				std::cout << "\033[0;32;40mOK\033[0m\n";
			} else {
				std::cout << "\033[0;31;40mKO\033[0m\n";
				result = false;
			}
		}
		{
			PRINT_DOUBLE_TAB;
			ft::vector<int> ft1_vec;
			ft::vector<int> ft2_vec;
			for (int i = 0; i < 6542; i ++){
				ft1_vec.push_back(i);
				ft2_vec.push_back(i);
			}
			std::cout << "Check <=() case2: ";
			if (ft1_vec <= ft2_vec) {
				std::cout << "\033[0;32;40mOK\033[0m\n";
			} else {
				std::cout << "\033[0;31;40mKO\033[0m\n";
				result = false;
			}
		}
	}
	return (result);
}

void	CheckList(){
	ft::list<int> tmp;
	ft::list<int> tmp2;

	// while (it2 != tmp.end()){
	// 	cout << *it2 << endl;
	// 	it2++;
	// }
	tmp.push_back(9);
	tmp.push_back(1445);
	tmp.push_back(2);
	tmp.push_back(7);
	tmp.push_back(2345);
	tmp.push_back(1445);
	tmp.push_back(645);
	tmp2.push_back(0);
	tmp2.push_back(0);
	tmp2.push_back(0);

	// tmp.push_back("12");
	// tmp.push_back("13");
	// tmp.push_back("14");
	// tmp.push_back("15");
	// tmp.push_back("16");
	// tmp.push_back("17");
	// tmp.push_back("18");

	// tmp.push_front("20");
	// ft::list<int>::iterator it = tmp.begin();
	// it++;
	// it++;
	// ft::list<int>::iterator it2 = tmp.end();
	tmp.splice(tmp.begin(),tmp2);
	// tmp.sort();
	// tmp.reverse();
	std::cout << "hi1" << std::endl;

	ft::list<int>::iterator it1 = tmp.begin();
	std::cout << "size = " << tmp.size() << std::endl;
	while (it1 != tmp.end()){
		std::cout << *it1 << std::endl;
		it1++;
	}
}

int	main(void){
	// CheckVector();
	CheckList();
	return (0);
}