#include <bits/stdc++.h>
using namespace std;
int n, x, d1, d2;
typedef long long ll;
ll ans;
priority_queue<int, vector<int>, greater<int>> pq;
int main(){
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> x;
        pq.push(x);
    }
    while (pq.size() >= 2){
        d1 = pq.top();
        pq.pop();
        d2 = pq.top();
        pq.pop();
        pq.push(d1 + d2);
        ans += d1 + d2;
    }
    cout << ans;
}