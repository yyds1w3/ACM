#include <iostream>
#include <stack>
using namespace std;
const int N = 3e6 + 5;
stack<int> st;
int n, x, ans[N], a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i){
        while(!st.empty() && a[i] > a[st.top()]){
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";

}