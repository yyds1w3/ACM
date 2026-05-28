//Wed Apr 22 10:37:07 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#define debug_range(...) 43
#endif
using i64 = long long;
using i128 = __int128;
const int INF = 1e9;
int sgn(double x) {
    if (std::abs(x) < 1e-6) {
        return 0;
    }else if (x > 0) {
        return 1;
    }else{
        return -1;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int n;
    std::cin >> n;
    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i];
    }
    // 初始化两点间的距离
    std::vector<std::vector<double>> dist(n, std::vector<double>(n, INF));
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < n; ++j) {
            if (i == j) dist[i][j] = 0;
            if (s[j] == '1') {
                dist[i][j] = std::hypot(x[i] - x[j], y[i] - y[j]);
            }
        }
    }
    // floyd更新全源两点之间最短距离
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (sgn(dist[i][k] - INF) == 0) continue; 
            for (int j = 0; j < n; ++j) {
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    // 记录每个点到自己牧区的最远距离, 记录单个牧区的最长直径
    std::vector<double> mx_d(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (sgn(dist[i][j] - INF) < 0) {
                mx_d[i] = std::max(mx_d[i], dist[i][j]);
            }
        }
    }
    // 每个点对应的牧场的最长直径
    std::vector<double> comb_d(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (sgn(dist[i][j] - INF) < 0) {
                comb_d[i] = std::max(comb_d[i], mx_d[j]);
            }
        }
    }
    // 只要两点之间不是同一牧区(距离是INF,因为如果连通肯定小于INF),看看更新后的直径,求最小值
    double mn = INF;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (sgn(dist[i][j] - INF) == 0) {
                double m1 = mx_d[i] + mx_d[j] + std::hypot(x[i] - x[j], y[i] - y[j]);
                double m2 = std::max({comb_d[i], comb_d[j], m1});
                mn = std::min(mn, m2);
            }
        }
    }
    std::cout << std::setprecision(6) << std::fixed  << mn << nl;
}
