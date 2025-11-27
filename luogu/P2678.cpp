#include <bits/stdc++.h>

using namespace std;
int L, N, M, a[500000];
int l = 0, r = 1000000000, m;
bool judge(int x){
    int now = 0;
    int yizou = 0;
    for (int i = 1; i <= N+1; ++i){
        if (a[i] - a[now] < x){
            yizou++;
        }else{
            now = i;
        }
    }
    return yizou <= M;
}

int find_(){
    while(l < r - 1){
        m = (l + r) / 2; // l + r <= 2e9不会越界
        if (judge(m) == 1){
            l = m;
        }else{
            r = m;
        }
    }
    return l; // 当l = 0, r = 2, m = 1, 可以就取1, 不可以就取0, 都是l
}

int main(){
    cin >> L >> N >> M;
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
    }
    a[0] = 0; a[N+1] = L;
    cout << find_();



}