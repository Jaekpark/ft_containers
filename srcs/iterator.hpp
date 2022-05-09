#ifndef _FT_ITERATOR_HPP
#define _FT_ITERATOR_HPP

#include <cstddef>
#include <iterator>
#include "config.hpp"
// template <class Category,              // iterator::iterator_category
//           class T,                     // iterator::value_type
//           class Distance = ptrdiff_t,  // iterator::difference_type
//           class Pointer = T*,          // iterator::pointer
//           class Reference = T&         // iterator::reference
//           > class iterator;

// iterator tag|Category of iterators
// -|-
// input_iterator_tag|Input Iterator
// output_iterator_tag|Output Iterator
// forward_iterator_tag|Forward Iterator
// bidirectional_iterator_tag|Bidirectional Iterator
// random_access_iterator_tag|Random-access Iterator

_BEGIN_NAMESPACE_FT
template <class Category,							// 반복자 종류
					class T,										// 데이터 타입
					class Distance = ptrdiff_t, //
					class Pointer = T *,				// 포인터
					class Reference = T &>			// 참쪼자
struct iterator
{
	typedef T value_type;
	typedef Distance difference_type;
	typedef Pointer pointer;
	typedef Reference reference;
	typedef Category iterator_category;
};

_END_NAMESPACE_FT
#endif