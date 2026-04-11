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
    freopen("in.txt", "r", stdin);
    #endif
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> dq(n);

    int head = 0, tail = -1;
    for (int i = 0; i < n; ++i) {
        while (head <= tail && a[dq[tail]] >= a[i]) {
            tail--;
        }
        dq[++tail] = i;
        if (i - dq[head] >= k) {
            head++;
        }
        if (i >= k - 1) {
            std::cout << a[dq[head]] << " ";
        }
    }
    std::cout << nl;

    head = 0, tail = -1;
    for (int i = 0; i < n; ++i) {
        while (head <= tail && a[dq[tail]] <= a[i]) {
            tail--;
        }
        dq[++tail] = i;
        if (i - dq[head] >= k) {
            head++;
        }
        if (i >= k - 1) {
            std::cout << a[dq[head]] << " ";
        }
    }
}
