#include <bits/stdc++.h>
#include <queue>
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
struct st {
    int a, b, c, x;
    int va() const {
        return a*x*x + b*x + c;
    }
    bool operator< (const st& other) const {return va() > other.va();}
};
void solve() {
    int n, m;
    cin >> n >> m;
    priority_queue<st> q;
    for (int i = 1; i <= n; ++i) {
        int a, b, c; cin >> a >> b >> c;
        q.push({a, b, c, 1});
    }
    for (int i = 1; i <= m; ++i) {
        st top = q.top();
        q.pop();
        cout << top.va() << " ";
        top.x += 1;
        q.push(top);
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
