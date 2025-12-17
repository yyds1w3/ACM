/**
 * Algorthim: Hash_table
 * Verified: Luogu P4305
 * Complexity:  O(1)
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);


// ===============================start=================================
const int HASH_MOD = 1e5 + 7;
const int MAXN = 5e4 + 5;
struct HashTable{
    int head[HASH_MOD]; // 桶的头指针
    int val[MAXN]; // 桶
    int nxt[MAXN]; // 链表的nxt
    int tot;

    void clear(){
        tot = 0;
        memset(head, 0, sizeof(head));
    }
    int getHash(int value){
        return (value % HASH_MOD + HASH_MOD) % HASH_MOD; // 标准正负数取模;
    }
    bool insert(int x){
        int h = getHash(x);
        for (int i = head[h]; i != 0; i = nxt[i]){
            if (val[i] == x) return false;
        }
        // 头插法, 最开始的头都是0
        tot++;
        val[tot] = x; // 把新节点放进去
        nxt[tot] = head[h]; // 新节点的下一个节点是原来的头节点
        head[h] = tot; // 新节点变成头了
        return true;
    }
    bool find(int x){
        int h = getHash(x);
        for (int i = head[h]; i != 0; i = nxt[i]){
            if (val[i] == x) return true;
        }
        return false;
    }
}hashmp;
// ===============================End=====================================

int main(){
    IOS;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        hashmp.clear();
        for (int i = 1; i <= n; ++i){
            int x;
            cin >> x;
            if (hashmp.insert(x))
                cout << x << " ";
        }
        cout << "\n";
    }
}
