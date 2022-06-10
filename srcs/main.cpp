#include <time.h>

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <string>
#include <type_traits>
#include <vector>

#include "config.hpp"
#include "container/vector.hpp"
#include "type_traits/enable_if.hpp"
#include "type_traits/is_integral.hpp"
#include "utility/binary_search_tree.hpp"
#include "utility/bst_node.hpp"
#include "utility/make_pair.hpp"
#include "utility/pair.hpp"

#define COUNT 10;
#ifndef NAMESPACE
#define NAMESPACE ft
#endif

template <class Container>
class print_container {
 public:
  void print(Container& x) {
    for (typename Container::iterator it = x.begin(); it != x.end(); it++)
      std::cout << *it << std::endl;
  }
};

int bst_index = 0;
template <class T1, class T2, class Node, class Bst>
void print_pair(Bst* bst, Node* node, ft::pair<T1, T2> pr) {
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
void printBT(const std::string& prefix, Node* node, bool isLeft) {
  if (node != nullptr) {
    std::cout << prefix;

    std::cout << (isLeft ? "├──" : "└──");

    // print the value of the node
    std::cout << node->get_value_ref().first << std::endl;

    // enter the next tree level - left and right branch
    printBT(prefix + (isLeft ? "│   " : "    "), node->get_left_node(), true);
    printBT(prefix + (isLeft ? "│   " : "    "), node->get_right_node(), false);
  }
}

template <class Node>
void printBST(Node* node) {
  printBT("", node, false);
}

// pass the root node of your binary tree
template <class Node>
void print2D(Node* root) {
  int num = 0;
  print2DUtil(root, num);
}

int main(void) {
  srand(time(NULL));
  ft::binary_search_tree<ft::pair<unsigned int, unsigned int> > bst;

  int count = 20;
  while (count--) {
    srand(clock());
    unsigned int num = rand() % 50;
    unsigned int num1 = rand() % 50;
    // std::cout << num << " " << num1 << std::endl;
    ft::pair<unsigned int, unsigned int> p = ft::make_pair(num, num1);
    if (!bst.get_root()) bst.set_root(bst.insert(bst.get_root(), p));
    bst.insert(bst.get_root(), p);
  }
  print2D(bst.get_root());
  // printBST(bst.get_root());
  // bst.inorder(bst.get_root(), print_pair);
  bst.delete_node(bst.get_root()->get_left_node());
  print2D(bst.get_root());
  // printBST(bst.get_root());
  // std::cout << bst.get_size() << std::endl;
  // std::cout << bst.min(bst.get_root())->get_value_ref().first << std::endl;
  // std::cout << bst.max(bst.get_root())->get_value_ref().first << std::endl;
  // std::cout << bst.successor(bst.get_root())->get_value_ref().first
  //           << std::endl;
  // std::cout << bst.predecessor(bst.get_root())->get_value_ref().first
  //           << std::endl;
  // bst.inorder(bst.get_root(), print_pair);
  // bst.inorder(bst.get_root(), print_pair);
  // std::cout << bst.get_root()->get_value_ref().first << std::endl;
  // std::cout << bst.get_root()->get_value_ref().second << std::endl;
  // std::cout << bst.get_root()->get_right_node()->get_value_ref().first
  //           << std::endl;
  // std::cout << bst.get_root()->get_right_node()->get_value_ref().second
  //           << std::endl;
  // std::cout << bst.get_root()->get_left_node()->get_value_ref().first
  //           << std::endl;
  // std::cout << bst.get_root()->get_left_node()->get_value_ref().second
  //           << std::endl;
}

// int main(void) {
//   clock_t start, end;
//   start = clock();
//   ft::vector<int> a;
//   ft::vector<int> a_1(5, 77);
//   ft::vector<int> assign = a_1;
//   // bool is_valid = ft::is_convertible<ft::vector<int>::iterator,
//   //                                    ft::vector<int>::iterator>::value;
//   // std::cout << is_valid << std::endl;
//   ft::vector<int>::iterator iter = a.begin();
//   std::cout << ft::is_iterator<ft::vector<int>::iterator>::value <<
//   std::endl; a.assign(a_1.begin(), a_1.end()); std::cout << "size : " <<
//   a.size() << std::endl; std::cout << "capacity : " << a.capacity() <<
//   std::endl; for (ft::vector<int>::iterator it = a.begin(); it != a.end();
//   it++) {
//     std::cout << *it << std::endl;
//   }
//   std::cout << "+++++++" << std::endl;
//   for (ft::vector<int>::iterator it3 = assign.begin(); it3 != assign.end();
//        it3++) {
//     std::cout << *it3 << std::endl;
//   }
//   end = clock();
//   std::cout << end - start << std::endl;
//   std::cout << "---------------" << std::endl;

//   start = clock();

//   // std::vector<int> a(5, 1);
//   std::vector<int> b(10, 1);
//   std::vector<int> c = b;
//   std::cout << "size : " << b.size() << std::endl;
//   std::cout << "capacity : " << b.capacity() << std::endl;
//   // std::vector<int>::iterator i = b.insert(b.begin(), 10);
//   for (std::vector<int>::iterator it1 = b.begin(); it1 != b.end(); it1++) {
//     std::cout << *it1 << std::endl;
//   }
//   // std::cout << *i << std::endl;
//   // b = a;
//   std::cout << "size : " << b.size() << std::endl;
//   std::cout << "capacity : " << b.capacity() << std::endl;
//   end = clock();
//   std::cout << end - start << std::endl;
//   // a.erase(a.begin(), a.end());
//   // a.erase(a.begin());
//   // std::cout << a.size() << std::endl;
//   // std::cout << a.capacity() << std::endl;
//   // std::cout << *a.begin() << std::endl;
//   // std::cout << a.bits_per_word << std::endl;
//   // a.destruct_at_end(a.begin());
//   // std::vector<int> b;
//   return 0;
// }