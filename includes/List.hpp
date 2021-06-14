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
				this->p = obj.p;
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
			void delete_elem(node_pointer point) {
				node_pointer tmp = point->_next;
				point->_prev->_next = tmp;
				tmp->_prev = point->_prev;
				point->_value->~value_type();
				delete point;
				--_size;
			};
			void add_elem(node_pointer &point, reference val) {
				node_pointer tmp = point->_next;
				point->_next = new node;
				point->_next->_prev = point;
				point->_next->_next = tmp;
				point->_next->_value = new value_type(val);
				tmp->_prev = point->_next;
			};
			node_pointer cut_elem(node_pointer &point) {
				node_pointer tmp = point;
				if (point == this->_FNode) {
					this->_FNode = tmp->_next;
				}
				tmp->_prev->_next = tmp->_next;
				tmp->_next->_prev = tmp->_prev;
				tmp->_next = NULL;
				tmp->_prev = NULL;
				this->_size--;
				return (tmp);
			};
			void paste_elem(node_pointer &point, iterator &position, list &list) {
				node_pointer pos = this->_FNode;
				iterator iter = this->begin();
				while (iter != position){
					iter++;
					pos = pos->_next;
				}
				this->_size++;
				point->_next = pos;
				point->_prev = pos->_prev;
				pos->_prev->_next = point;
				pos->_prev = point;
			};

		public:
			list(): _FNode(NULL), _size(0) {
				_rend_border = new node;
				_end_border = new node;
			};

			list(size_type n, const value_type& val = value_type()) {
				this->assign(n, val);
			};

			template <class InputIterator>
			 list(InputIterator first, InputIterator last) {
				this->assign(first, last);
			};

			list(const list& x){
				*this = x;
			};
			~list() {
				this->clear();
				delete this->_end_border;
				delete this->_rend_border;
			};

			void push_back(value_type val) {
				if (this->empty()){
					_FNode = new node;
					_FNode->_value = new value_type(val);
					_FNode->_prev = _rend_border;
					_rend_border->_next = _FNode;
					_FNode->_next = _end_border;
					_end_border->_prev = _FNode;
				} else {
					node_pointer tmp = _FNode;
					while (tmp->_next != _end_border)
						tmp = tmp->_next;
					tmp->_next = new node;
					tmp->_next->_value = new value_type(val);
					tmp->_next->_next = _end_border;
					tmp->_next->_prev = tmp;
					_end_border->_prev = tmp->_next;
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
					_rend_border->_next = _FNode;
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
					if (_size == 0) {
						_FNode = NULL;
						_end_border->_prev = NULL;
						_rend_border->_next = NULL;
					}
				}
			};

			void pop_front() {
				if (!this->empty()) {
					node_pointer tmp = _FNode;
					_FNode = tmp->_next;
					if (_FNode)
						_FNode->_prev = _rend_border;
					_rend_border->_next = _FNode;
					tmp->_value->~value_type();
					delete tmp;
					_size--;
					if (_size == 0) {
						_FNode = NULL;
						_end_border->prev = NULL;
						_rend_border->_next = NULL;
					}
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
			iterator end() { //TODO: проблема с end сегфолт
				return (iterator(_end_border));
			};
			const_iterator end() const {
				return (const_iterator(_end_border));
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

			template <class InputIterator>
			 void assign(InputIterator first, InputIterator last) {
				this->clear();
				for (; first != last; first++) {
					this->push_back(*first);
				}
			};
			void assign(size_type n, const_reference val) {
				this->clear();
				for (size_type i = 0; i < n; i++) {
					this->push_back(val);
				}
			};

			iterator insert(iterator position, const_reference val) {
				node_pointer insert_position = _FNode;
				while (insert_position->_next != position)
					insert_position= insert_position->_next;
				node_pointer tmp = insert_position->_next;
				insert_position->_next = new node;
				insert_position->_next->_value = new value_type(val);
				insert_position->_next->_next = tmp;
				insert_position->_next->_prev = insert_position;
				tmp->_prev = insert_position->_next;
				_size++;
				
			};
    		void insert(iterator position, size_type n, const_reference val) {
				for (size_type i = 0; i < n; i++) {
					this->insert(position, val);
				}
			};
			template <class InputIterator>
    		 void insert(iterator position, InputIterator first, InputIterator last) {
				for (;first != last; first++) {
					this->insert(position, *first);
					position++;
				}
			};

			iterator erase(iterator position) {
				node_pointer tmp = _FNode;
				iterator it1 = this->begin();
				while (it1 != position) {
					tmp = tmp->_next;
					it1++;
				}
				it1++;
				if (tmp == _FNode){
					_FNode = tmp->_next;
				}
				if (_size != 0) {
					delete_elem(tmp);
				}
				return (it1);
			};
			iterator erase(iterator first, iterator last) {
				iterator it1;
				for (;first != last; first++){
					it1 = this->erase(first);
				}
				return (it1);
			};

			void remove(const_reference val) {
				for (node_pointer tmp = _FNode; tmp != _end_border; tmp = tmp->_next) {
					if (tmp == _FNode && *_FNode->_value == val)
						_FNode = tmp->_next;
					if (*tmp->_value == val) {
						delete_elem(tmp);
					}
				}
			};
			template <class Predicate>
             void remove_if(Predicate pred) {
				for (pointer tmp = _FNode; tmp != _end_border; tmp = tmp->next) {
					if (pred(*tmp->_value))
						delete_elem(tmp);
				}
			};
			
			void splice(iterator position, list& x) {
				node_pointer tmp = this->_FNode;
				for (iterator i = this->begin(); i != position; i++) {
					tmp = tmp->_next;
				}
				tmp = tmp->_prev;
				while (x.size()) {
					node_pointer asd = x.cut_elem(x._FNode);
					this->paste_elem(asd, position, x);
					if (tmp == _rend_border){
						_FNode = tmp->_next;
					}
				}
			};
			void splice(iterator position, list& x, iterator i) {
				node_pointer tmp = this->_FNode;
				for (iterator it = this->begin(); it != position; it++) {
					tmp = tmp->_next;
				}
				tmp = tmp->_prev;
				node_pointer cut = x._FNode;
				for (iterator j = x.begin(); j != i; j++) {
					cut = cut->_next;
				}
				node_pointer asd = x.cut_elem(cut);
				this->paste_elem(asd, position, x);
				if (tmp == _rend_border){
					_FNode = tmp->_next;
				}
			};
			void splice(iterator position, list& x, iterator first, iterator last) {
				for (;first != last;) {
					iterator tmp = first;
					tmp++;
					this->splice(position, x, first);
					first = tmp;
				}
			};

			void unique() {
				for (node_pointer tmp = _rend_border; tmp != _end_border; tmp = tmp->_next) {
					if (tmp->_next->_value && tmp->_value && *tmp->_value == *tmp->_next->_value){
						this->erase(iterator(tmp));
					}
				}
			};
			template <class BinaryPredicate>
			 void unique (BinaryPredicate binary_pred) {
				for (node_pointer tmp = _rend_border; tmp != _end_border; tmp = tmp->_next) {
					if (tmp->_next->_value && tmp->_value && binary_pred(iterator(tmp->_next), iterator(tmp)))
						this->erase(iterator(tmp));
					}
			};

			// void merge(list& x) { // TODO: исправить метод должен вырезать node из другого
			// 	if (&x == this)
			// 		return ;
			// 	node_pointer x_pointer = &x;
			// 	node_pointer this_pointer = this;

			// };
			// template <class Compare>
			//  void merge(list& x, Compare comp) {

			// };
			
			void sort() {
				for (node_pointer x = this->_FNode; x != _end_border->_prev; x = x->_next) {
					for (node_pointer y = x; y != _end_border; y = y->_next) {
						if (*y->_value < *x->_value) {
							ft::swap(x->_value, y->_value);
						}
					}
				}
			};
			template <class Compare>
			 void sort(Compare comp) {
				for (node_pointer x = this->_FNode; x != _end_border->_prev; x = x->_next) {
					for (node_pointer y = x; y != _end_border; y = y->_next) {
						if (comp(*y->_value, *x->_value)) {
							ft::swap(x->_value, y->_value);
						}
					}
				}
			};

			void reverse() {
				node_pointer x = this->_FNode;
				node_pointer y = this->_end_border->_prev;
				for (size_type i = 0; i < this->size() / 2; x = x->_next, y = y->_prev, i++) {
					ft::swap(x->_value, y->_value);
				}
			};
	};

}

#endif
