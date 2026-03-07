#include <bits/stdc++.h>
#include <bitset>
#include <vector>
using namespace std;
using ll = long long;
using i128 = __int128;
#define nl "\n"
#define debug(x) cerr << x << endl
const int MAXN = 1005;
vector<int> w(MAXN);
vector<vector<int>> adj(MAXN);
bitset<MAXN> dp[MAXN];
void dfs(int u, int fa) {
    bool is_leaf = true;
    bitset<MAXN> cur;
    cur[0] = 1;
    for (int v : adj[u]) {
        if (v == fa) continue;
        is_leaf = false;
        dfs(v, u);
        bitset<MAXN> nxt;
        for (int i = 0; i <= 1000; ++i) {
            if (dp[v][i] == true) {
                nxt |= (cur << i);
            }
        }
        cur = nxt;
    }
    if (is_leaf) {
        dp[u][0] = 1;
        dp[u][w[u]] = 1;
    }else {
        for (int i = w[u] + 1; i <= 1000; ++i) {
            cur[i] = 0;
        }
        dp[u] = cur;
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 0, u, v; i < n-1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    for (int k = w[1]; k >= 0; --k) {
        if (dp[1][k] == true) {
            cout << k << nl;
            return 0;
        }
    }

}
