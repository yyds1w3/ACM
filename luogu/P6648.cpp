//Sun Apr 19 09:24:40 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;

int f[2][3000][3000];

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            std::cin >> f[0][i][j];
        }
    }
    
    int p = std::__lg(k);
    
    // 阶段一：用 6 个点建 ST 表，杜绝“瑞士奶酪”窟窿
    for (int step = 1; step <= p; ++step) {
        int cur = step & 1;
        int pre = cur ^ 1; 
        int half = 1 << (step - 1);
        int quarter = step >= 2 ? 1 << (step - 2) : 0; // 偏移量 cha
        
        for (int i = 0; i + (1 << step) <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (step == 1) {
                    // 拼 size=2，3个点刚好
                    f[cur][i][j] = std::max({
                        f[pre][i][j], 
                        f[pre][i+half][j], 
                        f[pre][i+half][j+half]
                    });
                } else {
                    // 拼 size>=4，必须上 6 个点！
                    f[cur][i][j] = std::max({
                        f[pre][i][j], 
                        f[pre][i+half][j], 
                        f[pre][i+half][j+half],
                        f[pre][i+half][j+quarter], // 底边填缝
                        f[pre][i+quarter][j],      // 左边填缝
                        f[pre][i+quarter][j+quarter] // 右边填缝
                    });
                }
            }
        }
    }
    
    // 阶段二：用 6 个点做最终查询
    i64 sum = 0;
    int len = 1 << p;
    int final_layer = p & 1;
    int offset = (k - len) / 2;
    
    for (int i = 0; i + k <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (k == len) {
                // 如果 k 恰好是 2 的整数次幂，ST表里直接就有完美答案
                sum += f[final_layer][i][j];
            } else {
                int mx = std::max({
                    f[final_layer][i][j], 
                    f[final_layer][i+k-len][j], 
                    f[final_layer][i+k-len][j+k-len],
                    f[final_layer][i+k-len][j+offset], 
                    f[final_layer][i+offset][j], 
                    f[final_layer][i+offset][j+offset]
                });
                sum += mx;
            }
        }
    }
    
    std::cout << sum << nl;

    return 0;
}
