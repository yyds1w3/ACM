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
    int n;
    std::cin >> n;
    std::set<std::string> names;
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        names.insert(s);
    }
    int m;
    std::cin >> m;
    std::map<std::string, int> mp;
    for (int i = 0; i < m; ++i) {
        std::string s;
        std::cin >> s;
        if (names.find(s) != names.end()) {
            if (mp[s] >= 1) {
                std::cout << "REPEAT" << nl;
            }else {
                std::cout << "OK" << nl;
            }
            mp[s]++;
        }else {
            std::cout << "WRONG" << nl;
        }
    }
}
