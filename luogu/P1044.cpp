#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll mem[20][20];
// i 未入栈 j 已入栈
ll dfs(int i, int j){
    if (mem[i][j]) return mem[i][j]; // 剪枝
    if (i == 0) return 1; // 边界
    ll ans = 0;
    if (i > 0) ans += dfs(i-1, j+1); // 进栈
    if (j > 0) ans +=dfs(i, j-1); // 出栈
    return mem[i][j] = ans;
}

int main(){
    cin >> n;
    cout << dfs(n, 0);
}
