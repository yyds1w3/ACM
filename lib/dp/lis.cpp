/**
 * Algorithm: LIS(Longest Increasing Subsequence)
 * Verified: Luogu P3637
 * Complexity: 
 * Author: Qingw 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//============================start======================================
struct LIS{
    // 关于lowerbound和upperbound我们假设tails里只有2, v也是2, 如果严格, tails应该还是只有2, 非降，tails里应该有22
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
            auto it = upper_bound(tails.begin(), tails.end(), v);
            if (it == tails.end()) tails.push_back(v);
            else *it = v;
        }
        return tails.size();
    }
}lis;

// ============================End=================================

int main() {
    IOS;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    cout << lis.strict(a);
}
