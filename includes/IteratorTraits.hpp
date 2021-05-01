// #pragma once
// Посмотреть требуется ли вообще этот трейт
// namespace ft{

// 	template<class T>
// 	 class IteratorTraits{
// 		public:
// 			typedef 	T 						value_type;
// 	    	typedef 	value_type* 			pointer;
// 	    	typedef 	value_type const* 		const_pointer;
// 	    	typedef 	value_type& 			reference;
// 	    	typedef 	value_type const& 		const_reference;
// 	    	typedef 	std::ptrdiff_t 			difference_type;

// 		public:
// 			// IteratorTraits();
// 			// IteratorTraits(const IteratorTraits<value_type> &obj){
// 				// *this = obj;
// 			// };
// 			virtual ~IteratorTraits() {};

// 			// virtual IteratorTraits<value_type>& operator=(const IteratorTraits<value_type> &obj) = 0;
// 			virtual value_type& operator*() = 0;
// 			virtual IteratorTraits<value_type>& operator++() = 0;
// 			// virtual IteratorTraits<value_type>& operator+=(unsigned int num) = 0;

// 			// virtual IteratorTraits<value_type> operator+(unsigned int num) const= 0; // TODO не работает, либо удалить, либо стараться поправить
// 			// virtual IteratorTraits<value_type>& operator--() = 0;
// 			// virtual IteratorTraits<value_type>& operator-=(unsigned int num) = 0;
// 			// virtual IteratorTraits<value_type>& operator-(unsigned int num) const = 0;
// 			// virtual value_type& operator->() = 0;
// 			// virtual value_type* operator[](unsigned int num) = 0;
// 			// virtual bool operator==(const IteratorTraits<value_type>& rhs) const = 0;
// 			// virtual bool operator!=(const IteratorTraits<value_type>& rhs) const = 0;
// 			// virtual bool operator>(const IteratorTraits<value_type>& rhs) const = 0;
// 			// virtual bool operator<(const IteratorTraits<value_type>& rhs) const = 0;
// 			// virtual bool operator>=(const IteratorTraits<value_type>& rhs) const = 0;
// 			// virtual bool operator<=(const IteratorTraits<value_type>& rhs) const = 0;
// 	};
// }