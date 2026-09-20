//Sat Jul 25 03:12:53 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

u64 f(u64 x) {
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;

    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
}
void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj1(n), adj2(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }
    std::vector<u64> D1(n, 1), D2(n + 1, 1), U1(n), U2(n + 1);
    auto dfs11 = [&](auto self, int u, int fa) -> void {
        for (int v : adj1[u]) if (v != fa) {
            self(self, v, u);
            D1[u] += f(D1[v]);
        }
    };
    dfs11(dfs11, 0, 0);
    auto dfs12 = [&](auto self, int u, int fa) -> void {
        for (int v : adj1[u]) if (v != fa) {
            U1[v] = D1[u] - f(D1[v]) + (u == 0 ? 0 : f(U1[u])); 
            self(self, v, u);
        }
    };
    dfs12(dfs12, 0, 0);
    auto dfs21 = [&](auto self, int u, int fa) -> void {
        for (int v : adj2[u]) if (v != fa) {
            self(self, v, u);
            D2[u] += f(D2[v]);
        }
    };
    dfs21(dfs21, 0, 0);
    auto dfs22 = [&](auto self, int u, int fa) -> void {
        for (int v : adj2[u]) if (v != fa) {
            U2[v] = D2[u] - f(D2[v]) + (u == 0 ? 0 : f(U2[u]));
            self(self, v, u);
        }
    };
    dfs22(dfs22, 0, 0);

    std::vector<u64> hashA(n), hashB(n + 1);
    for (int i = 0; i < n; ++i) {
        hashA[i] = D1[i] + (i == 0 ? 0 : f(U1[i]));
    }
    std::sort(hashA.begin(), hashA.end());
    for (int i = 0; i <= n; ++i) {
        hashB[i] = D2[i] + (i == 0 ? 0 : f(U2[i]));
    }
    for (int i = 0; i <= n; ++i) {
        if (adj2[i].size() == 1) {
            int p = adj2[i][0];
            u64 target = hashB[p] - f(1);
            if (std::binary_search(hashA.begin(), hashA.end(), target)) {
                std::cout << i + 1 << nl;
                return;
            }
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
