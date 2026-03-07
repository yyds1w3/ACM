#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;
using i128 = __int128;
#define nl "\n"
#define debug(x) cerr << x << endl

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n, m, q; cin >> n >> m >> q;
    vector<set<int>> a(n + 1);
    vector<bool> b(n + 1);
    for (int i = 1; i <= q; ++i) {
        int op, x, y; cin >> op;
        if (op == 1) {
            cin >> x >> y;
            a[x].insert(y);
        }else if (op == 2) {
            cin >> x;
            b[x] = true;
        }else {
            cin >> x >> y;
            if (b[x] == true) {
                cout << "Yes" << nl;
            }else {
                if (a[x].count(y) == 1) cout << "Yes" << nl;
                else cout << "No" << nl;
            }
        }
    }
}
