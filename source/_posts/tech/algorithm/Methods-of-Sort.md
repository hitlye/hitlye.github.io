---
title: Methods of Sort
date: 2018-07-01 16:56:55
mathjax: true
tags: [sort, quick-sort, heap-sort, bubble-sort, insertion-sort, shell-sort, selection-sort, merge-sort]
category:
- tech
- algorithm
---

# Scenario

**Try to sort the following cards (Min ---> Max)!**

   {% asset_img scenario-of-sort.png Scenario Of Sort %}

<!-- more -->
   <center>**Figure 1. Scenario Of Sort **</center>

# Sort Complexity
   <img src="sort-complexity.png" width="75%" height="75%" alt="Sort Complexity"></img>
   <center>**Figure 2. Sort Complexity **</center>
   $$ 2^h \ge \\#leaves \ge N! \\\\
   \Rightarrow h \ge lg(N!) \simeq N \bullet log(N)$$

# Selection sort

## Idea

* In interation `i`, select index `min` of smallest remaining entry.
* Swap `a[i]` and `a[min]`

## Code Sample

{% fold Sample %}
```c++
// v is the original array
void selection_sort(vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        // Index of smallest value;
        int min = i;
        // Find the smallest element from i - > v.size()
        for (size_t j = i + 1; j < v.size(); ++j) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
        swap(v[i], v[min]);
    }
    return;
}
```
{% endfold %}

## Analysis

* **Visualization:**
   <img src="selection-sort-visualization.png" width="50%" height="50%" alt="Selection Sort Visualization"></img>
   <center>**Figure 3. Selection Sort Visualization **</center>
* **Proposition:**
  * **Time Complexity:** $ (N - 1) + (N - 2) + ... + 1 + 0 \sim N^2/2 $
  * **Space Complexity:** $ \sim 1 $
  * **Stable:** No
  * **Other Features:** Running time insensitive to input & Data movement is minimal.

# Insertion sort

## Idea

* In iteration `i`, swap `a[i]` with each larger entry to its left.

## Code Sample

{% fold Sample %}
```c++
// v is the original array
void insertion_sort(vector<int>& v) {
    for (size_t i = 1; i < v.size(); ++i) {
        for (size_t j = i; j >= 1; --j) {
            if (v[j] < v[j - 1])
                swap(v[j], v[j - 1]);
            else
                // v[j] is the max value from 0 -> i - 1
                break;
        }
    }
    return;
}
```
{% endfold %}

## Analysis

* **Visualization:**
   <img src="insertion-sort-visualization.png" width="50%" height="50%" alt="Insertion Sort Visualization"></img>
   <center>**Figure 4. Insertion Sort Visualization **</center>
* **Proposition:**
  * **Time Complexity:**
    * Random-ordered array with distinct keys: $ \sim \frac{N^2}{4} $(Expect Half-Way Comparation)
    * Best case with sorted array: $ N - 1 $
    * Worsest case with reversed sorted array: $ 0 + 1 + ... + (N - 2) + (N - 1) \sim \frac{N^2}{2} $
  * **Space Complexity:** $ \sim 1$
  * **Stable:** Yes
  * **Other Features:**
  * Data Sensitive to input & Lots of data movements
  * **Partial Sorted Array(Linear Time Complexity):**
    * Definition: Number of Inversions pair is $ \leq cN $
    * Best: $ Num_{inv} $ - Number of Inversions pair
    * Worst: $ Num_{inv} + (N - 1) $
    * Explanation: If `a[i]` does not reach to the **left bound** of array, then there will be one more compare.

# Shell sort

## Idea

* Move entries more than one position at a time by *h-sorting* the array.

## Code Sample
{% fold Sample %}
```c++
// v is the original array
void shell_sort(vector<int>& v) {
    // step
    int h;
    while (h < v.size() / 3)
        h = (3 * h + 1);

    while (h >= 1) {
        // h -> v.size()
        for (int i = h; i < v.size(); ++i) {
            // Insertion sort
            for (int j = i; j >= h; j -= h) {
                if (v[j] > v[j - h])
                    swap(v[j], v[j - h]);
                else
                    break;
            }
        }
        h /= 3;
    }
    return;
}
```
{% endfold %}

## Analysis

* **Visualization:**
   <img src="shell-sort-visualization.png" width="50%" height="50%" alt="Shell Sort Visualization"></img>
   <center>**Figure 5. Shell Sort Visualization**</center>
* **Proposition:**
  * **Time Complexity:** $ \sim N^{\frac{3}{2}}$
  * **Space Complexity:** $ \sim 1 $
  * **Stable:** Yes
  * **Other Features:** Fast in small array and used in some embedded system.

# Merge sort

## Idea

* Divide array into two halves
* Recursively sort each half
* Merge two halves

## Code Sample
{% fold Sample %}
```c++
// merge two sorted sub-array, lo -> mid, mid+1 -> hi
void merge(vector<int>& v, vector<int>& aux, int lo, int mid, int hi) {
    // copy elements to aux
    for (int i = lo; i <= hi; ++i)
        aux[i] = v[i];
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; ++k) {
        if (i > mid)
            v[k] = aux[j++];  // lo -> mid has already been processed
        else if (j > hi)
            v[k] = aux[i++];  // mid + 1 -> hi has already been processed
        else if (v[j] < v[i])
            v[k] = aux[j++];  // normal condition 1
        else
            v[k] = aux[i++];  // normal condition 2
    }
    return;
}

// v is the original array
void merge_sort(vector<int>& v, vector<int>& aux, int lo, int hi) {
    // Improvement 1. Small array is efficient with insertion sort
    if (lo + CUTOFF >= hi) {
        insert_sort(v, lo, hi);
        return;
    }

    int mid = lo + (hi - lo)/2;
    merge_sort(v, aux, lo, mid);
    merge_sort(v, aux, mid + 1, hi);
    // Improvement 2. Check if sub arrays are already ordered.
    if (v[mid] <= v[mid + 1])
      return;
    merge(v, aux, lo, mid, hi);
}
```
{% endfold %}

## Analysis

* **Visualization:**
   <img src="merge-sort-visualization.png" width="75%" height="75%" alt="Merge Sort Visualization"></img>
   <center>**Figure 6. Merge Sort Visualization **</center>
* **Proposition:**
  * **Time Complexity:** $ \sim Nlog(N)$
    $$ D(N) \le C(\lceil {N/2} \rceil) + C(\lfloor {N/2} \rfloor) + N $$
    <img src="merge-sort-time.png" width="75%" height="75%" alt="Merge Sort Time"></img>
    <center>**Figure 7. Merge Sort Time **</center>
  * **Space Complexity:** $ \sim N $
  * **Stable:** Yes

# Quick sort

## Idea

* Shuffle the array
* Partition so that, for some `j`
  - entry `a[j]` is in place
  - no larger entry to the left of `j`
  - no smaller entry to the right of `j`
* Sort each piece recursively

## Code Sample
{% fold Sample %}
```c++
// Put pivot into right place
int partition(vector<int>& v, int lo, int hi) {
    int pivot = lo;

    int i = lo, j = hi + 1;
    while (1) {
        while (v[++i] <= v[pivot] && i < hi)
            ;
        while (v[--j] >= v[pivot] && j > lo)
            ;
        if (i >= j)
            break;
        swap(v[i], v[j]);
    }
    swap(v[pivot], v[j]);
    return j;
}

// v is the original array
void quick_sort(vector<int>& v, int lo, int hi) {
    // Improvement 1. Replace with insertion sort in small array
    if (lo + CUTOFF >= hi) {
        insertion_sort(v, lo, hi)
        return;
    }

    // Improvement 2. Select appropriate pivot
    int m = midian(lo, lo + (hi - lo)/2, hi);
    swap(v[m], v[m]);

    int j = partition(v, lo, hi);
    quick_sort(v, lo, j);
    quick_sort(v, j + 1, hi);
}

// Improvement 3. Duplicated keys
void quick_sort(vector<int>& v, int lo, int hi) {
    if (lo >= hi)
        return;
    int lt = lo, gt = hi;
    int i = lo;
    int pivot = lo;
    while (i <= gt) {
        if (v[i] < v[pivot]) {
            swap(v[i], v[lt]);
            ++i;
            ++lt;
        } else if (v[i] > v[pivot]) {
            swap(v[i], v[gt]);
            --gt;
        } else
            ++i;
    }

    quick_sort(v, lo, lt - 1);
    quick_sort(v, gt + 1, hi);
}

```
{% endfold %}

## Analysis

* **Visualization:**
   <img src="quick-sort-visualization.png" width="75%" height="75%" alt="Quick Sort Visualization"></img>
   <center>**Figure 7. Quick Sort Visualization **</center>
* **Proposition:**
  * **Time Complexity:**
    * Best and Average: $\sim N \bullet log(N)$
    * Worest: $\sim \frac{1}{2} \bullet N^2$
   * Qucik-Selection is almost **linear** time.

# Heap sort

## Idea

* Basic Knowledge points:
  * **Complete Binary Tree:** Perfectly balanced, except for bottom level.
  * **Heap-ordered:** Parent's key no smaller than children's keys.
  * **Binary Heap:** Arrat representation of a heap-ordered complete binary tree.
* Steps:
  1. Construct a binary heap
  2. At iteration `i`, get the $ i_{th} $ maximum element, and remove it.
  3. `++i` and goto step 2.

## Code Sample

{% fold Sample %}
```c++
// sink v[i] to appropriate position
void sink(vector<int>& v, size_t i, size_t n) {
  while (2 * i <= n) {
    // left_child
    size_t j = 2 * i;
    // left_child < right_child
    if (j < n && v[j - 1] < v[j])
      ++j;
    if (v[i - 1] >= v[j - 1])
      break;
    swap(v[i - 1], v[j - 1]);
    i = j;
  }
}

/*
 * Note: when the array starts from index = 1, then for every node i, its left child
 * is 2*i and its right child is 2*i + 1. But normally, the array starts from
 * index = 0. So, we map index(0 -> n -1) to (1 -> n), then the only change we have
 * to make is making index = index - 1 when accessing array data.
 *
*/
void heap_sort(vector<int>& v) {
  // 1. Construct the binary heap
  size_t len = v.size();
  for (int k = len / 2; k >= 1; --k) {
    sink(v, k, len);
  }

  // 2. Repeatedly remove the largest number which is in the v[0].
  while (len > 1) {
    swap(v[0], v[--len]);
    sink(v, 1, len);
  }
}
```
{% endfold %}

## Analysis

* **Visualization**
   <img src="heap-sort-visualization.png" width="50%" height="50%" alt="Heap Sort Visualization"></img>
   <center>**Figure 9. Heap Sort Visualization **</center>
* **Proposition:**
  * **Time Complexity:** constuction $ \ \le 2N $ + compares $ \ \le 2N \bullet lgN$
  * **Space Complexity:** $ \sim O(1) $
  * **Stable:** No
  * **Application:** [Priority Queue](/tech/algorithm/Stack-Queue/#Priority-Queue)
 
# Conclusion
   <img src="sort-conclusion.png" width="75%" height="75%" alt="Sort Conclusion"></img>
   <center>**Figure 10. Sort Conclusion **</center>

