#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
#define nl "\n"
#define debug(x) cerr << x << endl
bool vis[26];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    string s; cin >> s;
    for (char c : s) {
        vis[c - 'a'] = true;
    }
    for (int i = 0; i < 26; ++i) {
        if (!vis[i]) {cout << char('a' + i) << nl; return 0;}
    }
}
