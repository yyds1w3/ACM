#include <bits/stdc++.h>
using i64 = long long;

const int N = 3e4;
int f[N], val[N], siz[N];
void initDSU2(int n) {
    for (int i = 0; i < n; ++i) {
        f[i] = i;
        val[i] = 0;
        siz[i] = 1;
    }
}
int find(int x) {
    if (x == f[x]) return x;
    int root = find(f[x]);
    val[x] += val[f[x]];
    return f[x] = root;
}
void merge(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx == ry) return;
    f[rx] = ry;
    val[rx] = siz[ry];
    siz[ry] += siz[rx];
}
bool same(int x, int y) {
    return find(x) == find(y);
}
bool size(int x) {
    return siz[find(x)];
}

