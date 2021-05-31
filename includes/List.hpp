#ifndef __LIST_HPP
#define __LIST_HPP


namespace ft{

	template<class T>
	 class list{
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
			struct		List
			{
				List 		*_prev;
				pointer 	_value;
				List 		*_next;
			}			_node;
			size_type 	_size;
			
	}

}

#endif
