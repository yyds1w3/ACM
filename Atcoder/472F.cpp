//Fri Sep 18 06:41:34 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
#define double long double
struct Node {
};
std::ostream& operator<<(std::ostream& os, std::pair<double, double>& rhs) {
    return os << "[" << rhs.first << "," << rhs.second << "]";
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    std::vector<i64> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i];
    }
    // OA x OB
    auto calcArea =[&](int A, int B) -> i64 {
        return (x[A] * y[B] - x[B] * y[A]);
    };
    auto calcG = [&](int A, int B) -> std::pair<i64, i64> {
        return {(x[A]+x[B]), (y[A]+y[B])};
    };
    auto calcM = [&](int A, int B) -> std::pair<i64, i64> {
        auto [x, y] = calcG(A, B);
        auto Area = calcArea(A, B);
        return {x*Area, y*Area};
    };
    std::vector<std::pair<i128, i128>> m(n);
    std::vector<i64> Area(n);
    for (int i = 0; i < n; ++i) {
        m[i] = calcM(i, (i+1)%n);
        Area[i] = calcArea(i, (i+1)%n);
    }
    for (int i = 1; i < n; ++i) {
        m[i].first += m[i-1].first;
        m[i].second += m[i-1].second;
        Area[i] += Area[i-1];
    }

    while (q--) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        i128 x, y;
        double rx, ry;
        if (v > u) {
            x = m[v-1].first - (u > 0 ? m[u-1].first : 0) + calcM(v, u).first;
            y = m[v-1].second - (u > 0 ? m[u-1].second : 0) + calcM(v, u).second;
            i64 Areasum = Area[v-1] - (u > 0 ? Area[u-1] : 0) + calcArea(v, u);
            rx = (double)x / (3.0 * (double)Areasum);
            ry = (double)y / (3.0 * (double)Areasum);
        }else { // v < u
            x = m[n-1].first - (u > 0 ? m[u-1].first : 0) + (v > 0 ? m[v-1].first : 0) + calcM(v, u).first;
            y = m[n-1].second - (u > 0 ? m[u-1].second : 0) + (v > 0 ? m[v-1].second : 0) + calcM(v, u).second;
            i64 Areasum = Area[n-1] - (u > 0 ? Area[u-1] : 0) + (v > 0 ? Area[v-1] : 0) + calcArea(v, u);
            rx = (double)x / (3.0 * (double)Areasum);
            ry = (double)y / (3.0 * (double)Areasum);
        }
        std::cout << std::setprecision(8) << std::fixed;
        std::cout << rx << " " << ry << nl;
    }
}
