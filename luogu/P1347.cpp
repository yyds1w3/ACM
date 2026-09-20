#include <bits/stdc++.h>
using i64 = long long;
void solve(int n, int m) {
    std::vector<std::vector<int>> adj(n);
    std::vector<int> in(n, 0);
    int status = 0;
    int ans_step = 0;
    std::string ans_str = "";
    for (int i = 1; i <= m; ++i) {
        std::string s;
        std::cin >> s;
        if (status != 0) continue;
        int u = s[0] - 'A';
        int v = s[2] - 'A';
        adj[u].push_back(v);
        in[v]++;
        auto check = [&]() -> int {
            std::vector<int> temp_in = in;
            std::queue<int> q;
            for (int j = 0; j < n; ++j) {
                if (temp_in[j] == 0) {
                    q.push(j);
                }
            }
            bool uncertain = false;
            std::string res = "";
            while (!q.empty()) {
                if (q.size() > 1) {
                    uncertain = true;
                }
                int curr = q.front();
                q.pop();
                res += char('A' + curr);
                for (int nxt : adj[curr]) {
                    temp_in[nxt]--;
                    if (temp_in[nxt] == 0) {
                        q.push(nxt);
                    }
                }
            }
            if (res.length() < n) {
                return 2;
            }
            if (uncertain) {
                return 0;
            }
            ans_str = res;
            return 1;
        };
        status = check();
        if (status != 0) {
            ans_step = i;
        }
    }
    if (status == 0) {
        std::cout << "Sorted sequence cannot be determined.\n";
    } else if (status == 1) {
        std::cout << "Sorted sequence determined after " << ans_step 
                  << " relations: " << ans_str << ".\n";
    } else {
        std::cout << "Inconsistency found after " << ans_step << " relations.\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    while (std::cin >> n >> m && (n != 0 || m != 0)) {
        solve(n, m);
    }
    
    return 0;
}
