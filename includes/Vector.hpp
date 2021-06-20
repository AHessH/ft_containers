#pragma once
#include <iostream>
#include <cstring>

#include "Algorithm.hpp"

#ifndef __RESIZE_VALUE
# define __RESIZE_VALUE 128
#endif

namespace ft{

	template<class T>
	 class VectorIterator{
		public:
		 	typedef 	T 						value_type;
	    	typedef 	value_type* 			pointer;
	    	typedef 	value_type const* 		const_pointer;
	    	typedef 	value_type& 			reference;
	    	typedef 	value_type const& 		const_reference;
	    	typedef 	std::ptrdiff_t 			difference_type;

		private:
		 	pointer p;

		public:
			VectorIterator(): p(NULL) {};
		 	VectorIterator(pointer p): p(p) {};
			VectorIterator(const VectorIterator &obj): p(obj.p) {};
			~VectorIterator() {};

			VectorIterator &operator=(const VectorIterator &obj) {
				this->p = obj.p;
				return (*this);
			};
			
			reference operator*(){
				return (*(this->p));
			};
			VectorIterator& operator++() {
				(this->p)++;
				return (*this);
			};
			VectorIterator& operator++(int) {
				VectorIterator tmp = *this;
				++this->p;
				return (tmp);
			};
			VectorIterator& operator+=(unsigned int num) {
				(this->p) = this->p + num;
				return (*this);
			};
			VectorIterator operator+(unsigned int num) const {
				return ((VectorIterator(*this)) += num);
			};
			VectorIterator& operator--() {
				(this->p)--;
				return (*this);
			};
			VectorIterator& operator--(int) {
				ListIterator tmp = *this;
				--this->p;
				return (tmp);
			}
			VectorIterator& operator-=(unsigned int num) {
				(this->p) = this->p - num;
				return (*this);
			};
			VectorIterator& operator-(unsigned int num) const {
				return (VectorIterator(*this) -= num);
			};
			difference_type operator-(VectorIterator const &obj) const {
				return (this->p - obj.p);
			};
			pointer operator->(){
				return (this->p);
			};
			reference operator[](int num){
				return (*(this->p + num));
			};
			bool operator==(const VectorIterator& rhs) const {
				return (this->p == rhs.p);
			};
			bool operator!=(const VectorIterator& rhs) const {			
				return (!(*this == rhs));
			};
			bool operator>(const VectorIterator& rhs) const {
				return (this->p > rhs.p);
			};
			bool operator<(const VectorIterator& rhs) const {
				return (this->p < rhs.p);
			};
			bool operator>=(const VectorIterator& rhs) const {
				return (this->p >= rhs.p);
			};
			bool operator<=(const VectorIterator& rhs) const {
				return (this->p <= rhs.p);
			};
			
			operator VectorIterator<value_type const>() {return (this->p);};
	};
	template<class T>
	 class ReverseIterator{
		public:
		 	typedef 	T 						value_type;
	    	typedef 	value_type* 			pointer;
	    	typedef 	value_type const* 		const_pointer;
	    	typedef 	value_type& 			reference;
	    	typedef 	value_type const& 		const_reference;
	    	typedef 	std::ptrdiff_t 			difference_type;

		private:
		 	pointer p;

		public:
			ReverseIterator(): p(NULL) {};
		 	ReverseIterator(pointer p): p(p) {};
			ReverseIterator(const ReverseIterator &obj): p(obj.p) {};
			~ReverseIterator() {};

			ReverseIterator &operator=(const ReverseIterator &obj) {
				this->p = obj.p;
				return (*this);
			};
			
			reference operator*(){
				return (*(this->p));
			};
			ReverseIterator& operator++() {
				(this->p)--;
				return (*this);
			};
			ReverseIterator& operator++(int) {
				ListIterator tmp = *this;
				--this->p;
				return (tmp);
			};
			ReverseIterator& operator+=(unsigned int num) {
				(this->p) = this->p - num;
				return (*this);
			};
			ReverseIterator operator+(unsigned int num) const {
				return ((ReverseIterator(*this)) += num);
			};
			ReverseIterator& operator--() {
				(this->p)++;
				return (*this);
			};
			ReverseIterator& operator--(int) {
				ListIterator tmp = *this;
				++this->p;
				return (*tmp);
			}
			ReverseIterator& operator-=(unsigned int num) {
				(this->p) = this->p + num;
				return (*this);
			};		
			ReverseIterator& operator-(unsigned int num) const {
				return (ReverseIterator(*this) -= num);
			};
			pointer operator->(){
				return (this->p);
			};
			reference operator[](int num){
				return (*(this->p - num));
			};
			bool operator==(const ReverseIterator& rhs) const {
				return (this->p == rhs.p);
			};
			bool operator!=(const ReverseIterator& rhs) const {			
				return (!(*this == rhs));
			};
			bool operator>(const ReverseIterator& rhs) const {
				return (this->p < rhs.p);
			};
			bool operator<(const ReverseIterator& rhs) const {
				return (this->p > rhs.p);
			};
			bool operator>=(const ReverseIterator& rhs) const {
				return (this->p <= rhs.p);
			};
			bool operator<=(const ReverseIterator& rhs) const {
				return (this->p >= rhs.p);
			};
			
			operator ReverseIterator<value_type const>() {return (this->p);};
	};

	template<class T>
	 class vector{
		public:
			typedef		T 										value_type;//	Тип, представляющий тип данных, хранящихся в векторе.
			typedef		VectorIterator<value_type> 				iterator;//	Тип, предоставляющий итератор произвольного доступа, который может читать или изменять любой элемент в векторе.
			typedef		VectorIterator<value_type const> 		const_iterator;//	Тип, предоставляющий итератор произвольного доступа, который может считывать const элемент в векторе.
			typedef		ReverseIterator<value_type> 			reverse_iterator;//	Тип, предоставляющий итератор произвольного доступа, который может читать или изменять любой элемент в обратном векторе.
			typedef		ReverseIterator<value_type const> 		const_reverse_iterator;//	Тип, предоставляющий итератор произвольного доступа, который может читать любой const элемент в векторе.

			typedef		T* 										pointer;//	Тип, предоставляющий указатель на элемент в векторе.
			typedef		T& 										reference;//	Тип, предоставляющий ссылку на элемент, хранящийся в векторе.
			typedef		T const * 								const_pointer;//	Тип, предоставляющий указатель на const элемент в векторе.
			typedef		T const & 								const_reference;//	Тип, предоставляющий ссылку на const элемент, хранящийся в векторе. Он используется для чтения и выполнения const операций.
			typedef		std::ptrdiff_t 							difference_type;//	Тип, представляющий различие между адресами двух элементов в векторе.
			typedef		unsigned int 							size_type;//	Тип, считающий количество элементов в векторе.
		
		private:
			pointer					_data;
			size_type 				_size; //_data[_size] является последним элементом, для итератора
			size_type 				_capacity; // выделяется на 2 больше, 

			// Выделяет или освобождает память равную __RESIZE_VALUE объекта
			void		resize(){
				if (_size >= _capacity){
					_capacity += __RESIZE_VALUE;
					resize_internal(_capacity);
				} else if (_capacity != __RESIZE_VALUE && _size < _capacity - __RESIZE_VALUE) {
					_capacity -= __RESIZE_VALUE;
					resize_internal(_capacity);
				}
			};
			void		resize_internal(size_type capacity){
				pointer resized;

				resized = new value_type[sizeof(value_type) * (capacity + 2)];
				if (_data != NULL) {
					size_type old_size = _size;
					std::memcpy(resized, _data, (capacity + __RESIZE_VALUE) * sizeof(value_type));
					this->clear();
					_size = old_size;
					delete [] _data;
				}
				_data = resized;
				_capacity = capacity;
			};

		public:
			class out_of_range: public std::exception {
				virtual const char *what() const throw() {return ("Out of range!");};
			};

			vector():
			 _data(NULL), _size(0), _capacity(0){
			};

			vector(const size_type capacity):
			 _size(0), _capacity(capacity){
				resize_internal(_capacity);
			};

			vector(const vector &obj){
				*this = obj;
			};
			template <class InputIterator>
         	 vector (InputIterator first, InputIterator last){
				*this->assign(first, last);
			};

			~vector() {
				this->clear();
				if (this->_data)
					delete [] _data;
			};

			iterator insert(iterator pos, const_reference value){
				iterator it;
				size_type old_size = _size;

				if (_size + 1 > _capacity)
					this->reserve(_capacity + __RESIZE_VALUE);
				for (iterator it = this->end(); _size >= 0 && it != pos; ((_size != 0) ?_size-- : 0), it--){
					new(&this->_data[this->_size + 1]) value_type(_data[_size]);
				}
				new(&this->_data[this->_size + 1]) value_type(value);
				
				_size = old_size + 1;
				return (it);
			};

			void insert(iterator position, size_type n, const_reference val){
				iterator it;
				iterator tmp_position = position;
				size_type old_size = _size;
				size_type offset = position - this->begin();
				
				if (_size + n > _capacity)
					this->reserve(_capacity + __RESIZE_VALUE + (n / __RESIZE_VALUE));
				position = this->begin() + offset;
				for (iterator it = this->end(); _size >= 0 && it != position; ((_size != 0) ?_size-- : 0), it--){
					new(&this->_data[this->_size + n]) value_type(_data[_size]);
				}
				size_type i = 0;
				for (; i < n; i++)
					new(&this->_data[this->_size + 1 + i]) value_type(val);
				_size = old_size + i;
			};

			template <class InputIterator>
    		 void insert(iterator position, InputIterator first, InputIterator last){
				iterator it;
				iterator tmp_position = position;
				size_type old_size = _size;
				size_type offset = position - this->begin();

				if (_size + (last - first) > _capacity)
					this->reserve(_capacity + __RESIZE_VALUE + ((last - first) / __RESIZE_VALUE));
				position = this->begin() + offset;
				for (iterator it = this->end(); _size >= 0 && it != position; ((_size != 0) ?_size-- : 0), it--){
					new(&this->_data[this->_size + (last - first)]) value_type(_data[_size]);
				}
				size_type i = 0;
				for (; first < last; first++, i++)
					new(&this->_data[this->_size + 1 + i]) value_type(*first);
				_size = old_size + i;
			};

			iterator erase(iterator position){
				iterator it;
				size_type old_size = _size;

				size_type i = 1;
				for (iterator it = this->begin(); i <= _size; it++, i++){
					if (it >= position)
						new(&this->_data[i]) value_type(_data[i + 1]);
				}
				_size = old_size - 1;
				return (it);
			};
			
			iterator erase(iterator first, iterator last){
				iterator it;
				size_type old_size = _size;

				size_type i = 1;
				for (iterator it = this->begin(); i <= _size; it++, i++){
					if (it < last)
						continue ;
					new(&this->_data[i - (last - first)]) value_type(_data[i]);
				}
				_size = old_size - (last - first);
				return (it);
			};

			void assign(size_type count, const_reference value){
				if (count >= _capacity)
					resize_internal(count + _capacity + 2);
				for (size_type i = 1; i <= count; i++)
					_data[i] = value;
				_size = count;
			};
			template <class InputIterator>
			 void assign(InputIterator first, InputIterator last) {
				size_t l = last - first;
				if (l > _capacity)
					resize_internal(l + _capacity + 2);
				for (size_type i = 1; first != last; first++, i++){
					_data[i] = *first;
				}
				_size = l;
			};

			iterator begin() {
				return (iterator(&(_data[1])));
			};

			const_iterator begin() const {
				return (const_iterator(&(_data[1])));
			};

			reverse_iterator rbegin() {
				return (reverse_iterator(&(_data[_size])));

			};

			const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(&(_data[_size])));

			};

			reverse_iterator rend() {
				return (reverse_iterator(&(_data[0])));

			};

			const_reverse_iterator rend() const {
				return (const_reverse_iterator(&(_data[0])));

			};
			
			iterator end() {
				return (iterator(&(_data[_size + 1])));
			};

			const_iterator end() const {
				return (const_iterator(&(_data[_size + 1])));
			};

			void swap(vector& other){
				ft::swap(other._data, this->_data);
				ft::swap(other._size, this->_size);
				ft::swap(other._capacity, this->_capacity);
			}
			
			void clear(){
				for (size_type i = 0; i < this->_size; i++)
					this->_data[i].~value_type();
				_size = 0;
			}

			reference at(size_type pos){
				if (pos >= _size)
					throw out_of_range();
				return (_data[pos + 1]);
			};

			const_reference at(size_type pos) const{
				if (pos >= _size)
					throw out_of_range();
				return (_data[pos + 1]);
			};

			reference front(){
				return (_data[1]);
			};

			const_reference front() const{
				return (_data[1]);
			};

			reference back(){
				return (_data[_size]);
			}

			const_reference back() const{
				return (_data[_size + 1]);
			}

			void push_back(const_reference value) {
				resize();
				new(&this->_data[this->_size + 1]) value_type(value);
				_size++;
			};

			void pop_back(){
				resize();
				this->_data[_size].~value_type();
				_size--;
			}
			size_type max_size() const {
				return (UINT32_MAX / sizeof(value_type));
			};

			size_type	size() const {
				return (_size);
			};

			bool		empty() const {
				return (_size == 0);
			};

			size_type	capacity() const {
				return (_capacity);
			};

			// Выделяет дополнительное место capacity
			void		reserve(size_type capacity){
				if (capacity > _capacity){
					resize_internal(capacity);
				}
			};

			// Записывает value в выделенные ячейки
			void		resize(size_type capacity, value_type value = value_type()){
				size_type i = _size + 1;

				resize_internal(capacity);
				if (capacity < _size) {
					_size = capacity;
			 	} else {
					while (i < capacity + 1){
						_data[i] = value;
						i++;

					}
					_size = i - 1;
				}
			};

			size_type	size(){
				return (_size);
			};

			vector &operator=(const vector &obj){
				if (this->_capacity < obj._capacity)
					this->resize_internal(obj._capacity);
				this->_size = obj.size();
				std::memcpy(this->_data, obj._data, this->size());
				return (*this);
			};

			const_reference &operator[](size_type index) const {
				return (_data[index + 1]);
			};

			reference &operator[](size_type index){
				return (_data[index + 1]);
			};
	};
	template<typename T>
	bool operator==(ft::vector<T> const &lhs, ft::vector<T> const &rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		for (size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] != rhs[i])
				return (false);
		return (true);
	}

	template<typename T>
	bool operator!=(ft::vector<T> const &lhs, ft::vector<T> const &rhs) {
		return (!(lhs == rhs));
	}

	template<typename T>
	bool operator<(ft::vector<T> const &lhs, ft::vector<T> const &rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<typename T>
	bool operator<=(ft::vector<T> const &lhs, ft::vector<T> const &rhs) {
		return (!(rhs < lhs));
	}

	template<typename T>
	bool operator>(ft::vector<T> const &lhs, ft::vector<T> const &rhs) {
		return (rhs < lhs);
	}

	template<typename T>
	bool operator>=(ft::vector<T> const &lhs, ft::vector<T> const &rhs) {
		return (!(lhs < rhs));
	}

}
