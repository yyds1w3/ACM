#include <iostream>
using namespace std;
const int N = 2e5 + 5;
const int M = 1e6 + 5;
int n, m, z, x, y;
int fa[N];
void init(){
    for (int i = 1; i <= n; ++i){
        fa[i] = i;
    }
}
int find(int x){
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
void join(int x, int y){
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY){
        fa[rootX] = rootY; 
    }
}
int main(){
    cin >> n >> m;
    init();
    for (int i = 1; i <= m; ++i){
        cin >> z >> x >> y;
        if (z == 1) join(x, y);
        else find(x) == find(y) ? cout << "Y" << '\n' : cout << "N" << '\n';
    }
}