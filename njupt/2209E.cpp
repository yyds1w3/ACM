//Wed Aug 19 07:41:06 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl; 
#define debugv(v, sz) std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;
#define debugvv(v, sz1, sz2) std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}
using i64 = long long;
using i128 = __int128;
const int N = 1e6;
std::vector<int> f(N+1);
std::vector<int> f2(N+1);
void kmp(std::string s) {
    int n = s.size();
    f.assign(n + 1, 0);
    f2.assign(n+1, 0);
    f2[1] = 1;
    for (int i = 1, j = 0; i < n; ++i) {
        while (s[i] != s[j] && j) {
            j = f[j];
        }
        if (s[i] == s[j]) j++;
        f[i + 1] = j;
        f2[i+1] = (f[i+1] == 0 ? i + 1 : f2[f[i+1]]);
    }
}
void solve() {
    int n, q;
    std::string s;
    std::cin >> n >> q >> s;
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        l--;
        std::string t = s.substr(l, r - l);
        std::vector<int> dp(r - l + 1);
        kmp(t);
        i64 ans = 0;
        for (int i = 1; i <= r - l; ++i) {
            dp[i] = dp[i - f2[i]] + 1;
            ans += dp[i];
        }
        std::cout << ans << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
