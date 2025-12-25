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
deque<int> q;
const int MAXN = 2e6 + 1;
int a[MAXN];
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        int t = a[i];
        while (!q.empty() && t >= a[q.back()])
            q.pop_back();
        q.push_back(i);
        if (!q.empty() && i - q.front() >= k)
            q.pop_front();
        if (i >= k) cout << a[q.front()] << endl;
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
