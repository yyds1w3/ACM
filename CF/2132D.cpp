//Tue Sep  1 10:40:16 AM CST 2026
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
    i64 tot, cnt;
};
std::ostream& operator<<(std::ostream& os, st& rhs) {
    return os;
}
// k=1*9+2*90+3*900...
void solve() {
    i64 k;
    std::cin >> k;
    i64 a = 1, b = 9, c = 0, lea = 0;
    while (k) {
        if (k >= a * b) {
            k -= a * b;
            a++;
            c+=b;
            b*=10;
        }else {
            c += k / a;
            k -= k / a * a;
            lea = k;
            break;
        }
    }
    i64 c2 = c + 1;
    std::vector<int> d1, d2;
    while (c) {
        d1.push_back(c % 10);
        c /= 10;
    }
    while (c2) {
        d2.push_back(c2 % 10);
        c2 /= 10;
    }
    i64 ans = 0;
    for (int i = (int)d2.size() - 1; i >= (int)d2.size() - lea; --i) {
        ans += d2[i];
    }
    int m = d1.size();
    std::vector<st> dp(m, {-1, -1});
    std::reverse(d1.begin(), d1.end());
    auto f = [&](auto self, int pos, int lim) -> st {
        if (pos == m) return {0, 1};
        if (!lim && dp[pos].tot != -1) return dp[pos];
        int up = (lim ? d1[pos] : 9);
        i64 tot = 0;
        i64 cnt = 0;
        for (int i = 0; i <= up; ++i) {
            auto [totv, cntv] = self(self, pos+1, lim&&i==up);
            tot += totv + i * cntv;
            cnt += cntv;
        }
        if (!lim) dp[pos] = {tot, cnt};
        return {tot, cnt};
    };
    std::cout << ans + f(f, 0, 1).tot << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
