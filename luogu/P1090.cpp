#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
ll ans;
int n;
priority_queue<int, vector<int>, greater<int>> pq;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        pq.push(x);
    }
    while (pq.size() >= 2)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a + b);
        ans += a + b;
    }
    cout << ans;
}