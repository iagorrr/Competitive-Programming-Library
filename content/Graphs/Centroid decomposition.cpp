/*8<
  @Title: Centroid Decomposition
  @Description:
        Builds a vector $fat$ where $fat_i$ is who is the father of the node $i$
in the centroid decomposed tree. >8*/

#pragma once
#include "../Contest/template.cpp"

vi centroidDecomposition(const vi2d &g) {
    int n = len(g);
    vi fat(n, -1), szt(n), tk(n);
    function<int(int, int)> calcsz = [&](int x, int f) {
        szt[x] = 1;
        for (auto y : g[x])
            if (y != f && !tk[y]) szt[x] += calcsz(y, x);
        return szt[x];
    };
    function<void(int, int, int)> cdfs = [&](int x, int f, int sz) {
        if (sz < 0) sz = calcsz(x, -1);
        for (auto y : g[x])
            if (!tk[y] && szt[y] * 2 >= sz) {
                szt[x] = 0;
                cdfs(y, f, sz);
                return;
            }
        tk[x] = true;
        fat[x] = f;
        for (auto y : g[x])
            if (!tk[y]) cdfs(y, x, -1);
    };
    cdfs(0, -1, -1);
    return fat;
}
