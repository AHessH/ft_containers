#ifndef __LIST_HPP
#define __LIST_HPP

#include <limits>

namespace ft{
	namespace node{
		template<typename T>
		 struct		List
		{
			List 		*_prev;
			T		 	*_value;
			List 		*_next;
		};
	}
	template<class T, class N>
	 class ListIterator{
		public:
		 	typedef 	T 						value_type;
	    	typedef 	value_type* 			pointer;
	    	typedef 	value_type const* 		const_pointer;
	    	typedef 	value_type& 			reference;
	    	typedef 	value_type const& 		const_reference;
	    	typedef 	std::ptrdiff_t 			difference_type;
			typedef		N						node_type;
			typedef		node_type*				node_pointer;
		private:
		 	node_pointer p;

		public:
			ListIterator(): p(NULL) {};
		 	ListIterator(node_pointer p): p(p) {};
			ListIterator(const ListIterator &obj): p(obj.p) {};
			~ListIterator() {};

			ListIterator &operator=(const ListIterator &obj) {
				this->p = obj._FNode;
				return (*this);
			};
			
			reference operator*(){
				return (*(this->p->_value));
			};
			ListIterator& operator++() {
				this->p = this->p->_next;
				return (*this);
			};
			ListIterator& operator++(int) {
				this->p = this->p->_next;
				return (*this);
			};
			ListIterator& operator--() {
				this->p = this->p->_prev;
				return (*this);
			};
			ListIterator& operator--(int) {
				this->p = this->p->_prev;
				return (*this);
			}
			pointer operator->(){
				return (this->p->_value);
			};
			bool operator==(const ListIterator& rhs) const {
				return (this->p->_value == rhs.p->_value);
			};
			bool operator!=(const ListIterator& rhs) const {			
				return (!(*this == rhs));
			};
			bool operator>(const ListIterator& rhs) const {
				return (this->p->_value > rhs.p->_value);
			};
			bool operator<(const ListIterator& rhs) const {
				return (this->p->_value < rhs.p->_value);
			};
			bool operator>=(const ListIterator& rhs) const {
				return (this->p->_value >= rhs.p->_value);
			};
			bool operator<=(const ListIterator& rhs) const {
				return (this->p->_value <= rhs.p->_value);
			};

			// operator ListIterator<value_type const>() {return (this->p->_value);};
	};
	template<class T, class N>
	 class ReverseListIterator{
		public:
		 	typedef 	T 						value_type;
	    	typedef 	value_type* 			pointer;
	    	typedef 	value_type const* 		const_pointer;
	    	typedef 	value_type& 			reference;
	    	typedef 	value_type const& 		const_reference;
	    	typedef 	std::ptrdiff_t 			difference_type;
			typedef		N						node_type;
			typedef		node_type*				node_pointer;
		private:
		 	node_pointer p;

		public:
			ReverseListIterator(): p(NULL) {};
		 	ReverseListIterator(node_pointer p): p(p) {};
			ReverseListIterator(const ReverseListIterator &obj): p(obj.p) {};
			~ReverseListIterator() {};

			ReverseListIterator &operator=(const ReverseListIterator &obj) {
				this->p = obj._FNode;
				return (*this);
			};
			
			reference operator*(){
				return (*(this->p->_value));
			};
			ReverseListIterator& operator++() {
				this->p = this->p->_prev;
				return (*this);
			};
			ReverseListIterator& operator++(int) {
				this->p = this->p->_prev;
				return (*this);
			};
			ReverseListIterator& operator--() {
				this->p = this->p->_next;
				return (*this);
			};
			ReverseListIterator& operator--(int) {
				this->p = this->p->_next;
				return (*this);
			}
			pointer operator->(){
				return (this->p->_value);
			};
			bool operator==(const ReverseListIterator& rhs) const {
				return (this->p->_value == rhs.p->_value);
			};
			bool operator!=(const ReverseListIterator& rhs) const {			
				return (!(*this == rhs));
			};
			bool operator>(const ReverseListIterator& rhs) const {
				return (this->p->_value > rhs.p->_value);
			};
			bool operator<(const ReverseListIterator& rhs) const {
				return (this->p->_value < rhs.p->_value);
			};
			bool operator>=(const ReverseListIterator& rhs) const {
				return (this->p->_value >= rhs.p->_value);
			};
			bool operator<=(const ReverseListIterator& rhs) const {
				return (this->p->_value <= rhs.p->_value);
			};

			// operator ReverseListIterator<value_type const>() {return (this->p->_value);};
	};
	template<class T>
	 class list{
		public:
			typedef		T 												value_type;//				Тип, представляющий тип данных, хранящихся в списке.
		private:
			typedef		node::List<value_type>							node;//						Тип, предоставляющий node.
			typedef		node*											node_pointer;//				Тип, предоставлящий указатель на node списка.
		public:
			typedef		ListIterator<value_type, node> 					iterator;//					Тип, предоставляющий итератор произвольного доступа, который может читать или изменять любой элемент в списке.
			typedef		ListIterator<value_type const, node> 			const_iterator;//			Тип, предоставляющий итератор произвольного доступа, который может считывать const элемент в списке.
			typedef		ReverseListIterator<value_type, node> 			reverse_iterator;//			Тип, предоставляющий итератор произвольного доступа, который может читать или изменять любой элемент в обратном списке.
			typedef		ReverseListIterator<value_type const, node> 	const_reverse_iterator;//	Тип, предоставляющий итератор произвольного доступа, который может читать любой const элемент в списке.

			typedef		T* 												pointer;//					Тип, предоставляющий указатель на элемент в списке.
			typedef		T& 												reference;//				Тип, предоставляющий ссылку на элемент, хранящийся в списке.
			typedef		T const * 										const_pointer;//			Тип, предоставляющий указатель на const элемент в списке.
			typedef		T const & 										const_reference;//			Тип, предоставляющий ссылку на const элемент, хранящийся в списке. Он используется для чтения и выполнения const операций.
			typedef		std::ptrdiff_t 									difference_type;//			Тип, представляющий различие между адресами двух элементов в списке.
			typedef		unsigned int 									size_type;//				Тип, считающий количество элементов в списке.
		private:
			node_pointer				_rend_border;
			node_pointer				_end_border;
			node_pointer				_FNode;
			size_type 					_size;

		public:
			list(): _FNode(NULL), _size(0) {
				_rend_border = new node;
				_end_border = new node;
			};

/* 			list(size_type n, const value_type& val = value_type()) {};

			template <class InputIterator>
			 list(InputIterator first, InputIterator last) {};

			list(const list& x){
				*this = x;
			}; */
			
			void push_back(value_type val) {
				if (this->empty()){
					_FNode = new node;
					_FNode->_value = new value_type(val);
					_FNode->_prev = _rend_border;
					_FNode->_next = _end_border;
				} else {
					node_pointer tmp = _FNode;
					while (tmp->_next != _end_border)
						tmp = tmp->_next;
					tmp->_next = new node;
					tmp->_next->_value = new value_type(val);
					tmp->_next->_next = _end_border;
					tmp->_next->_prev = tmp;
				}
				_size++;
			};

			void push_front(value_type val) {
				if (this->empty()){
					push_back(val);
				} else {
					node_pointer tmp = _FNode;
					tmp->_prev = new node;
					tmp->_prev->_value = new value_type(val);
					tmp->_prev->_next = tmp;
					tmp->_prev->_prev = _rend_border;
					_FNode = tmp->_prev;
					_size++;
				}
			};
			void pop_back() {
				if (!this->empty()) {
					node_pointer tmp = _FNode;
					while (tmp->_next != _end_border)
						tmp = tmp->_next;
					if (tmp->_prev)
						tmp->_prev->_next = _end_border;
					tmp->_value->~value_type();
					delete tmp;
					_size--;
					if (_size == 0)
						_FNode = NULL;
				}
			};

			void pop_front() {
				if (!this->empty()) {
					node_pointer tmp = _FNode;
					_FNode = tmp->_next;
					if (_FNode)
						_FNode->_prev = _rend_border;
					tmp->_value->~value_type();
					delete tmp;
					_size--;
					if (_size == 0)
						_FNode = NULL;
				}
			};

			size_type size() {
				return (_size);
			};

			bool empty() {
				return (_size == 0);
			};
			
			void clear() {
				while (_FNode != NULL)
					pop_back();
			};

			reference front() {
				return (*_FNode->_value);
			};
			const_reference front() const {
				return (*_FNode->_value);
			};
			reference back() {
				node_pointer tmp = _FNode;
				while (tmp->_next)
					tmp = tmp->_next;
				return (*tmp->_value);
			};
			const_reference back() const {
				node_pointer tmp = _FNode;
				while (tmp->_next)
					tmp = tmp->_next;
				return (*tmp->_value);
			};

			iterator begin() {
				return (iterator(_FNode));
			};
			const_iterator begin() const {
				return (const_iterator(_FNode));
			};
			iterator end() {
				return (_end_border);
			};
			const_iterator end() const {
				return (_end_border);
			};
			reverse_iterator rbegin() {
				node_pointer tmp = _FNode;
				while (tmp->_next != _end_border)
					tmp = tmp->_next;
				return (reverse_iterator(tmp));
			};
			const_reverse_iterator rbegin() const {
				node_pointer tmp = _FNode;
				while (tmp->_next != _end_border)
					tmp = tmp->_next;
				return (const_reverse_iterator(tmp));
			};
			reverse_iterator rend() {
				return (_rend_border);
			};
			const_reverse_iterator rend() const {
				return (_rend_border);
			};

			size_type max_size() const {
				return std::numeric_limits<difference_type>::max() / sizeof(node);
			};

			void resize(size_type n, value_type val = value_type()) {
				if (n > _size) {
					for (size_type i = _size; i < n; i++)
						this->push_back(val);
				} else if (n < _size) {
					for (size_type i = _size; i > n; i--)
						this->pop_back();
				}
			};

			void swap(list& x){
				ft::swap(x._FNode, this->_FNode);
				ft::swap(x._size, this->_size);
			};
	};

}

#endif
