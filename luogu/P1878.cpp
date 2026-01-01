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
const int MAXN = 2e5 + 1;
struct Person {
    int val;
    int sex;
    int id;
}a[MAXN];
int L[MAXN], R[MAXN];
bool vis[MAXN];
struct Pair {
    int u, v;
    int diff;
    bool operator<(const Pair& other) const {
        if (diff != other.diff) return diff > other.diff;
        return u > other.u;
    }
};
priority_queue<Pair> q;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    // 初始化a， 双向链表
    for (int i = 1; i <= n; ++i) {
        a[i].sex = (s[i-1] == 'B' ? 1 : 0);
        a[i].id = i;
        L[i] = i - 1;
        R[i] = i + 1;
    }
    R[n] = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i].val;
    // 开始push舞伴
    for (int i = 1; i <= n - 1; ++i) {
        if (a[i].sex ^ a[i+1].sex) q.push({i, i+1, abs(a[i].val - a[i+1].val)});
    }
    vector<pair<int, int>> ans;
    while (!q.empty()) {
        Pair top = q.top();
        q.pop();
        int u = top.u;
        int v = top.v;
        if (vis[u] || vis[v]) continue;
        ans.push_back({u, v}); // 更新答案
        vis[u] = vis[v] = true;
        int pre = L[u];
        int nxt = R[v];
        if (pre != 0) R[pre] = nxt;
        if (nxt != 0) L[nxt] = pre;// 更新链表
        if (pre != 0 && nxt != 0) {
            if (a[pre].sex ^ a[nxt].sex) q.push({pre, nxt, abs(a[pre].val - a[nxt].val)}); // 动态更新堆
        }
    }
    cout << ans.size() << "\n";
    for (auto p : ans) {
        cout << p.first << " " << p.second << "\n";
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
