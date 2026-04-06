#include <bits/stdc++.h>
#include <queue>
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
    int m, n;
    std::cin >> m >> n;
    std::queue<int> q;
    std::vector<bool> in_q(1001);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (!in_q[x]) {
            int sz = q.size();
            if (sz < m) {
                in_q[x] = true;
                q.push(x);
            }else {
                in_q[x] = true;
                in_q[q.front()] = false;
                q.pop();
                q.push(x);
            }
            cnt++;
        }
    }
    std::cout << cnt << nl;
}
