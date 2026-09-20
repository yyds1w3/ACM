//Wed Jul 22 03:32:39 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    auto isC = [](char c) -> bool {
        return !(c == 'a' || c == 'e');
    };
    std::string temp;
    std::vector<int> idx;
    int sz = s.size();
    for (int i = 0; i < sz ;++i) {
        if (isC(s[i])) {
            temp += 'c';
        }else {
            temp += 'v';
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
