#include<bits/stdc++.h>
using namespace std;
#define sz size()
#define pb push_back
#define fi first
#define se second
#define cnt continue
string en="\n";
string sp=" ";
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(i,n) for(i=0;i<n;i++)
#define Rep(i,n) for(i=1;i<=n;i++)
using LL=long long;
vector<pair<LL,LL>>g[100005];
LL dist[100005], vis[100005];

void dijkstra(LL s)
{
   mem(dist,LLONG_MAX);
   mem(vis,0);
   dist[s]=0LL;
   priority_queue<pair<LL,LL>>qq;

   qq.push({0,s});
   while(!qq.empty())
   {
      pair<LL,LL>pr=qq.top();
      LL x=pr.fi,y=pr.se;
      vis[y]=1;
      qq.pop();
      for(int i=0;i<g[y].sz;i++)
      {
         pr=g[y][i];
         LL xx=pr.fi,yy=pr.se;
         if(vis[xx])cnt;
         dist[xx]=min(dist[xx],dist[yy]+dist[x]);
         qq.push({yy,xx});
      }
   }
}
int main()
{
    LL i,j,k,n,m,l,s=0,x,y,tc=1,p,q,a,b,c=0;
    while(cin>>n>>m)
    {
       while(m--)
       {
          cin>>a>>b>>c;
          g[a].pb({b,c});
          g[b].pb({a,c});
       }
       cin>>s;
       dijkstra(s);
       Rep(i,n)cout<<i<<sp<<dist[i]<<en;
    }
}
