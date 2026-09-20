//Tue Aug 25 09:34:06 PM CST 2026
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
    int n;
    std::cin >> n;
    std::vector<int> a(n), d(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < n; ++i) std::cin >> d[i];

    std::vector<int> ord;
    for (int i = n - 1; i >= 0; --i) {
        int cnt = 0;
        int pos = 0;
        for (int j = (int)ord.size() - 1; j >= 0; --j) {
            if (cnt == d[i]) {
                pos = j + 1;
                break;
            }
            int jj = ord[j];
            if (a[i] < a[jj]) cnt++;
        }
        if (cnt < d[i]) {
            std::cout << -1 << nl;
            return;
        }
        ord.insert(ord.begin() + pos, i);
    }
    std::vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[ord[i]] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
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
