#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back

LL M=1e9+9,P=27, p_Pow[1000005], invPow[1000005];
LL Hash[1000005];
LL binpow(LL a,LL b)
{
     LL ret=1;
    while(b)
    { if(b&1)ret=(ret*a)%M; a=(a*a)%M;  b>>=1; }
    return ret;
}
LL Hash(string st)
{
    LL val=0;
    for(int i=0;i<st.size();i++)
    {
        LL x=st[i]-'a'+1;
        x=(x*p_Pow[i])%M;
        val=(val+x)%M;
    }
    return val;
}
void precalc()
{
    p_Pow[0]=1;
    invPow[0]=1;
    for(int i=1;i<=1000002;i++)
    {
        p_Pow[i]=(p_Pow[i-1]*P)%M;
        invPow[i]=(binpow(p_Pow[i],M-2)%M);
        Hash[i]=0;
    }
}
LL sub_hash(LL i,LL j)
{
    LL val=(Hash[j]+M-Hash[i])%M;
    val=(val*invPow[i])%M;
    return val;
}

LL diff_sub_string(string st)
{
    LL c=0,n=st.size();
    vector<LL> preHash(n+5,0);
    for(int i=0;i<n;i++)
        preHash[i+1]=(preHash[i]+(st[i]-'a'+1)*p_Pow[i])%M;

    for(int l=1;l<=n;l++)
    {
        map<LL,LL>mp;
        for(int i=0;i<=n-l;i++)
        {
//            Sub hash is calculated here
            LL val=(preHash[i+l]+M-preHash[i])%M;
            val=(val*invPow[i])%M;
//            val=(val*p_Pow[n-i-1])%M; // both works fine
            mp[val]++;
        }
        c+=mp.size();
    }
    return c;
}
int main()
{
    precalc();
    string str; LL i,j;
    while(cin>>str)
    {
        cout<<diff_sub_string(str)<<endl;
    }
    while(cin>>str>>i>>j)
    {
        cout<<sub_hash(str,i,j)<<endl;
    }
    while(cin>>str)
    {
        cout<<Hash(str)<<endl;
    }
}
