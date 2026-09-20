//Mon Aug 17 08:33:30 PM CST 2027
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
const int N = 128;
std::vector<int> f(N), sz(N);
void init(int n) {
    std::iota(f.begin(), f.begin() + n, 0);
    sz.assign(n, 1);
}
int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}
void merge(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx != ry) {
        f[rx] = ry;
        sz[ry] += sz[rx];
    }
}
bool same(int x, int y) {
    return find(x) == find(y);
}
int size(int x) {
    return sz[find(x)];
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::vector<std::string>> g(N);
    std::vector<int> in(N), out(N);
    init(N);
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        int u = s[0];
        int v = s.back();
        g[u].push_back(s);
        out[u]++;
        in[v]++;
        merge(u, v);
    }
    int root = -1;
    int tot = 0;
    for (int i = 0; i < N; ++i) {
        if (in[i] > 0 || out[i] > 0) {
            tot++;
            root = i;
        }
    }
    if (size(root) != tot) {
        std::cout << "***" << nl;
        return 0;
    }
    int s = -1, t = -1;
    bool ok = true;
    for (int i = 0; i < N; ++i) {
        if (out[i] == in[i] + 1) {
            if (s == -1) s = i;
            else ok = false;
        }else if (out[i] == in[i] - 1) {
            if (t == -1) t = i;
            else ok = false;
        }else if (out[i] != in[i]) {
            ok = false;
        }
    }
    if (!ok || (s == -1 && t != -1) || (s != -1 && t == -1)) {
        std::cout << "***" << nl;
        return 0;
    }
    if (s == -1) {
        for (int i = 0; i < N; ++i) {
            if (out[i] > 0) {
                s = i;
                break;
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        std::sort(g[i].rbegin(), g[i].rend());
    }
    std::vector<std::string> ans;
    auto dfs = [&](auto self, int u) -> void {
        while (!g[u].empty()) {
            std::string tmp = g[u].back();
            int v = tmp.back();
            g[u].pop_back();
            self(self, v);
            ans.push_back(tmp);
        }
    };
    dfs(dfs, s);
    std::reverse(ans.begin(), ans.end());
    for (int i = 0; i < (int)ans.size(); ++i) {
        std::cout << ans[i] << (i < (int)ans.size() - 1 ? "." : "");
    }
    std::cout << nl;
}
