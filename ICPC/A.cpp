//Tue Sep  8 06:55:23 PM CST 2026
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
    std::string s;
    std::cin >> s;
    int n = s.size();
    int j = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '-') {
            j = i + 1;
            break;
        }
    }
    if (j > n - 3) { 
        std::cout << "No" << nl;
        return;
    }
    if (s[0] != '>') {
        std::cout << "No" << nl;
        return;
    }
    std::vector<std::pair<int, int>> ans;
    for (int i = 0, k = n - 1; i < j - 1; ++i) {
        if (s[i] == '>') {
            while (k > j + 2) {
                ans.push_back({i, k});
                k--;
            }
            ans.push_back({i, k});
        }
    }
    if (ans.size() == 0) {
        std::cout << "No" << nl;
        return;
    }
    std::cout << "Yes " << ans.size() << nl;
    for (auto [l, r] : ans) {
        std::cout << l + 1 << " " << r - l + 1 << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
