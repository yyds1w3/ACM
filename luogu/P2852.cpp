#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 2e5 + 5;
const int P = 131;
int n, k;
int a[N];
ull h[N], p[N]; // h[i]代表[1,i]的字串哈希, p[i]代表p^i
void init_hash(){
    p[0] = 1;
    h[0] = 0;
    for (int i = 1; i <= n; ++i){
        p[i] = p[i-1] * P;
        h[i] = h[i-1] * P + a[i];
    }
}
ull get_hash(int l, int r){
    return h[r] - h[l-1] * p[r-l+1];
}
bool check(int len){
    vector<ull> v;
    for (int i = 1; i + len - 1 <= n; ++i){
        v.push_back(get_hash(i, i + len - 1));
    }
    if (v.empty()) return false;
    sort(v.begin(), v.end());
    int cnt = 1;
    for (size_t i = 1; i < v.size(); ++i){
        if (v[i-1] == v[i]){
            cnt++;
        }else{
            if (cnt >= k) return true;
            cnt = 1;
        }
    }
    return cnt >= k;
}
int bsearch(){
    int l = 0; int r = n;
    while (l < r){
        int mid = l + ((r - l + 1) >> 1); // 我们是找最大值,向上取整
        if (check(mid)){
            l = mid;
        }else{
            r = mid - 1;
        }
    }
    return l;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    init_hash();
    cout << bsearch();
}