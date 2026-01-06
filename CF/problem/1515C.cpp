#include <bits/stdc++.h>
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
const int MAXN = 1e5 + 1;
struct tower {
    int h, id;
    bool operator< (const tower& other) const {return h > other.h;}
};
void solve() {
    int n, m, x; cin >> n >> m >> x;
    priority_queue<tower> pq;
    for (int i = 1; i <= m; ++i) pq.push({0, i});
    int mx = 0;
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        int v; cin >> v;
        tower now = pq.top();
        pq.pop();
        ans.push_back(now.id);
        now.h += v;
        mx = max(now.h, mx);
        pq.push(now);
    }
    cout << "YES\n";
    for (int v : ans) cout << v << " ";
    cout << "\n";
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
