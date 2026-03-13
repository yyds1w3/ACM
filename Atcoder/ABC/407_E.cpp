#include <bits/stdc++.h>
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
    while(t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(2*n);
        for (int i = 0; i < 2*n; ++i) {
            std::cin >> a[i];
        }
        std::priority_queue<int> pq;
        i64 ans = 0;
        for (int i = 0; i < 2*n; ++i) {
            pq.push(a[i]);
            if ((int)pq.size() > (i + 1) / 2) {
                ans += pq.top();
                pq.pop();
            } 
        }
        std::cout << ans << nl;
    }
}
