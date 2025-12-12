/**
 * Algorithm: Prime Factorization (Trial Division)
 * Verified: General Usage
 * Complexity: O(sqrt(N))
 * Author: Qingw
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);

// ========================start=========================================
struct Factorizer{
    map<ll, int> get_factors(ll n){
        map<ll, int> factors;
        for (ll i = 2; i * i <= n; ++i){
            while (n % i == 0){
                factors[i]++;
                n /= i;
            }
        }
        if (n > 1) factors[n]++;
        return factors;
    }
    vector<ll> get_factors_vector(ll n) {
        vector<ll> res;
        for (ll i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                res.push_back(i);
                n /= i;
            }
        }
        if (n > 1) res.push_back(n);
        return res;
    }
};


// =======================End================================================

int main() {
    IOS;
    ll n;
    cin >> n;
    
    Factorizer tool;
    map<ll, int> mp = tool.get_factors(n);
    
    for (auto const& [p, cnt] : mp) {
        cout << p << " " << cnt << "\n";
    }
    return 0; 
}