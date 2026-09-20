//Wed Aug 19 01:05:43 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl; 
#define debugv(v, sz) std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;
#define debugvv(v, sz1, sz2) std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}
using i64 = long long;
using i128 = __int128;
double f(double x, double y) {
    return std::sqrt(x * x + y * y);
}
void solve() {
    std::vector<double> x(3), y(3);
    std::cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
    double a = atan2(y[0], -x[0]);
    double b1 = atan2(y[1], x[1]);
    double b2 = atan2(y[2], x[2]);
    if (b1 < b2) std::swap(b1, b2);
    double b3 = std::numbers::pi / 2 - a;
    double b4 = 3 * std::numbers::pi / 2 - a;
    double b5 = std::numbers::pi - a;
    double l = f(x[1], y[1]);
    auto calc = [&](double b) -> double {
        double k = l * std::sin(b) / std::sin(a);
        return std::abs(l * std::cos(b) + k * std::cos(a));
    };
    std::vector<bool> vis(5);
    vis[0] = vis[1] = true;
    if (b2<=b3&&b3<=b1) vis[2] = true;
    if (b2<=b4&&b4<=b1) vis[3] = true;
    if (b2<=b5&&b5<=b1) vis[4] = true;
    double ans1 = std::min({calc(b1), calc(b2)});
    double ans2 = std::max({calc(b1), calc(b2)});
    if (vis[2]) {
        ans1 = std::min(ans1, calc(b3));
        ans2 = std::max(ans2, calc(b3));
    }
    if (vis[3]) {
        ans1 = std::min(ans1, calc(b4));
        ans2 = std::max(ans2, calc(b4));
    }
    if (vis[4]) {
        ans1 = std::min(ans1, calc(b5));
        ans2 = std::max(ans2, calc(b5));
    }
    std::cout << std::setprecision(6) << std::fixed <<  ans1 << " " << ans2 << nl;
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
