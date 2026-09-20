//Fri Jul 31 01:57:51 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
i64 C[51][51];

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::vector<int> cnt(10);
    for (int i = 0; i < n; ++i) {
        cnt[s[i] - '0']++;
    }
    C[0][0] = 1;
    for (int i = 1; i <= 50; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        int y = s[i] - '0';
        int len = n - i - 1;
        for (int x = 0; x < y; ++x) {
            if (cnt[x]) {
                cnt[x]--;
                i64 res = 1;
                i64 m = len;
                for (int num = 0; num <= 9; ++num) {
                    res *= C[m][cnt[num]];
                    m -= cnt[num];
                }
                ans += res;
                cnt[x]++;
            }
        }
        cnt[y]--;
    }
    std::cout << ans << nl;
}
