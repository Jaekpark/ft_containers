#ifndef _FT_ITERATOR_HPP
#define _FT_ITERATOR_HPP

#include <cstddef>
#include <iterator>
#include "../config.hpp"
#include "../iterator/iterator_traits.hpp"


_BEGIN_NAMESPACE_FT

template <class Category,
					class T,
					class Distance = ptrdiff_t,
					class Pointer = T*,
					class Reference = T&>
struct iterator
{
	typedef T					value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;
};

/** c++ 20 부터는 인접 반복자(contiguous_iterator)가 추가되었습니다.
 * struct contiguous_iterator_tag	: public random_access_iterator_tag {};
**/

_END_NAMESPACE_FT

#endif