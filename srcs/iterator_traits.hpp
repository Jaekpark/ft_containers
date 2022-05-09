#ifndef FT_ITERATOR_TRAITS_HPP
#define FT_ITERATOR_TRAITS_HPP

#include <cstddef>
#include <iterator>
#include "config.hpp"

// template <class Category,              // iterator::iterator_category
//           class T,                     // iterator::value_type
//           class Distance = ptrdiff_t,  // iterator::difference_type
//           class Pointer = T*,          // iterator::pointer
//           class Reference = T&         // iterator::reference
//           > class iterator;

_BEGIN_NAMESPACE_FT
template <class Category,
					class T,
					class Distance	= ptrdiff_t,
					class Pointer		= T*,
					class Reference = T&>
struct iterator {
	typedef T					value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;
};

_END_NAMESPACE_FT

#endif