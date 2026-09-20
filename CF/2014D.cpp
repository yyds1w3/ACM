//Sat Aug 29 01:44:28 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
struct st {
};
std::ostream& operator<<(std::ostream& os, std::pair<int, int>& rhs) {
    return os << "[" << rhs.first << "," << rhs.second << "]";
}
const int INF = 1e9;
void solve() {
    int n, d, k;
    std::cin >> n >> d >> k;
    std::vector<std::pair<int, int>> a(k);
    for (int i = 0; i < k; ++i) std::cin >> a[i].first >> a[i].second;
    std::sort(a.begin(), a.end());

    int r = -1;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int mn = INF, mx = 0;
    int mnidx = -1, mxidx = -1;
    for (int i = 1; i + d - 1 <= n; ++i) {
        while (r + 1 < k && a[r+1].first <= i + d - 1) {
            r++;
            pq.push(a[r].second);
        }
        while (!pq.empty()) {
            int x = pq.top();
            if (x < i) pq.pop();
            else break;
        }
        if ((int)pq.size() < mn) {
            mn = pq.size();
            mnidx = i;
        }
        if ((int)pq.size() > mx) {
            mx = pq.size();
            mxidx = i;
        }
    }
    std::cout << mxidx << " " << mnidx << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
