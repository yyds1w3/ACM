#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;
using i128 = __int128;
#define nl "\n"
#define debug(x) cerr << x << endl
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n, m; cin >> n >> m;
    vector<vector<int>> zl(n+1);
    vector<int> cnt(m+1);
    for (int i = 1; i <= m; ++i) {
        int k; cin >> k;
        for (int j = 1; j <= k; ++j) {
            int e; cin >> e;
            zl[e].push_back(i);
            cnt[i]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int z; cin >> z;
        for (int e : zl[z]) {
            cnt[e]--;
            if (cnt[e] == 0) ans++;
        }
        cout << ans << nl;
    }
}
