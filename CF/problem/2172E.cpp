#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);
vector<string> v;
int main() {
    IOS;
    int t;
    cin >> t;
    while(t--){
        string s;
        int j, k;
        cin >> s >> j >> k;
        v.clear();
        sort(s.begin(), s.end());
        v.push_back(s);
        while (next_permutation(s.begin(), s.end())){
            v.push_back(s);
        }
        int x = 0;
        for (int i = 0; i < s.size(); ++i){
            if (v[j-1][i] == v[k-1][i]) x++;
        }
        cout << x << "A" << s.size() - x << "B" << "\n";
    }
    return 0;
}