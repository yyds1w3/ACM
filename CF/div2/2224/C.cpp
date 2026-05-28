//Wed May  6 03:02:50 PM CST 2026
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

void solve() {
    int n;
    std::cin >> n;
    std::string a, b;
    std::cin >> a >> b;
    if (std::count(a.begin(), a.end(), '(') + std::count(b.begin(), b.end(), '(') != 
        std::count(a.begin(), a.end(), ')') + std::count(b.begin(), b.end(), ')')) {
        std::cout << "NO" << nl;
        return;
    }
    int preA = 0, preB = 0;
    int d1 = 0, d2 = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '(') preA++;
        else preA--;
        if (b[i] == '(') preB++;
        else preB--;
        if (a[i] == '(' && b[i] == ')') d1++;
        if (a[i] == ')' && b[i] == '(') d2++;
        if (preA < 0 && d2 > 0) {
            preA += 2;
            preB -= 2;
            d2--;
        }else if (preA > n - i - 1 && d1 > 0) {
            preA -= 2;
            preB += 2;
            d1--;
        }
        if (preB < 0 && d1 > 0) {
            preA -= 2;
            preB += 2;
            d1--;
        }else if (preB > n - i - 1 && d2 > 0) {
            preA += 2;
            preB -= 2;
            d2--;
        }
        if (preA < 0 || preA > n - i - 1 || preB < 0 || preB > n - i - 1) {
            std::cout << "NO" << nl;
            return;
        }
    }
    std::cout << "YES" << nl;
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
