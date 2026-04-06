#include <bits/stdc++.h>
#include <string>
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
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        int sum = 0;
        std::vector<int> cnt(10);
        for (int i = 0, sz = s.size(); i < sz; ++i) {
            sum += s[i] - '0';
            cnt[s[i] - '0']++;
        }
        // 900000 -> 54 --> 18 --> 18
        for (int i = sum - 100; i <= sum; ++i) {
            int cur = i;
            int left = cur;
            std::string s;
            std::vector<std::string> ans;
            ans.push_back(std::to_string(cur));
            while (cur > 9) {
                cur = 0;
                s = std::to_string(cur);
                for (int j = 0, sz = s.size(); j < sz; ++j) {
                    cur += s[i] - '0';
                }
                left += cur;
                ans.push_back(s);
            }
            left += cur;
            if (left == sum) {
                int f = true;
                for (auto ns : ans) {
                    for (int j = 0, sz = ns.size(); j < sz; ++j) {
                        cnt[ns[j] - '0']--;
                        if (cnt[ns[j] - '0'] < 0) {
                            f = false;
                        }
                    }
                }
                if (f) {

                }
            }
        }
    }
}
