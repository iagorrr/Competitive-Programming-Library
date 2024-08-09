# Competitive Programming Library

My own competitive programming library designed to be used in both presential contests, like [ICPC](https://icpc.global/), or online platforms such as [Codeforces](https://codeforces.com/), [AtCoder](https://atcoder.jp/), etc...

Some notes about the implementations:

- Each implementation should be self-contained, so once you typed or copied there is no need to look for other files, the only "template" you need is :

    ```cpp
    #include<bits/stdc++.h>
    using namespace std;
    ```

- Should be as short as possible, as you may have to type it in a presential contest

You can find a little explanation about each algorithm at the [PDF Notebook](notebook.pdf)


## Algorithms


#### Data Structures
- Segtree Dynamic
    - [segtree rsq psu (dynamic)](/algorithms/data-structures/segtree-dynamic/segtree-rsq-psu-(dynamic).cpp)
    - [segtree rmaxq pmaxu (dynamic)](/algorithms/data-structures/segtree-dynamic/segtree-rmaxq-pmaxu-(dynamic).cpp)

- Segtree Point Update (Bottom Up)
    - [query max subarray sum](/algorithms/data-structures/segtree-point-update-(bottom-up)/query-max-subarray-sum.cpp)
    - [query gcd](/algorithms/data-structures/segtree-point-update-(bottom-up)/query-gcd.cpp)
    - [query sum](/algorithms/data-structures/segtree-point-update-(bottom-up)/query-sum.cpp)
    - [query min](/algorithms/data-structures/segtree-point-update-(bottom-up)/query-min.cpp)

- Segtree Point Update (Top Down)
    - [query sum](/algorithms/data-structures/segtree-point-update-(top-down)/query-sum.cpp)
    - [struct](/algorithms/data-structures/segtree-point-update-(top-down)/struct.cpp)
    - [query hash](/algorithms/data-structures/segtree-point-update-(top-down)/query-hash.cpp)

- Segtree Range Update (Bottom Up)
    - [increment update query sum](/algorithms/data-structures/segtree-range-update-(bottom-up)/increment-update-query-sum.cpp)

- Segtree Range Update (Top Down)
    - [segtree PA](/algorithms/data-structures/segtree-range-update-(top-down)/segtree-PA.cpp)
    - [struct](/algorithms/data-structures/segtree-range-update-(top-down)/struct.cpp)
    - [set and increment update sum query](/algorithms/data-structures/segtree-range-update-(top-down)/set-and-increment-update-sum-query.cpp)
    - [increment update max query](/algorithms/data-structures/segtree-range-update-(top-down)/increment-update-max-query.cpp)

- Sqrt_Decomposition
    - [two sequence queries](/algorithms/data-structures/sqrt_decomposition/two-sequence-queries.cpp)

- [bitree 2d](/algorithms/data-structures/bitree-2d.cpp)
- [bitree](/algorithms/data-structures/bitree.cpp)
- [convex hull trick](/algorithms/data-structures/convex-hull-trick.cpp)
- [disjoint sparse table](/algorithms/data-structures/disjoint_sparse_table.cpp)
- [dsu](/algorithms/data-structures/dsu.cpp)
- [lichao tree dynamic](/algorithms/data-structures/lichao-tree-dynamic.cpp)
- [merge sort tree](/algorithms/data-structures/merge-sort-tree.cpp)
- [mex](/algorithms/data-structures/mex.cpp)
- [ordered set gnu pbds](/algorithms/data-structures/ordered_set_gnu_pbds.cpp)
- [prefix sum 2d](/algorithms/data-structures/prefix-sum-2d.cpp)
- [sparse table](/algorithms/data-structures/sparse-table.cpp)
- [venice set](/algorithms/data-structures/venice-set.cpp)
- [wavlet tree](/algorithms/data-structures/wavlet-tree.cpp)



#### Dynamic Programming
- Digits
    - [longest increasing subsequence](/algorithms/dynamic-programming/digits/longest-increasing-subsequence.cpp)
    - [sum digits divisible by d](/algorithms/dynamic-programming/digits/sum-digits-divisible-by-d.cpp)
    - [number divisible by sum of digits](/algorithms/dynamic-programming/digits/number-divisible-by-sum-of-digits.cpp)
    - [product of digits less equal than k](/algorithms/dynamic-programming/digits/product-of-digits-less-equal-than-k.cpp)
    - [no 13 and 4 as substr](/algorithms/dynamic-programming/digits/no-13-and-4-as-substr.cpp)
    - [no consecutive equal](/algorithms/dynamic-programming/digits/no-consecutive-equal.cpp)

- [binary knapsack (bottom up)](/algorithms/dynamic-programming/binary-knapsack-(bottom-up).cpp)
- [binary knapsack (top down)](/algorithms/dynamic-programming/binary-knapsack-(top-down).cpp)
- [edit distance](/algorithms/dynamic-programming/edit_distance.cpp)
- [kadane](/algorithms/dynamic-programming/kadane.cpp)
- [knapsack with quantity (no recover)](/algorithms/dynamic-programming/knapsack-with-quantity-(no-recover).cpp)
- [longest increasing subsequence](/algorithms/dynamic-programming/longest-increasing-subsequence.cpp)
- [min cost to make subsequence of substring a palindrome with size k](/algorithms/dynamic-programming/min-cost-to-make-subsequence-of-substring-a-palindrome-with-size-k.cpp)
- [money sum bottom up](/algorithms/dynamic-programming/money_sum_bottom_up.cpp)
- [tsp](/algorithms/dynamic-programming/tsp.cpp)



#### Extras
- [binary to gray](/algorithms/extras/binary_to_gray.cpp)
- [closest value greater than](/algorithms/extras/closest_value_greater_than.cpp)
- [get permutation cycles](/algorithms/extras/get-permutation-cycles.cpp)
- [hanoi tower](/algorithms/extras/hanoi-tower.cpp)
- [meet in the middle](/algorithms/extras/meet-in-the-middle.cpp)
- [mos algorithm](/algorithms/extras/mos_algorithm.cpp)
- [ternary search recursive](/algorithms/extras/ternary_search_recursive.cpp)
- [to any base](/algorithms/extras/to-any-base.cpp)



#### Geometry
- [check point inside triangle](/algorithms/geometry/check-point-inside-triangle.cpp)
- [convex hull](/algorithms/geometry/convex-hull.cpp)
- [determinant](/algorithms/geometry/determinant.cpp)
- [equals](/algorithms/geometry/equals.cpp)
- [line](/algorithms/geometry/line.cpp)
- [point struct and utils (2d)](/algorithms/geometry/point-struct-and-utils-(2d).cpp)
- [polygon lattice points](/algorithms/geometry/polygon-lattice-points.cpp)
- [segment intersection](/algorithms/geometry/segment-intersection.cpp)
- [segment](/algorithms/geometry/segment.cpp)
- [template line](/algorithms/geometry/template-line.cpp)
- [template point](/algorithms/geometry/template-point.cpp)
- [template segment](/algorithms/geometry/template-segment.cpp)



#### Graphs
- Flow Problems
    - [minimum cost flow](/algorithms/graphs/Flow%20Problems/minimum-cost-flow.cpp)
    - [Maximum Flow (Dinic)](/algorithms/graphs/Flow%20Problems/Maximum%20Flow%20(Dinic).cpp)
    - [minimum cut (unweighted)](/algorithms/graphs/Flow%20Problems/minimum-cut-(unweighted).cpp)
    - [maximum flow (edmonds karp)](/algorithms/graphs/Flow%20Problems/maximum-flow-(edmonds-karp).cpp)

- Heavy Light Decomposition (Point Update)
    - [Maximum Number on Path](/algorithms/graphs/Heavy-Light%20Decomposition%20(point%20update)/Maximum%20Number%20on%20Path.cpp)

- [2 SAT](/algorithms/graphs/2-SAT.cpp)
- [Cycle Distances](/algorithms/graphs/Cycle-Distances.cpp)
- [Extra edges to make directed graph fully connected](/algorithms/graphs/Extra%20edges%20to%20make%20directed%20graph%20fully%20connected.cpp)
- [Strongly Connected Components](/algorithms/graphs/Strongly%20Connected%20Components.cpp)
- [bellman ford (find negative cycle)](/algorithms/graphs/bellman-ford-(find-negative-cycle).cpp)
- [bellman ford](/algorithms/graphs/bellman-ford.cpp)
- [bfs 01](/algorithms/graphs/bfs-01.cpp)
- [biconnected components](/algorithms/graphs/biconnected-components.cpp)
- [binary lifting](/algorithms/graphs/binary-lifting.cpp)
- [block cut tree](/algorithms/graphs/block-cut-tree.cpp)
- [check bipartite](/algorithms/graphs/check-bipartite.cpp)
- [dijkstra (k shortest paths)](/algorithms/graphs/dijkstra-(k-shortest-paths).cpp)
- [dijkstra (restore path)](/algorithms/graphs/dijkstra-(restore-path).cpp)
- [disjoint edge paths (maxflow)](/algorithms/graphs/disjoint-edge-paths-(maxflow).cpp)
- [euler path (directed)](/algorithms/graphs/euler-path-(directed).cpp)
- [euler path (undirected)](/algorithms/graphs/euler-path-(undirected).cpp)
- [find articulation points](/algorithms/graphs/find-articulation-points.cpp)
- [find bridge tree components](/algorithms/graphs/find-bridge-tree-components.cpp)
- [find bridges (online)](/algorithms/graphs/find-bridges-(online).cpp)
- [find bridges](/algorithms/graphs/find-bridges.cpp)
- [find centroid](/algorithms/graphs/find-centroid.cpp)
- [floyd warshall](/algorithms/graphs/floyd_warshall.cpp)
- [functional graph](/algorithms/graphs/functional-graph.cpp)
- [graph cycle (directed)](/algorithms/graphs/graph-cycle-(directed).cpp)
- [graph cycle (undirected)](/algorithms/graphs/graph_cycle-(undirected).cpp)
- [kruskal](/algorithms/graphs/kruskal.cpp)
- [lowest common ancestor (binary lifting)](/algorithms/graphs/lowest-common-ancestor-(binary-lifting).cpp)
- [lowest common ancestor (sparse table)](/algorithms/graphs/lowest-common-ancestor-(sparse-table).cpp)
- [minimum vertex cover (already divided)](/algorithms/graphs/minimum-vertex-cover-(already-divided).cpp)
- [prim](/algorithms/graphs/prim.cpp)
- [shortest path with k edges](/algorithms/graphs/shortest-path-with-k-edges.cpp)
- [small to large](/algorithms/graphs/small_to_large.cpp)
- [successor graph (struct)](/algorithms/graphs/successor_graph-(struct).cpp)
- [sum every node distance](/algorithms/graphs/sum-every-node-distance.cpp)
- [topological sorting (kahn)](/algorithms/graphs/topological-sorting-(kahn).cpp)
- [topological sorting (tarjan)](/algorithms/graphs/topological-sorting-(tarjan).cpp)
- [tree diameter (dp)](/algorithms/graphs/tree-diameter-(dp).cpp)
- [tree isomorphism (not rooted)](/algorithms/graphs/tree-isomorphism-(not-rooted).cpp)
- [tree isomorphism (rooted)](/algorithms/graphs/tree-isomorphism-(rooted).cpp)
- [tree maximum distances](/algorithms/graphs/tree-maximum-distances.cpp)



#### Math
- [GCD](/algorithms/math/GCD.cpp)
- [LCM](/algorithms/math/LCM.cpp)
- [arithmetic progression sum](/algorithms/math/arithmetic-progression-sum.cpp)
- [binomial mod](/algorithms/math/binomial-mod.cpp)
- [binomial](/algorithms/math/binomial.cpp)
- [chinese remainder theorem](/algorithms/math/chinese-remainder-theorem.cpp)
- [derangement](/algorithms/math/derangement.cpp)
- [euler phi (in range)](/algorithms/math/euler-phi-(in-range).cpp)
- [euler phi](/algorithms/math/euler-phi.cpp)
- [factorial factorization](/algorithms/math/factorial-factorization.cpp)
- [factorization (Pollard)](/algorithms/math/factorization-(Pollard).cpp)
- [factorization](/algorithms/math/factorization.cpp)
- [fast pow](/algorithms/math/fast-pow.cpp)
- [fft convolution](/algorithms/math/fft-convolution.cpp)
- [find multiplicative inverse](/algorithms/math/find-multiplicative-inverse.cpp)
- [find solution diophantine equation](/algorithms/math/find-solution-diophantine-equation.cpp)
- [gauss elimination](/algorithms/math/gauss-elimination.cpp)
- [gauss xor](/algorithms/math/gauss-xor.cpp)
- [integer mod](/algorithms/math/integer_mod.cpp)
- [integer partition](/algorithms/math/integer-partition.cpp)
- [linear recurrence](/algorithms/math/linear-recurrence.cpp)
- [list n elements choose k](/algorithms/math/list-n-elements-choose-k.cpp)
- [matrix exponentiation](/algorithms/math/matrix-exponentiation.cpp)
- [ntt int convolution and exp](/algorithms/math/ntt-int-convolution-and-exp.cpp)
- [ntt int convolution two mods](/algorithms/math/ntt-int-convolution-two-mods.cpp)
- [polyominoes](/algorithms/math/polyominoes.cpp)
- [power sum](/algorithms/math/power-sum.cpp)
- [sieve list primes](/algorithms/math/sieve-list-primes.cpp)



#### Primitives
- [bigint](/algorithms/primitives/bigint.cpp)
- [integer mod](/algorithms/primitives/integer_mod.cpp)
- [matrix](/algorithms/primitives/matrix.cpp)



#### Strings
- [count distinct anagrams](/algorithms/strings/count-distinct-anagrams.cpp)
- [double hash range query](/algorithms/strings/double-hash-range-query.cpp)
- [hash big mod](/algorithms/strings/hash-big-mod.cpp)
- [hash range query](/algorithms/strings/hash-range-query.cpp)
- [hash ull](/algorithms/strings/hash-ull.cpp)
- [kth digit in digit string](/algorithms/strings/kth-digit-in-digit-string.cpp)
- [longest palindrome substring (manacher)](/algorithms/strings/longest-palindrome-substring-(manacher).cpp)
- [longest palindrome](/algorithms/strings/longest-palindrome.cpp)
- [rabin karp](/algorithms/strings/rabin-karp.cpp)
- [suffix array](/algorithms/strings/suffix-array.cpp)
- [suffix automaton (complete)](/algorithms/strings/suffix-automaton-(complete).cpp)
- [trie](/algorithms/strings/trie.cpp)
- [z function get occurence positions](/algorithms/strings/z-function-get-occurence-positions.cpp)



## References & Courses

- [Thalisson's Library](https://github.com/Thalisson-Alves/Competitive-Programming)
- [Macacário](https://github.com/splucs/Competitive-Programming)
- [KACTL ICPC Code Library](https://github.com/kth-competitive-programming/kactl)
- [PauloMiranda98's Library](https://github.com/PauloMiranda98/Competitive-Programming-Notebook)
- [SSRS lib](https://ssrs-cp.github.io/cp_library/)
- [IME algoritmos](https://www.ime.usp.br/~pf/algoritmos/idx.html)
- [UFMG Library](https://github.com/brunomaletta/Biblioteca)

- [TEP](https://github.com/edsomjr/TEP)
- [UnBalloon](https://github.com/UnBalloon/programacao-competitiva)
- [Algorithms for Competitive Programming](https://cp-algorithms.com/)
- [Neps Academy](https://neps.academy/br/courses)
- [USACO Guide](https://usaco.guide/dashboard/)
- [Competitive Programing Book](https://cpbook.net/details?cp=4)
- [Competitive Programmer's Handbook](https://cses.fi/book/book.pdf)


