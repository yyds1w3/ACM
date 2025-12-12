#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    // 【错误点】：习惯性把最大值初始化为 0
    // 如果输入是 -5 -10 -3，正确答案是 -3，但这里会输出 0
    int max_val = 0; 
    
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x > max_val) max_val = x;
    }
    cout << max_val << endl;
    return 0;
}