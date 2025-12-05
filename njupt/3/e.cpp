#include <iostream>
using namespace std;

const int N = 100005;
struct Node {
    int l{}, r{};
    bool removed;
} list[N];
int n, m;
int head = 1;
void r(int k, int i) {
    list[i].r = list[k].r;
    list[i].l = k;
    
    if (list[k].r != 0) list[list[k].r].l = i;
    list[k].r = i;
}

void l(int k, int i) {
    list[i].r = k;
    list[i].l = list[k].l;
    
    if (list[k].l != 0) list[list[k].l].r = i;
    list[k].l = i;
    
    if (k == head) head = i;
}
void d(int k){
    if (list[k].removed){
        return;
    }
    list[k].removed = true;
    if (list[k].l) list[list[k].l].r = list[k].r;
    if (list[k].r) list[list[k].r].l = list[k].l;
    if (head == k) head = list[k].r;
    list[k].l = list[k].r = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int k, p;
        cin >> k >> p;
        if (p == 1) {
            r(k, i);
        } else {
            l(k, i);
        }
    }
    cin >> m;
    for (int i = 1; i <= m; ++i){
        int x; cin >> x;
        d(x);
    }
    while (head != 0) {
        cout << head << " ";
        head = list[head].r;
    }
    
    return 0;
}