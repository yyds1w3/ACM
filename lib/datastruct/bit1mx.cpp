#include <bits/stdc++.h>
using i64 = long long;
const int N = 2e5;
const i64 INF = 2e18;
int n;
i64 treeA[N + 1];
void initBIT(int n) {
    std::fill(treeA, treeA + n + 1, -INF);
}
void add(int pos, i64 val) {
    for (int i = pos + 1; i <= N; i += i & -i) {
        treeA[i] = std::max(treeA[i], val);
    }
}
// [0, pos)
i64 sum(int pos) {
    i64 res = -INF;
    for (int i = pos; i >= 1; i -= i & -i) {
        res = std::max(res, treeA[i]);
    }
    return res;
}
