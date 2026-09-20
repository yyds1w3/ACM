//Mon Aug  3 06:55:33 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 

void solve() {
    std::string s;
    std::cin >> s;
    bool f1 = false, f2 = false;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == '0' && s[i + 1] == '1') {
            s.erase(i, 1);
            f1 = true;
            break;
        }
    }
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == '1' && s[i + 1] == '0') {
            s.erase(i, 1);
            f2 = true;
            break;
        }
    }
    if (!f1) for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == '0') {s.erase(i, 1); break;}
    }
    if (!f2) for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == '1') {s.erase(i, 1); break;}
    }
    std::cout << s << nl;
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
