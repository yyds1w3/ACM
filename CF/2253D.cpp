//Mon Aug 31 02:22:44 PM CST 2026
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
    int x, y;
    std::cin >> x >> y;
    int t = 1;
    i64 tot = 0;
    while (tot + t <= x + y) {
        tot += t;
        t++;
    }
    t--;
    std::vector<int> a(t + 1);
    for (int i = t; i >= 1; --i) {
        if (x > y) {
            x -= i;
            a[t+1-i] = 1;
        }else {
            y -= i;
            a[t+1-i] = 2;
        }
    }
    for (int i = 1;i <= t; ++i) {
        if (a[i] == 1) {
            std::cout << "X";
        }else if (a[i] == 2){
            std::cout << "Y";
        }
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
