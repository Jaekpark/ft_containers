#ifndef _FT_ITERATOR_HPP
#define _FT_ITERATOR_HPP

#include <cstddef>
#include <iterator>

#include "../config.hpp"
#include "../iterator/advance.hpp"
#include "../iterator/distance.hpp"
#include "../iterator/iterator_traits.hpp"

_BEGIN_NAMESPACE_FT

template <class Category, class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T&>
struct iterator {
  typedef T value_type;
  typedef Distance difference_type;
  typedef Pointer pointer;
  typedef Reference reference;
  typedef Category iterator_category;
};

template <class Iterator>
class wrap_iterator {
 public:
  typedef Iterator iterator_type;
  typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
  typedef typename ft::iterator_traits<iterator_type>::difference_type
      difference_type;
  typedef typename ft::iterator_traits<iterator_type>::pointer pointer;
  typedef typename ft::iterator_traits<iterator_type>::reference reference;
  typedef typename ft::iterator_traits<iterator_type>::iterator_category
      iterator_category;

 private:
  iterator_type _i;

 public:
  wrap_iterator(void) : _i{};
  wrap_iterator(const wrap_iterator<Iterator>& x)
};
/** c++ 20 부터는 인접 반복자(contiguous_iterator)가 추가되었습니다.
 * struct contiguous_iterator_tag	: public random_access_iterator_tag {};
 **/

_END_NAMESPACE_FT

#endif