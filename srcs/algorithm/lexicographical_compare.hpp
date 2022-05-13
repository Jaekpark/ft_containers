#ifndef _FT_LEXICOGRAPHICAL_COMPARE_HPP
#define _FT_LEXICOGRAPHICAL_COMPARE_HPP

#include "../config.hpp"
//namespace_start
_BEGIN_NAMESPACE_FT
template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
															InputIterator2 first2, InputIterator2 last2) {};
template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
															InputIterator2 first2, InputIterator2 last2,
															Compare comp) {};
//namespace_end
_END_NAMESPACE_FT
#endif