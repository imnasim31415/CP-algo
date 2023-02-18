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
using LL=long long;
LL dx[]={-1,0,0,1,-1,-1,1,1},Row,Col;
LL dy[]={0,-1,1,0,-1,1,-1,1};
LL kx[]={-2,-2,2,2,-1,-1,1,1};
LL ky[]={-1,1,-1,1,-2,2,-2,2};
using LD=long double;
using ULL=unsigned long long;
bool isprm(LL a){for(LL i=2;i*i<=a;i++){if(a%i==0)return false;}return true;}
bool palin(string a){for(LL i=0;i<a.sz;i++){if(a.at(i)!=a.at(a.sz-i-1))return 0;} return 1;}
LL binpow(LL a,LL b){LL r=1;while(b>0){if(b&1)r=r*a;a=a*a;b>>=1;}return r;}
LL binpow(LL a,LL b,LL m){a%=m;LL r=1;while(b>0){if(b&1) r=r*a%m;a=a*a%m; b>>=1;}return r;}
template<typename T>inline T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<typename T>inline T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
LL arr[200002],segTree[1000003],prop[1000003];

void build(LL n,LL lo,LL hi)
{
    if(lo==hi)
    {
        segTree[n]=arr[lo];
        return ;
    }


    LL mid=(lo+hi)/2;
    build(n*2,lo,mid);
    build(n*2+1,mid+1,hi);
    segTree[n]=min(segTree[n*2],segTree[n*2+1]);
}
void upd(LL n,LL lo,LL hi,LL l,LL r,LL v)
{
    if(prop[n]!=0)
    {
        segTree[n]+=prop[n];
        if(lo!=hi)
        {
            prop[n*2]+=prop[n];
            prop[n*2+1]+=prop[n];
        }
        prop[n]=0;
    }
    if(lo>r||hi<l)return;


    if(lo>=l&&hi<=r)
    {
        segTree[n]+=v;
        if(lo!=hi)
        {
            prop[n*2]+=v;
            prop[n*2+1]+=v;
        }
        return ;
    }
    LL mid=(lo+hi)/2;
    upd(n*2,lo,mid,l,r,v);
    upd(n*2+1,mid+1,hi,l,r,v);
    segTree[n]=min(segTree[n*2],segTree[n*2+1]);
}
LL query(LL n,LL lo,LL hi,LL l,LL r)
{
    if(prop[n]!=0)
    {
        segTree[n]+=prop[n];
        if(lo!=hi)
        {
            prop[n*2]+=prop[n];
            prop[n*2+1]+=prop[n];
        }
        prop[n]=0;
    }
    if(lo>r||hi<l)return 1e12;
    if(lo>=l&&hi<=r)return segTree[n];
    LL mid=(lo+hi)/2;


    LL p1=query(n*2,lo,mid,l,r);
    LL p2=query(n*2+1,mid+1,hi,l,r);
    return min(p1,p2);

}
int main()
{
//    fast;
    LL i,j,k,n,m,l,s=0,x,y,tc=1,p,q,a,b,c=0,d;
    bool f=0,ff=0;string st,sa,sb,sc; char ch;

    cout<<"Enter Array size: ";
    cin>>n;
    rep(i,n)cin>>arr[i];

    build(1,0,n-1);
    cout<<"Enter Query number: ";
    cin>>q;

    while(q--)
    {
        cout<<"1->update\t2->query\n\n";

        cin>>x;

        if(x==1)
        {
            cout<<"Enter Range and value ";
            cin>>a>>b>>c;
            upd(1,0,n-1,a,b,c);
        }
        else
        {
            cout<<"Enter range ";
            cin>>a>>b;
            cout<<query(1,0,n-1,a,b)<<endl;
        }
    }
    return 0;
}
