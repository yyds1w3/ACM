#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
#define nl "\n"
#define debug(x) cerr << x << endl

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n; cin >> n;
    vector<int> arr(n + 1);
    vector<int> left(n + 1), right(n + 1);
    vector<int> tails, ntails;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    for (int i = 1; i <= n; ++i) {
        auto it = lower_bound(tails.begin(), tails.end(), arr[i]);
        if (it == tails.end()) {
            tails.push_back(arr[i]);
            left[i] = tails.size();
        }
        else {
            *it = arr[i];
            left[i] = it - tails.begin() + 1;
        }
    } 
    for (int i = n; i >= 1; --i) {
        auto it = lower_bound(ntails.begin(), ntails.end(), arr[i]);
        if (it == ntails.end()) {
            ntails.push_back(arr[i]);
            right[i] = ntails.size();
        }
        else {
            *it = arr[i];
            right[i] = it - ntails.begin() + 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, left[i] + right[i] - 1);
    }
    cout << n - ans << nl;
    
}
