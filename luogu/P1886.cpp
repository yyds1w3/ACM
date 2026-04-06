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
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> q(n);
    int hh = 0, tt = -1;
    for (int i = 0; i < n; ++i) {
        while (hh <= tt && a[q[tt]] >= a[i]) {
            tt--;
        }
        q[++tt] = i;
        while (hh <= tt && i > q[hh] + k - 1) {
            hh++;
        }
        if (i >= k - 1) {
            std::cout << a[q[hh]] << " ";
        }
    }
    std::cout << nl;
    hh = 0, tt = -1;
    for (int i = 0; i < n; ++i) {
        while (hh <= tt && a[q[tt]] <= a[i]) {
            tt--;
        }
        q[++tt] = i;
        while (hh <= tt && i > q[hh] + k - 1) {
            hh++;
        }
        if (i >= k - 1) {
            std::cout << a[q[hh]] << " ";
        }
    }
}
