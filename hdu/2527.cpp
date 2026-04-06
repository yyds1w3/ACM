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
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n;
    std::cin >> n;
    while (n--) {
        int m;
        std::cin >> m;
        std::string s;
        std::cin >> s;
        std::vector<int> cnt(26);
        for (int i = 0, sz = s.size(); i < sz; ++i) {
            cnt[s[i] - 'a']++; 
        }
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > 0) {
                pq.push(cnt[i]);
            }
        }
        if (pq.size() == 1) {
            std::cout << ((pq.top() <= m) ? "yes" : "no") << nl;
            continue;
        }
        int ans = 0;
        while (pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            pq.push(x + y);
            ans += x + y;
        }
        std::cout << (ans <= m ? "yes" : "no") << nl;

    }
}
