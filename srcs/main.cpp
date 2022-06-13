#include <time.h>

#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <stack>
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
#include "utility/utility.hpp"

#define LINE_LENGTH 100
#define TYPE_WIDTH 15
#ifndef NAMESPACE
#define NAMESPACE ft
#endif

// template <class T1, class T2, class Node, class Bst>
// void print_pair(Bst* bst, Node* node, ft::pair<T1, T2> pr) {
//   int bst_index = 0;
//   std::cout << "[" << ++bst_index << "] key : " << pr.first << "  |  ";
//   std::cout << "val : " << pr.second;
//   if (node->get_parent_node())
//     std::cout << "  | [parent key] : "
//               << node->get_parent_node()->get_value_ref().first;
//   else
//     std::cout << "  | [has no parent]";
//   if (node->get_left_node())
//     std::cout << "  | [left child key] : "
//               << node->get_left_node()->get_value_ref().first;
//   else
//     std::cout << "  | [no left child]";
//   if (node->get_right_node())
//     std::cout << "  | [right child key] : "
//               << node->get_right_node()->get_value_ref().first;
//   else
//     std::cout << "  | [no right child]";
//   if (node == bst->get_root()) std::cout << "  <- this is root node.";
//   std::cout << std::endl;
// }

// template <class Node>
// void print2DUtil(Node* root, int space) {
//   if (root == NULL) return;

//   space += 10;

//   print2DUtil(root->get_right_node(), space);

//   std::cout << std::endl;
//   for (int i = 10; i < space; i++) {
//     std::cout << " ";
//   }

//   std::cout << root->get_value_ref().first << std::endl;

//   print2DUtil(root->get_left_node(), space);
// }

// template <class Node>
// void print2D(Node* root) {
//   int num = 0;
//   print2DUtil(root, num);
// }

void print_header(std::string title, size_t line_len = LINE_LENGTH,
                  char divider = '-') {
  size_t len = title.length();
  std::transform(title.begin(), title.end(), title.begin(), ::toupper);
  std::cout << std::setw(line_len) << std::setfill(divider) << "" << std::endl;
  std::cout << std::setw(line_len / 2 + (len / 2)) << std::setfill(' ') << title
            << std::endl;
  std::cout << std::setw(line_len) << std::setfill(divider) << "" << std::endl;
  std::cout << std::setfill(' ');
  std::cout << std::endl;
}

void print_line(std::string msg, size_t line_len = LINE_LENGTH) {
  size_t len = msg.length();
  std::transform(msg.begin(), msg.end(), msg.begin(), ::toupper);
  std::cout << std::setw(line_len / 2 + (len / 2)) << msg << std::endl;
}

void print_log(std::string log) {
  std::cout << std::endl << "# " << log << std::endl << std::endl;
}

void print_type(std::string type, size_t width = TYPE_WIDTH) {
  std::cout << "[";
  std::cout << std::setw(width) << type;
  std::cout << " ] : ";
}

void print_namespace(bool is_ft) {
  if (is_ft)
    print_header("FT", 80, '-');
  else
    print_header("STD", 80, '-');
}

void print_test_name(std::string name, size_t line_len = LINE_LENGTH) {
  size_t len = name.length();
  std::transform(name.begin(), name.end(), name.begin(), ::toupper);
  std::cout << "/*";
  std::cout << std::setw((line_len / 2 - (len / 2)) - 2) << std::setfill('-')
            << "";
  std::cout << name;
  std::cout << std::setw((line_len / 2 - (len / 2)) - 2) << std::setfill('-')
            << "";
  std::cout << "*/" << std::endl;
  std::cout << std::setfill(' ');
  std::cout << std::endl;
}

template <class T>
void print_element(T& vector) {
  int index = 0;
  typename T::iterator beg = vector.begin();
  typename T::iterator end = vector.end();
  print_type("elements");
  if (vector.size() > 0) {
    while (beg != end) {
      std::cout << "[" << index << "] ";
      std::cout << *beg << " ";
      beg++;
      index++;
    }
    std::cout << std::endl;
  } else if (vector.size() == 0)
    std::cout << "empty" << std::endl;
  std::cout << std::endl;
}

void print_divider(size_t line_len = LINE_LENGTH, char divider = '-') {
  std::cout << std::setfill(' ') << std::endl;
  std::cout << std::setw(line_len) << std::setfill(divider) << "" << std::endl;
  std::cout << std::setfill(' ') << std::endl;
}
template <class T>
void print_vector_capacity(T& vector) {
  std::stringstream ss;
  if (!vector.empty()) {
    ss << "at[" << vector.size() / 2 << "]";
    print_type(ss.str());
    std::cout << vector.at(vector.size() / 2) << std::endl;
  }
  /* ----------------------------- FRONT ---------------------------- */
  print_type("front");
  std::cout << vector.front() << std::endl;
  /* ----------------------------- BACK ----------------------------- */
  print_type("back");
  std::cout << vector.back() << std::endl;
  /* ----------------------------- SIZE ----------------------------- */
  print_type("size");
  std::cout << vector.size() << std::endl;
  /* --------------------------- CAPACITY --------------------------- */
  print_type("capacity");
  std::cout << vector.capacity() << std::endl;
  /* --------------------------- MAX_SIZE --------------------------- */
  print_type("max_size");
  std::cout << vector.max_size() << std::endl;
  /* ----------------------------- EMPTY ---------------------------- */
  print_type("is_empty");
  std::cout << vector.empty() << std::endl;
  /* ---------------------------------------------------------------- */
}

template <class T>
void print_vector(T& vector) {
  time_t _start, _end;
  _start = clock();
  T back_up(vector);
  typename T::iterator beg = vector.begin();
  print_divider();
  if (beg.base()) {
    print_log("default");
    print_element(vector);
    print_vector_capacity(vector);
    if (vector.size() > 1) {
      print_log("pop_back() last element");
      /* --------------------------- POP_BACK --------------------------- */
      vector.pop_back();
      print_element(vector);
      print_vector_capacity(vector);
    }
  }
  /* ---------------------------- INSERT ---------------------------- */
  print_log("insert 5, 777 elements before begin()");
  vector.insert(vector.begin(), 5, 777);
  print_element(vector);
  print_vector_capacity(vector);
  print_log("insert 1, 777 elements before end()");
  vector.insert(vector.end(), 777);
  print_element(vector);
  print_vector_capacity(vector);
  print_log("range insert other object before begin()");
  vector.insert(vector.begin(), back_up.begin(), back_up.end());
  print_element(vector);
  print_vector_capacity(vector);
  print_log("reserve (now capacity * 2)");
  print_type("before cap");
  std::cout << vector.capacity() << std::endl;
  print_type("after cap");
  vector.reserve(vector.capacity() * 2);
  std::cout << vector.capacity() << std::endl;
  print_log("erase first element");
  vector.erase(vector.begin());
  print_element(vector);
  print_vector_capacity(vector);
  print_log("range erase -> erase begin to end");
  vector.erase(vector.begin(), vector.end());
  print_element(vector);
  print_vector_capacity(vector);
  print_log("swap with back_up vector");
  vector.swap(back_up);
  print_element(vector);
  print_vector_capacity(vector);
  print_log("clear this vector");
  vector.clear();
  print_element(vector);
  print_vector_capacity(vector);
  _end = clock();
  print_log("time report");
  print_type("time");
  std::cout << _end - _start << "ms" << std::endl;
}

void vector_test() {
  print_header("vector");
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
  print_test_name("vector member functions");
  print_divider();
  print_line("case 1 : FT");
  print_vector(one);
  print_divider();
  print_line("case 1 : STD");
  print_vector(one_origin);
  print_divider();
  print_line("case 2 : FT");
  print_vector(two);
  print_divider();
  print_line("case 2 : STD");
  print_vector(two_origin);
  print_divider();
  print_line("case 3 : FT");
  print_vector(three);
  print_divider();
  print_line("case 3 : STD");
  print_vector(three_origin);
  print_divider();
  print_line("case 4 : FT");
  print_vector(three_copy);
  print_divider();
  print_line("case 4 : STD");
  print_vector(three_origin_copy);
}

void vector_rv() {
  print_divider();
  print_test_name("vector reverse iterator");
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
  print_log("reverse iterator");
  while (rv != v.rend()) {
    std::cout << *rv << " ";
    rv++;
  }
  std::cout << std::endl;
  print_log("normal iterator");
  while (itv != v.end()) {
    std::cout << *itv << " ";
    itv++;
  }
  std::cout << std::endl;
  print_log("reverse iterator");
  while (rv1 != _v.rend()) {
    std::cout << *rv1 << " ";
    rv1++;
  }
  std::cout << std::endl;
  print_log("normal iterator");
  while (itv1 != _v.end()) {
    std::cout << *itv1 << " ";
    itv1++;
  }
  std::cout << std::endl;
  print_divider();
}
void vector_relation() {
  time_t _start, _end;
  print_divider();
  print_test_name("vector relation operator");
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
  print_line("FT");
  print_divider();
  print_type("v");
  print_element(v);
  print_type("v_comp");
  print_element(v_comp);
  print_type("t");
  print_element(t);
  print_type("v == v_comp");
  std::cout << (v == v_comp) << std::endl;
  print_type("v != v_comp");
  std::cout << (v != v_comp) << std::endl;
  print_type("v <  v_comp");
  std::cout << (v < v_comp) << std::endl;
  print_type("v <= v_comp");
  std::cout << (v <= v_comp) << std::endl;
  print_type("v >  v_comp");
  std::cout << (v > v_comp) << std::endl;
  print_type("v >= v_comp");
  std::cout << (v >= v_comp) << std::endl;
  print_divider();
  print_type("t == v_comp");
  std::cout << (t == v_comp) << std::endl;
  print_type("t != v_comp");
  std::cout << (t != v_comp) << std::endl;
  print_type("t <  v_comp");
  std::cout << (t < v_comp) << std::endl;
  print_type("t <= v_comp");
  std::cout << (t <= v_comp) << std::endl;
  print_type("t >  v_comp");
  std::cout << (t > v_comp) << std::endl;
  print_type("t >= v_comp");
  std::cout << (t >= v_comp) << std::endl;
  _end = clock();
  print_log("time report");
  print_type("time");
  std::cout << _end - _start << "ms" << std::endl;
  print_divider();
  _start = clock();
  print_line("STD");
  print_divider();
  print_type("_v");
  print_element(_v);
  print_type("_v_comp");
  print_element(_v_comp);
  print_type("_t");
  print_element(_t);
  print_type("_v == _v_comp");
  std::cout << (_v == _v_comp) << std::endl;
  print_type("_v != _v_comp");
  std::cout << (_v != _v_comp) << std::endl;
  print_type("_v <  _v_comp");
  std::cout << (_v < _v_comp) << std::endl;
  print_type("_v <= _v_comp");
  std::cout << (_v <= _v_comp) << std::endl;
  print_type("_v >  _v_comp");
  std::cout << (_v > _v_comp) << std::endl;
  print_type("_v >= _v_comp");
  std::cout << (_v >= _v_comp) << std::endl;
  print_divider();
  print_type("_t == _v_comp");
  std::cout << (_t == _v_comp) << std::endl;
  print_type("_t != _v_comp");
  std::cout << (_t != _v_comp) << std::endl;
  print_type("_t <  _v_comp");
  std::cout << (_t < _v_comp) << std::endl;
  print_type("_t <= _v_comp");
  std::cout << (_t <= _v_comp) << std::endl;
  print_type("_t >  _v_comp");
  std::cout << (_t > _v_comp) << std::endl;
  print_type("_t >= _v_comp");
  std::cout << (_t >= _v_comp) << std::endl;
  _end = clock();
  print_log("time report");
  print_type("time");
  std::cout << _end - _start << "ms" << std::endl;
  print_divider();
}

template <class T>
void print_map(T& map) {
  typename T::iterator beg = map.begin();
  typename T::iterator end = map.end();
  // if (map.empty()) {
  //   std::cout << "!!!!!!!!! empty map !!!!!!!!" << std::endl;
  //   return;
  // }
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
  } else
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
  map['b'] = 2;
  map['c'] = 3;
  map['z'] = 5;
  map['f'] = 23;
  map['g'] = 13;
  map['x'] = 124;
  print_map(map);
  map_capa_test(map);
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

  ft::map<char, int> alice;
  std::map<char, int> _alice;
  cnt = 10;
  while (cnt--) {
    srand(clock());
    char key1 = rand() % range + 97;
    int value1 = rand() % 30;
    ft::pair<char, int> p11 = ft::make_pair<char, int>(key1, value1);
    std::pair<char, int> _p11 = std::make_pair<char, int>(key1, value1);
    alice.insert(p11);
    _alice.insert(_p11);
  }

  cnt = 10;
  ft::map<char, int> bob;
  std::map<char, int> _bob;
  while (cnt--) {
    srand(clock());
    char key1 = rand() % range + 97;
    int value1 = rand() % 30;
    ft::pair<char, int> p11 = ft::make_pair<char, int>(key1, value1);
    std::pair<char, int> _p11 = std::make_pair<char, int>(key1, value1);
    bob.insert(p11);
    _bob.insert(_p11);
  }

  print_map(alice);
  print_map(_alice);
  print_map(bob);
  print_map(_bob);
  std::cout << std::boolalpha;

  // // Compare non equal containers
  std::cout << "alice == bob returns " << (alice == bob) << '\n';
  std::cout << "alice != bob returns " << (alice != bob) << '\n';
  std::cout << "alice <  bob returns " << (alice < bob) << '\n';
  std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
  std::cout << "alice >  bob returns " << (alice > bob) << '\n';
  std::cout << "alice >= bob returns " << (alice >= bob) << '\n';

  // std::cout << '\n';

  // // Compare equal containers
  std::cout << "_alice == _bob returns " << (_alice == _bob) << '\n';
  std::cout << "_alice != _bob returns " << (_alice != _bob) << '\n';
  std::cout << "_alice <  _bob returns " << (_alice < _bob) << '\n';
  std::cout << "_alice <= _bob returns " << (_alice <= _bob) << '\n';
  std::cout << "_alice >  _bob returns " << (_alice > _bob) << '\n';
  std::cout << "_alice >= _bob returns " << (_alice >= _bob) << '\n';
  system("leaks a.out");
}

void stack_test() {
  ft::stack<int> a;
  std::stack<int> b;

  std::cout << a.empty() << std::endl;
  std::cout << b.empty() << std::endl;
  a.push(10);
  b.push(10);
  a.push(9);
  b.push(9);
  a.push(8);
  b.push(8);
  std::cout << a.size() << std::endl;
  std::cout << b.size() << std::endl;
  std::cout << a.top() << std::endl;
  std::cout << b.top() << std::endl;
  system("leaks a.out");
}

int main(void) {
  vector_test();
  vector_rv();
  vector_relation();
  // map_test();
  // stack_test();
  // print_header("vector", 80, '=');
  // print_namespace(1);
  // print_test_name("vector insert");
}