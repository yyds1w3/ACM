#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

// 测试规模：10 亿次
const int N = 1000000000; 

int main() {
    // 竞速起手式
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ==========================================
    // 测试 1：极速轻量级运算（位运算与加法）
    // ==========================================
    auto start1 = high_resolution_clock::now();
    
    long long sum1 = 0;
    for (int i = 1; i <= N; ++i) {
        // 模拟 01-Trie 里的位移和异或操作
        sum1 ^= (i & (i >> 1)); 
    }
    
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(end1 - start1).count();
    
    cout << "测试 1 (位运算) 结果: " << sum1 << "\n";
    cout << "完成 10 亿次位运算耗时: " << duration1 << " ms\n";
    cout << "--------------------------------\n";

    // ==========================================
    // 测试 2：沉重的内存访问（大数组随机/跳跃访问）
    // ==========================================
    // 规模缩小到 1 亿次，防止内存直接爆炸
    const int M = 100000000; 
    vector<int> arr(M, 1);
    
    auto start2 = high_resolution_clock::now();
    
    long long sum2 = 0;
    // 故意制造缓存未命中 (Cache Miss)，步长设为 16
    for (int i = 0; i < M; i += 16) {
        sum2 += arr[i];
    }
    
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(end2 - start2).count();
    
    cout << "测试 2 (跳跃内存访问) 结果: " << sum2 << "\n";
    cout << "完成 1 亿次内存跳跃耗时: " << duration2 << " ms\n";

    return 0;
}
