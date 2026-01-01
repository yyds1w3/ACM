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
const int MAXN = 1e5 + 1;
int a[MAXN], b[MAXN];
struct st {
    int x, y;
    int va() const {return a[x] + b[y];}
    bool operator<(const st& other) const {return va() > other.va();}
};
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    priority_queue<st> q;
    for (int i = 1; i <= n; ++i) {
        q.push({i, 1});
    }
    for (int i = 1; i <= n; ++i) {
        st top = q.top();
        q.pop();
        cout << top.va() << " ";
        top.y++;
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
