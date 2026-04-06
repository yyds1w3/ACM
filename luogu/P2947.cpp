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
    int n;
    std::cin >> n;
    std::vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> h[i];
    }
    std::vector<int> q(n);
    std::vector<int> ans(n);
    int top = -1;
    for (int i = n - 1; i >= 0; --i) {
        while (top >= 0 && h[q[top]] <= h[i]) {
            top--;
        }
        if (top >= 0 && h[q[top]] > h[i]) {
            ans[i] = q[top] + 1;
        } 
        q[++top] = i;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << nl;
    }
}
