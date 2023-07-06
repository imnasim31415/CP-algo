#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define dbg(a)  cerr << __LINE__ << ": " << #a << " = " << a << '\n'
#define E end()
#define B begin()
#define sz size()
#define em empty()
#define fi first
#define se second
#define cnt continue
#define pb push_back
#define rep(i,n) for(i=0;i<n;i++)
#define Rep(i,n) for(i=1;i<=n;i++)
#define per(i,n) for(i=n-1;i>=0;i--)
#define peR(i,n) for(i=n;i>0;i--)
#define valid(x,y) x>=1 && x<=Row && y>=1 && y<=Col
#define mem(a,b) memset(a,b,sizeof(a))
#define all(cont) cont.begin(),cont.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define pi 3.1415926535897932384626433832795
#define vi vector<long long>
#define vs  vector<string>
#define MX LLONG_MAX
#define MN LLONG_MIN
#define MOD 1000000007
#define vp(vi,x) cin>>x; vi.pb(x);
#define bsearch(a,x) binary_search(all(a),x)
#define LB(a,x) (lower_bound(all(a),x)-a.B)
#define UB(a,x) (upper_bound(all(a),x)-a.B)
#define LL long long
#define Case(c) printf("Case %lld: ",++c)
string en="\n";
string sp=" ";
string t="hello";
string Y="YES\n";
string N="NO\n";
int dx[]={-1,0,0,1,-1,-1,1,1},Row,Col;
int dy[]={0,-1,1,0,-1,1,-1,1};
int kx[]={-2,-2,2,2,-1,-1,1,1};
int ky[]={-1,1,-1,1,-2,2,-2,2};
bool isprm(LL a){for(LL i=2;i*i<=a;i++){if(a%i==0)return false;}return true;}
bool palin(string a){for(int i=0;i<a.sz;i++){if(a.at(i)!=a.at(a.sz-i-1))return 0;} return 1;}
LL binpow(LL a,LL b){LL r=1;while(b>0){if(b&1)r=r*a;a=a*a;b>>=1;}return r;}
LL binpow(LL a,LL b,LL m){a%=m;LL r=1;while(b>0){if(b&1) r=r*a%m;a=a*a%m; b>>=1;}return r;}
template<typename T>inline T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<typename T>inline T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
LL dp[200005];
LL fun(LL n)
{
    if(n==1)return 0;
    if(dp[n]!=-1)return dp[n];

    LL c=MX;
    if(n%3==0)c=min(c,1+fun(n/3));
    if(n%2==0)c=min(c,1+fun(n/2));
    c=min(c,fun(n-1)+1);
    dp[n]=c;
    return c;
}
int main()
{
//    fast;
    LL i,j,k,n,m,l,s=0,x,y,tc=1,p,q,a,b,c=0,d;
    bool f=0,ff=0;string st,sa,sb,sc; char ch;
    while(cin>>n)
    {
        mem(dp,-1);
        cout<<fun(n)<<en;


        mem(dp,11111);
        dp[1]=0;

        for(i=1;i<=n;i++)
        {
            dp[i*3]=min(dp[i*3],dp[i]+1);
            dp[i*2]=min(dp[i*2],dp[i]+1);
            dp[i+1]=min(dp[i+1],dp[i]+1);
        }
        cout<<dp[n]<<en;
    }
}
