#include <bits/stdc++.h>

using namespace std;
int L, N, K, a[500000];
int l = 0, r = 10000000, m;
bool judge(int x){
    int res = 0;
    for (int i = 0; i < N-1; ++i){
        res += (a[i+1] - a[i] - 1) / x;
    }
    return res <= K;
}

int find_(){
    while(l < r - 1){
        m = (l + r) / 2; // l + r <= 2e9不会越界
        if (judge(m) == 1){ // 空旷指数可行, m可以更小吗
            r = m;
        }else{
            l = m;
        }
    }
    return r; // 当l = 0, r = 2, m = 1, 可以就取1, 不可以就取2, 都是r
}

int main(){
    cin >> L >> N >> K;
    r = L;
    for (int i = 0; i < N; ++i){
        cin >> a[i];
    }
    cout << find_();



}