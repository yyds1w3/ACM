#include <bits/stdc++.h>
#include <vector>
using i64 = long long;
using i128 = __int128;
#define nl "\n"

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n, m;
    std::cin >> n >> m;
    std::vector<i64> a(n + 1);
    for (int i = 1 ; i <= n; ++i) {
        std::cin >> a[i];
        a[i] += a[i - 1];
    }
    std::vector<int> q(n + 1);
    int hh = 0, tt = -1; 
    q[++tt] = 0;
    i64 ans = -3e9;
    for (int i = 1; i <= n; ++i) {
        if (hh <= tt && q[hh] < i - m){
            hh++;
        }
        ans = std::max(a[i] - a[q[hh]], ans);
        while (hh <= tt && a[q[tt]] >= a[i]) {
            tt--;
        }
        q[++tt] = i;
    }
    std::cout << ans << nl;

}
