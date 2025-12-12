#include <bits/stdc++.h>
using namespace std;

// === 随机数生成器封装 (复制这块就好) ===
// 使用 high_resolution_clock 防止一秒内多次运行种子相同
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// 生成 [l, r] 之间的随机整数
int rnd(int l, int r) {
    uniform_int_distribution<int> dist(l, r);
    return dist(rng);
}
// ======================================

int main() {
    // 假设题目输入格式：
    // 第一行：t (测试组数)
    // 接下来 t 组：
    //   n (数组长度)
    //   a1 a2 ... an (数组元素)
    
    int t = 1; // 如果题目是单测，就写 1；如果是多测，可以随机 rnd(1, 10)
    cout << t << endl;

    while (t--) {
        // 1. 生成 N (比如 1 到 10)
        // 注意：对拍时 N 不要太大，方便肉眼看 Bug
        int n = rnd(1, 10);
        cout << n << endl;

        // 2. 生成数组
        for (int i = 0; i < n; i++) {
            // 生成 [-100, 100] 的数
            int x = rnd(-100, 100); 
            cout << x << (i == n - 1 ? "" : " "); // 最后一个数不加空格
        }
        cout << endl;
    }
    
    return 0;
}