//Wed Aug 26 08:12:37 PM CST 2026
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
const i64 MOD = 998244353;
const int N = 1e6;
i64 fact[N+1], infact[N+1];
i64 qpow(i64 a, i64 b) {
    i64 res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
};
i64 inv(i64 x) {
    return qpow(x, MOD - 2);
}
void init() {
    fact[0] = 1;
    for (int i = 1; i <= N; ++i) fact[i] = fact[i - 1] * i % MOD;
    infact[N] = inv(fact[N]);
    for (int i = N - 1; i >= 0; --i) infact[i] = infact[i+1] * (i + 1) % MOD;
}
i64 comb(i64 n, i64 m) {
    if (n < 0 || m > n || m < 0) return -1;
    return (fact[n] * infact[m] % MOD) * (infact[n-m]) % MOD;
}
void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int seg0 = 0, seg1 = 0;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; ++i) {
        int num = s[i] - '0';
        if (i > 0 && s[i] != s[i - 1]) {
            if (s[i - 1] == '0') {
                seg0++;
            }else {
                seg1++;
            }
        }
        if (num == 0) cnt0++;
        else cnt1++;
    }
    if (s[n - 1] == '1') {
        seg1++;
    }else {
        seg0++;
    }
    i64 ans = 1;
    if (cnt0 > 0) ans = (ans * comb(cnt0-1,seg0-1)) % MOD;
    if (cnt1 > 0) ans = (ans * comb(cnt1-1,seg1-1)) % MOD;
    std::cout << ans << nl;

}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    init();
    int t;
    std::cin >> t;
    while (t--) solve();
}
