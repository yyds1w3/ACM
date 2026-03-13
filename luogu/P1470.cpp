#include <bits/stdc++.h>
#include <vector>
using i64 = long long;
using i128 = __int128;
#define nl "\n"

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    std::set<std::string> st;
    std::string s;
    while (std::cin >> s) {
        if (s == ".") break;
        st.insert(s);
    }
    s = "";
    std::string temp;
    while (std::cin >> temp) {
        s += temp;
    }
    int n = s.size();
    std::vector<bool> dp(n);
    for (int i = 0; i < n; ++i) {
        if (dp[i] == true) continue;
        for (auto p : st) {
            int m = p.size();
            int start = i - m + 1;
            if (start >= 0) {
                bool f = true;
                for (int j = start; j <= i; ++j) {
                    if (s[j] != p[j - start]) {
                        f = false;
                        break;
                    }
                }
                if (f) {
                    if (start == 0) dp[i] = true;
                    else dp[i] = dp[i] | dp[i-m];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (dp[i] == true) {
            ans = i + 1;
        }
    }
    std::cout << ans << nl;
}
