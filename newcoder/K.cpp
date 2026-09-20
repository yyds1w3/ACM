//Fri Jul 31 12:32:52 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;

int mex(int a, int b, int c) {
    if (a < b) std::swap(a, b);
    if (a < c) std::swap(a, c);
    if (b < c) std::swap(b, c);
    // a > b > c;
    int mex = 0;
    if (mex == c) mex++;
    if (mex == b) mex++;
    if (mex == a) mex++;
    return mex;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> a(11, std::vector<int>(n)); 
    for (int i = 0; i < n; ++i) std::cin >> a[0][i];
    for (int j = 1; j < 11; ++j) {
        for (int i = 0; i < n; ++i) {
            a[j][i] = mex(a[j - 1][i], a[j - 1][(i + n - 1) % n], a[j - 1][(i + 1) % n]);
        }
    }
    if (k > 10) {
        if (k & 1) k = 9;
        else k = 10;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << a[k][i] << " ";
    }
    std::cout << nl;
}
