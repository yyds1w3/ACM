#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
map<string, string> fa;
string find(string x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(string &x, string &y){
    string rx = fa[x];
    string ry = fa[y];
    if (rx != ry) fa[rx] = find(ry);
}
void solve() {
    string s;
    string now_fa = "";
    while (cin >> s && s != "$"){
        char type = s[0];
        string name = s.substr(1);
        if (type == '#'){
            now_fa = name;
            if (fa.find(now_fa) == fa.end()){ // 新的祖先, 未曾在之前存在过
                fa[now_fa] = now_fa;
            }
        }else if (type == '+'){
            fa[name] = now_fa;
        }else{
            cout << name << " " << find(name) << "\n";
        }
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) {
        freopen("in.txt", "r", stdin);
    }
    auto _clock_start = chrono::high_resolution_clock::now();
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
#ifdef LOCAL
    auto _clock_end = chrono::high_resolution_clock::now();
    cerr << "Run Time: " 
         << chrono::duration_cast<chrono::milliseconds>(_clock_end - _clock_start).count() 
         << " ms" << endl;
#endif
    return 0;
}
