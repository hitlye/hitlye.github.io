---
title: Foundation of Computer System - Big Picture
date: 2018-06-19 00:24:35
mathjax: true
tags: [computer-system, csapp, 18600]
category:
- tech
- system
- foundation of computer system
---

# Get Started

## What is a computer?

Actually, it is hard to answer this question. Since a computer contains countless design ideas including hardware & software, processor & memory and operating system & compiler.
But if we stand in a high level, then the computer we are using is an **Subclass** of **[Von Neumann architecture](https://en.wikipedia.org/wiki/Von_Neumann_architecture).**

   {% asset_img von-neumann-architecture.png von-neumann-architecure %}
<!-- more -->

   <center>**Figure 1. Von Neumann Architecture **</center>

A computer consists of:

1. Control Unit inside Central Process Unit(CPU).
2. Arithmetic/Logic Unit(ALU) inside Central Process Unit(CPU).
3. Memory
4. I/O Devices

# More Specifically

## What is a computer system?

Now, the second qeustion comes. Obviously, the computer system is differ from computer, since the latter contains new word **system**. Just like the 1st question, we will also give you a specific picture of computer system. In addition, it is one of the most important thing you should be focused on.

{% asset_img isa-based-architecture.png isa-based-architecutre %}
   <center>**Figure 2. ISA Based Architecture**</center>

From the above architecure, we can make some conclusions:

```text
Computer System = Software + Hardware
                = [Application + Operation System] + Computer
                = [Programming Languages + Operating System] + Computer Architecture
```

You may notice that in the conclusions above, we try to use `[]` to separate `Software` from `Hardware`. Why? The answer is the middle line in the picture - `ISA`.

ISA is the abbreviate of **Instruction Set Architecture**, and all you need to know about it are:

1. All codes are parsed to **instructions** and then run by computer. ISA contains the description and definition of these instructions.
e.g. `b = a + c` ==> `get a, get c, add a to c, push result to b`
2. Isa is used to separate software from hardware, but not unrelated. In contrast, software and hardware need to communicate with each other. And ISA is the bridge and contract.
3. Why should we have ISA? To make software and hardware can evolve independently. This will make life easy.

# Evaluation

The performance of computer is very important, so we have to evaluate it. Here we'll introduce three methods:

1. Computer Performance - Iron Law
   {% asset_img iron-law.png Iron Law%}
   <center>**Figure 3. Iron Law**</center>

2. Program Performance - Amdahl's Law
    $$ Speedup = \frac{1}{(1 - f) + \frac{f}{N}} $$
    * f: fraction of program that is vectorizable or parallelizable
    * N: Parallelized rate
    
3. Machine Performance - Moore's Law
> (Transistors/Die) increases by 2x every 18 months

