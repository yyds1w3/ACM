#include<bits/stdc++.h>
using namespace std;
struct node{
    int l, r;
}Tree[1000000];
int M;

void dfs(int depth, int now){
    if (now == 0) return;
    M = max(depth, M);
    dfs(depth + 1, Tree[now].l);
    dfs(depth + 1, Tree[now].r);
}
int main(){
    int n; cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> Tree[i].l >> Tree[i].r;
    }
    dfs(1, 1);
    cout << M;
    
}
