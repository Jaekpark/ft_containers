#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>
#include "../config.hpp"
#include "../iterator/iterator.hpp"
#include "../iterator/reverse_iterator.hpp"

#define _ITERATOR_CATEGORY random_access_iterator_tag

_BEGIN_NAMESPACE_FT
template < class T, class Allocator = std::allocator<T> >
class vector {
public:
	typedef T																								value_type;
	typedef Allocator																				allocator_type;
	typedef typename allocator_type::size_type							size_type;
	typedef typename allocator_type::difference_type				difference_type;
	// 참조자 타입 선언
	typedef typename allocator_type::reference							reference;
	typedef typename allocator_type::const_reference				const_reference;
	// 포인터 타입 선언
	typedef typename allocator_type::pointer								pointer;
	typedef typename allocator_type::const_pointer					const_pointer;
	// 반복자 타입 선언
	typedef ft::iterator<_ITERATOR_CATEGORY, pointer>				iterator;
	typedef ft::iterator<_ITERATOR_CATEGORY, const_pointer>	const_iterator;
	typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator>		const_reverse_iterator;

	vector(void) {};
	explicit vector(const Allocator& alloc = Allocator()) {};
	explicit vector(size_type n, const T& value = T(),
									const Allocator& allocator = Allocator()) {};
	template <class InputIterator>
		explicit vector(InputIterator first, InputIterator last,
										const Allocator& allocator = Allocator()) {};
	explicit vector(const vector<T, Allocator>& x) {};
	~vector(void) {};

	vector<T, Allocator>& operator=(const vector<T, Allocator>& x) {};
	// 	for (int i = 0; i < n; i++)
	// 		pointer++ = value;
	// }
	// template <class InputIterator>
	// 	explicit vector(InputIterator first, Inputiterator last, const allocator_type& alloc = allocator_type()) {
	// 		for (iterator iter = first; iter != last; first++)
	// 			iterator 
	// 	}
	// explicit Vector(const vector& x);
	~Vector(void);

private:

};

_END_NAMESPACE_FT


#endif