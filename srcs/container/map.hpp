#ifndef _FT_MAP_HPP
#define _FT_MAP_HPP

#include <map>
#include <memory>

#include "../config.hpp"
#include "../iterator/iterator.hpp"
#include "../iterator/iterator_traits.hpp"
#include "../iterator/reverse_iterator.hpp"
#include "../utility/binary_search_tree.hpp"
#include "../utility/bst_node.hpp"
#include "../utility/make_pair.hpp"
#include "../utility/pair.hpp"

_BEGIN_NAMESPACE_FT
// namespace_start
template <class Key, class T, class Compare = std::less<Key>,
          class Allocator = std::allocator<ft::pair<const Key, T> > >
class map {
 public:
  typedef Key key_type;
  typedef T mapped_type;
  typedef ft::pair<const key_type, mapped_type> value_type;
  typedef Compare key_compare;
  typedef Allocator allocator_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef typename allocator_type::size_type size_type;
  typedef typename allocator_type::difference_type difference_type;

  typedef ft::reserve_iterator<iterator> reserve_iterator;
  typedef ft::reserve_iterator<const_iterator> reserve_iterator;

  // default_constructor
  explicit map(void);
  // copy_constructor
  explicit map(const map& x);
  // destructor
  ~map(void);
  // operator=
  map operator=(const map& x);
};

_END_NAMESPACE_FT
// namespace_end
#endif