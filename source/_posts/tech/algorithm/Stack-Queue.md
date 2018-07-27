---
title: Stack & Queue
date: 2018-06-28 10:27:58
mathjax: true
tags: [stack, queue]
categories:
- tech
- algorithm
---

# Scenario

There are two significant ordering methods:

* **Last In First Out(FIFO)**
* **First In First Out(LIFO)**

{% asset_img lifo_vs_fifo.png Picture of LIFO vs FIFO %}

<!-- more -->
   <center>**Figure 1. LIFO vs FIFO**</center>

You may notice that there are also two stange nouns in the picture, **Stack** and **Queue**.  These are two abstract structure to implement these two ordering methods in computer science area.

# Stack - LIFO

Generally speaking, the Stack is a term which represents an abstract structure of LIFO. It do not give any constraint of implementation. Therefore, we can implement Stack with any data structure in any language. But **Array** and **LinkedList** are the two most common way.

In the next of this article, we will concern about some **special** parts or usages of stack.

## In Computer System

1. Core of function call, arguments and return address will be pushed into stack.
2. Local variable in Function are stored in stack.

## Two stack

## Monotone stack

TODO

# Queue - FIFO

Similiar to Stack, the Queue is also a term and the most common way to implement it are also **Array** and **LinkedList**.

## Priority Queue

* **Concept:** This queue will put entry with largest/smallest value in the front, even if it comes later.
* **Underlying Techniques:** [Binary Heap](/tech/algorithm/Methods-of-Sort#Heap-sort), **Note:** Binary Search + Ordered Array has $ \frac {N}{2}$ average time complexity.
* **Operations:**
  * **Insert:** Insert in the end of array and run `swim(...)`
  ```c++
  // assume v is already a binary heap and array start from index = 1.
  void swim(vector<int>& v, int k) {
      while (k > 1 && v[k/2] < v[k]) {
        swap(v[k/2], v[k]);
        k = k / 2;
      }
  }
  ```
  * **Delete:** Delete `v[1]` and `swap(v[1], v[n])`, then `sink(...)`
  * **Front:** `return v[1];`
* **Application:** Dijkstra(TODO), Distributed DataStore Consistency, Load Balancing
