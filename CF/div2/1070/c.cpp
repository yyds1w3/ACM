#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

void solve()
{
    int n;
    cin >> n;
    vector<int> odd, even;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        if (x & 1)
            odd.push_back(x);
        else
            even.push_back(x);
    }
    if (!odd.empty())
        sort(odd.begin(), odd.end(), greater<int>());
    if (!even.empty())
        sort(even.begin(), even.end(), greater<int>());

    vector<ll> pre_even(even.size() + 1, 0);
    for (int i = 0; i < even.size(); ++i)
    {
        pre_even[i + 1] = pre_even[i] + even[i];
    }
    for (int k = 1; k <= n; ++k)
    {
        if (odd.empty()){
            cout << 0 << " ";
            continue;
        }
        int even_num = min((int)even.size(), k - 1);
        int odd_num = k - even_num;
        if ((odd_num & 1) == 0){
            even_num--;
            odd_num++;
        }
        ll ans;
        if (odd_num <= odd.size() && even_num >= 0){
            ans = odd[0] + pre_even[even_num];
        }else ans = 0;
        cout << ans << " ";
    }
    cout << '\n';
}

int main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}