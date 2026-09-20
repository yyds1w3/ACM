//Fri Aug 28 12:37:59 PM CST 2026
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
    std::string s;
    std::cin >> s;
    int n = s.size();
    int cA = 0;
    std::vector<int> a;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') {
            cA++;
        }else {
            a.push_back(cA);
            cA = 0;
        }
    }
    a.push_back(cA);
    std::sort(a.begin(), a.end());
    // debugv(a, (int)a.size());
    std::cout << std::accumulate(a.begin() + 1, a.end(), 0) << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
