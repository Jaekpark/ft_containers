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
#include "../iterator/reverse_iterator.hpp"

#define _ITERATOR_CATEGORY random_access_iterator_tag

_BEGIN_NAMESPACE_FT
template <class T, class Allocator = std::allocator<T> >
class vector {
 protected:
  typedef typename Allocator::difference_type difference_type;
  // 참조자 타입 선언
  typedef typename Allocator::reference reference;
  typedef typename Allocator::const_reference const_reference;
  // 포인터 타입 선언
  typedef typename Allocator::pointer pointer;
  typedef typename Allocator::const_pointer const_pointer;
  // 반복자 타입 선언
  typedef ft::iterator<_ITERATOR_CATEGORY, pointer> iterator;
  typedef ft::iterator<_ITERATOR_CATEGORY, const_pointer> const_iterator;
  typedef typename ft::reverse_iterator<iterator> reverse_iterator;
  typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

 private:
  Allocator _alloc;
  pointer _begin;
  pointer _end;
  pointer _end_capacity;

 public:
  typedef T value_type;
  typedef Allocator allocator_type;
  typedef typename allocator_type::size_type size_type;

  explicit vector(const Allocator &alloc = Allocator())
      : _alloc(alloc), _begin(nullptr), _end(nullptr), _end_capacity(nullptr){};
  explicit vector(size_type n, const T &value = T(),
                  const Allocator &alloc = Allocator())
      : _alloc(alloc), _begin(nullptr), _end(nullptr), _end_capacity(nullptr) {
    _begin = _alloc.allocate(n);
    _end = _begin;
    _end_capacity = _begin + n;
    while (n--) _alloc.construct(_end++, value);
  };
  template <class InputIterator>
  vector(InputIterator first, InputIterator last,
         const Allocator &alloc = Allocator())
      : _alloc(alloc), _begin(nullptr), _end(nullptr), _end_capacity(nullptr) {
    difference_type n = std::distance(first, last);
    _begin = _alloc.allocate(n);
    _end = _begin;
    _end_capacity = _begin + n;
    while (n--) _alloc.construct(_end++, *first++);
  };
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
  ~vector(void) {
    difference_type n = _begin - _end_capacity;
    pointer _last_element = _end;
    for (; _last_element != _begin; _last_element--)
      _alloc.destroy(_last_element);
    _alloc.deallocate(_begin, n);
  };

  vector<T, Allocator> &operator=(const vector<T, Allocator> &x){};

  template <class InputIterator>
  void assign(size_type n, const T &u);
  allocator_type get_allocator(void) const;

  // iterator
  iterator begin(void) { return _begin; };
  const_iterator begin(void) const {
    return static_cast<const_pointer>(_begin);
  };
  iterator end(void) { return _end; };
  const_iterator end(void) const { return _end; };
  reverse_iterator rbegin(void);
  const_reverse_iterator rbegin(void) const;
  reverse_iterator rend(void);
  const_reverse_iterator rend(void) const;

  // capacity
  size_type size(void) const { return _end - _begin; };
  size_type max_size(void) const;
  void resize(size_type n, value_type val = value_type());
  size_type capacity(void) const { return _end_capacity - _begin; };
  bool empty(void) const;
  void reserve(size_type n);

  // element access
  reference operator[](size_type n) { return *(_begin + n); };
  const_reference operator[](size_type n) const;
  reference at(size_type n);
  const_reference at(size_type n) const;
  reference front(void);
  const_reference front(void) const;
  reference back(void);
  const_reference back(void) const;

  // modifiers
  void push_back(const T &x);
  void pop_back(void);
  iterator insert(iterator position, const T &x);
  void insert(iterator position, size_type n, const T &x);
  template <class InputIterator>
  void insert(iterator position, InputIterator first, InputIterator last);
  iterator erase(iterator position);
  iterator erase(iterator first, iterator last);
  void swap(vector<T, Allocator> &);
  void clear(void);
};

_END_NAMESPACE_FT

#endif