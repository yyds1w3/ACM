#include <iostream>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
const int N = 1e6+1;
int a[N];

int bin_search(int *a, int size, int target){
    int l = 1, r = size, m, ans = -1;
    while (l <= r){
        m = l - (l - r ) / 2;
        if (target <= a[m]){
            if (target == a[m]){
                ans = m;
            }
            r = m - 1;
        }else{
            l = m + 1;
        }
    }
    return ans;
}   

int main(){
    IOS;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    int target;
    for (int i = 0; i < m; ++i){
        cin >> target;
        cout << bin_search(a, n, target) << " ";
        
    }
}