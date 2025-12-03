#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int N = 20; // 20! 已经很大了，爆 long long
ll fact[N];       // 阶乘表

void init_fact() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i;
}

// 逆康托展开：求长度为 n 的第 k 个排列 (1-based)
vector<int> reverse_cantor(int n, ll k) {
    k--; // 先转成 0-based (前面有多少个数)
    vector<int> res;
    vector<int> unused;
    
    // 初始化可用数字列表: 1, 2, ..., n
    for (int i = 1; i <= n; i++) unused.push_back(i);

    for (int i = n - 1; i >=  0; i--) {
        // 计算当前这一位应该是 unused 里的第几个
        ll idx = k / fact[i];
        k %= fact[i]; // 更新余数
        
        // 取出该数字
        res.push_back(unused[idx]);
        // 【关键】从可用列表里删除，保证不重复
        // vector erase 是 O(N)，总复杂度 O(N^2)
        unused.erase(unused.begin() + idx);
    }
    return res;
}

int main() {
    init_fact();
    int n = 5;
    ll k = 62;
    
    vector<int> p = reverse_cantor(n, k);
    
    for (int x : p) cout << x << " ";
    cout << endl;
    return 0;
}