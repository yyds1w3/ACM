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

struct Point {
    double x, y;
};
double getDist(Point a, Point b) {
    double dx = std::abs(a.x - b.x);
    double dy = std::abs(a.y - b.y);
    return std::sqrt(dx * dx +  dy * dy);
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int N;
    std::cin >> N;
    double x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    int ltx = std::min(x1, x2);
    int lty = std::min(y1, y2);
    int rdx = std::max(x1, x2);
    int rdy = std::max(y1, y2);
    double area = (rdx - ltx) * (rdy - lty);
    std::vector<Point> a(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i].x >> a[i].y;
    }
    std::vector<int> b(N);
    std::iota(b.begin(), b.end(), 0);
    double mx = 0.0;
    while (true) {
        std::vector<double> r(N);
        double curr = 0;
        for (int i = 0; i < N; ++i) {
            int u = b[i];
            double limit = std::min({a[u].x - ltx, rdx - a[u].x, a[u].y - lty, rdy - a[u].y});
            for (int j = 0; j < i; ++j) {
                int v = b[j];
                double dist = getDist(a[u], a[v]);
                limit = std::min(limit, std::max(0.0, dist - r[v]));
            }
            r[u] = std::max(0.0, limit);
            curr += r[u] * r[u] * 3.1415926;
        }
        mx = std::max(mx, curr);
        if (!std::next_permutation(b.begin(), b.end())) break;
    }
    std::cout << (i64)std::round(area - mx) << nl;

}
