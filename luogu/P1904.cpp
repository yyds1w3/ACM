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

struct st{
    int v, id;
    bool operator<(const st& other) const {if (v != other.v) return v < other.v; return id < other.id;}
}a[100001];
bool vis[100001];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].v;
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n);
    int cnt = 0, ans = 1;
    for (int i = 1; i <= n; ++i){
        if (i < a[i].id) cnt++; // 有逆序对， 流量+1 // 每次只能把最小的元素运送到对应的位置
        if (vis[i]) cnt--; // 发现发源地， 流量-1
        vis[a[i].id] = true; // 标记发源地
        ans = max(ans, cnt); // 记录最大重叠区间
    }
    cout << ans;
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
