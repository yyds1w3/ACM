#include <bits/stdc++.h>

using namespace std;
long long a[1000000];
long long n, k;
long long ff(long long x){
    long long ans = 0;
    for (long long i = 0; i < n; ++i){
        ans += a[i] / x;
    }
    return ans;
}

long long f(long long l, long long r){
    while (l < r - 1){ // l = 5, r >= 7 --> m < 7, m == 6 ? 5
        long long m = (l + r) / 2;    // 目标找到最大的m能达成目标
        long long q = ff(m);
        if (q >= k){ // ff越大, m越小, 我们要找满足条件(q >= k)的最大的m
            l = m;
        }else{
            r = m;
        }
    }
    return l;
}

int main(){
    cin >> n >> k;
    for (long long i = 0; i < n; ++i){
        cin >> a[i];
    }
    cout << f(0, 100000001);

}