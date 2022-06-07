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
  typedef std::allocator_traits<allocator_type> alloc_traits;
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
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

  allocator_type _alloc;
  pointer _begin;
  pointer _end;
  pointer _end_capacity;

  // * Default Constructor
  explicit vector_base(const Allocator &alloc = Allocator())
      : _alloc(alloc), _begin(nullptr), _end(nullptr), _end_capacity(nullptr) {}
  // * Fill Constructor
  explicit vector_base(size_type n, const T &value = T(),
                       const Allocator &alloc = Allocator())
      : _alloc(alloc), _begin(nullptr), _end(nullptr), _end_capacity(nullptr) {
    _begin = _alloc.allocate(n);
    _end = _begin;
    _end_capacity = _begin + n;
    while (n--) _alloc.construct(_end++, value);
  }
  // * Range Constructor
  template <class InputIterator>
  vector_base(InputIterator first, InputIterator last,
              const Allocator &alloc = Allocator(),
              typename ft::enable_if<!ft::is_integral<InputIterator>::value,
                                     InputIterator>::type * = nullptr)
      : _alloc(alloc), _begin(nullptr), _end(nullptr), _end_capacity(nullptr) {
    difference_type n = std::distance(first, last);
    _begin = _alloc.allocate(n);
    _end = _begin;
    _end_capacity = _begin + n;
    while (n--) _alloc.construct(_end++, *first++);
  }
  // * Copy Constructor
  explicit vector_base(const vector_base<T, Allocator> &x)
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
  ~vector_base(void) {
    difference_type n = _begin - _end_capacity;
    pointer _last_element = _end;
    for (; _last_element != _begin; _last_element--)
      _alloc.destroy(_last_element);
    _alloc.deallocate(_begin, n);
  }

  // * Operator =
  vector_base<T, Allocator> &operator=(const vector_base<T, Allocator> &x) {
    (void)x;
    return *this;
  }

  // * utility
 public:
  allocator_type &_allocator(void) { return this->_alloc; }
  const allocator_type &_allocator(void) const { return this->_alloc; }
  pointer &_end_cap(void) { return this->_end_capacity; }
  const pointer &_end_cap(void) const { return this->_end_capacity; }
  size_type _capacity(void) const { return _end_cap() - _begin; }
  value_type *to_address(pointer p) { return p; }
  void _destruct_at_end(pointer new_end) {
    pointer origin_end = this->_end;
    while (new_end != origin_end)
      alloc_traits::destroy(_alloc, to_address(--origin_end));
    this->_end = new_end;
  }
  // size_type align_it(size_type new_size) { return new_size + }
};

template <class T, class Allocator = std::allocator<T> >
class vector : public vector_base<T, Allocator> {
 private:
  typedef vector_base<T, Allocator> _base;
  typedef Allocator _default_allocator;

 public:
  typedef vector self;
  typedef T value_type;
  typedef Allocator allocator_type;
  typedef typename _base::alloc_traits alloc_traits;
  typedef typename _base::reference reference;
  typedef typename _base::const_reference const_reference;
  typedef typename _base::size_type size_type;
  typedef typename _base::difference_type difference_type;
  typedef typename _base::pointer pointer;
  typedef typename _base::const_pointer const_pointer;
  typedef wrap_iterator<pointer> iterator;
  typedef wrap_iterator<const_pointer> const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

  // * utility
  void __destruct_at_end(iterator new_end) {
    _base::_destruct_at_end(new_end.base());
  }
  void throw_length_error(void) const { throw(std::length_error("vector")); }
  static const unsigned bits_per_word =
      static_cast<unsigned>(sizeof(size_type) * FT_CHAR_BIT);
  size_type recommend(size_type new_size) const {
    const size_type ms = max_size();
    if (new_size > ms) this->throw_length_error();
    const size_type cap = capacity();
    if (cap >= ms / 2) return ms;
    return std::max<size_type>(2 * cap, new_size);
  }
  iterator make_iterator(pointer p) { return iterator(p); }
  const_iterator make_iterator(const_pointer p) const {
    return const_iterator(p);
  }
  pointer _vallocate(size_type n, value_type val = value_type()) {
    if (n > max_size()) this->throw_length_error();
    pointer p = _default_allocator().allocate(n);
    pointer temp = p;
    while (n--) _default_allocator().construct(temp++, val);
    return p;
  }
  void _construct_node(pointer p, value_type val = value_type()) {
    p = this->_alloc.construct(p, val);
  }
  void _vdeallocate(void) {
    if (this->_begin != nullptr) {
      clear();
      this->_alloc.deallocate(this->_begin, capacity());
      this->_begin = nullptr;
      this->_end = nullptr;
      this->_end_capacity = nullptr;
    }
  }
  template <typename Iter>
  Iter copy(Iter first, Iter last, Iter d_first) {
    while (first != last) *d_first++ = *first++;
    return d_first;
  }

  // * Constructor
  vector(void) : _base() {}
  explicit vector(const Allocator &alloc) : _base(alloc) {}
  vector(size_type n) : _base(n) {}
  vector(size_type n, const value_type &x) : _base(n, x) {}
  vector(size_type n, const value_type &x, const allocator_type &alloc)
      : _base(n, x, alloc) {}
  // * Destructor
  ~vector(void) {}
  // * Allocator
  allocator_type get_allocator(void) const { return this->_allocator(); }
  // * Iterator
  iterator begin(void) { return make_iterator(this->_begin); }
  const_iterator begin(void) const { return make_iterator(this->_begin); }
  iterator end(void) { return make_iterator(this->_end); }
  const_iterator end(void) const { return make_iterator(this->_end); }
  reverse_iterator rbegin(void) { return reverse_iterator(begin()); }
  const_reverse_iterator rbegin(void) const {
    return const_reverse_iterator(begin());
  }
  reverse_iterator rend(void) { return reverse_iterator(end()); }
  const_reverse_iterator rend(void) const { return reverse_iterator(end()); }
  // * capacity
  size_type size(void) const { return end() - begin(); }
  size_type max_size(void) const { return get_allocator().max_size(); }
  void resize(size_type n, value_type val = value_type()) {
    size_type sz = size();
    if (n > max_size())
      throw(std::length_error("vector::resize"));
    else if (sz > n)
      for (; sz != n; sz--) get_allocator().destroy(this->_end--);
    else
      for (; sz != n; sz++) get_allocator().construct(this->_end++, val);
  }
  size_type capacity(void) const { return this->_capacity(); }
  bool empty(void) const { return size() == 0 ? true : false; }
  void reserve(size_type n) {
    if (n > max_size())
      throw(std::length_error("vector::reserve"));
    else if (n > capacity()) {
      pointer new_begin = _vallocate(n);
      size_type sz = size();
      copy(this->_begin, this->_end, new_begin);
      _vdeallocate();
      this->_begin = new_begin;
      this->_end = new_begin + sz;
      this->_end_capacity = new_begin + n;
    }
    // - implement
  }

  // * Element access
  reference operator[](size_type n) { return *(begin() + n); }
  const_reference operator[](size_type n) const { return *(begin() + n); }
  reference at(size_type n) {
    if (n >= size()) throw(std::out_of_range("vector::at"));
    return *(begin() + n);
  }
  const_reference at(size_type n) const {
    if (n >= size()) throw(std::out_of_range("vector::at"));
    return *(begin() + n);
  }
  reference front(void) { return *(begin()); }
  const_reference front(void) const { return *(begin()); }
  reference back(void) { return *(end()); }
  const_reference back(void) const { return *(end()); }
  // * modifiers

  void swap(vector &x) {
    allocator_type temp_alloc = get_allocator();
    pointer temp_begin = this->_begin;
    pointer temp_end = this->_end;
    pointer temp_cap = this->_end_capacity;

    this->_alloc = x.get_allocator();
    this->_begin = x._begin;
    this->_end = x._end;
    this->_end_capacity = x._end_capacity;

    x._alloc = temp_alloc;
    x._begin = temp_begin;
    x._end = temp_end;
    x._end_capacity = temp_cap;
  }
  void push_back(const T &x) {
    if (size() >= capacity()) reserve(recommend(size() + 1));
    this->_alloc.construct(this->_end++, x);
  }  // - impl
  void pop_back(void) {
    if (!empty()) this->_destruct_at_end(this->_end - 1);
  }
  iterator insert(iterator position, const T &x) {
    if (size() >= capacity()) reserve(size() + 1);
  }  // - impl
  // void insert(iterator position, size_type n, const T &x) {}
  // template <class InputIterator>
  // void insert(iterator position, InputIterator first, InputIterator last) {}
  iterator erase(iterator position) {
    difference_type pos = position - this->begin();
    pointer p = this->_begin + pos;
    __destruct_at_end(copy(make_iterator(p + 1), end(), make_iterator(p)));
    iterator r = make_iterator(p);
    return r;
  }
  iterator erase(iterator first, iterator last) {
    difference_type pos = first - begin();
    pointer p = this->_begin + pos;
    if (first != last)
      __destruct_at_end(
          copy(make_iterator(p + (last - first)), end(), make_iterator(p)));
    iterator r = make_iterator(p);
    return r;
  }
  void clear(void) { __destruct_at_end(begin()); }

  // // * Default Constructor
  // explicit vector(const Allocator &alloc = Allocator())
  //     : _alloc(alloc), _begin(nullptr), _end(nullptr),
  //     _end_capacity(nullptr){};
  // // * Fill Constructor
  // explicit vector(size_type n, const T &value = T(),
  //                 const Allocator &alloc = Allocator())
  //     : _alloc(alloc), _begin(nullptr), _end(nullptr),
  //     _end_capacity(nullptr)
  //     {
  //   _begin = _alloc.allocate(n);
  //   _end = _begin;
  //   _end_capacity = _begin + n;
  //   while (n--) _alloc.construct(_end++, value);
  // };
  // // * Range Constructor
  // template <class InputIterator>
  // vector(InputIterator first, InputIterator last,
  //        const Allocator &alloc = Allocator(),
  //        typename ft::enable_if<!ft::is_integral<InputIterator>::value,
  //                               InputIterator>::type * = nullptr)
  //     : _alloc(alloc), _begin(nullptr), _end(nullptr),
  //     _end_capacity(nullptr)
  //     {
  //   difference_type n = std::distance(first, last);
  //   _begin = _alloc.allocate(n);
  //   _end = _begin;
  //   _end_capacity = _begin + n;
  //   while (n--) _alloc.construct(_end++, *first++);
  // };
  // // * Copy Constructor
  // explicit vector(const vector<T, Allocator> &x)
  //     : _alloc(Allocator()),
  //       _begin(nullptr),
  //       _end(nullptr),
  //       _end_capacity(nullptr) {
  //   difference_type n = std::distance(x._begin, x._end_capacity);
  //   pointer x_end = x._end;
  //   _begin = _alloc.allocate(n);
  //   _end = _begin;
  //   _end_capacity = _begin + n;
  //   for (; x_end != x._begin; x_end--) _alloc.construct(_end++, *x_end);
  // }
  // // * Destructor
  // ~vector(void) {
  //   difference_type n = _begin - _end_capacity;
  //   pointer _last_element = _end;
  //   for (; _last_element != _begin; _last_element--)
  //     _alloc.destroy(_last_element);
  //   _alloc.deallocate(_begin, n);
  // };
  // // * Operator =
  // vector<T, Allocator> &operator=(const vector<T, Allocator> &x) {
  //   (void)x;
  //   return *this;
  // };

  // template <class InputIterator>
  // void assign(InputIterator first, InputIterator last);
  // void assign(size_type n, const T &u);
  // allocator_type get_allocator(void) const { return _alloc; };

  // // * iterator
  // iterator begin(void) { return _begin; };
  // const_iterator begin(void) const {
  //   return static_cast<const_pointer>(_begin);
  // };
  // iterator end(void) { return _end; };
  // const_iterator end(void) const { return _end; };
  // reverse_iterator rbegin(void) { return reverse_iterator(begin()); };
  // const_reverse_iterator rbegin(void) const {
  //   return const_reverse_iterator(begin());
  // };
  // reverse_iterator rend(void) { return reverse_iterator(end()); };
  // const_reverse_iterator rend(void) const {
  //   return const_reverse_iterator(end());
  // };

  // // * capacity
  // size_type size(void) const { return _end - _begin; };
  // size_type max_size(void) const { return _alloc().max_size(); };
  // void resize(size_type n, value_type val = value_type()) {
  //   size_type sz = this->size();
  //   if (n > this->max_size()) throw(std::length_error("vector::resize"));
  //   if (sz > n)
  //     for (; sz != n; sz--) _alloc.destroy(_end--);
  //   else
  //     for (; sz != n; sz++)
  //       _alloc.construct(_end++, val);  // not yet, after implement
  //       insert
  // };
  // size_type capacity(void) const { return _end_capacity - _begin; };
  // bool empty(void) const { return (size() == 0 ? true : false); };
  // void reserve(size_type n) {
  //   if (n > this->max_size())
  //     throw(std::length_error("vector::reserve"));  // not complete
  // };

  // // * element access
  // reference operator[](size_type n) { return *(_begin + n); };
  // const_reference operator[](size_type n) const { return *(_begin + n);
  // };
  // reference at(size_type n) {
  //   if (n >= this->size()) throw(std::out_of_range("vector::at"));
  //   return *(_begin + n);
  // };
  // const_reference at(size_type n) const {
  //   if (n >= this->size()) throw(std::out_of_range("vector::at"));
  //   return *(_begin + n);
  // };
  // reference front(void) { return *(_begin); };
  // const_reference front(void) const { return *_begin; };
  // reference back(void) { return *_end; };
  // const_reference back(void) const { return *_end; };

  // // * modifiers
  // void push_back(const T &x);
  // void pop_back(void);
  // iterator insert(iterator position, const T &x);
  // void insert(iterator position, size_type n, const T &x);
  // template <class InputIterator>
  // void insert(iterator position, InputIterator first, InputIterator
  // last);
  // iterator erase(iterator position);
  // iterator erase(iterator first, iterator last);
  // void swap(vector<T, Allocator> &);
  // void clear(void) {
  //   size_type n = _begin - _end;
  //   while (n--) _alloc.destroy(_end--);
  // };
};

template <class T, class Allocator>
void swap(vector<T, Allocator> &x, vector<T, Allocator> &y) {
  x.swap(y);
}

_END_NAMESPACE_FT

#endif