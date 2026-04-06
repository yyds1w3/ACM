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
bool f(int x) {
    int idx = 1;
    while (x) {
        if (idx % 2 == 1) {
            if ((x % 10) % 2 == 0) return 0;
        }else {
            if ((x % 10) % 2 == 1) return 0;
        }
        x /= 10;
        idx++;
    }
    return 1;
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int N;
    std::cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        if (f(i)) ans++;
    }
    std::cout << ans << nl;
}
