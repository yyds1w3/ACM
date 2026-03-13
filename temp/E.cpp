#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
#define nl "\n"

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    std::string s;
    int n;
    std::cin >> s >> n;
    for (int i = 0; i < n; ++i) {
        int l, r; 
        std::cin >> l >> r;
        l--;
        std::string s1, s2;
        std::cin >> s1 >> s2;
        std::string temp = s.substr(l, r - l);
        s.erase(l, r - l);
        size_t idx = s.find(s1 + s2);
        if (idx != std::string::npos) {
            s.insert(idx + s1.size(), temp);
        }else {
            s += temp;
        }
    }
    std::cout << s << nl;
}
