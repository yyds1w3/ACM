/**
 * Algorithm: Min Heap
 * Verified: Luogu P3865
 * Complexity:  build(O(N)), other(log(n));
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);

//===========================start==================================
const int MAXN = 1e5 + 5;
struct MinHeap{
    int h[MAXN];
    int sz;
    void down(int u){
        while(u * 2 <= sz){ // ensure non leave point
            // compare the child , ensure the t is the min leave
            int t = 2 * u; 
            if (t + 1 <= sz && h[t+1] < h[t]){
                t++;
            }
            // fa <= child ? break : swap and continue the cirle;
            if (h[u] <= h[t]) break;
            swap(h[u], h[t]);
            u = t;
        }
    }
    void up(int u){
        while (u > 1 && h[u] < h[u>>1]){
            swap(h[u], h[u>>1]);
            u >>= 1;
        }

    }
    void push(int x){
        h[++sz] = x;
        up(sz);
    }
    void pop(){
        h[1] = h[sz];
        sz--;
        down(1);
    }
    int top(){
        return h[1];
    }
    void build(int n){
        sz = n;
        for (int i = n / 2; i >= 1; --i){
            down(i);
        }
    }
};
