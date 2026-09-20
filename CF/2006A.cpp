//Mon Aug 24 08:50:47 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
const int INF = 1e9;
struct st {
};
std::ostream& operator<<(std::ostream& os, st& rhs) {
    return os;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> deg(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        deg[u]++;
        deg[v]++;
    }
    std::string s;
    std::cin >> s;
    int L0 = 0, L1 = 0, L2 = 0, I = 0;
    for (int i = 1; i < n; ++i) {
        if (deg[i] == 1) {
            if (s[i] == '0') L0++;
            if (s[i] == '1') L1++;
            if (s[i] == '?') L2++; 
        }else {
            if (s[i] == '?') I++;
        }
    }
    if (s[0] == '0') {
        std::cout << L1 + (L2 + 1) / 2 << nl;
    }else if (s[0] == '1') {
        std::cout << L0 + (L2 + 1) / 2 << nl;
    }else {
        if (L0 > L1) {
            std::cout << L0 + L2 / 2 << nl;
        }else if (L0 < L1) {
            std::cout << L1 + L2 / 2 << nl;
        }else {
            if (I & 1) {
                std::cout << L0 + (L2 + 1) / 2 << nl;
            }else {
                std::cout << L0 + L2 / 2 << nl;
            }
        }
    }

}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
