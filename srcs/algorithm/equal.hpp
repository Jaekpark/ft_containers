#ifndef _FT_EQUAL_HPP
#define _FT_EQUAL_HPP

//namespace_start
template <class InputIterator1, class InputIterator2>
	void equal(InputIterator1 first1, InputIterator1 last1,
						InputIterator2 first2) {};
template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	void equal(InputIterator1 first1, InputIterator1 last1,
						InputIterator2 first2, BinaryPredicate pred) {};
//namespace_end
#endif		