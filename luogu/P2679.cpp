#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
#define nl "\n"
struct stringHash {
    int P1 = 131;
    int P2 = 13331;
    int MOD1 = 1e9 + 7;
    int MOD2 = 1e9 + 9;
    std::vector<i64> h1, p1, h2, p2;

    stringHash(const std::string& s) {
        int n = s.size();
        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);
        p1.assign(n + 1, 0);
        p2.assign(n + 1, 0);
        p1[0] = p2[0] = 1;
        // h[i] 表示[0, i)的hash值
        // p[i] 表示s[i]位的基数
        for (int i = 0; i < n; ++i) {
            p1[i+1] = (p1[i] * P1) % MOD1;
            h1[i+1] = (h1[i] * P1 + s[i]) % MOD1;
            p2[i+1] = (p2[i] * P2) % MOD2;
            h2[i+1] = (h2[i] * P2 + s[i]) % MOD2;
        }
    }
    std::pair<i64, i64> get(int l, int r) {
        i64 res1 = (h1[r] - h1[l] * p1[r - l] % MOD1 + MOD1) % MOD1;
        i64 res2 = (h2[r] - h2[l] * p2[r - l] % MOD2 + MOD2) % MOD2;
        return {res1, res2};
    }
};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int N;
    std::cin >> N;
    std::set<std::pair<i64, i64>> st;
    for (int i = 0; i < N; ++i) {
        std::string s;
        std::cin >> s;
        stringHash ss(s);
        auto [res1, res2] = ss.get(0, s.size());
        st.insert({res1, res2}); 
    }
    std::cout << st.size() << nl;
}
