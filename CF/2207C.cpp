//Tue Sep  1 02:02:28 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
struct st {
};
std::ostream& operator<<(std::ostream& os, st& rhs) {
    return os;
}

void solve() {
    i64 n, h;
    std::cin >> n >> h;
    std::vector<i64> a(n + 1), cnt(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        i64 mxL = a[i];
        for (int j = i; j >= 1; --j) {
            mxL = std::max(mxL, a[j]);
            cnt[i] += h - mxL;
        }
        i64 mxR = a[i];
        for (int j = i; j <= n; ++j) {
            mxR = std::max(mxR, a[j]);
            cnt[i] += h - mxR;
        }
        cnt[i] -= h - a[i];
    }
    i64 ans = 0;
    for (int i = 1; i <= n; ++i) {
        int mx = 0;
        int k = -1;
        for (int j = i; j <= n; ++j) {
            if (a[j] > mx) {
                mx = a[j];
                k = j;
            }
            ans = std::max(ans, cnt[i] + cnt[j] - cnt[k]);
        }
    }
    std::cout << ans << nl;

}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
