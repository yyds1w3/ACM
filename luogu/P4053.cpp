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
const int MAXN = 1.5e5 + 1;
struct st {
    int t1, t2;
    bool operator< (const st& other) const {return t2 < other.t2;}
}a[MAXN];
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].t1 >> a[i].t2;
    }
    sort(a + 1, a + 1 + n);
    priority_queue<int> q;
    ll now = 0;
    for (int i = 1; i <= n; ++i) {
        if (now + a[i].t1 <= a[i].t2) {
            now += a[i].t1;
            q.push(a[i].t1);
        }else {
            if (!q.empty() && q.top() > a[i].t1) {
                now -= q.top();
                q.pop();
                now += a[i].t1;
                q.push(a[i].t1);
            }
        }
    }
    cout << q.size() << "\n";
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
