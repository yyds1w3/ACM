#include <bits/stdc++.h>
#include <queue>
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
    int q; cin >> q;
    queue<int> que;
    while (q--) {
        int a, b; cin >> a;
        if (a == 1) {
            cin >> b;
            que.push(b); 
        }else {
            cout << que.front() << nl;
            que.pop();
        }
    }
}
