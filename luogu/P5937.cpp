#include <algorithm>
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
const int MAXM = 5e3 + 1;
struct st{
    int x,y,z;
}a[2*MAXM];
int fa[2*MAXM], n, m, b[2*MAXM];
int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y){
    fa[find(x)] = find(y);
}
void solve(){
    cin >> n >> m;
    string s;
    for (int i = 1; i <= m; ++i){
        cin >> a[i].x >> a[i].y >> s;
        if (s[0] == 'o') a[i].z = 1;
        else a[i].z = 0;
        b[2*i-1] = a[i].x;
        b[2*i] = a[i].y;
    }
    sort(b+1, b+1+2*m);
    int sz = unique(b + 1, b + 1 + 2*m) - b - 1;
    for (int i = 1; i <= 2*sz; ++i){
        fa[i] = i;
    }
    for (int i = 1; i <= m; ++i){
        a[i].x = lower_bound(b+1, b+1+sz, a[i].x) -b;
        a[i].y = lower_bound(b+1, b+1+sz, a[i].y) -b;
        if (a[i].z==0){
            if(find(a[i].x) == find(a[i].y + sz)){
                cout << i-1;
                return;
            }else{
                merge(a[i].x, a[i].y);
                merge(a[i].x+sz, a[i].y+sz);
            }
        }else{
            if (find(a[i].x) == find(a[i].y)){
                cout << i - 1;
                return;
            }else{
                merge(a[i].x, a[i].y + sz);
                merge(a[i].y, a[i].x + sz);
            }
        }
    }
    cout << m;


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
