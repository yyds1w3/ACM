//Sun Sep 20 06:25:29 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
using namespace std;
struct Node {
};
std::ostream& operator<<(std::ostream& os, Node& rhs) {
    return os << "[" << "," << "]";
}
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1), b(n+1);
    vector<vector<i64>> c(n+1, vector<i64>(n+1, 0));
    
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            c[i][j] = 1LL * a[i] * b[j] % m;
            c[i][j] += -c[i-1][j-1] + c[i-1][j] + c[i][j-1];
        }
    }
    auto calc = [&](int x1, int y1, int x2, int y2) -> i64 {
        x1 = max(1, x1); y1 = max(1, y1);
        x2 = min(n, x2); y2 = min(n, y2);
        return c[x2][y2] - c[x1-1][y2] - c[x2][y1-1] + c[x1-1][y1-1];
    };
    auto get_c = [&](int x, int y) -> i64 {
        x = max(0, min(n, x));
        y = max(0, min(n, y));
        return c[x][y];
    };
    int offset = n + 2; 
    int max_dim = 3 * n + 5; 
    vector<vector<i64>> d1(max_dim, vector<i64>(max_dim, 0));
    vector<vector<i64>> d2(max_dim, vector<i64>(max_dim, 0));
    for (int i = 1; i < max_dim; ++i) {
        for (int j = 1; j < max_dim; ++j) {
            d1[i][j] = d1[i-1][j-1] + get_c(i - offset, j - offset);
        }
    }
    for (int i = 1; i < max_dim; ++i) {
        for (int j = max_dim - 2; j >= 1; --j) {
            d2[i][j] = d2[i-1][j+1] + get_c(i - offset, j - offset);
        }
    }
    i64 ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int L = max({i - 1, j - 1, n - i, n - j});
            i64 res = 1LL * L * calc(i - L, j - L, i + L, j + L);
            res -= d1[i+L-1+offset][j+L-1+offset] - d1[i-1+offset][j-1+offset]; 
            res -= d1[i-1+offset][j-1+offset] - d1[i-L-1+offset][j-L-1+offset]; 
            res += d2[i+L-1+offset][j-L+offset] - d2[i-1+offset][j+offset]; 
            res += d2[i-1+offset][j+offset] - d2[i-L-1+offset][j+L+offset]; 
            ans ^= res + (i - 1) * n + j - 1;
        }
    }
    cout << ans << nl;
    return 0;
}

