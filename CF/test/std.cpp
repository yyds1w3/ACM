#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    // 【正确写法】：初始化为极小值，或者数组第一个元素
    int max_val = -2e9; 
    
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        max_val = max(max_val, x);
    }
    cout << max_val << endl;
    return 0;
}