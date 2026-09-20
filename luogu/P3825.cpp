#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, d;
    std::cin >> n >> d;
    std::string s;
    std::cin >> s;
    int m;
    std::cin >> m;
    std::vector<int> U(m), V(m);
    std::vector<char> HU(m), HV(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> U[i] >> HU[i] >> V[i] >> HV[i];
        U[i]--; V[i]--;
    }
    std::vector<int> pos_x;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'x') pos_x.push_back(i);
    }
    auto get_id = [&](char map_type, char car) -> int {
        if (map_type == 'a') return car == 'A' ? -1 : (car == 'B' ? 0 : 1);
        if (map_type == 'b') return car == 'B' ? -1 : (car == 'A' ? 0 : 1);
        if (map_type == 'c') return car == 'C' ? -1 : (car == 'A' ? 0 : 1);
        return -1;
    };
    auto get_car = [&](char map_type, int id) -> char {
        if (map_type == 'a') return id == 0 ? 'B' : 'C';
        if (map_type == 'b') return id == 0 ? 'A' : 'C';
        if (map_type == 'c') return id == 0 ? 'A' : 'B';
        return ' ';
    };
    for (int msk = 0; msk < (1 << d); ++msk) {
        std::string cur_s = s;
        for (int i = 0; i < d; ++i) {
            cur_s[pos_x[i]] = ((msk >> i) & 1) ? 'b' : 'a';
        }
        std::vector<std::vector<int>> adj(2 * n);
        for (int i = 0; i < m; ++i) {
            int u = U[i], v = V[i];
            int pu = get_id(cur_s[u], HU[i]);
            int pv = get_id(cur_s[v], HV[i]);
            if (pu == -1) continue; 
            if (pv == -1) {
                adj[2 * u + pu].push_back(2 * u + (pu ^ 1));
            } else {
                adj[2 * u + pu].push_back(2 * v + pv);
                adj[2 * v + (pv ^ 1)].push_back(2 * u + (pu ^ 1));
            }
        }
        int tot = 0, cnt = 0;
        std::vector<int> dfn(2 * n, 0), low(2 * n, 0), id(2 * n, 0), stk;
        auto dfs = [&](auto self, int u) -> void {
            dfn[u] = low[u] = ++tot;
            stk.push_back(u);
            for (int v : adj[u]) {
                if (!dfn[v]) {
                    self(self, v);
                    low[u] = std::min(low[u], low[v]);
                } else if (!id[v]) {
                    low[u] = std::min(low[u], dfn[v]);
                }
            }
            if (dfn[u] == low[u]) {
                cnt++;
                while (true) {
                    int x = stk.back();
                    stk.pop_back();
                    id[x] = cnt; 
                    if (x == u) break;
                }
            }
        };
        for (int i = 0; i < 2 * n; ++i) {
            if (!dfn[i]) dfs(dfs, i);
        }
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (id[2 * i] == id[2 * i + 1]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            for (int i = 0; i < n; ++i) {
                int choice = (id[2 * i + 1] < id[2 * i]) ? 1 : 0;
                std::cout << get_car(cur_s[i], choice);
            }
            std::cout << "\n";
            return 0;
        }
    }
    std::cout << "-1\n";
    return 0;
}
