//Fri Sep 11 06:02:33 PM CST 2026
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
    i64 tot = 0;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        tot += a[i];
    }
    std::sort(a.begin(), a.end());
    int i = 1, j = n;
    std::vector<i64> ans(n + 1);
    // [i, j) [j, j]
    tot -= a[j];

    for (int k = n; k >= 1; --k) {
        while (i + k - 1 < j) {
            tot -= a[i];
            i++;
        }

        if (tot > a[j]) {
            ans[k] = tot + a[j];
        }else {
            while (tot <= a[j] && i > 1) {
                j--;
                tot -= a[j];
                i--;
                tot += a[i];
            }
            if (tot > a[j]) {
                ans[k] = tot + a[j];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        std::cout << ans[i] << " ";
    }
    std::cout << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
