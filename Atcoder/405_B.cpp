#include <bits/stdc++.h>
#include <vector>
using i64 = long long;
using i128 = __int128;
#define nl "\n"
int cnt[101];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n, m;
    std::cin >> n >> m;
    std::vector<int> v;
    for (int i = 0; i < n; ++i) {
        int x; 
        std::cin >> x;
        cnt[x]++;
        v.push_back(x);
    }
    for (int i = 0; i < m; ++i) {
        if (cnt[i+1] == 0) {
            std::cout << 0 << nl;
            return 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int ele = v.back();
        v.pop_back();
        cnt[ele]--;
        if (cnt[ele] == 0) {
            ans = i + 1;
            break;
        }
    }
    std::cout << ans << nl;
}
