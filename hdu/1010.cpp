//Thu Jul 23 03:58:47 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
// 0.5 * (5x^2 + 45x);
i64 f(i64 len, i64 times) {
    if (times >= len) return 0;
    i64 zduan = times + 1;
    i64 duanlen = (len - times) / zduan;
    i64 cduan = (len - times) % zduan;
    i64 dduan = zduan - cduan;
    i64 res = ((5 * duanlen * duanlen + 45 * duanlen) * dduan + (5 * (duanlen + 1) * (duanlen + 1) + 45 * (duanlen + 1)) * cduan) / 2;
    return res;
}
struct st {
    i64 len;
    i64 times;
    i64 shouyi;
    bool operator<(const struct st& other)const {
        return shouyi < other.shouyi;
    };
};
void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    std::priority_queue<st> pq;

    int l = 0;
    i64 tot = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') l++;
        else {
            if (l > 0) {
                pq.push({l, 0, f(l, 0) - f(l, 1)});
                tot += f(l, 0);
            }
            l = 0;
        }
    }
    if (l > 0) {
        pq.push({l, 0, f(l, 0) - f(l, 1)});
        tot += f(l, 0);
    }
    while (k-- && !pq.empty()) {
        auto stt = pq.top();
        pq.pop();
        tot -= stt.shouyi;
        pq.push({stt.len, stt.times + 1, f(stt.len, stt.times + 1) - f(stt.len, stt.times + 2)});
    }
    std::cout << tot << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
