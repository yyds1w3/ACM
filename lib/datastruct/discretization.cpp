/**
 * Algorithm: Discretization
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);

// =======================Start==============================
struct Discretization{
    vector<int> raw;

    void add(int x){
        raw.push_back(x);
    }
    void build(){
        sort(raw.begin(), raw.end());
        raw.erase(unique(raw.begin(), raw.end()), raw.end());
    }
    int get(int x){ // 1 - based
        return lower_bound(raw.begin(), raw.end(), x) - raw.begin() + 1;
    }
    int size(){
        return raw.size();
    }
};