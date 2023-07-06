#include <bits/stdc++.h>
using namespace std;
#define dbg(a)  cerr << __LINE__ << ": " << #a << " = " << a << '\n'
#define E end()
#define B begin()
#define sz size()
#define em empty()
#define fi first
#define se second
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


LL exgcd(LL a, LL b, LL& x, LL& y) {
    if(!b)
    {
        x=1,y=0; return a;
    }
    LL x1, y1;
    LL d = exgcd(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}

bool find_any(LL a,LL b, LL c, LL &x0,LL &y0,LL &g)
{
    g=exgcd(abs(a),abs(b),x0,y0);
    if(c%g) return false;

    x0=x0*(c/g), y0=y0*(c/g);
    if(a<0)x0*=-1;
    if(b<0)y0*=-1;
    return true;
}
void shift_solution(LL & x, LL & y, LL a, LL b, LL cnt) {
    x += cnt * b;
    y -= cnt * a;
}

LL find_all(LL a, LL b, LL c, LL minx, LL maxx, LL miny, LL maxy) {
    LL x, y, g;
    if (!find_any(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    LL sign_a = a > 0 ? +1 : -1;
    LL sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    LL lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    LL rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    LL lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    LL rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    LL lx = max(lx1, lx2);
    LL rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}
int main()
{
//    fast;
    LL i,j,k,n,m,l,s=0,x,y,tc=1,p,q,a,b,c=0,d=0;
    bool f=0,ff=0;string st,sa,sb,sc; char ch;
    cin>>tc;
    while(tc--)
    {
        LL x1, x2, y1, y2;
        cin>>a>>b>>c>>x1>>x2>>y1>>y2;
        c*=-1;

        cout<<"Case "<<++d<<": ";
        if(a==0 && b==0 && c==0) cout<<(x2-x1+1)*(y2-y1+1)<<en;
        else if(a==0 && b==0) cout<<0<<en;
        else if(a==0)
        {
            if(c%b!=0 || y1>c/b || y2<c/b) cout<<0<<en;
            else cout<<(x2-x1+1)<<en;
        }
        else if(b==0)
        {
            else cout<<(y2-y1+1)<<en;
        }
        else cout<<find_all(a, b, c, x1,x2,y1,y2)<<en;
    }
}