#ifndef _FT_ITERATOR_ADVANCE_HPP
#define _FT_ITEARTOR_ADVANCE_HPP

#include "../config.hpp"
#include "../iterator/iterator.hpp"

_BEGIN_NAMESPACE_FT
template <class InputIterator>
void advance(InputIterator& i,
             typename iterator_traits<InputIterator>::difference_type n,
             input_iterator_tag) {
  for (; n > 0; --n) ++i;
}

template <class BidirIterator>
void advance(BidirIterator& i,
             typename iterator_traits<BidirIterator>::difference_type n,
             bidirectional_iterator_tag) {
  if (n >= 0)
    for (; n > 0; --n) ++i;
  else
    for (; n < 0; ++n) --i;
}

template <class RandomIterator>
void advance(RandomIterator& i,
             typename iterator_traits<RandomIterator>::difference_type n,
             random_access_iterator_tag) {
  i += n;
}

template <class InputIterator, class Distance>
void advance(InputIterator& i, Distance n) {
  ft::advance(i,
              typename ft::iterator_traits<InputIterator>::difference_type(n),
              typename ft::iterator_tratis<InputIterator>::iterator_category());
}

_END_NAMESPACE_FT
#endif