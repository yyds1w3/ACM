#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);

void solve(){
    int x;
    cin >> x;
    if (x == 0) cout << "YES" << '\n';
    else{
        int bit = 0;
        int mp[32] = {0};
        int start = 0;
        bool flag = 1;
        while (x){
            bit++;
            mp[bit] = x&1;
            if (mp[bit] != 1 && flag) start++;
            else flag = 0;
            x >>= 1;
        }
        if ((bit - start) &1 == 1 && mp[(bit + start + 1) / 2] == 1) {cout << "NO" << '\n'; return;}
        for (int i = start+1; i <= (bit + start + 1) / 2; ++i){ // a[mid] == a[mid] is alway true
            if (mp[i] != mp[bit + start - i + 1] ) {cout << "NO" << '\n'; return; }
        }
        cout << "YES" << "\n";  
    }
}
int main() {
    IOS;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}