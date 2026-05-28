//Fri Apr 17 09:48:51 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#define debug_range(...) 43
#endif
using i64 = long long;
using i128 = __int128;


int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int n;
    std::cin >> n;
    std::vector<std::string> words(n);
    for (int i = 0; i < n; ++i) std::cin >> words[i];
    int k;
    std::cin >> k;
    std::cin.ignore();
    std::string s;
    std::getline(std::cin, s);
    int pos = 0;
    int cnt = 0;
    while (pos < s.size()) {
        for (auto &w : words) {
            if (s.substr(pos, w.size()) == w) {
                s.replace(pos, w.size(), "<censored>");
                pos += 9;
                cnt++;
                break;
            }
        }
        pos++;
    }
    if (cnt >= k) {
        std::cout << cnt << nl << "He Xie Ni Quan Jia!" << nl;
    }else {
        std::cout << s << nl;
    }
}
