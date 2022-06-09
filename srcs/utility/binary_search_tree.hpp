#ifndef _FT_BINARY_SEARCH_TREE_HPP
#define _FT_BINARY_SEARCH_TREE_HPP

#include <functional>
#include <iostream>
#include <memory>

#include "../config.hpp"
#include "../utility/bst_node.hpp"

_BEGIN_NAMESPACE_FT
template <class T, class Compare = std::less<T>, class Node = ft::bst_node<T>,
          class Allocator = std::allocator<T>,
          class Node_Allocator = std::allocator<Node> >
class binary_search_tree {
  /* ---------------------------------------------------------------- */
  /*                           TYPE ALIASES                           */
  /* ---------------------------------------------------------------- */

 public:
  typedef binary_search_tree tree;
  typedef tree &tree_reference;
  typedef tree *tree_pointer;

  typedef T value_type;
  typedef Allocator allocator_type;
  typedef typename Allocator::reference reference;
  typedef typename Allocator::const_reference const_reference;
  typedef typename Allocator::pointer pointer;
  typedef typename Allocator::const_pointer const_pointer;
  typedef typename Allocator::size_type size_type;
  typedef typename Allocator::difference_type difference_type;

  typedef Compare compare;
  typedef Node node_type;
  typedef Node_Allocator n_allocator_type;
  typedef typename n_allocator_type::reference n_reference;
  typedef typename n_allocator_type::const_reference n_const_reference;
  typedef typename n_allocator_type::pointer n_pointer;
  typedef typename n_allocator_type::const_pointer n_const_node_pointer;
  typedef typename n_allocator_type::size_type n_size_type;
  typedef typename n_allocator_type::difference_type n_difference_type;

  // typedef ft::bst_iterator<n_pointer, compare> iterator;
  // typedef ft::bst_iterator<n_const_pointer, compare> const_iterator;

  /* ---------------------------------------------------------------- */
  /*                            ATTRIBUTES                            */
  /* ---------------------------------------------------------------- */
 private:
  n_size_type _sz;          // Number of nodes in this bst
  n_allocator_type _alloc;  // Allocator for bst_node
  n_pointer _root;          // A pointer variable pointing to root node

 public:
  /* ---------------------- DEFAULT CONSTRUCTOR --------------------- */
  binary_search_tree(const n_allocator_type &alloc = n_allocator_type())
      : _sz(0), _alloc(alloc), _root(nullptr) {}

  /* -------------------------- DESTRUCTOR -------------------------- */
  ~binary_search_tree(void) { destroy(_root); };
  // * member functions
  n_size_type get_size(void) { return _sz; }
  n_pointer get_root(void) { return _root; }
  void set_root(n_pointer node) { this->_root = node; }
  n_pointer create_bst_node(value_type &val, n_pointer parent = nullptr,
                            n_pointer left = nullptr,
                            n_pointer right = nullptr) {
    n_pointer new_node = this->_alloc.allocate(1);
    new_node->set_value(val);
    new_node->set_parent_node(parent);
    new_node->set_left_node(left);
    new_node->set_right_node(right);
    return new_node;
  }
  n_pointer insert(n_pointer node, value_type &val) {
    if (!node) {
      this->_sz++;
      return create_bst_node(val);
    }
    if (val < node->get_value_ref()) {
      n_pointer left = insert(node->get_left_node(), val);
      node->set_left_node(left);
      left->set_parent_node(node);
    } else if (val > node->get_value_ref()) {
      n_pointer right = insert(node->get_right_node(), val);
      node->set_right_node(right);
      right->set_parent_node(node);
    }
    return node;
  }
  void inorder(n_pointer node, void (*f)(tree *, n_pointer, T)) {
    if (node) {
      inorder(node->get_left_node(), f);
      f(this, node, node->get_value_ref());
      inorder(node->get_right_node(), f);
    }
  }
  void preorder(n_pointer node, void (*f)(tree *, n_pointer, T)) {
    if (node) {
      f(this, node, node->get_value_ref());
      preorder(node->get_left_node(), f);
      preorder(node->get_right_node(), f);
    }
  }
  void postorder(n_pointer node, void (*f)(tree *, n_pointer, T)) {
    if (node) {
      postorder(node->get_left_node(), f);
      postorder(node->get_right_node(), f);
      f(this, node, node->get_value_ref());
    }
  }
  void destroy(n_pointer node) {
    if (node != nullptr) {
      destroy(static_cast<n_pointer>(node->get_left_node()));
      destroy(static_cast<n_pointer>(node->get_right_node()));
      _alloc.deallocate(node, 1);
    }
  }
};
_END_NAMESPACE_FT
#endif

/**
 * @brief
 * ? 트리(tree)
 * 노드들의 집합
 * 각 노드는 값과 다른 노드를 가리키는 레퍼런스를 포함
 *
 * ? 간선(edge)
 * 노드와 노드를 연결하는 선
 * 구현 관점에서 레퍼런스를 의미
 * link, branch
 *
 * ? 루트(root) 노드
 * 가장 최상단 노드
 *
 * ? 자녀(child) 노드
 * 모든 노드는 0개 이상의 자녀노드를 가진다.
 *
 * ? 부모(parent) 노드
 * 자녀 노드를 갖는 노드
 *
 * ? 형제(sibling) 노드
 * 같은 부모를 같는 노드
 *
 * ? 조상(ancestor) 노드
 * 부모 노드를 따라 루트 노드까지 올라가며 만나는 모든 노드
 *
 * ? 자손(descendant) 노드
 * 자녀 노드를 따라 내려가며 만날 수 있는 모든 노드
 *
 * ? 내부(internal) 노드
 * 자녀 노드를 가지는 노드
 *
 * ? 외부(external) 노드
 * 자녀 노드가 없는 노드
 * leaf node, outer node, terminal node
 *
 * ? 경로(path)
 * 한 노드에서 다른 노드 사이의 노드들의 시퀀스
 *
 * ? 경로 길이 (length of path)
 * 경로에 있는 노드들의 수
 *
 * ? 노드의 높이(height)
 * 노드에서 리프 노드까지의 가장 긴 경로의 간선 수
 *
 * ? 트리의 높이
 * 루트 노드의 높이
 *
 * ? 노드의 깊이(depth)
 * 루트 노드에서 해당 노드까지 경로의 간선 수
 *
 * ? 트리의 깊이
 * 트리에 있는 노드들의 깊이 중 가장 긴 깊이 = 루트 노드의 깊이
 *
 * ? 노드의 차수(degree)
 * 노드의 자녀 노드 수
 *
 * ? 트리의 차수
 * 트리에 있는 노드들의 차수 중 가장 큰 차수
 *
 * ? 두 노드 사이의 거리(distance)
 * 두 노드의 최단 경로의 간선 수
 *
 * ? 노드의 레벨
 * 노드와 루트 노드 사이의 경로에서 간선의 수, 루트 노드의 레벨 = 0
 *
 * ? width
 * 임의 레벨에서 노드의 수
 *
 * ? 트리의 크기
 * 트리의 모든 노드의 수
 *
 * ? 서브 트리
 * 각 노드의 자녀 노드들을 재귀적으로 서브트리로 구성한다.
 *
 *
 * ! 루트 노드는 1개만 존재
 * ! 사이클이 존재할 수 없음
 * ! 자녀 노드는 하나의 부모 노드만 존재
 * 데이터를 순차적으로 저장하지 않는 비선형 구조
 * 트리에 서브트리가 있는 재귀적 구조
 * 계층적 구조
 *
 * ? 이진(binary)트리
 * 각 노드의 자녀 노드 수가 최대 두 개인 트리
 * ? 정 이진 트리(full binary tree)
 * 모든 노드가 자녀도가 없거나 두 개인 트리
 * ? 완전 이진 트리(complete binary tree)
 * 마지막 레벨을 제외한 모든 레벨에서 노드가 빠짐없이 채워져 있고
 * 마지막 레벨은 왼쪽부터 빠짐없이 노드가 채워져있는 트리
 * ? 포화 이진 트리(perfect binary tree)
 * 모든 레벨에서 노드가 빠짐없이 채워져 있는 트리
 * ? 변질 이진 트리(degenerate binary tree)
 * 모든 부모 노드는 하나의 자녀 노드만 가지는 트리
 * pathological binary tree 라고도 불림
 * ? left skewed binary tree
 * 모든 부모 노드가 왼쪽 자녀 노드만 가지는 트리
 * ? right skewed binary tree
 * 모든 부모 노드가 오른쪽 자녀 노드만 가지는 트리
 * ? 균형 이진 트리(balanaced binary tree)
 * 모든 노드에서 왼쪽 서브 트리와 오른쪽 서브 트리의
 * 높이 차이가 최대 1인 트리
 */
/*
- 이진 탐색 트리 (binary search tree)
모든 노드의 왼쪽 서브트리는 해당 노드의 값보다 작은 값들만 가지고,
모든 노드의 오른쪽 서브트리는 해당 노드보다 큰 값들만 가진다.

- 이진 트리의 최소값
트리의 가장 왼쪽에 존재.
- 이진 트리의 최대값
트리의 가장 오른쪽에 존재.

- 중위 순회(inorder traversal)
1.재귀적으로 왼쪽 서브트리 순회.
2.현재 노드 방문.
3.재귀적으로 오른쪽 서브트리 순회.

- 전위 순회 (preorder traversal)
1. 현재 노드 방문
2. 재귀적으로 왼쪽 서브 트리 순회
3. 재귀적으로 오른쪽 서브 트리 순회

- 후위 순회(postorder traversal)
1. 재귀적으로 왼쪽 서브 트리 순회
2. 재귀적으로 오른쪽 서브 트리 순회
3. 현재 노드 방문

- 노드의 successor(후임자)
        해당 노드보다 값이 큰 노드들 중에서 가장 값이 작은 노드.
- 노드의 predecessor(선임자)
        해당 노드보다 값이 작은 노드들 중에서 가장 값이 큰 노드.

- insert
        루트 노드에서 출발
        노드별 비교 삽입 하고자하는 노드 값이
        현재 노드값보다 작으면 왼쪽으로 크면 오른쪽으로
        더 이상 노드가 존재하지 않는 위치에 도달한 경우
        해당 위치에 삽입

- delete
        루트 노드에서 출발
        현재 노드 값이 삭제하고자 하는 노드 값보다
        작으면 왼쪽으로 크면 오른쪽 노드로 이동해서 탐색
        발견하면 자녀노드가 없을 경우 해당 노드의 엣지 해제
        자녀노드가 1개 있을 경우 자신의 부모노드가 해당 자식 노드를
가리키도록 변경 자녀노드가 2개 있을 경우 오른쪽 서브트리에서 제일 값이 작은
노드가 대체, 왼쪽 서브트리의 경우에는 가장 큰 값이 대체

- search
        루트 노드에서 시작해 노드를 방문할때 마다 값 비교, 현재 노드보다
        탐색 대상 값이 작으면 왼쪽으로, 크면 오른쪽으로 이동하며 탐색
*/