#include <iostream>
using namespace std;
const int N = 1e5 + 1;
const int K = 21;
int st[N][K];
int Log2[N];
int n, m;
void init(){
    Log2[1] = 0;
    for (int i = 2; i <= n; ++i){
        Log2[i] = Log2[i>>1] + 1;
    }
    for (int j = 1; j < K; ++j){
        for (int i = 1; i + (1 << j) - 1 <= n; ++i){
            st[i][j] = max(st[i][j-1], st[i+ (1<<(j-1))][j-1]);
        }
    }
}
int query(int l, int r){
    int k = Log2[r - l + 1];
    return max(st[l][k], st[r - (1<<k) + 1][k]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin  >> st[i][0];
    }
    init();
    for (int i = 1; i <= m; ++i){
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << '\n';
    }
}