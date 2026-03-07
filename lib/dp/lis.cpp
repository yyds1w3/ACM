#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
            auto it = upper_bound(tails.begin(), tails.end(), v);
            if (it == tails.end()) tails.push_back(v);
            else *it = v;
        }
        return tails.size();
    }
};
