//Sat Apr 18 08:12:32 PM CST 2026
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
    int t;
    std::cin >> t;
    while (t--) {
        std::string a, b;
        std::cin >> a >> b;
        auto f = [&](const std::string& s) -> std::string {
            std::string ans;
            for (char c : s) {
                ans += c;
                if (ans.size() >= 4 && ans.substr(ans.size() - 4) == "(xx)") {
                    ans.erase(ans.size() - 4);
                    ans += "xx";
                } 
            }
            return ans;
        };
        if (f(a) == f(b)) {
            std::cout << "Yes" << nl;
        }else {
            std::cout << "No" << nl;
        }
    }
}
