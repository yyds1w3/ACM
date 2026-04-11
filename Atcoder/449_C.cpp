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
    int n, l, r;
    std::string s;
    std::cin >> n >> l >> r >> s;
    r++;
    std::vector<int> cnt(26);
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i >= l) {
            cnt[s[i - l] - 'a']++;
        }
        if (i >= r) {
            cnt[s[i - r] - 'a']--;
        }
        ans += cnt[s[i] - 'a'];
    }
    std::cout << ans << nl;
}
