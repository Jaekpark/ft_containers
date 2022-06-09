#ifndef _FT_BST_NODE_HPP
#define _FT_BST_NODE_HPP

#include <memory>

#include "../config.hpp"

_BEGIN_NAMESPACE_FT
template <class T, class Allocator = std::allocator<T> >
struct bst_node {
  /* ---------------------------------------------------------------- */
  /*                           TYPE ALIASES                           */
  /* ---------------------------------------------------------------- */

 public:
  typedef T value_type;
  typedef Allocator allocator_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;

  /* ---------------------------------------------------------------- */
  /*                            ATTRIBUTES                            */
  /* ---------------------------------------------------------------- */

 private:
  value_type _value;
  bst_node *_parent;
  bst_node *_left;
  bst_node *_right;

 public:
  /* ---------------------- DEFAULT CONSTRUCTOR --------------------- */
  bst_node(void)
      : _value(), _parent(nullptr), _left(nullptr), _right(nullptr) {}

  /* -------------------- CONSTRUCTOR OVERLOADING ------------------- */
  bst_node(bst_node *parent = nullptr, bst_node *left = nullptr,
           bst_node *right = nullptr)
      : _value(), _parent(parent), _left(left), _right(right) {}

  bst_node(const value_type &val, bst_node *parent = nullptr,
           bst_node *left = nullptr, bst_node *right = nullptr)
      : _value(value), _parent(parent), _left(left), _right(right) {}

  /* ----------------------- COPY CONSTRUCTOR ----------------------- */
  bst_node(const bst_node &node)
      : _value(node.get_value()),
        _parent(node.get_parent_node()),
        _left(node.get_left_node()),
        _right(node.get_right_node()) {}

  /* ---------------- ASSIGNMENT OPERATOR OVERLOADING --------------- */
  bst_node &operator=(const bst_node &node) {
    if (*this != node) {
      set_value(node.get_value());
      set_parent_node(node.get_parent_node());
      set_left_node(node.get_left_node());
      set_right_node(node.get_right_node());
    }
    return *this;
  }

  /* -------------------------- DESTRUCTOR -------------------------- */
  ~bst_node(void) {}

  /* ---------------------------------------------------------------- */
  /*                         MEMBER FUNCTIONS                         */
  /* ---------------------------------------------------------------- */
  value_type get_value(void) { return _value; }
  value_type &get_value_ref(void) { return _value; }
  void set_value(value_type &val) { this->_value = val; }
  bst_node *get_parent_node(void) { return _parent; }
  void set_parent_node(bst_node *node) { this->_parent = node; }
  bst_node *get_left_node(void) { return _left; }
  void set_left_node(bst_node *node) { this->_left = node; }
  bst_node *get_right_node(void) { return _right; }
  void set_right_node(bst_node *node) { this->_right = node; }
  bool has_parent(bst_node *node) {
    if (node->_parent) return true;
    return false;
  }
  bool has_left_child(bst_node *node) {
    if (node->_left) return true;
    return false;
  }
  bool has_right_child(bst_node *node) {
    if (node->_right) return true;
    return false;
  }
};

/* ---------------------------------------------------------------- */
/*                         RELATION OPERATOR                        */
/* ---------------------------------------------------------------- */
template <class T>
bool operator==(const bst_node<T> &lhs, const bst_node<T> &rhs) {
  return lhs.get_value_ref() == rhs.get_value_ref();
}
template <class T>
bool operator!=(const bst_node<T> &lhs, const bst_node<T> &rhs) {
  return !(lhs.get_value_ref() == rhs.get_value_ref());
}
template <class T>
bool operator<(const bst_node<T> &lhs, const bst_node<T> &rhs) {
  return lhs.get_value_ref() < rhs.get_value_ref();
}
template <class T>
bool operator>(const bst_node<T> &lhs, const bst_node<T> &rhs) {
  return rhs.get_value_ref() < lhs.get_value_ref();
}
template <class T>
bool operator>=(const bst_node<T> &lhs, const bst_node<T> &rhs) {
  return !(lhs < rhs);
}
template <class T>
bool operator<=(const bst_node<T> &lhs, const bst_node<T> &rhs) {
  return !(rhs < lhs);
}
_END_NAMESPACE_FT

#endif