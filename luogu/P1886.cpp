#include <bits/stdc++.h>
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
int a[1000001];
void solve() {
    int n, k; cin >> n >> k;
    deque<int> qx, qn;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i){
        while (!qn.empty() && a[qn.back()] >= a[i]) qn.pop_back();
        qn.push_back(i);
        if (!qn.empty() && i - qn.front() >= k) qn.pop_front();
        if (i >= k) cout << a[qn.front()] << " ";
    }
    cout << "\n";
    for (int i = 1; i <= n; ++i){
        while (!qx.empty() && a[qx.back()] <= a[i]) qx.pop_back();
        qx.push_back(i);
        if (!qx.empty() && i - qx.front() >= k) qx.pop_front();
        if (i >= k) cout << a[qx.front()] << " ";
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
