#ifndef _FT_LEXICOGRAPHICAL_COMPARE_HPP
#define _FT_LEXICOGRAPHICAL_COMPARE_HPP

#include "../config.hpp"
// namespace_start
_BEGIN_NAMESPACE_FT
template <class InputIterator1, class InputIterator2>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                             InputIterator2 first2, InputIterator2 last2) {
  for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2) {
    if (*first1 < *first2) return true;
    if (*first2 < *first1) return false;
  }
  return (first1 == last1) && (first2 != last2);
}
template <class InputIterator1, class InputIterator2, class Compare>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                             InputIterator2 first2, InputIterator2 last2,
                             Compare comp) {
  for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2) {
    if (comp(*first1, *first2)) return false;
    if (comp(*first2, *first1)) return true;
  }
  return (first1 == last1) && (first2 != last2);
}
// namespace_end
_END_NAMESPACE_FT
#endif