#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 500005;
ll v[N];
int L[N], R[N];
struct Node {
    ll val;
    int id;
    bool operator>(const Node& other) const {return val > other.val;}
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    R[0] = 1;
    L[n + 1] = n;
    for (int i = 1; i <= n; ++i) { // init
        cin >> v[i];
        L[i] = i - 1;
        R[i] = i + 1;
        pq.push({v[i], i});
    }
    while (k > 0) {
        Node curr = pq.top();
        pq.pop();
        int id = curr.id;
        ll val = curr.val;
        if (val != v[id]) continue; // 已经被删过了
        k--;
        int left = L[id];
        int right = R[id];
        if (left != 0) {
            v[left] += val;
            pq.push({v[left], left});
        }
        if (right != n + 1) {
            v[right] += val;
            pq.push({v[right], right});
        }
        R[left] = right;
        L[right] = left;
        v[id] = -1; 
    }
    int curr = R[0];
    while (curr != n + 1) {
        cout << v[curr] << " ";
        curr = R[curr];
    }
}