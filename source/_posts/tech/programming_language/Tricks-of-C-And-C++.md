---
layout: posts
title: Tricks of C and C++
date: 2018-06-13 15:24:45
tags: [c, c++, tricks]
categories:
- tech
- programming language
---

## String

1. Delete all `c` in `s[]`.
    ``` c
    // Delete all c in s[]
    void squeeze(const char c, char s[]) {
        int i;
        int j;

        for (i = 0, j = 0; s[i] != '\0'; ++i) {
            if (s[i] != c) {
                s[j++] = s[i];
            }
        }
        s[j] = '\0';
    }
    ```
<!-- more -->

2. Check if a given string is an integer(C++).
    ```c++
    // Check s is int or not
    bool is_int(String s) {
        stringstream ss;
        int i;
        return ss >> i;
    }
    ```

3. String Join
   ```c++
    string s = "abc";
    stringstream ss;
    copy(s.begin(), s.end(), ostream_iterator<char>(ss, "#"));
    // then ss.str() == "a#b#c#"
    ```

4. String Split
   ```c++
   string item;
   stringstream ss("a,b,,c");
   vector<string> vals;
   while (getline(ss, item, ',')) vals.emplace_back(item);
   // then vals == {a, b, , c}
   ```

## Pointer

1. `a[-1]` is legal if the element it accesses is valid and not out of array's bound

2. How to parse complicated declaration of pointer?
   **Theory Basis**
   > Right-Left Rule: Start reading the declaration from the variable name, go right, and then, go left. When you encounter parentheses, the direction should be reversed. Once everything in the parentheses has been parsed, jump out of it. Continue till the whole declaration has been parsed

   Examples:
   - `int (*func)(int *p);`
   Explanation: func is a pointer to a function, the function has an int pointer as argument and return int.
   - `int (*func)(int *p, int (*f)(int*));`
   Explanation: func is a pointer to a function, the function has two arguments with return type int. one is an int pointer and the other(f) is a pointer to a function which takes an int pointer as the only argmument with return type int.
   - `int (*func[5])(int *p);`
   Explanation: func is a 5-size array and its element is pointer which points to a function with int pointer as the only argument and int as return type.
   - `int (*(*func)(int *p))[5];`
   Explanation: func is a function pointer which points to a function with int pointer as argument and return type is a pointer which points to a 5-size int array.
   - `int (*(*func[7][8][9])(int*))[5];`
   Explanation: func is a 3D array and its element is a function pointer which points to a function with int pointer as argument and 5-size int array as return.


# Vector & Array

1. Sort an array `sort(begin(counter), end(counter));`

2. Sort in **descending order** ` sort(begin(counter), end(counter), greater<int>());`



# Misc

1. The evaluation order of operands of an operator is not specified in C. e.g. `x = ++n + g(n)`
This will cause unpredictable problem.
