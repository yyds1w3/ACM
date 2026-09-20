//Sat Aug  1 08:14:16 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(m), b(m);
    std::vector<int> cnt(4);
    for (int i = 0; i < m; ++i) {
        std::cin >> a[i] >> b[i];
    }
    auto f = [&](int x, int y) -> bool {
        for (int i = 0; i < m; ++i) {
            if (a[i] != x && a[i] != y && b[i] != x && b[i] != y) return false;
        }
        return true;
    };
    int ans = 0;
    std::vector<int> u(2);
    u[0] = a[0], u[1] = b[0];
    std::vector<int> v(2);
    bool ok1 = true;
    for (int i = 0; i < m; ++i) {
        if (u[0] != a[i] && u[0] != b[i]) {
            v[0] = a[i];
            v[1] = b[i];
            ok1 = false;
            break;
        }
    }
    if (ok1) ans += n - 1;
    else {
        if (f(u[0], v[0])) ans++;
        if (f(u[0], v[1])) ans++;
    }
    bool ok2 = true;
    for (int i = 0; i < m; ++i) {
        if (u[1] != a[i] && u[1] != b[i]) {
            v[0] = a[i];
            v[1] = b[i];
            ok2 = false;
            break;
        }
    }
    if (ok2) ans += n - 1;
    else {
        if (f(u[1], v[0])) ans++;
        if (f(u[1], v[1])) ans++;
    }
    if (f(u[0], u[1])) ans--;
    std::cout << ans << nl;
}
