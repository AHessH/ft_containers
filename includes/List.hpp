#ifndef __LIST_HPP
#define __LIST_HPP


namespace ft{

	template<class T>
	 class ListIterator{
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
				++this->p;
				return (*this);
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
				--this->p;
				return (*this);
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
	 class ReverseListIterator{
	};
	template<class T>
	 class list{
		public:
			typedef		T 										value_type;//	Тип, представляющий тип данных, хранящихся в векторе.
			typedef		ListIterator<value_type> 				iterator;//	Тип, предоставляющий итератор произвольного доступа, который может читать или изменять любой элемент в векторе.
			typedef		ListIterator<value_type const> 			const_iterator;//	Тип, предоставляющий итератор произвольного доступа, который может считывать const элемент в векторе.
			typedef		ReverseListIterator<value_type> 		reverse_iterator;//	Тип, предоставляющий итератор произвольного доступа, который может читать или изменять любой элемент в обратном векторе.
			typedef		ReverseListIterator<value_type const> 	const_reverse_iterator;//	Тип, предоставляющий итератор произвольного доступа, который может читать любой const элемент в векторе.

			typedef		T* 										pointer;//	Тип, предоставляющий указатель на элемент в векторе.
			typedef		T& 										reference;//	Тип, предоставляющий ссылку на элемент, хранящийся в векторе.
			typedef		T const * 								const_pointer;//	Тип, предоставляющий указатель на const элемент в векторе.
			typedef		T const & 								const_reference;//	Тип, предоставляющий ссылку на const элемент, хранящийся в векторе. Он используется для чтения и выполнения const операций.
			typedef		std::ptrdiff_t 							difference_type;//	Тип, представляющий различие между адресами двух элементов в векторе.
			typedef		unsigned int 							size_type;//	Тип, считающий количество элементов в векторе.
		private:
			struct		List
			{
				List 		*_prev;
				pointer 	_value;
				List 		*_next;
			}			*_FNode;
			size_type 	_size;
		public:
			list(): _FNode(NULL), _size(0) {};

/* 			list(size_type n, const value_type& val = value_type()) {};

			template <class InputIterator>
			 list(InputIterator first, InputIterator last) {};

			list(const list& x){
				*this = x;
			}; */
			
			void push_back(value_type val) {
				if (this->empty()){
					_FNode = new List;
					_FNode->_value = new value_type(val);
					_FNode->_prev = NULL;
					_FNode->_next = NULL;
				} else {
				List *tmp = _FNode;
					while (tmp->_next)
						tmp = tmp->_next;
					tmp->_next = new List;
					tmp->_next->_value = new value_type(val);
					tmp->_next->_next = NULL;
					tmp->_next->_prev = tmp;
				}
				_size++;
			};

			void push_front(value_type val) {
				if (this->empty()){
					push_back(val);
				} else {
					List *tmp = _FNode;
					tmp->_prev = new List;
					tmp->_prev->_value = new value_type(val);
					tmp->_prev->_next = tmp;
					tmp->_prev->_prev = NULL;
					_FNode = tmp->_prev;
					_size++;
				}
			};
			void pop_back() {
				if (!this->empty()) {
					List *tmp = _FNode;
					while (tmp->_next)
						tmp = tmp->_next;
					if (tmp->_prev)
						tmp->_prev->_next = NULL;
					tmp->_value->~value_type();
					delete tmp;
					_size--;
					if (_size == 0)
						_FNode = NULL;
				}
			};

			void pop_front() {
				if (!this->empty()) {
					List *tmp = _FNode;
					_FNode = tmp->_next;
					if (_FNode)
						_FNode->_prev = NULL;
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
				List *tmp = _FNode;
				while (tmp->_next)
					tmp = tmp->_next;
				return (*tmp->_value);
			};

			const_reference back() const {
				List *tmp = _FNode;
				while (tmp->_next)
					tmp = tmp->_next;
				return (*tmp->_value);
			};

			iterator begin() {
				return (iterator(_FNode);
			};

			const_iterator begin() const {
				return (const_iterator(_FNode));
			};
			
			iterator end() {
				return (NULL);
			};

			const_iterator end() const {
				return (NULL);
			};
		//NOTE: Подумать над тем чтобы сделать границы для rend и end
	};

}

#endif
