#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
#define nl "\n"
#define debug(x) cerr << x << endl
const int MAXN = 5e5 + 1;
ll arr[MAXN], help[MAXN];
ll merge(int l, int m, int r) {
    ll ans = 0;
    for (int i = m, j = r; i >=l; i--) {
        while (j >= m + 1 && arr[i] <= arr[j]) {
            j--;
        }
        ans += j - m;
    }
    int i = l;
    int a = l;
    int b = m + 1;
    while (a <= m && b <= r) {
        help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
    }
    while (a <= m) {
        help[i++] = arr[a++];
    }
    while (b <= r) {
        help[i++] = arr[b++];
    }
    for (int i = l; i <= r; ++i) {
        arr[i] = help[i];
    }
    return ans;
     
}
ll f(int l, int r) {
    if (l == r) return 0;
    int m = (l + r) / 2;
    return f(l, m) + f(m + 1, r) + merge(l, m, r);
    
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    cout << f(1, n) << nl;
}
