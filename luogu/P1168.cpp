#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using i128 = __int128;
priority_queue<int> qx;
priority_queue<int, vector<int>, greater<int>> qn;
int n;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        qx.push(a);
        qn.push(qx.top());
        qx.pop();
        if (qn.size() > qx.size()) {
            qx.push(qn.top());
            qn.pop();
        }
        if (i % 2 == 1) cout << qx.top() << "\n";
    }
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
