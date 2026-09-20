//Sun Sep 20 12:05:42 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
struct Node {
};
std::ostream& operator<<(std::ostream& os, std::pair<i64,int>& rhs) {
    return os << "[" << rhs.first << "," << rhs.second << "]";
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    i64 n, m, k, x, y;
    std::cin >> n >> m >> k >> x >> y;
    std::vector<i64> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    std::priority_queue<i64> pq;
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        i64 need = (b[i] + k - 1) / k;
        if (y >= need) {
            y -= need;
            x += need * k - b[i];
            pq.push(b[i]);
            cnt++;
        }else break;
    }
    i64 tot = x + y * k;
    for (int i = 0; i < n; ++i) {
        if (tot >= a[i]) {
            tot -= a[i];
            cnt++;
        }else {
            if ((!pq.empty()) && (a[i] < pq.top())) {
                tot += pq.top() - a[i];
                pq.pop();
            }else {
                break;
            }
        }
    }
    std::cout << cnt << nl;
}
