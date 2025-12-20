/**
 * Algorithm: monotonic queue
 * Verified: Luogu P3373
 * Complexity: O(N) to find the mx and mn in the array
 * Author: Qingw
 */
#include <bits/stdc++.h>
#include <deque>
#include <vector>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);


// ==================satrt============================
struct MonoQueue{
    // k 指的是滑动窗口的最大值
    int get_max(const vector<int> &a, int k){
        int mx = -0x3f3f3f3f;
        deque<int> q;
        for (int i = 0; i < a.size(); ++i){
            while (!q.empty() && a[q.back()] <= a[i]) q.pop_back();
            q.push_back(i);
            while (!q.empty() && q.front() <= i - k) q.pop_front();
            mx = max(mx, a[q.front()]);
        }
        return mx;
    }
    int get_min(const vector<int> &a, int k){
        int mn = 0x3f3f3f3f;
        deque<int> q;
        for (int i = 0; i < a.size(); ++i){
            while (!q.empty() && a[q.back()] >= a[i]) q.pop_back();
            q.push_back(i);
            while (!q.empty() && q.front() <= i - k) q.pop_front();
            mn = min(mn, a[q.front()]);
        }
        return mn;
    }
};













// ========================End=================================
