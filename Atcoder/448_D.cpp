#include <bits/stdc++.h>
#include <vector>
using ll = long long;
using i128 = __int128;
#define nl "\n"
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
    std::vector<std::vector<int>> adj(N);
    for (int i = 0; i < N - 1; ++i) {
        int U, V;
        std::cin >> U >> V;
        U--, V--;
        adj[U].push_back(V);
        adj[V].push_back(U);
    }
    std::vector<bool> ans(N);
    std::map<int, int> cnt;
    auto dfs = [&](auto self, int u, int fa, bool dup) -> void{
        cnt[A[u]]++;
        ans[u] = (dup || cnt[A[u]] >= 2);
        for (int v : adj[u]) {
            if (v == fa) continue;
            self(self, v, u, ans[u]);
        }
        cnt[A[u]]--;
    };
    dfs(dfs, 0, -1, false);
    for (int i = 0; i < N; ++i) {
        std::cout << (ans[i] ? "Yes" : "No") << nl;
    }

}
