#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
using LL=long long;
LL f[200005];
LL binpow(LL a,LL b)
{
    LL ret=1;
    while(b)
    {
        if(b&1)ret=(ret*a)%MOD;
        a=(a*a)%MOD,b>>=1;
    }
    return ret;
}
void fact()
{
    f[0]=1;
    for(int i=1;i<200005;i++)
        f[i]=(i*f[i-1])%MOD;
}
LL ncr(LL n,LL r)
{
    if(r>n)swap(n,r);
    LL a=f[n],b=(f[r]*f[n-r])%MOD;
    a=(a*binpow(b,MOD-2))%MOD;
    return a;
}
int main()
{
    fact();
    LL n,r;
    while(cin>>n>>r)
    {
        cout<<ncr(n,r)<<endl;
    }
}
