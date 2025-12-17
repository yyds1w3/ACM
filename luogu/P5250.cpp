#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int m, op, len;
    set<int> st;
    cin >> m;
    for (int i = 0; i < m; ++i){
        cin >> op >> len;
        debug(st);
        if (op == 1) {
            if (st.find(len) != st.end()){
                cout << "Already Exist\n";
            }else{
                st.insert(len);
            }
        }else if (op == 2) {
            if (st.empty()) cout << "Empty\n";
            else{
                auto it = st.lower_bound(len);
                if (it == st.begin()){
                    cout << *it << '\n';
                    st.erase(it);
                }else if (it == st.end()){
                    cout << *prev(it) << '\n';
                    st.erase(prev(it));
                }
                else if ((*it-len) < (len-*prev(it))){
                    cout << *it << '\n';
                    st.erase(it);
                }
                else{
                    cout << *prev(it) << '\n';
                    st.erase(prev(it));
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) {
        freopen("in.txt", "r", stdin);
    }
    auto _clock_start = chrono::high_resolution_clock::now();
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
#ifdef LOCAL
    auto _clock_end = chrono::high_resolution_clock::now();
    cerr << "Run Time: " 
         << chrono::duration_cast<chrono::milliseconds>(_clock_end - _clock_start).count() 
         << " ms" << endl;
#endif
    return 0;
}
