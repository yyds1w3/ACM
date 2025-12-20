// 正解是sort + unique来去重，因为数组在栈上且是连续内存，比set的堆快（分散）
#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
unordered_set<int> row;
unordered_set<int> col;
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; ++i){
        int r, c;
        cin >> r >> c;
        row.insert(r);
        col.insert(c);
    }
    cout << n * (row.size() + col.size()) - row.size() * col.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
