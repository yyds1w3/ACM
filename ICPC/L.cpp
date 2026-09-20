//Wed Sep  9 06:37:10 PM CST 2026
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
};
std::ostream& operator<<(std::ostream& os, std::pair<int, int>& rhs) {
    return os << "[" << rhs.first << "," << rhs.second << "]";
}
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int r, c, n, p;
    std::cin >> r >> c >> n >> p;
    std::vector<std::vector<int>> a(r + 1, std::vector<int>(c + 1));
    std::vector<std::pair<int, int>> pos(n + 1);
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            std::cin >> a[i][j];
            if (a[i][j] != 0) {
                pos[a[i][j]] = {i, j};
            }
        }
    }
    std::set<int> s;
    for (int i = p; i >= 1; --i) {
        auto [x, y] = pos[i];
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 1 || nx > r || ny < 1 || ny > c) continue;
            if (a[nx][ny] != 0) {
                if (a[nx][ny] + p - i <= n) {
                    s.insert(a[nx][ny] + p - i);
                }
            }
        }
    }
    std::cout << s.size() << "/" << n - 1 << nl;
}
