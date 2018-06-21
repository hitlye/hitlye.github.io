---
layout: posts
title: Notes of C and C++
date: 2018-06-13 15:24:45
tags: [c, c++, note]
categories:
- tech
- c/c++
---

# Input & Output

## In C Programming Language

#include "stdio.h"
- `int putc(int c, FILE* f)`: put **c** to f, buffering
- `int fputc(int c, FILE* f)`: ...
- `int putchar(int c)`: 2nd argument is STDOUT
- `int fputchar(int c)`: ...
<!-- more -->
---
- `int getc(FILE* f)`: get **c** from f, buffering
- `int fgetc(FILE* f)`: ...
- `int getchar()`: 2nd argument is STDIN
- `int fgetchar()`: ...
---
- `char* fgets(char* str, int num, FILE* f)`: read from **f** until **'\n'** or **num**. **'\n'**(Conditional) and **'\0'**(Required) will be attached to the end of **str**.
- **(Deprecated)**`char* gets(char* str)`: No *num* and **'\n'**
- `int fputs(const char* str, FILE* f)`: put **str** to **f** until **'\0'**
- `int puts(const char* str)`: put **str** to **STDOUT** and will append **'\n'** to the end of str
---
- `int scanf(const char* format, ...)`: [Click](http://www.cplusplus.com/reference/cstdio/scanf/)
- `int printf(const char* format, ...)`: [Click](http://www.cplusplus.com/reference/cstdio/printf/)
- `sscanf\sprintf`: ...
---
**Note**: fopen/fwrite/fread/fseek/fclose/fscanf/fprintf in [Click](http://www.cplusplus.com/)

## In C++ Programming Language

# Data Type

## String / Char*

1. All strings terminate with `'\0'`.

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


# Misc

1. The evaluation order of operands of an operator is not specified in C. e.g. `x = ++n + g(n)`
This will cause unpredictable problem.
