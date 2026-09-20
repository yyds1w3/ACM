//Fri Aug 28 05:30:28 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
struct st {
    i64 x;
    i64 l, r;
};
std::ostream& operator<<(std::ostream& os, st& rhs) {
    return os;
}
const int N = 2e5;
const i64 INF = 2e18;
i64 dp[N][2];
void solve() {
    int n, sx, sy, ex, ey;
    std::cin >> n >> sx >> sy >> ex >> ey;
    std::vector<std::pair<i64, i64>> p(n);
    for (int i = 0; i < n; ++i) std::cin >> p[i].first;
    for (int i = 0; i < n; ++i) std::cin >> p[i].second;
    std::sort(p.begin(), p.end());

    std::vector<st> lines;
    lines.push_back({sx, sy, sy});
    for (int i = 0; i < n; ++i) {
        auto [x, y] = p[i];
        if (i != 0 && (x == lines.back().x)) {
            auto& [_, l, r] = lines.back(); 
            l = std::min(l, y);
            r = std::max(r, y);
        }else {
            lines.push_back({x, y, y});
        }
    }
    lines.push_back({ex, ey, ey});
    int m = lines.size();
    for (int i = 0; i < m; ++i) for (int j = 0; j < 2; ++j) dp[i][j] = INF;
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i < m; ++i) {
        auto [sx, sl, sr] = lines[i-1];
        auto [ex, el, er] = lines[i];

        if (sl <= er) dp[i][0] = std::min(dp[i][0], dp[i-1][0] + 2*er-sl-el);
        else dp[i][0] = std::min(dp[i][0], dp[i-1][0] + sl-el);
        if (sr <= er) dp[i][0] = std::min(dp[i][0], dp[i-1][1] + 2*er-sr-el);
        else dp[i][0] = std::min(dp[i][0], dp[i-1][1] + sr-el);
        dp[i][0] += ex-sx;

        if (sl >= el) dp[i][1] = std::min(dp[i][1], dp[i-1][0] + er+sl-2*el); 
        else dp[i][1] = std::min(dp[i][1], dp[i-1][0] + er-sl);
        if (sr >= el) dp[i][1] = std::min(dp[i][1], dp[i-1][1] + er+sr-2*el);
        else dp[i][1] = std::min(dp[i][1], dp[i-1][1] + er-sr);
        dp[i][1] += ex-sx;
    }
    std::cout << dp[m-1][0] << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
