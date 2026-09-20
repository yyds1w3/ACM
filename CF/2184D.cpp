//Fri Aug 28 06:54:01 PM CST 2026
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
int dp[32][100];
void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> d;
    while (n) {
        d.push_back(n % 2);
        n /= 2;
    }
    int m = d.size();
    memset(dp, -1, sizeof(dp));
    auto dfs = [&](auto self, int pos, bool lim, int cnt) -> int {
        if (pos == -1) {
            return cnt > k;
        }
        if (!lim && dp[pos][cnt] != -1) return dp[pos][cnt];
        int res = 0;
        int up = lim ? d[pos] : 1;
        for (int i = 0; i <= up; ++i) {
            if (!cnt) {
                res += self(self, pos-1, lim&&i==up, cnt+(i?(pos+1):0));
            }else {
                res += self(self, pos-1, lim&&i==up, cnt+i);
            }
        }
        if (!lim) dp[pos][cnt] = res;
        return res;
    };
    std::cout << dfs(dfs, m-1, 1, 0) << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
