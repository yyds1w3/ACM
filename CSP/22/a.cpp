#include <bits/stdc++.h>
using namespace std;
int n, m, l;
int t[256];
int main(){
    cin >> n >> m >> l;
    int v;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> v;
            t[v]++;
        }
    }
    for (int i = 0; i < l; ++i){
        cout << t[i] << ' ';
    }
}