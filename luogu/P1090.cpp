#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    int x, y;
    int ans = 0;
    for (int i = 0; i < n; ++i){
        cin >> x;
        pq.push(x);
    }
    while (pq.size() >= 2){
        x = pq.top();
        pq.pop();
        y = pq.top();
        pq.pop();
        ans += (x + y);
        pq.push(x + y);
    }
    cout << ans;
    
}