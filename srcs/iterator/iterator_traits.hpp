#ifndef FT_ITERATOR_TRAITS_HPP
#define FT_ITERATOR_TRAITS_HPP

#include "../config.hpp"
#include "../type_traits/is_integral.hpp"

_BEGIN_NAMESPACE_FT

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template <class Iter>
struct iterator_traits {
  typedef typename Iter::difference_type difference_type;
  typedef typename Iter::value_type value_type;
  typedef typename Iter::pointer pointer;
  typedef typename Iter::reference reference;
  typedef typename Iter::iterator_category iterator_category;
};

template <class T>
struct iterator_traits<T*> {
  typedef ptrdiff_t difference_type;
  typedef T value_type;
  typedef T* pointer;
  typedef T& reference;
  typedef random_access_iterator_tag iterator_category;
};

template <class T>
struct iterator_traits<const T*> {
  typedef ptrdiff_t difference_type;
  typedef T value_type;
  typedef const T* pointer;
  typedef const T& reference;
  typedef random_access_iterator_tag iterator_category;
};

template <class T>
struct is_input_iterator : false_type {};
template <>
struct is_input_iterator<ft::input_iterator_tag> : true_type {};
template <class T>
struct is_output_iterator : false_type {};
template <>
struct is_output_iterator<ft::output_iterator_tag> : true_type {};
template <class T>
struct is_forward_iterator : false_type {};
template <>
struct is_forward_iterator<ft::forward_iterator_tag> : true_type {};
template <class T>
struct is_bidirectional_iterator : false_type {};
template <>
struct is_bidirectional_iterator<ft::bidirectional_iterator_tag> : true_type {};
template <class T>
struct is_random_access_iterator : false_type {};
template <>
struct is_random_access_iterator<ft::random_access_iterator_tag> : true_type {};

_END_NAMESPACE_FT

#endif