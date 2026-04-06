#include <bits/stdc++.h>
#include <string>
#include <vector>
using i64 = long long;
using i128 = __int128;
#define nl "\n"
int digit_sum(int n) {
    int ans = 0;
    while (n) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}
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
        if (s.size() == 1) {
            std::cout << s << nl;
            continue;
        }
        std::vector<int> cnt(10);
        int sum = 0;
        for (int i = 0, sz = s.size(); i < sz; ++i) {
            cnt[s[i] - '0']++;
            sum += s[i] - '0';
        }
        for (int i = std::max(1, sum - 100); i <= sum; ++i) {
            std::vector<int> seq;
            seq.push_back(i);
            int x = i;
            i64 left = x;
            while (x > 9) {
                x = digit_sum(x);
                seq.push_back(x);
                left += x;
            }
            left += x;
            if (left == sum) {
                bool ok = true;
                auto temp_cnt = cnt;
                for (int num : seq) {
                    std::string str_num = std::to_string(num);
                    for (char c : str_num) {
                        if (temp_cnt[c - '0'] > 0) {
                            temp_cnt[c - '0']--;
                        }else {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) break;
                }
                if (ok) {
                    int first = -1;
                    for (int d = 1; d <= 9; ++d) {
                        if (temp_cnt[d] > 0) {
                            first = d;
                            temp_cnt[d]--;
                            break;
                        }
                    }
                    if (first != -1) {
                        std::string ans = std::to_string(first);
                        for (int d = 0; d <= 9; ++d) {
                            ans.append(temp_cnt[d], d + '0');
                        }
                        for (int nm : seq) {
                            ans += std::to_string(nm);
                        }
                        std::cout << ans << nl;
                        break;
                    }
                }
            }
        }

    }
}
