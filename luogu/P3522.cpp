//Tue Aug 11 09:34:11 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i];
    }
    int ans = 1;
    std::vector<int> q(n);
    int head = 0, tail = -1, l = 0;
    for (int i = 1; i < n; ++i) {
        while (head <= tail && x[i - 1] >= x[q[tail]]) tail--;
        q[++tail] = i - 1;
        while (head <= tail && y[i] < x[q[head]]) {
            l = q[head] + 1;
            head++;
        }
        ans = std::max(ans, i - l + 1);
    }
    std::cout << ans << nl;
}
