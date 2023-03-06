#include<bits/stdc++.h>
using namespace std;
#define E end()
#define B begin()
#define sz size()
#define em empty()
#define fi first
#define se second
#define cnt continue
#define cl clear()
#define pb push_back
string en="\n";
string sp=" ";
string t="hello";
string Y="YES\n";
string N="NO\n";
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
int dx[]={-1,0,0,1,-1,-1,1,1},Row,Col;
int dy[]={0,-1,1,0,-1,1,-1,1};
int kx[]={-2,-2,2,2,-1,-1,1,1};
int ky[]={-1,1,-1,1,-2,2,-2,2};
using LL=long long;
using LD=long double;
using ULL=unsigned long long;
bool isprm(LL a){for(LL i=2;i*i<=a;i++){if(a%i==0)return false;}return true;}
bool palin(string a){for(int i=0;i<a.sz;i++){if(a.at(i)!=a.at(a.sz-i-1))return 0;} return 1;}
int toInt(string s){int sm;stringstream ss(s);ss>>sm;return sm;}
LL ceil2(LL a,LL b){LL c=a/b; if(a%b)c++; return c; }
LL binpow(LL a,LL b){LL r=1;while(b>0){if(b&1)r=r*a;a=a*a;b>>=1;}return r;}
LL binpow(LL a,LL b,LL m){a%=m;LL r=1;while(b>0){if(b&1) r=r*a%m;a=a*a%m; b>>=1;}return r;}
template<typename T>inline T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<typename T>inline T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
LL parent[10000];
map<LL,pair<LL,LL>>edg;
LL Find(LL r)
{
    if(parent[r]==r)return r;
    else return Find(parent[r]);
}
LL mst(LL n)
{
    for(int i=1;i<=n;i++)parent[i]=i;
    LL c=0,s=0;
    for(auto it=edg.B;it!=edg.E;it++)
    {
        LL a=it->se.fi,b=it->se.se,w=it->fi;
        if(Find(a)!=Find(b))
        {
            parent[Find(a)]=Find(b);
            c++,s+=w;
            if(c==n-1)break;
        }
    }
    return s;
}
int main()
{
//    fast;
    LL i,j,k,n,m,l,s=0,x,y,tc=1,p,q,a,b,c=0;
    bool f=0,ff=0;string st,s1,s2,s3; char ch;
    while(cin>>n>>m)
    {
        edg.clear();
        while(m--)
        {
            cin>>a>>b>>c;
            edg[c]={a,b};
        }
        p=mst(n);
        cout<<p<<en;
    }
}
