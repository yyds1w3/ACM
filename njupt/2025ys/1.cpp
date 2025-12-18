#include <bits/stdc++.h>
#include <cctype>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
const int MAXN = 1e3 + 1;
char mp[MAXN][MAXN];
int a, b, c, d;
int n, m;
void solve() {
    bool flag = 0;
    cin >> n >> m;
    debug(n, m);
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> mp[i][j];
            if (flag == false && mp[i][j] == '#'){
                flag = true;
                debug(flag);
                continue;
            }
            else if (flag == true){
                debug(a, b, c);
                if (mp[i][j] == '#'){
                    cout << a << " " << b << " " << c << " " << d;
                    return;
                }
                a++;
                if (isupper(mp[i][j])) b++;
                else if(islower(mp[i][j])) c++;
                else if(isdigit(mp[i][j])) d++;
            }
            
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
