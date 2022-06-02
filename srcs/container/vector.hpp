#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <iostream>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

#include "../config.hpp"
#include "../iterator/iterator.hpp"
#include "../iterator/iterator_traits.hpp"
#include "../iterator/reverse_iterator.hpp"
#include "../type_traits/enable_if.hpp"

#define _ITERATOR_CATEGORY random_access_iterator_tag

_BEGIN_NAMESPACE_FT
template <class T, class Allocator = std::allocator<T> >
class vector_base {
 public:
  typedef Allocator allocator_type;
  typedef allocator_traits<allocator_type> alloc_traits;
  typedef typename alloc_traits::size_type size_type;

 protected:
  typedef T value_type;
  typedef value_type &reference;
  typedef const value_type &const_reference;
  typedef typename alloc_traits::difference_type difference_type;
  typedef typename alloc_traits::pointer pointer;
  typedef typename alloc_traits::const_pointer const_pointer;
  typedef pointer iterator;
  typedef const_pointer const_iterator;

  allocator_type _alloc;
  pointer _begin;
  pointer _end;
  pointer _end_capacity;

 public:
  virtual ~vector_base(void) {}
  iterator begin(void) = 0;
};

template <class T, class Allocator = std::allocator<T> >
class vector : private vector_base<T, Allocator> {
 private:
  typedef vector_base<T, Allocator> _base;
  typedef Allocator<T> _default_allocator;

 public:
  typedef T value_type;
  typedef Allocator allocator_type;
  typedef typename allocator_type::size_type size_type;

  // * Default Constructor
  explicit vector(const Allocator &alloc = Allocator())
      : _alloc(alloc), _begin(nullptr), _end(nullptr), _end_capacity(nullptr){};
  // * Fill Constructor
  explicit vector(size_type n, const T &value = T(),
                  const Allocator &alloc = Allocator())
      : _alloc(alloc), _begin(nullptr), _end(nullptr), _end_capacity(nullptr) {
    _begin = _alloc.allocate(n);
    _end = _begin;
    _end_capacity = _begin + n;
    while (n--) _alloc.construct(_end++, value);
  };
  // * Range Constructor
  template <class InputIterator>
  vector(InputIterator first, InputIterator last,
         const Allocator &alloc = Allocator(),
         typename ft::enable_if<!ft::is_integral<InputIterator>::value,
                                InputIterator>::type * = nullptr)
      : _alloc(alloc), _begin(nullptr), _end(nullptr), _end_capacity(nullptr) {
    difference_type n = std::distance(first, last);
    _begin = _alloc.allocate(n);
    _end = _begin;
    _end_capacity = _begin + n;
    while (n--) _alloc.construct(_end++, *first++);
  };
  // * Copy Constructor
  explicit vector(const vector<T, Allocator> &x)
      : _alloc(Allocator()),
        _begin(nullptr),
        _end(nullptr),
        _end_capacity(nullptr) {
    difference_type n = std::distance(x._begin, x._end_capacity);
    pointer x_end = x._end;
    _begin = _alloc.allocate(n);
    _end = _begin;
    _end_capacity = _begin + n;
    for (; x_end != x._begin; x_end--) _alloc.construct(_end++, *x_end);
  }
  // * Destructor
  ~vector(void) {
    difference_type n = _begin - _end_capacity;
    pointer _last_element = _end;
    for (; _last_element != _begin; _last_element--)
      _alloc.destroy(_last_element);
    _alloc.deallocate(_begin, n);
  };
  // * Operator =
  vector<T, Allocator> &operator=(const vector<T, Allocator> &x) {
    (void)x;
    return *this;
  };

  template <class InputIterator>
  void assign(InputIterator first, InputIterator last);
  void assign(size_type n, const T &u);
  allocator_type get_allocator(void) const { return _alloc; };

  // * iterator
  iterator begin(void) { return _begin; };
  const_iterator begin(void) const {
    return static_cast<const_pointer>(_begin);
  };
  iterator end(void) { return _end; };
  const_iterator end(void) const { return _end; };
  reverse_iterator rbegin(void) { return reverse_iterator(begin()); };
  const_reverse_iterator rbegin(void) const {
    return const_reverse_iterator(begin());
  };
  reverse_iterator rend(void) { return reverse_iterator(end()); };
  const_reverse_iterator rend(void) const {
    return const_reverse_iterator(end());
  };

  // * capacity
  size_type size(void) const { return _end - _begin; };
  size_type max_size(void) const { return _alloc().max_size(); };
  void resize(size_type n, value_type val = value_type()) {
    size_type sz = this->size();
    if (n > this->max_size()) throw(std::length_error("vector::resize"));
    if (sz > n)
      for (; sz != n; sz--) _alloc.destroy(_end--);
    else
      for (; sz != n; sz++)
        _alloc.construct(_end++, val);  // not yet, after implement insert
  };
  size_type capacity(void) const { return _end_capacity - _begin; };
  bool empty(void) const { return (size() == 0 ? true : false); };
  void reserve(size_type n) {
    if (n > this->max_size())
      throw(std::length_error("vector::reserve"));  // not complete
  };

  // * element access
  reference operator[](size_type n) { return *(_begin + n); };
  const_reference operator[](size_type n) const { return *(_begin + n); };
  reference at(size_type n) {
    if (n >= this->size()) throw(std::out_of_range("vector::at"));
    return *(_begin + n);
  };
  const_reference at(size_type n) const {
    if (n >= this->size()) throw(std::out_of_range("vector::at"));
    return *(_begin + n);
  };
  reference front(void) { return *(_begin); };
  const_reference front(void) const { return *_begin; };
  reference back(void) { return *_end; };
  const_reference back(void) const { return *_end; };

  // * modifiers
  void push_back(const T &x);
  void pop_back(void);
  iterator insert(iterator position, const T &x);
  void insert(iterator position, size_type n, const T &x);
  template <class InputIterator>
  void insert(iterator position, InputIterator first, InputIterator last);
  iterator erase(iterator position);
  iterator erase(iterator first, iterator last);
  void swap(vector<T, Allocator> &);
  void clear(void) {
    size_type n = _begin - _end;
    while (n--) _alloc.destroy(_end--);
  };
};

_END_NAMESPACE_FT

#endif