//Tue Sep  8 11:28:37 PM CST 2026
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
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    if (s[0] == '0') {
        std::cout << -1 << nl;
        return;
    }
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '0' && s[i + 1] == '0') {
            std::cout << -1 << nl;
            return;
        }
    }
    int f1 = 1, f2 = 1;
    int cnt = 0;
    int fir = 1;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            cnt++;
        }else if (s[i] == '0') {
            if (cnt % 2 == 0) f1 = 0;
            cnt = 0;
            fir = 1;
        }else {
            if (s[i] == '+' && s[i - 1] == '-') {
                f1 = 0;
                if (cnt == 2 && !fir) f2 = 0;
                fir = 0;
                cnt = 1;
            }else if (s[i] == '-' && s[i - 1] == '+') {
                f1 = 0;
                if (cnt == 2 && !fir) f2 = 0;
                fir = 0;
                cnt = 1;
            }else {
                cnt++;
            }
        }
    }
    if (f1) std::cout << 1 << nl;
    else if (f2) std::cout << 2 << nl;
    else std::cout << 3 << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
