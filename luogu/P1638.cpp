#include <iostream>
#include <vector>
using namespace std;

const int N = 1e6 + 5;
const int M = 2005;

int n, m;
int a[N];
int t[M];

int main() {
    // 加速 IO
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int l = 1, r = 1;
    int cnt = 0;  
    int min_len = 1e9;
    int ans_l = 1, ans_r = n;

    for (r = 1; r <= n; ++r) {
        if (t[a[r]] == 0) {
            cnt++;
        }
        t[a[r]]++;
        while (cnt == m) {
            if (r - l + 1 < min_len) {
                min_len = r - l + 1;
                ans_l = l;
                ans_r = r;
            }
            
            t[a[l]]--;
            if (t[a[l]] == 0) {
                cnt--;
            }
            l++; // 无论如何 L 都要走
        }
    }

    cout << ans_l << " " << ans_r << endl;
    return 0;
}