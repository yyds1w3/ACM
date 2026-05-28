//Sat May 23 07:48:14 PM CST 2026
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
const int P = 998244353;

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < n; ++i) std::cin >> b[i];
    int m;
    std::cin >> m;
    std::vector<int> c(m), d(m);
    for (int i = 0; i < m; ++i) std::cin >> c[i];
    for (int i = 0; i < m; ++i) std::cin >> d[i];
    int i = 0, j = 0;
    i64 ans = 1;
    while (i < n && j < m) {
        if (a[i] == c[j]) {
            if (b[i] > d[j]) {
                ans = (ans * 2) % P;
            }else if (b[i] < d[j]){
                ans = 0;
                break;
            }
            i++;
            j++;
        }else if (a[i] < c[j]) {
            ans = (ans * 2) % P;
            i++;
        }else {
            ans = 0;
            break;
        }
    }
    while (i < n) {
        ans = (ans * 2) % P;
        i++;
    }
    while (j < m) {
        ans = 0;
        j++;
        break;
    }
    std::cout << ans << nl;
}
