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
const int MAXN = 2e5 + 1;
const int INF = 1e9 + 1;
void solve() {
    int n, x; cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    ll health = 0;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        health += x;
        q.push(x);
        while (health < 0) {
            health -= q.top();
            q.pop();
        }
    }
    cout << q.size();
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
