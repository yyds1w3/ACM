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
    int n;
    std::cin >> n;
    std::vector<int> a(2 * n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        a[i + n] = a[i];
    }
    std::vector<int> s(2 * n + 1);
    for (int i = 1; i <= 2 * n; ++i) {
        s[i] = s[i - 1] + a[i];
    }
    std::vector<int> q(2 * n + 1);
    int hh = 0, tt = -1;
    int ans = 0;
    for (int i = 1; i <= 2 * n - 1; ++i) {
        if (hh <= tt && q[hh] < i - n + 1) {
            hh++;
        } 
        while (hh <= tt && s[q[tt]] >= s[i]) {
            tt--;
        }
        q[++tt] = i;
        if (i >= n) {
            if (s[q[hh]] >= s[i - n]) {
                ans++;
            }
        }
    }
    std::cout << ans << nl;
}
