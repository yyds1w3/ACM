#include <iostream>
#include <iomanip>
using namespace std;
typedef long long ll;
const int N = 1e5 + 1;
int A[N];
ll P[N];
int main(){
    int n, S, T;
    cin >> n;
    cin >> S >> T;
    for (int i = 1; i <= n; ++i){
        cin >> A[i];
        P[i] = P[i-1] + A[i];
    }
    double Maxeval = 0;
    for (int i = S; i <= T; ++i){
        ll Maxsum = 0;
        for (int j = 1; j + i - 1 <= n; ++j){
            Maxsum = max(P[j + i - 1] - P[j-1], Maxsum);
        }
        Maxeval = max(Maxeval, Maxsum / (double)i);
    }
    cout << setprecision(3) << fixed << Maxeval;

}