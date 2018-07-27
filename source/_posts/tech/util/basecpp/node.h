/*
 * Node.h - Struct to represent simple Binary Tree Node
 *
 */

#ifndef _TREE_NODE_H_
#define _TREE_NODE_H_

#include <string>

namespace tree {
/*
 * K for key, v for value
 */
template <typename K, typename V>
struct Node {
  K key;
  V value;
  // number of nodes in this subtree
  size_t count;

  struct Node<K, V> *lchild;
  struct Node<K, V> *rchild;

  // constructor
  Node(K k, V v) :key(k), value(v), count(1), lchild(nullptr), rchild(nullptr){}
};

// pre-define some common node
template <typename K, typename V>
using TNode = struct Node<K, V>;
}

#endif // _TREE_NODE_H_
