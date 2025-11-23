#include<cstdio>
typedef long long ll;
ll x,y,len; int k;

// x，y局部坐标
// a， b全局左上角坐标
void solve(ll x,ll y,ll a,ll b,ll l)
{
    if(l==1) return;
    // 左上
    if(x-a<=l/2-1 && y-b<=l/2-1)
    {
        printf("%lld %lld 1\n",a+l/2,b+l/2); // 中心的
        solve(x,y,a,b,l/2); // 左上
        solve(a+l/2-1,b+l/2,a,b+l/2,l/2); // 右上
        solve(a+l/2,b+l/2-1,a+l/2,b,l/2); // 左下
        solve(a+l/2,b+l/2,a+l/2,b+l/2,l/2); // 右下
    }
    // 左下
    else if(x-a<=l/2-1 && y-b>l/2-1)
    {
        printf("%lld %lld 2\n",a+l/2,b+l/2-1);
        solve(a+l/2-1,b+l/2-1,a,b,l/2);
        solve(x,y,a,b+l/2,l/2);
        solve(a+l/2,b+l/2-1,a+l/2,b,l/2);
        solve(a+l/2,b+l/2,a+l/2,b+l/2,l/2);
    }
    // 左下
    else if(x-a>l/2-1 && y-b<=l/2-1)
    {
        printf("%lld %lld 3\n",a+l/2-1,b+l/2);
        solve(a+l/2-1,b+l/2-1,a,b,l/2);
        solve(a+l/2-1,b+l/2,a,b+l/2,l/2);
        solve(x,y,a+l/2,b,l/2);
        solve(a+l/2,b+l/2,a+l/2,b+l/2,l/2);
    }
    // 右下
    else
    {
        printf("%lld %lld 4\n",a+l/2-1,b+l/2-1);
        solve(a+l/2-1,b+l/2-1,a,b,l/2);
        solve(a+l/2-1,b+l/2,a,b+l/2,l/2);
        solve(a+l/2,b+l/2-1,a+l/2,b,l/2);
        solve(x,y,a+l/2,b+l/2,l/2);
    }
}
int main()
{
    scanf("%d %lld %lld",&k,&x,&y);
    len=1 << k;
    solve(x,y,1,1,len);
    return 0;
}

