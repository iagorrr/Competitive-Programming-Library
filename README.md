# Competitive-Programming-Algorithms
- A repository to store my solutions to competitive programming problems, of some platforms, and also useful algorithms and links to study.

## Algorithms and Data Structures

### Sorting

<details> <summary> <i>extras</i> </summary>

- [Test sort algorithms](https://www.codechef.com/problems/TSORT)

</details>

1. Quicksort
   1. [Partition <img src="https://upload.wikimedia.org/wikipedia/commons/archive/3/35/20220802133510%21The_C_Programming_Language_logo.svg" height=20px>](algorithms/ds-c/partition.c)
   2. [Quicksort Naive <img src="https://upload.wikimedia.org/wikipedia/commons/archive/3/35/20220802133510%21The_C_Programming_Language_logo.svg" height=20px>](algorithms/ds-c/quicksort_1_naive.c)
   3. [Quicksort M3 <img src="https://upload.wikimedia.org/wikipedia/commons/archive/3/35/20220802133510%21The_C_Programming_Language_logo.svg" height=20px>](algorithms/ds-c/quicksort_2_m3.c)
   4. [Quicksort M3 and Insertion <img src="https://upload.wikimedia.org/wikipedia/commons/archive/3/35/20220802133510%21The_C_Programming_Language_logo.svg" height=20px>](algorithms/ds-c/quicksort_3_m3_insertion.c)
   5. [Quicksort M3 and Insertion with max recurstion <img src="https://upload.wikimedia.org/wikipedia/commons/archive/3/35/20220802133510%21The_C_Programming_Language_logo.svg" height=20px>](algorithms/ds-c/quicksort_4_m3_insertion_maxrec.c)
    <details> <summary> <i>extras</i> </summary>

    [partition animation](http://cs.armstrong.edu/liang/animation/animation.html)

    </details>
2. Merge Sort
   1. [ Regular <img src="https://upload.wikimedia.org/wikipedia/commons/archive/3/35/20220802133510%21The_C_Programming_Language_logo.svg" height=20px>](algorithms/ds-c/merge_sort.c)

### Searching

1. Binary Search [<img src="https://upload.wikimedia.org/wikipedia/commons/archive/3/35/20220802133510%21The_C_Programming_Language_logo.svg" height=20px>](algorithms/ds-c/binary_search.c)
2. Ternary Search
   1. [Recursive with eps <img src="https://upload.wikimedia.org/wikipedia/commons/1/18/ISO_C%2B%2B_Logo.svg" height=20px>](algorithms/ternary_search_recursive.cpp)

### Strings

1.Morris-Pratt [<img src="https://upload.wikimedia.org/wikipedia/commons/archive/3/35/20220802133510%21The_C_Programming_Language_logo.svg" height=20px>](algorithms/morris-pratt.c)
      <details>
         ```
            Find the total occurrence of the string P as substring of S in O(N+M)
         ```
      [Test implementation](https://cses.fi/problemset/task/1753/)
      </details>

### Data structures
1. Stack
   1. [Naive <img src="https://upload.wikimedia.org/wikipedia/commons/archive/3/35/20220802133510%21The_C_Programming_Language_logo.svg" height=20px>](algorithms/ds-c/stack_naive.c)
2. Double Linked List
   1. [Naive <img src="https://upload.wikimedia.org/wikipedia/commons/archive/3/35/20220802133510%21The_C_Programming_Language_logo.svg" height=20px>](algorithms/ds-c/double_linked_list_full.c)
3. Queue
   1. [Naive <img src="https://upload.wikimedia.org/wikipedia/commons/archive/3/35/20220802133510%21The_C_Programming_Language_logo.svg" height=20px>](algorithms/ds-c/queue_naive.c)
   2. [Circular <img src="https://upload.wikimedia.org/wikipedia/commons/archive/3/35/20220802133510%21The_C_Programming_Language_logo.svg" height=20px>](algorithms/ds-c/queue_circular.c)
   3. [Circular and dynamic <img src="https://upload.wikimedia.org/wikipedia/commons/archive/3/35/20220802133510%21The_C_Programming_Language_logo.svg" height=20px>](algorithms/ds-c/queue_circular_dynamic.c)
4. Segment Tree
   1. [Point update, Range minimum query <img src="https://upload.wikimedia.org/wikipedia/commons/1/18/ISO_C%2B%2B_Logo.svg" height=20px>](algorithms/segtree_point_rmq.cpp)
5. DSU/UFDS (Disjoint Set Union or Union-set Disjoint Set) [<img src="https://cdn3.emoji.gg/emojis/1850-python-logo.png" height="20px" alt="Python_Logo"></a>](algorithms/dsu.py)
   1. [c++ version](algorithms/dsu.cpp)
6. Prefix sum [<img src="https://cdn3.emoji.gg/emojis/1850-python-logo.png" height=20px alt="Python_Logo"></a>](algorithms/prefix_sum.py)
      <details>
         Exercises:
         1.[static range sum queries](https://cses.fi/problemset/task/1646)
      </details>
      
7. Sparse Table
   1. [RMQ <img src="https://upload.wikimedia.org/wikipedia/commons/1/18/ISO_C%2B%2B_Logo.svg" height=20px>](algorithms/sparse_table_rmq.cpp)

### Brute Force / Complete Search
1. Combinatorics N choose K
   1. [No repetitions <img src="https://upload.wikimedia.org/wikipedia/commons/1/18/ISO_C%2B%2B_Logo.svg" height=20px>](algorithms/combinatorics_no_repetitions.cpp)
   2. [With repetitions <img src="https://upload.wikimedia.org/wikipedia/commons/1/18/ISO_C%2B%2B_Logo.svg" height=20px>](algorithms/combinatorics_with_repetitions.cpp)
2. Arrangement N choose K
   1. [Recursive <img src="https://upload.wikimedia.org/wikipedia/commons/1/18/ISO_C%2B%2B_Logo.svg" height=20px>](algorithms/arrangement_rec.cpp)

### Graphs & Trees
1. Kruskal [<img src="https://cdn3.emoji.gg/emojis/1850-python-logo.png" height="15px" alt="Python_Logo"></a>](algorithms/fast_pow.c) 
1. LCA (Lowest Common Ancestor)
   1. [Sparse Table <img src="https://upload.wikimedia.org/wikipedia/commons/1/18/ISO_C%2B%2B_Logo.svg" height=20px>](algorithms/lowest_common_ancestor_sparse_table.cpp)


### Math

1. Fast exponentiation [<img src="https://upload.wikimedia.org/wikipedia/commons/1/18/ISO_C%2B%2B_Logo.svg" height=20px>](algorithms/fast_expp.cpp)[<img src="https://upload.wikimedia.org/wikipedia/commons/archive/3/35/20220802133510%21The_C_Programming_Language_logo.svg" height=22px>](algorithms/fast_exp.c)


2. [Fast Log 2 <img src="https://upload.wikimedia.org/wikipedia/commons/1/18/ISO_C%2B%2B_Logo.svg" height=20px>](algorithms/log2_fast.cpp)
<div align="center" max-height="100%">
    <img heigh="100px" src="https://raw.githubusercontent.com/Iagorrr04/Competitive-Programming-Algorithms/main/komi_algorithms.jpg">
</div>




<details><summary> <b>References & Courses</b> </summary>

- [TEP](https://github.com/edsomjr/TEP)
- [UnBalloon](https://github.com/UnBalloon/programacao-competitiva)
- [Macacário](https://github.com/splucs/Competitive-Programming)
- [Algorithms for Competitive Programming](https://cp-algorithms.com/)
- [Neps Academy](https://neps.academy/br/courses)
- [USACO Guide](https://usaco.guide/dashboard/)
- [IME algoritmos](https://www.ime.usp.br/~pf/algoritmos/idx.html )
</details>
