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
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        ll base = 10;
        ll ans = 0;
        vector<ll> nums;
        while (n >= base + 1) {
            if (n % (base + 1) == 0) {
                ans++;
                nums.push_back(n / (base + 1));
            }
            base *= 10;
        }
        cout << ans << endl;
        if (ans > 0) {
            for (int i = ans-1; i >= 0; --i) cout << nums[i] << " ";
            cout << nl;
        }
    }
}
