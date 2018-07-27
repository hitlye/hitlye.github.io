/*
 * Binary Search Tree with 3 operations:
 *    1. get - return value of given key
 *    2. put - put <key, value> pair to current BST
 *    3. remove - remove <key, value> pair from current BST
 *
 * Usage:
 *
 */

#ifndef _TREE_BINARY_SEARCH_TREE_
#define _TREE_BINARY_SEARCH_TREE_

#include "../../util/basecpp/node.h"

#include <string>
#include <queue>

namespace tree {

template<typename K, typename V>
class BinarySearchTree {
private:

  inline size_t count(TNode<K, V> *node) {
    return node == nullptr ? 0 : node->count;
  }

  // recursively search until find the right place of given <key, value>
  // two scenario:
  // 1. find existing key, replace with new val
  // 2. meet a nullptr node means the pair should be inserted here
  // NOTE: pattern xxx = put(xxx, key, value) is used to maintain the parrent info
  TNode<K, V> *put(TNode<K, V> *node, K key, V value) {
    // locate key's position
    if (node == nullptr) {
      TNode<K, V> *node = new TNode<K, V>(key, value);
      return node;
    }
    // binary search & update subtree count
    if (node->key > key) node->lchild = put(node->lchild, key, value);
    else if (node->key < key) node->rchild = put(node->rchild, key, value);
    else node->value = value;
    node->count = 1 + count(node->lchild) + count(node->rchild);
    return node;
  }

  // recursively search the biggest k for k <= key
  // 3 cases:
  // 1. node->key == key, return node
  // 2. node->key > key, search in node->lchild
  // 3. node->key < key, target >= node->key
  TNode<K, V> *floor(TNode<K, V> *node, K key) {
    if (node == nullptr) return node; // error handling
    if (node->key == key) return node; // case 1
    else if (node->key > key) return floor(node->lchild, key); // case 2
    else { // case 3
      TNode<K, V> *right = floor(node->rchild, key);
      return right == nullptr ? node : right;
    }
  }

  // recursively search the smallest k for k >= key
  // 3 cases:
  // 1. node->key == key, return node
  // 2. node->key < key, search in node->rchild
  // 3. node->key > key, target <= node->key
  TNode<K, V> *ceiling(TNode<K, V> *node, K key) {
    if (node == nullptr) return node; // error handling
    if (node->key == key) return node; // case 1
    else if (node->key < key) return ceiling(node->rchild, key); // case 2
    else { // case 3
      TNode<K, V> *left = ceiling(node->lchild, key);
      return left == nullptr ? node : left;
    }
  }

  // recursively find until meeting the biggest k in k <= key
  // 3 cases:
  // 1. node->key == key, return 1;
  // 2. node->key > key, search in node->lchild;
  // 3. node->key < key, 1 + node->left->count + search in node->rchild
  size_t rank(TNode<K, V> *node, K key) {
    if (node == nullptr) return 0; // error handling
    if (node->key == key) return 1 + count(node->lchild); // case 1
    else if (node->key > key){
      return rank(node->lchild, key); // case 2
    } else {
      return 1 + count(node->lchild) + rank(node->rchild, key); // case 3
    }
  }
public:
  explicit BinarySearchTree(V value) :null_value_(value) {};

  // BFS delete every malloced node
  ~BinarySearchTree() {
    std::queue<TNode<K, V> *> q;
    q.push(root_);
    while (!q.empty()) {
      TNode<K, V> *node = q.front();
      q.pop();
      if (node == nullptr) {
        continue;
      }
      q.push(node->lchild);
      q.push(node->rchild);
      delete node;
    }
  };

  inline size_t size() const{
    return size_;
  }

  // put <key, val> pair as a node in BST
  void put(K key, V value) {
    root_ = put(root_, key, value);
    ++size_;
  };

  //get val of given key, if no sunch key, then return nullptr
  V get(K key) {
    V found_value = null_value_;
    // temp node for travasing the tree
    TNode<K, V> *node = root_;
    while (node != nullptr) {
      if (node->key < key) {
        node = node->rchild;
      } else if (node->key > key) {
        node = node->lchild;
      } else {
        found_value = node->value;
        break;
      }
    }
    return found_value;
  };

  // floor means the biggest k in k <= key
  V floor(K key) {
    TNode<K, V> *node = floor(root_, key);
    // key is the smallest key
    if (node == nullptr) return null_value_;
    return node->key;
  }

  // ceil means the smallest k in k >= key
  V ceiling(K key) {
    TNode<K, V> *node = ceiling(root_, key);
    // key is the biggest key
    if (node == nullptr) return null_value_;
    return node->key;
  }

  // rank means how many k for k <= key
  size_t rank(K key) {
    return rank(root_, key);
  }

  // remove min node in tree
  TNode<K, V> *remove_min(TNode<K, V> *node) {
    if (node->lchild == nullptr) return node->rchild;
    node->lchild = remove_min(node->lchild);
    node->count = 1 + count(node->lchild) + count(node->rchild);
    return node;
  }

  // remove <key, value> pair from current BST by given kye
  // 3 cases:
  // 1. no child: remove directly
  // 2. 1 child: remove than link child to its parent
  // 3. 2 child: replace key with its successor which means ceiling(key)
  TNode<K, V> *remove(TNode<K, V> *node, K key) {
    if (node == nullptr) return nullptr; // not found
    if (node->key > key) {
      node->lchild = remove(node->lchild, key); // in left subtree
    } else if (node->key < key) {
      node->rchild = remove(node->rchild, key); // in right subtree
    } else {
      // found key
      --size_;
      if (node->lchild == nullptr) { // case 1 & 2
        TNode<K, V> *right = node->rchild;
        delete node;
        return right;
      }

      if (node->rchild == nullptr) { // case 1 & 2
        TNode<K, V> *left = node->lchild;
        delete node;
        return left;
      }

      // case 3. replace node with successor
      TNode<K, V> *successor = node->rchild;
      while (successor->lchild != nullptr) successor = successor->lchild;
      successor->rchild = remove_min(successor);
      successor->lchild = node->lchild;
      delete node;
      node = successor;
    }
    node->count = 1 + count(node->lchild) + count(node->rchild);
    return node;
  };

  // remove <key, value> pair from current BST by given key
  void remove(K key) {
    root_ = remove(root_, key);
  }

private:
  TNode<K, V> *root_ = nullptr;
  V null_value_;
  size_t size_ = 0;

};
} // namspace tree

#endif // _TREE_BINARY_SEARCH_TREE_
