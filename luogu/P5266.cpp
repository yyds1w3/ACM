//2026-04-09 21:16:49
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
    #endif
    int Q;
    std::cin >> Q;
    std::map<std::string, int> mp;
    while (Q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            std::string name;
            int score;
            std::cin >> name >> score;
            mp[name] = score;
            std::cout << "OK" << nl;
        }else if (op == 2) {
            std::string name;
            std::cin >> name;
            auto it = mp.find(name);
            if (it != mp.end()) {
                std::cout << it->second << nl;
            }else {
                std::cout << "Not found" << nl;
            }
        }else if (op == 3) {
            std::string name;
            std::cin >> name;
            auto it = mp.find(name);
            if (it != mp.end()) {
                mp.erase(it);
                std::cout << "Deleted successfully" << nl;
            }else {
                std::cout << "Not found" << nl;
            }
        }else {
            std::cout << mp.size() << nl;
        }
    }
}
