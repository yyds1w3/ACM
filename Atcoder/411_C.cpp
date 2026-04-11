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


int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < q; ++i) {
        int b;
        std::cin >> b; 
        b--;
        if(a[b] == 0) { // white
            if (b == n - 1) {
                if (a[b - 1] == 0) {
                    ans++;
                }
            }else if (b == 0) {
                if (a[b + 1] == 0) {
                    ans++;
                }
            }else {
                if (a[b - 1] == 1 && a[b + 1] == 1) {
                    ans--;
                }else if (a[b - 1] == 0 && a[b + 1] == 0) {
                    ans++;
                }
            }
            a[b] = 1;
        }else if (a[b] == 1) {
            if (b == n - 1) {
                if (a[b - 1] == 0) {
                    ans--;
                }
            }else if (b == 0) {
                if (a[b + 1] == 0) {
                    ans--;
                }
            }else {
                if (a[b - 1] == 1 && a[b + 1] == 1) {
                    ans++;
                }else if (a[b - 1] == 0 && a[b + 1] == 0) {
                    ans--;
                }
            }
            a[b] = 0;
        }
        std::cout << ans << nl;
    }
}
