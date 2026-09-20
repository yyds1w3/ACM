#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main( )
{
    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        vector<ll> a(n);
        int num = 0;
        for(int i = 0;i < n;i++){
            cin>>a[i];
            num += a[i];
        }
        ll maxn = 0;
        sort(a.begin(),a.end());
        if(k%2 == 1 && k!=1){
            int chu = (k-1)/2;
            ll num1 = 0;
            for(int i = 0;i < chu;i++)
                num1 += a[i];
            int end = (n-(k - chu));
            int cha = (k-chu);    
            for(int i = chu;i <= end;i ++){
                ll num2 =0;
                for(int j = i;j < i + cha;j ++)
                    num2 +=a[j];
                ll maxn2 = k * a[i] - (num2+num1);     
                maxn = max(maxn,maxn2);    
            }     
        }
        else if(k!= 2) {
            int chu = k/2 - 1;
            ll num1 = 0;
            for(int i = 0;i < chu;i++)
                num1 += a[i];
            int cha = (k - chu);
            int end = (n-(k - chu));
            for(int i = chu;i <= end;i ++){
                ll num2 =0;
                for(int j = i;j < i + cha;j ++)
                    num2 +=a[j];
                ll maxn2 = (k*(a[i]+a[i+1]))/2 - (num2+num1);     
                maxn = max(maxn,maxn2);    
            }    
        }    
        cout<<num + maxn<<endl;
    }
    return 0;
}
