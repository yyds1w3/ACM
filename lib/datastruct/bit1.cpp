#include <bits/stdc++.h>
using i64 = long long;
const int N = 2e5;
int n;
i64 treeA[N + 1];
void initBIT(int n) {
    std::fill(treeA, treeA + n, 0);
}
void add(int pos, i64 val) {
    for (int i = pos + 1; i <= n; i += i&-i) {
        treeA[i] += val;
    }
}
// [0, pos)
i64 sum(int pos) {
    i64 res = 0;
    for (int i = pos; i >= 1; i -= i&-i) {
        res += treeA[i];
    }
    return res;
}
// [l, r)
i64 ask(int l, int r) {
    return sum(r) - sum(l);
}
void upd(int pos, i64 val) {
    i64 x = val - ask(pos, pos+1);
    add(pos, x);
}
