#include <bits/stdc++.h>
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
    string t, u; cin >> t >> u;
    for (unsigned int i = 0, len = u.size(); i + len - 1 < t.size(); ++i) {
        bool ans = true;
        for (unsigned int j = i; j < i + len; ++j) {
            if (t[j] != '?' && t[j] != u[j - i]) {
                ans = false;
                break;
            }
        }
        if (ans == true) {cout << "Yes" << nl; return 0;}
    }
    cout << "No" << nl;
}
