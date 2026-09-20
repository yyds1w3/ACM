//Tue Aug 25 03:11:34 PM CST 2026
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
    int val, id;
    bool operator<(const st& other) const {
        return val < other.val;
    }
};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, x, k;
    std::cin >> n >> x >> k;
    std::vector<int> a(n);
    std::vector<int> pos(n);
    std::iota(pos.begin(), pos.end(), 0);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::priority_queue<st> pq;
    i64 ans = 0;
    for (int i = n - 1; i >= n - k; --i) pq.push({a[i], i});
    for (int i = n - 1; i >= x; --i) {
        if (i-k>=0) pq.push({a[pos[i-k]], pos[i-k]});
        if ((i - x) % (x + 1) == 0) {
            while (!pq.empty()) {
                auto [val, id] = pq.top();
                if (pos[id] <= i + k) {
                    ans += val / 2;
                    pq.pop();
                    pos[id] = i + k;
                    pq.push({a[pos[i]], i + k});
                    break;
                }
                pq.pop();
            }
        }
    }
    std::cout << ans << nl;
}
