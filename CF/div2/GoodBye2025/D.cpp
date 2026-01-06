#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using i128 = __int128;
const int MAXN = 2e5 + 1;
array<int, 2> a[MAXN];
void solve() {
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i][0], a[i][1] = i;
	if(m > n / 2) {
		cout << -1 << '\n';
		return;
	}
	sort(a + 1, a + 1 + n);
	
	vector<array<int, 2>> ans;
	if(m > 0) {
		for(int i = 1; i < n - 2 * (m - 1); i ++) {
			ans.push_back({a[i + 1][1], a[i][1]});
		}
		for(int i = n - 2 * (m - 1) + 1; i < n; i += 2) {
			ans.push_back({a[i + 1][1], a[i][1]});
		}
	} else {
		long long total = 0;
		for(int i = 1; i < n; i ++) total += a[i][0];
		if(total < a[n][0]) {
			cout << -1 << '\n';
			return;
		}
		for(int i = n - 1; i >= 1; i --) {
			a[n][0] -= a[i][0];
			if(a[n][0] <= 0) {
				for(int j = 1; j < i; j ++) {
					ans.push_back({a[j + 1][1], a[j][1]});
				}
				ans.push_back({a[n][1], a[i][1]});
				break;
			}
			ans.push_back({a[i][1], a[n][1]});
		}
	}
	
	cout << ans.size() << '\n';
	for(auto [x, y] : ans) cout << x << " " <<y << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
