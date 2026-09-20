//Wed Aug 26 06:20:57 PM CST 2026
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
    std::string s;
    std::cin >> n >> s;
    int pos00 = -1, pos01 = -1, pos10 = -1, pos11 = -1;
    int c0 = 2, c1 = 2;
    for (int i = 0; i < n; ++i) {
        if (!(i & 1)) {
            if (s[i] == '0') {
                if (pos00 == -1 || pos00 == i % 4) {
                    pos00 = i % 4;
                    c0 = 1;
                }else {
                    c0 = 0;
                    break;
                }
            }else if (s[i] == '1') {
                if (pos01 == -1 || pos01 == i % 4) {
                    pos01 = i % 4;
                    c0 = 1;
                }else {
                    c0 = 0;
                    break;
                }
            }
        }else {
            if (s[i] == '0') {
                if (pos10 == -1 || pos10 == i % 4) {
                    pos10 = i % 4;
                    c1 = 1;
                }else {
                    c1 = 0;
                    break;
                }
            }else if (s[i] == '1') {
                if (pos11 == -1 || pos11 == i % 4) {
                    pos11 = i % 4;
                    c1 = 1;
                }else {
                    c1 = 0;
                    break;
                }
            }
        }
    }
    if ((pos00 != -1 || pos01 != -1) && pos00 == pos01) c0 = 0;
    if ((pos10 != -1 || pos11 != -1) && pos10 == pos11) c1 = 0;
    std::cout << c0 * c1 << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
