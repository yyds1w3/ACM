//Wed Aug 12 02:55:26 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    std::string s1, s2;
    while (std::getline(std::cin, s1) && std::getline(std::cin, s2)) {
        std::vector<int> in(30, -1);
        std::vector<std::vector<int>> adj(30);
        int tot = 0;
        for (char c : s1) {
            if (c != ' ') {
                in[c - 'a'] = 0;
                tot++;
            }
        }
        int u = -1, v = -1;
        for (char c : s2) {
            if (c == ' ') continue;
            if (u == -1) u = c - 'a';
            else if (v == -1) {
                v = c - 'a';
                in[v]++;
                adj[u].push_back(v);
                u = -1;
                v = -1;
            }
        }
        std::string ans;
        auto dfs = [&](auto self) -> void {
            if (ans.size() == tot) {
                std::cout << ans << nl;
                return;
            }
            for (int i = 0; i < 26; ++i) {
                if (in[i] == 0) {
                    ans += 'a' + i;
                    in[i] = -1;
                    for (int v : adj[i]) {
                        in[v]--;
                    }
                    self(self);
                    for (int v : adj[i]) {
                        in[v]++;
                    }
                    in[i] = 0;
                    ans.pop_back();
                }
            }
        };
        dfs(dfs);
        std::cout << nl;
    }
}
