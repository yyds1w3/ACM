#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
#define nl "\n"

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string a; cin >> a;
        int m; cin >> m;
        string b, c; cin >> b >> c;
        for (int i = 0; i < m; ++i) {
            if (c[i] == 'V') {
                a = b[i] + a;
            }else if (c[i] == 'D'){
                a = a + b[i];
            }
        }
        cout << a << nl;
    }
}
