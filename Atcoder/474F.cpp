//Fri Sep 11 12:53:49 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
struct Node {
};
std::ostream& operator<<(std::ostream& os, Node& rhs) {
    return os << "[" << "," << "]";
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    std::vector<std::vector<i64>> primes(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 2*i; j <= n; j += i) {
            primes[j].push_back(i);
        }
    }

    i64 mn = 0, mx = 2e18;
    std::vector<i64> k(n + 1), b(n + 1); // c = kx + b >= 0;
    for (int i = n; i >= 1; --i) {
        k[i] += 1;
        b[i] -= a[i];

        for (int j : primes[i]) {
            k[j] -= k[i];
            b[j] -= b[i];
        }

        if (k[i] < 0) {
            k[i] = -k[i];
            mx = std::min(mx, b[i] / k[i]);
        }else if (k[i] == 0) {
            if (b[i] < 0) {
                std::cout << -1 << nl;
                return;
            }
        }else {
            b[i] = -b[i];
            mn = std::max(mn, 1 + (b[i] - 1) / k[i]);
        }
    }
    if (mn <= mx) {
        std::cout << mn - a[1] << nl;
    }else std::cout << -1 << nl;

}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
