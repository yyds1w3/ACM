// 题目说的有负权边，故每个节点初始化为-INF
// 如果没有人访问某一个点，那么该节点不可达到, 值为-INF
// 因为题目说u < w， 所以1~n一定是一个拓扑排序，我们只需要从一到n处理就行了， 然后dp无效性来求最大值
// 为什么不初始化为-1， 当-1时, a -> b 的权值为-1, 程序会以为b不可达就错了
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
const int MAXN = 1501;
const int INF = 0x3f3f3f3f;
struct Edge{
    int v, w;
};
vector<Edge> adj[MAXN];
ll dp[MAXN];
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    fill(dp, dp + n + 1, -INF);
    dp[1] = 0;
    for (int u = 1; u <= n; ++u){
        if (dp[u] == -INF) continue;
        for (auto edge : adj[u]){
            int v = edge.v;
            int w = edge.w;
            dp[v] = max(dp[v], dp[u] + w);
        }
    }
    if (dp[n] == -INF) cout << "-1";
    else cout << dp[n];

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) {
        freopen("in.txt", "r", stdin);
    }
    auto _clock_start = chrono::high_resolution_clock::now();
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
#ifdef LOCAL
    auto _clock_end = chrono::high_resolution_clock::now();
    cerr << "Run Time: " 
         << chrono::duration_cast<chrono::milliseconds>(_clock_end - _clock_start).count() 
         << " ms" << endl;
#endif
    return 0;
}
