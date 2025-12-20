#include <bits/stdc++.h>
#include <deque>
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
int a[500005];
int pi[500005];
void solve() {
    int n, m, mx = -0x3f3f3f3f;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        pi[i] = a[i] + pi[i-1];
    }
    // 单调队列
    deque<int> q;
    q.push_back(0);
    for (int j = 1; j <= n; ++j){
        while(!q.empty() && pi[q.back()] >= pi[j - 1]) q.pop_back();
        q.push_back(j - 1);
        while(!q.empty() && q.front() < j - m) q.pop_front();
        mx = max(mx, pi[j] - pi[q.front()]);
    }
    cout << mx;
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
