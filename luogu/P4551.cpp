#include <bits/stdc++.h>
#include <vector>
using i64 = long long;
using i128 = __int128;
#define nl "\n"

constexpr int N = 3200001;

int trie[N][2]; // trie[i][0] 表示第i个节点通过'a'去的下一个节点编号 描述了节点之间的路径
int tot; // 分配的总节点
int val[N];
void init() {
    tot = 0;
}
int newNode() {
    tot++;
    std::fill(trie[tot], trie[tot] + 2, 0);
    val[tot] = 0;
    return tot;
}
void insert(int w) {
    int p = 0;
    for (int i = 30; i >= 0; --i) {
        int x = (w >> i) & 1;
        if (trie[p][x] == 0) {
            trie[p][x] = newNode();
        }
        p = trie[p][x];
    }
}
struct Edge {
    int to, w;
};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n;
    std::cin >> n;
    std::vector<std::vector<Edge>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    std::vector<int> D(n);
    auto dfs = [&](auto self, int u, int fa) -> void {
        for (auto [v, w] : adj[u]) {
            if (v == fa) continue;
            D[v] = D[u] ^ w;
            self(self, v, u);
        }
    };
    dfs(dfs, 0, -1);
    int ans = 0;
    init();
    for (int i = 0; i < n; ++i) {
        insert(D[i]);
        int x = D[i];
        int p = 0;
        for (int j = 30; j >= 0; --j) {
            int bit = (x >> j) & 1;
            int target = !bit;
            if (trie[p][target] != 0) {
                x |= (1 << j);
                p = trie[p][target];
            }else {
                x &= ~(1 << j);
                p = trie[p][bit];
            }
        }
        ans = std::max(ans, x);
    }
    std::cout << ans << nl;
}
