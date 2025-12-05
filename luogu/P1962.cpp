#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
ll n;
struct Marix{
    ll m[2][2];
    Marix(){
        memset(m, 0, sizeof(m));
    }
    Marix operator*(const Marix& other) const{
        Marix c;
        for (int i = 0; i < 2; ++i){
            for (int j = 0; j < 2; ++j){
                for (int k = 0; k < 2; ++k){
                    c.m[i][j] = (c.m[i][j] + this->m[i][k] * other.m[k][j]) % MOD;
                }
            }
        }
        return c;
    }
};
int main(){
    cin >> n;
    if (n <= 2) {cout << 1; return 0;}
    Marix base;
    base.m[0][0] = 0, base.m[0][1] = 1;
    base.m[1][0] = 1, base.m[1][1] = 1;
    Marix res;
    res.m[0][0] = 1, res.m[0][1] = 1;
    ll p = n - 2;
    while (p){
        if (p & 1){
            res = res * base;
        }
        base = base * base;
        p >>= 1;
    }
    ll ans = res.m[0][1];
    cout << ans;
}