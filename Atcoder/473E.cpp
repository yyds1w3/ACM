//Thu Sep 17 16:04:16 CST 2026
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
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n + 1);
    std::map<int, int> mp;
    mp[0] = 0;
    int ans = 0;
    int lst = 0;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        a[i] = (a[i] + a[i - 1]) % k;
        if (mp.count(a[i]) != 0 && mp[a[i]] >= lst) {
            ans++;
            lst = i;
        }
        mp[a[i]] = i;
    }
    std::cout << ans << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
