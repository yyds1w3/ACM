/**
 * Algorthim: Linklist(static)
 * Verified:
 * Complexity: query(O(n)), insert, remove(O(1));
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);

// ====================start==============================
const int MAXN = 1e5 + 5;
struct Linklist{
    int head;
    int val[MAXN];
    int nxt[MAXN];
    int idx;

    void init(){
        head = -1;
        idx = 0;
    }
    void insert(int x){
        val[idx] = x;
        nxt[idx] = head;
        head = idx;
        idx++;
    }
    void traverse(){
        for (int i = head; i != -1; i = nxt[i]){
            cout << val[i] << " ";
        }
    }
};
// ====================end====================================
