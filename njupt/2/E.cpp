#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<long long> s(n);
    for (int i=0;i<n;i++) cin>>s[i];
    priority_queue<long long,vector<long long>,greater<long long>> q;
    long long ans=0;
    for (int i=0; i<n; i++) {
        q.push(s[i]);
        if (q.size() && q.top()<s[i]) {
            ans+=s[i]-q.top();
            q.pop();q.push(s[i]);
        }
    }
    cout << ans << endl;
    return 0;
}