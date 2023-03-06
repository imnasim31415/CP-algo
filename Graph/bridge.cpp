#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz size()
#define cnt continue
#define all(cont) cont.begin(),cont.end()
using LL=long long;
vector<LL> adj[200005];
LL vis[200005],low[200005],Time=0;
vector<pair<LL,LL>>ans;

void dfs(LL n,LL par)
{
    vis[n]=low[n]=++Time;
    LL child=0;
    vector<LL> vv;
    for(int i=0;i<adj[n].sz;i++)
    {
        LL x=adj[n][i];
        if(x==par)cnt;
        if(!vis[x])
        {
            dfs(x,n);
            low[n]=min(low[n],low[x]);
            if(low[x]>vis[n])
            {
                ans.pb({min(x,n),max(n,x)});
            }
            child++;
            vv.pb(x);
        }
        else
        {
            low[n]=min(vis[x],low[n]);
        }
    }
}
int main()
{
    LL i,j,k,n,m,l,s=0,x,y,tc=1,p,q,a,b,c=0,d=0;
    bool f=0,ff=0;string st,sa,sb,sc; char ch;
    while(cin>>n>>m)
    {

        ans.clear();
        Time=0;
        for(i=0;i<n+5;i++)
        {
            adj[i].clear();
            vis[i]=low[i]=0;
        }

        for(i=0;i<m;i++)
        {
            cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        for(i=1;i<=n;i++)
        {
            if(!vis[i])dfs(i,-1);
        }

        cout<<"critical links or Bridges:"<<endl;
        for(auto x:ans)
        {
            cout<<x.first<<" - "<<x.second<<endl;
        }
        cout<<endl;
    }
}

