//Wed Sep 16 20:08:43 CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
struct Node {
    int x1, y1, x2, y2;
};
std::ostream& operator<<(std::ostream& os, Node& rhs) {
    auto [x1, y1, x2, y2] = rhs;
    return os << "[" <<x1<<','<<y1<<','<<x2<<y2<< "," << "]";
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> s(n, std::string(m, ' '));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> s[i][j];
        }
    }
    if (n > m) {
        std::vector<std::string> t(m, std::string(n, ' '));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                t[i][j] = s[j][i];
            }
        }
        s = t;
        std::swap(n, m);
    }

    i64 ans = 0;
    std::vector<int> ok(m);
    std::vector<int> sum(m);
    for (int top = 0; top < n; ++top) {
        ok.assign(m, 0);
        for (int dow = top; dow < n; ++dow) {
            int lt = -1, ld = -1;
            for (int j = 0; j < m; ++j) {
                if (s[dow][j] == '.') {
                    ld = j;
                    ok[j] = 1;
                }
                if (s[top][j] == '.') lt = j;
                sum[j] = (j > 0 ? sum[j-1] : 0) + ok[j];

                if (ok[j] && ld != -1 && lt != -1) {
                    int k = std::min(ld, lt);
                    ans += sum[k];
                }
            }

        }
    }
    std::cout << ans + 1 << nl;
}
