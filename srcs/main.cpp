#include <time.h>

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

#include "config.hpp"
#include "container/map.hpp"
#include "container/stack.hpp"
#include "container/vector.hpp"
#include "type_traits/enable_if.hpp"
#include "type_traits/is_integral.hpp"
#include "utility/binary_search_tree.hpp"
#include "utility/bst_node.hpp"
#include "utility/make_pair.hpp"
#include "utility/nullptr_t.hpp"
#include "utility/pair.hpp"

#ifndef NAMESPACE
#define NAMESPACE ft
#endif

template <class T1, class T2, class Node, class Bst>
void print_pair(Bst* bst, Node* node, ft::pair<T1, T2> pr) {
  int bst_index = 0;
  std::cout << "[" << ++bst_index << "] key : " << pr.first << "  |  ";
  std::cout << "val : " << pr.second;
  if (node->get_parent_node())
    std::cout << "  | [parent key] : "
              << node->get_parent_node()->get_value_ref().first;
  else
    std::cout << "  | [has no parent]";
  if (node->get_left_node())
    std::cout << "  | [left child key] : "
              << node->get_left_node()->get_value_ref().first;
  else
    std::cout << "  | [no left child]";
  if (node->get_right_node())
    std::cout << "  | [right child key] : "
              << node->get_right_node()->get_value_ref().first;
  else
    std::cout << "  | [no right child]";
  if (node == bst->get_root()) std::cout << "  <- this is root node.";
  std::cout << std::endl;
}

template <class Node>
void print2DUtil(Node* root, int space) {
  if (root == NULL) return;

  space += 10;

  print2DUtil(root->get_right_node(), space);

  std::cout << std::endl;
  for (int i = 10; i < space; i++) {
    std::cout << " ";
  }

  std::cout << root->get_value_ref().first << std::endl;

  print2DUtil(root->get_left_node(), space);
}

template <class Node>
void print2D(Node* root) {
  int num = 0;
  print2DUtil(root, num);
}

template <class T>
void print_element(T& vector) {
  int index = 0;
  typename T::iterator beg = vector.begin();
  typename T::iterator end = vector.end();
  if (vector.size() > 0) {
    while (beg != end) {
      std::cout << "[" << index << "] ";
      std::cout << *beg << " ";
      beg++;
      index++;
    }
    std::cout << std::endl;
  } else if (vector.size() == 0)
    std::cout << "!!!! empty !!!!" << std::endl;
}

template <class T>
void print_vector(T& vector) {
  time_t _start, _end;

  _start = clock();
  T back_up(vector);
  typename T::iterator beg = vector.begin();
  // typename T::iterator end = vector.end();
  std::cout << "---------------------" << std::endl;
  if (beg.base()) {
    print_element(vector);
    if (vector.size() > 2) {
      std::cout << "pop_back() last element : " << vector.back() << std::endl;
      /* --------------------------- POP_BACK --------------------------- */
      vector.pop_back();
      print_element(vector);
    }
  }
  /* ------------------------------ AT ------------------------------ */
  std::cout << "at[" << vector.size() / 2
            << "] : " << vector.at(vector.size() / 2) << std::endl;
  /* ---------------------------- INSERT ---------------------------- */
  std::cout << "insert 5, 777 element before begin()" << std::endl;
  vector.insert(vector.begin(), 5, 777);
  print_element(vector);
  std::cout << "insert 1, 777 element before end()" << std::endl;
  vector.insert(vector.end(), 777);
  print_element(vector);
  std::cout << "range insert other object before begin()" << std::endl;
  vector.insert(vector.begin(), back_up.begin(), back_up.end());
  print_element(vector);
  /* ----------------------------- FRONT ---------------------------- */
  std::cout << "front : " << vector.front() << std::endl;
  /* ----------------------------- BACK ----------------------------- */
  std::cout << "back : " << vector.back() << std::endl;

  /* ----------------------------- SIZE ----------------------------- */
  std::cout << "size : " << vector.size() << std::endl;
  /* --------------------------- CAPACITY --------------------------- */
  std::cout << "capacity : " << vector.capacity() << std::endl;
  /* --------------------------- MAX_SIZE --------------------------- */
  std::cout << "max_size : " << vector.max_size() << std::endl;
  /* ----------------------------- EMPTY ---------------------------- */
  std::cout << "is_empty : " << vector.empty() << std::endl;
  std::cout << "# reserve (now capacity * 2)" << std::endl;
  std::cout << "before cap : " << vector.capacity() << std::endl;
  vector.reserve(vector.capacity() * 2);
  std::cout << "after cap : " << vector.capacity() << std::endl;
  std::cout << "# erase first element" << std::endl;
  vector.erase(vector.begin());
  print_element(vector);
  std::cout << "# range erase -> erase begin to end" << std::endl;
  vector.erase(vector.begin(), vector.end());
  print_element(vector);
  std::cout << "# swap with back_up vector" << std::endl;
  vector.swap(back_up);
  print_element(vector);
  std::cout << "# clear this vector" << std::endl;
  vector.clear();
  print_element(vector);
  _end = clock();
  std::cout << "# time report" << std::endl;
  std::cout << _end - _start << "ms" << std::endl;
  std::cout << "---------------------" << std::endl;
}

void vector_test() {
  /* ------------------------ CONSTRUCT TEST ------------------------ */
  int count = 20;
  ft::vector<int> one(10, 1);
  std::vector<int> one_origin(10, 1);
  ft::vector<int> two;
  std::vector<int> two_origin;
  /* ----------------------- PUSH_BACK ELEMENT ---------------------- */
  while (count--) {
    srand(clock());
    int elem = rand() % 100;
    two.push_back(elem);
    two_origin.push_back(elem);
  }
  /* ------------------------ RANGE_CONSTRUCT ----------------------- */
  ft::vector<int> three(two.begin(), two.end());
  std::vector<int> three_origin(two_origin.begin(), two_origin.end());
  /* ------------------------ COPY_CONSTRUCT ------------------------ */
  ft::vector<int> three_copy(three);
  std::vector<int> three_origin_copy(three_origin);
  /* ------------------------- PRINT result ------------------------- */
  std::cout << "***************************" << std::endl;
  std::cout << "(test 1)" << std::endl;
  std::cout << "_________________FT" << std::endl;
  print_vector(one);
  std::cout << "_________________STD" << std::endl;
  print_vector(one_origin);
  std::cout << "***************************" << std::endl;
  std::cout << "***************************" << std::endl;
  std::cout << "(test 2)" << std::endl;
  std::cout << "_________________FT" << std::endl;
  print_vector(two);
  std::cout << "_________________STD" << std::endl;
  print_vector(two_origin);
  std::cout << "***************************" << std::endl;
  std::cout << "***************************" << std::endl;
  std::cout << "(test 3)" << std::endl;
  std::cout << "_________________FT" << std::endl;
  print_vector(three);
  std::cout << "_________________STD" << std::endl;
  print_vector(three_origin);
  std::cout << "***************************" << std::endl;
  std::cout << "***************************" << std::endl;
  std::cout << "(test 4)" << std::endl;
  std::cout << "_________________FT" << std::endl;
  print_vector(three_copy);
  std::cout << "_________________STD" << std::endl;
  print_vector(three_origin_copy);
  std::cout << "***************************" << std::endl;
  system("leaks a.out");
}

void vector_rv() {
  std::cout << "----------------------------------" << std::endl;
  std::cout << "__________vector reverse iterator" << std::endl;
  int count = 20;
  ft::vector<int> v;
  std::vector<int> _v;
  /* ----------------------- PUSH_BACK ELEMENT ---------------------- */
  while (count--) {
    srand(clock());
    int elem = rand() % 100;
    v.push_back(elem);
    _v.push_back(elem);
  }

  ft::vector<int>::reverse_iterator rv = v.rbegin();
  ft::vector<int>::iterator itv = v.begin();
  std::vector<int>::reverse_iterator rv1 = _v.rbegin();
  std::vector<int>::iterator itv1 = _v.begin();
  std::cout << "__FT" << std::endl;
  std::cout << "Reverse" << std::endl;

  while (rv != v.rend()) {
    std::cout << *rv << " ";
    rv++;
  }
  std::cout << std::endl;
  std::cout << "Normal" << std::endl;
  while (itv != v.end()) {
    std::cout << *itv << " ";
    itv++;
  }
  std::cout << std::endl;
  std::cout << "__STD" << std::endl;
  std::cout << "Reverse" << std::endl;
  while (rv1 != _v.rend()) {
    std::cout << *rv1 << " ";
    rv1++;
  }
  std::cout << std::endl;
  std::cout << "Normal" << std::endl;
  while (itv1 != _v.end()) {
    std::cout << *itv1 << " ";
    itv1++;
  }
  std::cout << std::endl;
  std::cout << "---------------------------------" << std::endl;
}
void vector_relation() {
  time_t _start, _end;
  std::cout << "----------------------------------" << std::endl;
  std::cout << "__________vector relation operator" << std::endl;
  int count = 20;
  ft::vector<int> v;
  ft::vector<int> v_comp;
  std::vector<int> _v;
  std::vector<int> _v_comp;
  /* ----------------------- PUSH_BACK ELEMENT ---------------------- */
  while (count--) {
    srand(clock());
    int elem = rand() % 100;
    v.push_back(elem);
    v_comp.push_back(elem);
    _v.push_back(elem);
    _v_comp.push_back(elem);
  }
  ft::vector<int> t(10, 1);
  std::vector<int> _t(10, 1);
  _start = clock();
  std::cout << "__FT" << std::endl;
  std::cout << "v     : ";
  print_element(v);
  std::cout << "v_comp: ";
  print_element(v_comp);
  std::cout << "t     : ";
  print_element(t);
  std::cout << "v == v_comp : " << (v == v_comp) << std::endl;
  std::cout << "v != v_comp : " << (v != v_comp) << std::endl;
  std::cout << "v <  v_comp : " << (v < v_comp) << std::endl;
  std::cout << "v <= v_comp : " << (v <= v_comp) << std::endl;
  std::cout << "v >  v_comp : " << (v > v_comp) << std::endl;
  std::cout << "v >= v_comp : " << (v >= v_comp) << std::endl;
  std::cout << "-------------------------" << std::endl;
  std::cout << "t == v_comp : " << (t == v_comp) << std::endl;
  std::cout << "t != v_comp : " << (t != v_comp) << std::endl;
  std::cout << "t <  v_comp : " << (t < v_comp) << std::endl;
  std::cout << "t <= v_comp : " << (t <= v_comp) << std::endl;
  std::cout << "t >  v_comp : " << (t > v_comp) << std::endl;
  std::cout << "t >= v_comp : " << (t >= v_comp) << std::endl;
  _end = clock();
  std::cout << "# time report" << std::endl;
  std::cout << _end - _start << "ms" << std::endl;
  std::cout << "-------------------------" << std::endl;
  _start = clock();
  std::cout << "__STD" << std::endl;
  std::cout << "_v     : ";
  print_element(_v);
  std::cout << "_v_comp: ";
  print_element(_v_comp);
  std::cout << "_t     : ";
  print_element(_t);
  std::cout << "_v == _v_comp : " << (_v == _v_comp) << std::endl;
  std::cout << "_v != _v_comp : " << (_v != _v_comp) << std::endl;
  std::cout << "_v <  _v_comp : " << (_v < _v_comp) << std::endl;
  std::cout << "_v <= _v_comp : " << (_v <= _v_comp) << std::endl;
  std::cout << "_v >  _v_comp : " << (_v > _v_comp) << std::endl;
  std::cout << "_v >= _v_comp : " << (_v >= _v_comp) << std::endl;
  std::cout << "-------------------------" << std::endl;
  std::cout << "_t == _v_comp : " << (_t == _v_comp) << std::endl;
  std::cout << "_t != _v_comp : " << (_t != _v_comp) << std::endl;
  std::cout << "_t <  _v_comp : " << (_t < _v_comp) << std::endl;
  std::cout << "_t <= _v_comp : " << (_t <= _v_comp) << std::endl;
  std::cout << "_t >  _v_comp : " << (_t > _v_comp) << std::endl;
  std::cout << "_t >= _v_comp : " << (_t >= _v_comp) << std::endl;
  _end = clock();
  std::cout << "# time report" << std::endl;
  std::cout << _end - _start << "ms" << std::endl;
  std::cout << "-------------------------" << std::endl;
}

template <class T>
void print_map(T& map) {
  typename T::iterator beg = map.begin();
  typename T::iterator end = map.end();
  if (map.empty()) {
    std::cout << "!!!!!!!!! empty map !!!!!!!!" << std::endl;
    return;
  }
  while (beg != end) {
    std::cout << "[" << beg->first << " " << beg->second << "] ";
    beg++;
  }
  std::cout << std::endl;
}
template <class T>
void print_map_rv(T& map) {
  typename T::reverse_iterator beg = map.rbegin();
  typename T::reverse_iterator end = map.rend();
  if (map.empty()) {
    std::cout << "!!!!!!!!! empty map !!!!!!!!" << std::endl;
    return;
  }
  while (beg != end) {
    std::cout << "[" << beg->first << " " << beg->second << "] ";
    beg++;
  }
  std::cout << std::endl;
}

template <class T>
void map_insert_test(T& map, int cnt) {
  time_t _start, _end;
  _start = clock();
  while (cnt--) {
    srand(clock());
    int range = 122 - 97 + 1;
    char key = rand() % range + 97;
    int value = rand() % 30;
    typename T::value_type p(key, value);
    map.insert(p);
  }
  print_map(map);
  _end = clock();
  std::cout << "# time report" << std::endl;
  std::cout << _end - _start << "ms" << std::endl;
  std::cout << std::endl;
}

template <class T>
void map_capa_test(T& map) {
  std::cout << "[ empty    ] : " << map.empty() << std::endl;
  std::cout << "[ size     ] : " << map.size() << std::endl;
  std::cout << "[ max size ] : " << map.max_size() << std::endl;
  std::cout << std::endl;
}

template <class T>
void map_count_test(T& map, typename T::key_type key) {
  std::cout << "[Count Test]" << std::endl;
  std::cout << std::endl;
  time_t start, end;
  start = clock();
  typename T::size_type sz = map.count(key);
  std::cout << "[ count key ] : " << key << std::endl;
  std::cout << "[ result    ] : " << sz << std::endl;
  end = clock();
  std::cout << "[ time      ] : " << end - start << "ms" << std::endl;
  std::cout << std::endl;
}

template <class T>
void map_bound_test(T& map, typename T::key_type key) {
  std::cout << "[Bound Test]" << std::endl;
  std::cout << std::endl;
  time_t start, end;
  start = clock();
  typename T::iterator it = map.lower_bound(key);
  if (it != map.end()) {
    std::cout << "[ bound key ] : " << key << std::endl;
    std::cout << "[ lower     ] : " << it->first << std::endl;
  } else {
    std::cout << "[ bound key ] : " << key << std::endl;
    std::cout << "[ lower    ] : "
              << "can't find" << std::endl;
  }
  typename T::iterator itu = map.upper_bound(key);
  if (itu != map.end()) {
    std::cout << "[ bound key ] : " << key << std::endl;
    std::cout << "[ upper     ] : " << it->first << std::endl;
  } else {
    std::cout << "[ bound key ] : " << key << std::endl;
    std::cout << "[ upper    ] : "
              << "can't find" << std::endl;
  };
  end = clock();
  std::cout << "[ time      ] : " << end - start << "ms" << std::endl;
  std::cout << std::endl;
}

template <class T>
void map_find_test(T& map, typename T::key_type key) {
  std::cout << "[Find Test]" << std::endl;
  std::cout << std::endl;
  time_t start, end;
  start = clock();
  typename T::iterator it = map.find(key);
  if (it != map.end()) {
    std::cout << "[ find key ] : " << key << std::endl;
    std::cout << "[ result   ] : " << it->first << " , " << it->second
              << std::endl;
  } else {
    std::cout << "[ find key ] : " << key << std::endl;
    std::cout << "[ result   ] : not found" << std::endl;
  }
  end = clock();
  std::cout << "[ time     ] : " << end - start << "ms" << std::endl;
  std::cout << std::endl;
}

template <class T>
void map_erase_test(T& map, typename T::key_type key) {
  time_t start, end;
  start = clock();
  std::cout << "[ Erase Test ]" << std::endl;
  std::cout << "# before erase" << std::endl;
  print_map(map);
  map_capa_test(map);
  std::cout << "# case 1: erase begin()" << std::endl;
  map.erase(map.begin());
  print_map(map);
  map_capa_test(map);
  std::cout << "# case 2: erase with key" << std::endl;
  map.erase(key);
  print_map(map);
  map_capa_test(map);
  std::cout << "# case 3: erase with range begin() to end()" << std::endl;
  map.erase(map.begin(), map.end());
  print_map(map);
  map_capa_test(map);
  end = clock();
  std::cout << "[ time ] : " << end - start << std::endl;
}

template <class T>
void map_swap_test(T& m1, T& m2) {
  time_t start, end;
  start = clock();
  std::cout << "[Swap test]" << std::endl;
  std::cout << "____before swap" << std::endl;
  print_map(m1);
  map_capa_test(m1);
  print_map(m2);
  map_capa_test(m2);
  m1.swap(m2);
  std::cout << "____after swap" << std::endl;
  print_map(m1);
  map_capa_test(m1);
  print_map(m2);
  map_capa_test(m2);
  end = clock();
  std::cout << "[ time ] : " << end - start << std::endl;
}

template <class T>
void map_clear_test(T& map) {
  time_t start, end;
  start = clock();
  std::cout << "[clear test]" << std::endl;
  std::cout << "____before clear" << std::endl;
  print_map(map);
  map_capa_test(map);
  map.clear();
  std::cout << "____after clear" << std::endl;
  print_map(map);
  map_capa_test(map);
  end = clock();
  std::cout << "[ time ] : " << end - start << std::endl;
}

template <class T>
void map_access_test(T& map) {
  std::cout << "[ map access test]" << std::endl;
  map['a'] = 1;
  // map['b'] = 2;
  // map['c'] = 3;
  // map['z'] = 5;
  // map['f'] = 23;
  // map['g'] = 13;
  // map['x'] = 124;
  print_map(map);
  // map_capa_test(map);
  std::cout << std::endl;
}

void map_test() {
  int cnt = 10;
  int range = 122 - 97 + 1;
  ft::map<char, int> m;
  std::map<char, int> _m;
  std::cout << "[ same value insert ]" << std::endl;
  while (cnt--) {
    srand(clock());
    char key = rand() % range + 97;
    int value = rand() % 30;
    ft::pair<char, int> p = ft::make_pair<char, int>(key, value);
    std::pair<char, int> _p = std::make_pair<char, int>(key, value);
    m.insert(p);
    _m.insert(_p);
  }
  std::cout << "FT  : ";
  print_map(m);
  std::cout << std::endl;
  map_capa_test(m);
  std::cout << "STD : ";
  print_map(_m);
  std::cout << std::endl;
  map_capa_test(_m);
  std::cout << std::endl << "[ print with reverse_iterator ]" << std::endl;
  std::cout << "FT  : ";
  print_map_rv(m);
  std::cout << "STD : ";
  print_map_rv(_m);
  std::cout << std::endl << "[ diff value insert ]" << std::endl;
  ft::map<char, int> m1;
  std::map<char, int> _m1;
  std::cout << "FT  : ";
  map_insert_test(m1, 20);
  std::cout << "STD : ";
  map_insert_test(_m1, 20);
  srand(clock());
  char target = rand() % range + 97;
  std::cout << "__FT" << std::endl;
  map_find_test(m, target);
  std::cout << "__STD" << std::endl;
  map_find_test(_m, target);
  std::cout << "__FT" << std::endl;
  map_count_test(m, target);
  std::cout << "__STD" << std::endl;
  map_count_test(_m, target);
  std::cout << "__FT" << std::endl;
  map_bound_test(m, target);
  std::cout << "__STD" << std::endl;
  map_bound_test(_m, target);

  std::cout << "[ equal range test ]" << std::endl;
  ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> er;
  er = m.equal_range(target);
  std::cout << "__FT" << std::endl;
  if (er.first != m.end()) {
    std::cout << er.first->first << " , " << er.first->second << std::endl;
    std::cout << er.second->first << " , " << er.second->second << std::endl;
  } else {
    std::cout << "not found" << std::endl;
  }
  std::pair<std::map<char, int>::iterator, std::map<char, int>::iterator> _er;
  _er = _m.equal_range(target);
  std::cout << "__STD" << std::endl;
  if (_er.first != _m.end()) {
    std::cout << _er.first->first << " , " << _er.first->second << std::endl;
    std::cout << _er.second->first << " , " << _er.second->second << std::endl;
  } else {
    std::cout << "not found" << std::endl;
  }
  std::cout << "__FT" << std::endl;
  map_erase_test(m, target);
  std::cout << "__STD" << std::endl;
  map_erase_test(_m, target);
  std::cout << "__FT" << std::endl;
  map_swap_test(m, m1);
  std::cout << "__STD" << std::endl;
  map_swap_test(_m, _m1);
  std::cout << "__FT" << std::endl;
  map_clear_test(m);
  std::cout << "__STD" << std::endl;
  map_clear_test(_m);
  std::cout << "__FT" << std::endl;
  map_access_test(m);
  std::cout << "__STD" << std::endl;
  map_access_test(_m);
  system("leaks a.out");
}

int main(void) {
  vector_test();
  vector_rv();
  vector_relation();
  map_test();
}