#include <bits/stdc++.h>
#include <functional>
#include <vector>
using namespace std;
using ll = long long;
using i128 = __int128;
#define nl "\n"
#define debug(x) cerr << x << endl
struct LIS{
    int strict(const vector<int> &a){
        if (a.empty()) return 0;
        vector<int> tails;
        for (int v : a){
            auto it = lower_bound(tails.begin(), tails.end(), v);
            if (it == tails.end()) tails.push_back(v);
            else *it = v;
        }
        return tails.size();
    }
    int non_decreasing(const vector<int> &a){
        if (a.empty()) return 0;
        vector<int> tails;
        for (int v : a){
            auto it = upper_bound(tails.begin(), tails.end(), v, greater<int>());
            if (it == tails.end()) tails.push_back(v);
            else *it = v;
        }
        return tails.size();
    }
};
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    vector<int> a;
    int x;
    while (cin >> x) {
        a.push_back(x);
    }
    LIS lis;
    cout << lis.non_decreasing(a) << nl;
    cout << lis.strict(a) << nl;
}
