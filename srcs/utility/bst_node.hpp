#ifndef _FT_BST_NODE_HPP
#define _FT_BST_NODE_HPP

#define ROOT_NO_CHILD 1
#define ROOT_HAS_LEFT 2
#define ROOT_HAS_RIGHT 3
#define ROOT_HAS_BOTH 4
#define HAS_PARENT_NO_CHILD 5
#define HAS_PARENT_AND_LEFT 6
#define HAS_PARENT_AND_RIGHT 7
#define HAS_PARENT_AND_BOTH 8

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
  typedef typename allocator_type::size_type size_type;
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
      : _value(val), _parent(parent), _left(left), _right(right) {}

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
  void set_value(value_type val) { this->_value = val; }
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
  bool has_no_child(bst_node *node) {
    if (!node->has_left_child(node) && !node->has_right_child(node))
      return true;
    return false;
  }
  bool is_left_child(bst_node *node) {
    if (node == node->_parent->_left) return true;
    return false;
  }
  bool is_right_child(bst_node *node) {
    if (node == node->_parent->right) return true;
    return false;
  }
  int node_relation(bool parent, bool left, bool right) {
    if (!parent) {
      if (!left && !right)
        return ROOT_NO_CHILD;
      else if (left && right)
        return ROOT_HAS_BOTH;
      else if (left && !right)
        return ROOT_HAS_LEFT;
      else if (!left && right)
        return ROOT_HAS_RIGHT;
    } else {
      if (!left && !right)
        return HAS_PARENT_NO_CHILD;
      else if (left && right)
        return HAS_PARENT_AND_BOTH;
      else if (left && !right)
        return HAS_PARENT_AND_LEFT;
      else if (!left && right)
        return HAS_PARENT_AND_RIGHT;
    }
    return 0;
  }
  size_type get_size_right_subtree(bst_node *node) {
    size_type n = 0;
    bst_node *r_subtree = node->_right;
    while (r_subtree) {
      r_subtree = r_subtree->_right;
      n++;
    }
    return n;
  };
  size_type get_size_left_subtree(bst_node *node) {
    size_type n = 0;
    bst_node *l_subtree = node->_left;
    while (l_subtree) {
      l_subtree = l_subtree->_left;
      n++;
    }
    return n;
  };
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